#include "spotview.h"

#include <QVariant>
#include <QDebug>
#include <QtXmlPatterns/QXmlQuery>
#include <QFile>
#include <QDesktopServices>
#include <QBuffer>
#include <QSettings>
#include <QApplication>
#include <QRegExp>
#include <QWidget>
#include <QVBoxLayout>
#include <QToolBar>
#include <QToolButton>
#include <QIcon>
#include <QDirIterator>
#include <QAction>
#include <QFileDialog>
#include <QMenu>
#include <QMessageBox>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include <QWebEngineSettings>
#include <QWebEngineDownloadItem>
#include <QTextCodec>
#include "qtioprocessor/qtiocompressor.h"
#include <QPushButton>

#include "hashcash.h"
#include "spotsmodel.h"
#include "spotcategories.h"
#include "spotreplywindow.h"
#include "spotreportwindow.h"
#include "spotsignature.h"
#include "userdialog.h"
#include "parsedate.h"

QByteArray SpotView::_glMainTemplate, SpotView::_glCommentTemplate;
QString SpotView::_skinPath;
QIcon SpotView::_watchlistIcon;
QIcon SpotView::_replyIcon;
QIcon SpotView::_deleteIcon;
QSet<QByteArray> SpotView::_smileys;

// Decode NNTP text using charset from headers; default UTF-8, fallback Latin1/cp1252.
static QString decodeText(const QByteArray &bytes, const QList<QByteArray> &headers, const QString &defaultCharset = QStringLiteral("utf-8"))
{
    QString charset = defaultCharset;
    for (const QByteArray &h : headers)
    {
        int p = h.indexOf("charset=");
        if (p != -1)
        {
            QByteArray cs = h.mid(p + 8).trimmed();
            if (cs.startsWith('"') && cs.endsWith('"') && cs.length() > 1)
                cs = cs.mid(1, cs.length() - 2);
            charset = QString::fromLatin1(cs);
            break;
        }
    }

    auto codec = QTextCodec::codecForName(charset.toLatin1());
    QString text;
    if (codec)
        text = codec->toUnicode(bytes);
    else
        text = QString::fromUtf8(bytes);

    // Heuristiek: als veel vervangingskarakters, probeer Latin1/cp1252
    if (text.count(QChar::ReplacementCharacter) > 2 && charset.toLower() != QStringLiteral("windows-1252"))
        text = QString::fromLatin1(bytes);

    return text;
}

class SpotWebPage : public QWebEnginePage
{
    Q_OBJECT
public:
    using QWebEnginePage::QWebEnginePage;

signals:
    void linkClicked(const QUrl &url);

protected:
    bool acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame) override
    {
        if (type == NavigationTypeLinkClicked)
        {
            emit linkClicked(url);
            return false;
        }
        return QWebEnginePage::acceptNavigationRequest(url, type, isMainFrame);
    }
};

SpotView::SpotView(SpotLite *sl, QTabWidget *tw, int spotid, const QString &title, const QString &skinpath, QObject *parent) :
    QObject(parent), _sl(sl), _tw(tw), _spotid(spotid), _size(0), _title(title), _useActionLinks(true), _requireValidSignature(true)
{
    if (_mainTemplate.isEmpty() || skinpath != _skinPath )
    {
        QString path = skinpath;
        if (!QFile::exists(path+"/spot.tpl"))
            path = ":/tpl";

        QFile qf(path+"/spot.tpl");
        qf.open(qf.ReadOnly);
        _glMainTemplate = qf.readAll();
        qf.close();

        if (QFile::exists(path+"/comment.tpl"))
            qf.setFileName(path+"/comment.tpl");
        else
            qf.setFileName(":/tpl/comment.tpl");

        qf.open(qf.ReadOnly);
        _glCommentTemplate = qf.readAll();
        qf.close();

        _watchlistIcon = QIcon(":/icons/watchlist.png");
        _replyIcon = QIcon(":/icons/reply.png");
        _deleteIcon = QIcon(":/icons/ban.png");

        _smileys.clear();
        QDirIterator iter(":/smileys", QStringList("*.gif"));
        while (iter.hasNext())
        {
            iter.next();
            _smileys.insert(iter.fileName().left(iter.fileName().length()-4).toLatin1() );
        }
        _skinPath = skinpath;
    }
    _mainTemplate    = _glMainTemplate;
    _commentTemplate = _glCommentTemplate;

    connect(_sl, SIGNAL(articleData(QByteArray,QByteArray)), this, SLOT(onArticleData(QByteArray,QByteArray)));
    connect(_sl, SIGNAL(articleNotFound(QByteArray)), this, SLOT(onArticleNotFound(QByteArray)));

    if (_tw)
    {
        _widget = new QWidget();
        _initWebbrowser();
        _displayHTML("Bezig met laden van spot...", false);

        /* Toolbar spul */
        QToolBar *toolbar = new QToolBar( tr("Spot opties"), _widget);
        QToolButton *button1 = new QToolButton(toolbar);
        button1->setIcon(_watchlistIcon);
        button1->setText("Op watchlist");
        button1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        button1->setCheckable(true);
        button1->setChecked(_sl->isOnWatchlist(_spotid));
    /*    if (spotid < 0)
            button1->setEnabled(false); */
        QToolButton *button2 = new QToolButton(toolbar);
        button2->setIcon(_replyIcon);
        button2->setText("Reactie plaatsen");
        button2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        QToolButton *button3 = new QToolButton(toolbar);
        button3->setIcon(_deleteIcon);
        button3->setText("Verwijderen");
        button3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolbar->addWidget(button1);
        toolbar->addWidget(button2);
        toolbar->addWidget(button3);

        QVBoxLayout *layout = new QVBoxLayout(_widget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(_web);
        layout->addWidget(toolbar);
        _widget->setLayout(layout);

        connect(button1, SIGNAL(toggled(bool)), this, SLOT(onWatchlistToggle(bool)));
        connect(button2, SIGNAL(clicked()), this, SLOT(onReply()));
        connect(button3, SIGNAL(clicked()), this, SLOT(onDeleteSpot()));
        /* ---- */
        _tw->addTab(/*_web*/ _widget, _title.replace("&", "&&") );
    }
}

void SpotView::loadSpot()
{
    bool trans = false;
    if ( !_sl->inTransaction() )
    {
        trans = true;
        _sl->spotDatabase()->transaction();
    }

    QSqlQuery q(*_sl->spotDatabase() );
    if (_spotid < 0)
    {
        q.prepare("SELECT msgid,cat,subcat,othercats,tag,spotter,spotdate,title,spotterid FROM erospots WHERE id=?");
        q.addBindValue(0-_spotid);
    }
    else
    {
        q.prepare("SELECT msgid,cat,subcat,othercats,tag,spotter,spotdate,title,spotterid FROM spots WHERE id=?");
        q.addBindValue(_spotid);
    }
    q.exec();

    if ( q.next() )
    {
        _spotMSGID = q.value(0).toByteArray();
        _cat    = q.value(1).toInt();
        _subcat = q.value(2).toInt();
        QByteArray othercats = q.value(3).toByteArray();
        _tag = _toHTML( q.value(4).toByteArray() );
        _spotter = _toHTML( q.value(5).toByteArray() );
        _spotdate = q.value(6).toInt();
        if ( _spotdate < 1299884400)
            _requireValidSignature = false;
        _title = _toHTML( q.value(7).toString() );

        _cats.append(SpotsModel::subcategoryname(_subcat));
        if (!othercats.isEmpty() && othercats.length() % 3 == 0)
        {
            for (int i=0; i<othercats.length(); i+=3)
            {
                QString s = SpotCategories::cat2name(_cat, othercats.mid(i, 3));
                if (!s.isEmpty())
                    _cats.append(s);
            }
        }

        int spotterid = q.value(8).toInt();
        if (spotterid)
        {
            q.prepare("SELECT name FROM spotters WHERE id=?");
            q.addBindValue(spotterid);
            q.exec();

            if ( q.next() )
            {
                QByteArray spotters_origname = _toHTML( q.value(0).toByteArray() );
                if ( spotters_origname.toLower().trimmed() != _spotter.toLower().trimmed() )
                {
                    _spotter += " (alias "+spotters_origname+")";
                }
            }
        }

        _commentsToDownload = _sl->getCommentMsgNrs(_spotMSGID);
//        qDebug() << "comment nummertjes:" << _commentsToDownload;

        if (!_spotMSGID.contains('@'))
            _spotMSGID += "@free.pt";
        _sl->downloadArticle(_spotMSGID, true);

        foreach (int nr, _commentsToDownload)
        {
            _sl->downloadArticle(nr);
        }

        if ( _mainHTML.isEmpty() )
            emit notice(0, tr("Bezig met binnenhalen spotinformatie en %1 reacties...").arg( QString::number( _commentsToDownload.count() )) );
    }
    else
        _displayHTML("Kan spotinformatie niet (meer) in database vinden...");

    if (trans)
        _sl->spotDatabase()->commit();
//        sl->spotDatabase()->rollback();
}

void SpotView::activate()
{
    _tw->setCurrentIndex( tabIndex() );
}

int SpotView::tabIndex() const
{
    return _tw->indexOf(_widget /*_web*/);
}

int SpotView::spotId() const
{
    return _spotid;
}

void SpotView::onArticleData(const QByteArray &msgid, QByteArray data)
{
    if (msgid == _spotMSGID)
    {
        if (_parseSpot(data))
        {
            if (!_spotterkey.isEmpty() && _sl->isFoe(_spotterkey))
            {
                _displayHTML("Spot wordt niet getoond omdat deze is geplaatst door iemand die op je banlist staat.<p>Spotter: "+_spotter+"<br>UserID: "+_toHTML(_spotterkey));
                _commentsToDownload.clear();
                return;
            }

            _updateHTML();

            if ( !_imgMSGID.isEmpty() )
            {
                _imgMSGID = ">"+_imgMSGID;
                _sl->downloadArticle( _imgMSGID, true);
            }
            if ( !_nzbMSGID.isEmpty() )
            {
                _nzbMSGID = ">"+_nzbMSGID;
                _sl->downloadArticle( _nzbMSGID, true);
            }
        }
        else
        {
            QByteArray msg = "Spot bevat ongeldige informatie :-(";
            _displayHTML(msg);
            emit notice(0, msg);
        }
    }
    else if (msgid == _nzbMSGID)
    {
        if (_decodeNZB(data))
            _updateHTML();
    }
    else if (msgid == _imgMSGID)
    {
        if (_decodeIMG(data))
            _updateHTML();

        _imgMSGID.clear();
    }
    else if (!msgid.contains('@'))
    {
        int nr = msgid.toInt();
        if ( _commentsToDownload.contains(nr) )
        {
            _commentsHTML += _parseComment(nr, data);
            _commentsToDownload.removeOne(nr);
            if (_commentsToDownload.isEmpty())
            {
                _updateHTML();
            }
        }
        else
        {
            return; /* voor ander spot scherm bestemd */
        }
    }
    else
    {
        return; /* voor ander spot scherm bestemd */
    }

    if ( !_commentsToDownload.isEmpty() )
    {
        emit notice(0, tr("Bezig met %1 reacties te downloaden...").arg( QString::number(_commentsToDownload.size() )));
        //qDebug() << "bezig met: " << _commentsToDownload;
    }
    else if ( !_mainHTML.isEmpty() && !_newsgroup.isEmpty() )
        emit notice(0,tr("Klaar met downloaden spotinformatie..."));

}

void SpotView::onArticleNotFound(const QByteArray &msgid)
{
    if (msgid == _spotMSGID)
    {
        QByteArray msg = "Spot informatie niet aanwezig op Usenet server :-(";
        _displayHTML(msg);
        emit notice(0, msg);
    }
    else if (msgid == _nzbMSGID)
    {
        _newsgroup = "[b]Het lijkt erop dat je Usenet provider de bestandsnaam/groep informatie niet heeft![/b][br][br]Ook kan het zijn dat deze aparte systemen voor tekst- en binary groepen heeft, en niet naar het juiste systeem overschakelt. Probeer de 'NNTPswitch' optie onder 'Opties' -> 'Configuratie'[br][br]";
        _updateHTML();
        emit notice(0,tr("Bestandsnaam informatie ontbreekt..."));
    }
    else if (msgid == _imgMSGID)
    {
        _imgMSGID.clear();
        _updateHTML();
        emit notice(0, tr("Afbeelding is niet aanwezig op Usenet server :-("));
    }
    else if (!msgid.contains('@'))
    {
        int nr = msgid.toInt();
        if ( _commentsToDownload.contains(nr) )
        {
            _commentsToDownload.removeOne(nr);
            if (_commentsToDownload.isEmpty())
                _updateHTML();
        }

        //qDebug() << _commentsToDownload;
        emit notice(0,tr("Reactiebericht ID %1 ontbreekt op server... Nog %2 andere berichten te downloaden.").arg(QString(msgid), QString::number(_commentsToDownload.count() ) ));
    }
}

inline QByteArray _fmtSize(double size)
{
    static const char *suffixes[] = {" B", " KB", " MB", " GB", " TB", " PB"};
    int  i = 0;

    if (!size)
        return "-";

    while (size >= 1024 && i < 4)
    {
        size /= 1024;
        i++;
    }

    return QByteArray::number(size, 'f', 2)+suffixes[i];
}

void SpotView::_updateHTML()
{
    QByteArray linkurl, link, numfiles, firstfile, lastfile, cathtml, html = _mainTemplate;

    if (_website.isEmpty() )
    {
        link = "-";
    }
    else
    {
        linkurl = _website.toLatin1().replace('<', "&lt;").replace('>', "&gt;").replace('&', "&amp;").replace('"', "");
        link = "<a href=\""+linkurl+"\">"+linkurl+"</a>";
    }

    if (!_filenames.isEmpty())
    {
        numfiles  = QByteArray::number(_filenames.size() );
        firstfile = _filenames.first().toLatin1().replace('"', "");
        lastfile  = _filenames.last().toLatin1();

        if (firstfile.contains(".r00") && lastfile.contains(".rar"))
        {
            firstfile = lastfile;
            lastfile = _filenames[_filenames.count()-2].toLatin1();
        }
    }
    else
    {
        numfiles = firstfile = lastfile = "-";
    }

    if (!_cats.isEmpty())
    {
        foreach (QString catname, _cats)
        {
            cathtml += catname.toUtf8()+"<br>";
        }
    }
    else
    {
        cathtml = "-";
    }

    html.replace("{description}", _mainHTML);
    html.replace("{size}", _fmtSize(_size));
//    html.replace("{spotter}", _spotter);
//    html.replace("{userid}", _toHTML(_spotterkey)+"#"+_spotter);


    html.replace("{tag}", (_tag.isEmpty() ? "-" : _tag) );
    if (_useActionLinks)
    {
        html.replace("{spotterlink}", "<a href=\"action:user:"+_toHTML(_spotterkey)+"#"+_spotter+"\" class=\"spottername\" title=\""+SpotSignature::crc32base64(_spotterkey)+"\">"+_spotter+"</a>");
        html.replace("{taglink}", (_tag.isEmpty() ? "" : "[<a href=\"action:tag\" style=\"text-decoration: none;\">+</a>]") );
    }
    else
    {
        html.replace("{spotterlink}", _spotter);
        html.replace("{taglink}", "");
    }

    html.replace("{msgid}", _spotMSGID);
    html.replace("{title}", _title.toLatin1() );
    html.replace("{spotid}", QByteArray::number(_spotid) );
    html.replace("{subcat}", QByteArray::number(_subcat) );
    html.replace("{cat}", QByteArray::number(_cat) );
    QDateTime dt = QDateTime::fromTime_t(_spotdate);
    html.replace("{date}", dt.toString("d-M-yy").toLatin1() );
    html.replace("{time}", dt.toString("hh:mm").toLatin1() );
    html.replace("{website}", link );
    html.replace("{websiteurl}", linkurl );
    html.replace("{numfiles}", numfiles);
    html.replace("{firstfile}", _toHTML(firstfile));
    html.replace("{lastfile}", _toHTML(lastfile));
    html.replace("{newsgroup}", (_newsgroup.isEmpty() ? "-" : _toHTML(_newsgroup)));
    html.replace("{categories}", cathtml);
    html.replace("{comments}", _commentsHTML);
    _displayHTML(html, (!_newsgroup.isEmpty() && _commentsToDownload.isEmpty() && _imgMSGID.isEmpty() ) );
}

inline void doXpath(QXmlQuery &q, QString &result, const char *query)
{
    q.setQuery(query);
    q.evaluateTo(&result);
    result = result.replace('\n', "").replace("&amp;", "&");
}

QByteArray SpotView::_unSpecial(QByteArray s)
{
    s.replace("-s", "/").replace("-p", "+");

    switch (s.length() % 4)
    {
    case 0:
        return s;

    case 1:
        return s+"===";

    case 2:
         return s+"==";

    case 3:
         return s+"=";
    default:
         return "";
    }
}

bool SpotView::_parseSpot(const QByteArray &data)
{
    int pos = data.indexOf("\r\n\r\n");
    if (pos == -1)
        return false;

    QByteArray xml, rawmodulus, rawexponent, signature, msgid, xmlsignature;
    QString description, image, nzbref, sizestr, imgref;
    QXmlQuery q;
    QSettings *s = _sl->settings();
    QList<QByteArray> headerlines = data.left(pos).split('\n');
    bool has_signature = false;

    qDebug() << "Headers:" << headerlines;

    foreach (QByteArray line, headerlines)
    {
        if (line.startsWith("X-XML: "))
            xml += line.mid(7);
        else if (line.startsWith("X-User-Key: "))
        {
            QString modulus, exponent;
            QByteArray rsaxmlkey = line.mid(12);
            q.setFocus(rsaxmlkey);
            doXpath(q, modulus, "/RSAKeyValue/Modulus/string()");
            doXpath(q, exponent, "/RSAKeyValue/Exponent/string()");
            _spotterkey = modulus.toLatin1();

            rawmodulus  = QByteArray::fromBase64(_spotterkey);
            rawexponent = QByteArray::fromBase64(exponent.toLatin1() );
        }
        else if (line.startsWith("X-User-Signature: "))
        {
            signature = QByteArray::fromBase64( _unSpecial(line.mid(18)) );
        }
        else if (line.startsWith("Message-ID: <"))
        {
            msgid = line.mid(12);
            int p = msgid.indexOf(">");
            msgid = msgid.left(p+1);
        }
        else if (line.startsWith("X-XML-Signature: "))
        {
            xmlsignature = line.mid(17).replace('\r', "");
        }
    }
    QByteArray xmlBytes = xml;
    xml = xml.replace('\r', "").replace('\n', "");

    if (xml.isEmpty())
        return false;

    if ( !signature.isEmpty() && !rawmodulus.isEmpty() && !rawexponent.isEmpty() )
    {
        qDebug() << "Checken van spot RSA...";
        has_signature = SpotSignature::verify(rawmodulus, rawexponent, msgid, signature);

        if (!has_signature)
        {
            has_signature = SpotSignature::verify(rawmodulus, rawexponent, xmlsignature, signature);
        }
        qDebug() << (has_signature ? "Handtekening OK!" : "Handtekening onjuist!");
    }

    if ( !has_signature )
    {
        if ( _requireValidSignature )
            return false;
        else
            _spotterkey.clear();
    }

    //qDebug() << "XMLer: " << xml;
    xml = xml.replace("SpotNet>", "Spotnet>");

    auto parseXmlWithString = [&](const QString &xmlString) -> bool {
        description.clear();
        image.clear();
        nzbref.clear();
        sizestr.clear();
        imgref.clear();
        _filenames.clear();
        _website.clear();
        _newsgroup.clear();
        _imgMSGID.clear();
        _image.clear();

        QXmlQuery q2;
        q2.setFocus(xmlString);
        doXpath(q2, description, "/Spotnet/Posting/Description[1]/string()");
        if (description.isEmpty())
            return false;

        doXpath(q2, sizestr, "/Spotnet/Posting/Size[1]/string()");
        _size = sizestr.toLongLong();
        doXpath(q2, imgref, "/Spotnet/Posting/Image[1]/Segment[1]/string()");
        if ( imgref.isEmpty() )
        {
            if ( s->value("images").toBool() )
                doXpath(q2, _image, "/Spotnet/Posting/Image[1]/string()");
        }
        else
        {
            if ( s->value("nntpImages").toBool() )
                _imgMSGID = imgref.toLatin1();
        }
        doXpath(q2, _website, "/Spotnet/Posting/Website[1]/string()");
        doXpath(q2, _newsgroup, "/Spotnet/Posting/Newsgroup[1]/string()");
        doXpath(q2, nzbref, "/Spotnet/Posting/NZB/Segment[1]/string()");
        q2.setQuery("/Spotnet/Posting/Filename/string()");
        q2.evaluateTo(&_filenames);
        return true;
    };

    // Decodeer XML met charset uit headers (default UTF-8), fallback Latin-1
    QString xmlText = decodeText(xmlBytes, headerlines, QStringLiteral("utf-8"));
    if (!parseXmlWithString(xmlText))
    {
        qDebug() << "Fout bij het parsen van XML";
        return false;
    }
    if (description.count(QChar::ReplacementCharacter) > 1)
    {
        parseXmlWithString(QString::fromLatin1(xmlBytes));
    }

    if (!nzbref.isEmpty() )
    {
        _nzbMSGID = nzbref.toLatin1();
    }
    else
        qDebug() << tr("Geen NZB referentie in spot informatie");

    if ( !_image.isEmpty() /*&& s.value("images").toBool()*/ )
    {
        _image = _image.replace('<', "&lt;").replace('>', "&gt;").replace('&', "&amp;").replace('"', "");
        _mainHTML = "<img style=\"float:left; margin-right: 10px; margin-bottom:15px;\" alt=\"Plaatje\" onload=\"resizeme(this);\" onmouseover=\"supersizeme(this);\" onmouseout=\"resizeme(this);\" src=\""+_image.toLatin1()+"\"> ";
    }
    _mainHTML += _toHTML(description);


    /*QByteArray body   = data.mid(pos+4, data.length()-pos-7);
    QString    html   = _toHTML(body);
    _web->setHtml(html);
    */

    return true;
}

QByteArray SpotView::_toHTML(const QString &in)
{
    static const char *replacements[] =
    {
        "&amp;amp;lt;br /&gt;", "[br]", /* work around */
        "&amp;lt;br /&amp;gt;", "[br]",
        "&lt;br /&gt;", "[br]",
        "&amp;lt;br /&gt;", "[br]", /* oude spots */
        "<", "&lt;",
        ">", "&gt;",
        "&amp;#", "&#", /* ugly workaround */
        "&amp;amp;#", "&#",
        "&amp;quot;", "&quot;",
        "[br]", "<br>",
        "[b]", "<b>",
        "[B]", "<b>",
        "[i]", "<i>",
        "[u]", "<u>",
        "[/b]", "</b>",
        "[/B]", "</b>",
        "[/i]", "</i>",
        "[/u]", "</u>",
        0
    };

    // behoud Unicode (UTF-8) zodat accenten zichtbaar blijven
    QByteArray h = in.toUtf8();
    //h.replace('\n', "<br>");
    for (const char **r = replacements; *r; r+=2)
    {
        //qDebug() << *r << r[1];
        h.replace(*r, r[1]);
    }

    if ( h.contains("[img=") )
    {
        foreach (QByteArray smiley, _smileys)
            h.replace("[img="+smiley+"]", "<img src=\"qrc:/smileys/"+smiley+".gif\">");
    }

    return h;
}

void SpotView::onLinkClick(const QUrl &url)
{
    qDebug() << url;
    if (url.scheme() == "http" || url.scheme() == "https")
        QDesktopServices::openUrl(url);
    else if (url.scheme() == "action")
    {
        if (url.path() == "tag")
        {
            emit createTagFilter(_cat, _tag);
        }
        else if (url.path() == "reportspot")
        {
            onReport();
        }
        else if (url.path() == "reply")
        {
            onReply();
        }
        else if (url.path() == "deletespot")
        {
            onDeleteSpot();
        }
        else if (url.path().startsWith("user:") )
        {
            QByteArray userid   = url.path().mid(5).toLatin1();
            QByteArray username = url.fragment().toLatin1();

            UserDialog ud(_sl, userid, username);
            if ( ud.exec() == ud.Accepted )
            {
                /* Spotter gebanned */
                if ( _sl->isFoe(_spotterkey) )
                {
                    closeRequested();
                }
                else
                {
                    /* reload comments */

                    _commentsHTML.clear(); _commentsHashes.clear();
                    QByteArray m = _spotMSGID;
                    if (m.endsWith("@free.pt"))
                        m = m.left(m.indexOf('@'));
                    _commentsToDownload = _sl->getCommentMsgNrs(m);

                    foreach (int nr, _commentsToDownload)
                    {
                        _sl->downloadArticle(nr);
                    }
                }
            }
        }
    }
}


inline QString _subject2filename(const QString &subject)
{
    QString _filename, _ext;
    int q1, q2;

    if ( (q1 = subject.indexOf('"')) != -1 && (q2 = subject.indexOf('"', q1+1)) != -1 )
    {
        _filename = subject.mid(q1+1, q2-q1-1);
    }
    else if ( (q1 = subject.lastIndexOf('.')) )
    {
        for (q2 = q1+1; q2 < subject.length(); q2++)
        {
            if ( subject.at(q2).isLetterOrNumber() )
                _ext += subject.at(q2);
            else
                break;
        }

        for (q2 = q1; q2>0 ; q2--)
        {
            char c = subject.at(q2-1).toLatin1();
            if ( c == ']' || c == '/' || c == '\\' || c == ':' || c == '*' || c == '?' || c == '`' || c == '&' || c == '>' || c == '<' || c == '|' || c == '"' || c == '\\' )
                break;
        }
        _filename = subject.mid(q2, q1-q2)+"."+_ext;
    }
    else
    {
        _filename = subject;
    }

    return _filename.trimmed();
}


bool SpotView::_decodeNZB(const QByteArray &data)
{
   //qDebug() << data << data.length();

    /*int pos = data.indexOf("\r\n\r\n");
    if (pos == -1)
        return false;
    QByteArray _buf = data.mid(pos+4);*/
    QByteArray _buf = data;

    _buf.replace("\n..", "."); /* Todo: start of msg? */
    _buf.replace("\n", "");
    _buf.replace("\r", "");
    _buf.replace("=C", "\n");
    _buf.replace("=B", "\r");
    _buf.replace("=A", QByteArray(1, 0));
    _buf.replace("=D", "=");

    _buf.chop(1); /* remove final . */
    //qDebug() << _buf.length();
    QBuffer b(&_buf);
    QtIOCompressor io(&b);
    //io.setStreamFormat(io.DeflateStream);
    io.setStreamFormat(io.RawZipFormat);
    io.open(io.ReadOnly);
    QByteArray nzb = io.readAll();
//    qDebug() << "err" << io.errorString();
    io.close();
    b.close();

  //  qDebug() << "NZB data:" << nzb;
    if ( nzb.isEmpty() )
        qDebug() << "Fout bij decoderen/uitpakken NZB";

    if (nzb.contains("</nzb>"))
    {
        QStringList subjects;
        QXmlQuery q;
        QByteArray ns = "declare default element namespace \"http://www.newzbin.com/DTD/2003/nzb\";";
        q.setFocus(nzb);

        doXpath(q, _newsgroup, ns+"/nzb/file[1]/groups[1]/group/string()");
        q.setQuery(ns+"/nzb/file/@subject/string()");
        q.evaluateTo(&subjects);
        //qDebug() << "subjects" << subjects;

        bool rars = false;
        foreach (QString subject, subjects)
        {
            if (!rars && subject.contains(".rar", Qt::CaseInsensitive))
                rars = true;

            _filenames.append(_subject2filename(subject));
        }

        if (rars)
        {
            /* remove non-rars */
            foreach (QString file, _filenames)
            {
                if ( !file.contains(".r", Qt::CaseInsensitive) )
                    _filenames.removeAll(file);
            }
        }
        _filenames.sort();

        //return true;
        if (_newsgroup.isEmpty() )
            qDebug() << "NZB bevat foutieve XML";
    }

    if (_newsgroup.isEmpty() && nzb.contains("<nzb")) /* partial */
    {
        QRegExp gr("<group>\\s*([^<]+)\\s*</group>");
        if ( gr.indexIn(nzb) != -1 )
        {
            _newsgroup = gr.cap(1);
        }

        QRegExp sj("subject=\\\"([^\\\"]+)\\\"");
        if ( sj.indexIn(nzb) != -1 )
        {
            qDebug() << sj.cap(1);
            _filenames.append( _subject2filename(sj.cap(1).replace("&quot;", "\"")) );
        }
    }
    else if ( !nzb.contains("<nzb") )
        qDebug() << "NZB ongeldig (geen <nzb> tag)";

    return !_newsgroup.isEmpty();
}

bool SpotView::_decodeIMG(const QByteArray &data)
{
//    qDebug() << "IMG DATA" << data;

    QByteArray _buf = data;

    _buf.replace("\n..", "."); /* Todo: start of msg? */
    _buf.replace("\n", "");
    _buf.replace("\r", "");
    _buf.replace("=C", "\n");
    _buf.replace("=B", "\r");
    _buf.replace("=A", QByteArray(1, 0));
    _buf.replace("=D", "=");
    _buf.chop(1);

    if (!_buf.isEmpty() )
    {
        QByteArray _imgtype;

        if ( _buf.startsWith("\x89PNG\r\n") )
            _imgtype = "image/png";
        else /* TODO: jpg sanity check? */
            _imgtype = "image/jpeg";

        _buf = "data:"+_imgtype+";base64,"+_buf.toBase64();
        _mainHTML = "<img style=\"float:left; margin-right: 10px; margin-bottom:15px;\" alt=\"Plaatje\" onload=\"resizeme(this);\" onmouseover=\"supersizeme(this);\" onmouseout=\"resizeme(this);\" src=\""+_buf+"\"> "+_mainHTML;
        return true;
    }

    return false;
}

void SpotView::_initWebbrowser()
{
    _web = new QWebEngineView(_widget);
    auto *page = new SpotWebPage(_web);
    _web->setPage(page);
    connect(page, SIGNAL(linkClicked(QUrl)), this, SLOT(onLinkClick(QUrl)));
    QAction *act = _web->pageAction(QWebEnginePage::Copy);
    act->setShortcut(QKeySequence::Copy);
    _web->addAction(act);

    connect(page->profile(), SIGNAL(downloadRequested(QWebEngineDownloadItem*)), this, SLOT(_downloadRequested(QWebEngineDownloadItem*)));

    connect(_web, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextmenu(QPoint)));
    _web->setContextMenuPolicy(Qt::CustomContextMenu);
}

void SpotView::_displayHTML(const QByteArray &html, bool /*final*/)
{
    // Render HTML als UTF-8 (voorkomt latin1 fallback)
    _web->setHtml(QString::fromUtf8(html), QUrl::fromLocalFile(_skinPath+"/") );
}

QByteArray SpotView::_parseComment(int msgnr, const QByteArray &data)
{
    //qDebug() << data;
    int pos = data.indexOf("\r\n\r\n");
    if (pos == -1)
        return "";

    QList<QByteArray> headerlines = data.left(pos).split('\n');
    QByteArray from = "-", hash, r, msgid, hashcash, references, signature, rawmodulus, rawexponent, date, userid, body = data.mid(pos+4);
    body.chop(5);
    body.replace("\n..", "\n.");
    bool has_signature = false, has_valid_hashcash = false, posted_by_spotter = false;

    //qDebug() << headerlines;

    /* Get poster name from "from" header */
    foreach (QByteArray h, headerlines)
    {
        if (h.startsWith("From: "))
        {
            int p = h.indexOf(" <", 6);
            if (p != -1)
            {
                from = h.mid(6, p-6);
            }
        }
        else if (h.startsWith("X-User-Signature: "))
        {
            signature = QByteArray::fromBase64( _unSpecial(h.mid(18)) );
            //has_signature   = true;
        }
        else if (h.startsWith("X-Hashcash: "))
        {
            hashcash = h.mid(12).replace("\r", "");
        }
        else if (h.startsWith("References: <"))
        {
            references = h.mid(13).replace("\r", "");
            references.chop(1);
        }
        else if (h.startsWith("Message-ID: <"))
        {
            msgid = h.mid(12);
            int p = msgid.indexOf(">");
            msgid = msgid.left(p+1);
        }
        else if (h.startsWith("X-User-Key: "))
        {
            QByteArray rsaxmlkey = h.mid(12);
            QString modulus, exponent;

            QXmlQuery q;
            q.setFocus(rsaxmlkey);
            doXpath(q, modulus, "/RSAKeyValue/Modulus/string()");
            doXpath(q, exponent, "/RSAKeyValue/Exponent/string()");

            userid = modulus.toLatin1();
            rawmodulus  = QByteArray::fromBase64(userid);
            rawexponent = QByteArray::fromBase64(exponent.toLatin1() );

            if ( _sl->isFoe(userid))
                return "";

            if (userid == _spotterkey && !_spotterkey.isEmpty() )
                posted_by_spotter = true;
        }
        else if (h.startsWith("Date: "))
        {
            date = h.mid(6);
        }
    }

    // Decode naam en body op basis van charset
    QString fromText = decodeText(from, headerlines);
    from = fromText.toUtf8();
    QString bodyText = decodeText(body, headerlines);

    hash = from+"\n"+body; /* Todo: use real hash? */
    if (_commentsHashes.contains(hash))
    {
      qDebug() << "Dubbele reactie verwijderd";
      return "";
    }

    if ( !signature.isEmpty() && !rawmodulus.isEmpty() && !rawexponent.isEmpty() )
    {
        qDebug() << "Checken van RSA...";
        has_signature = SpotSignature::verify(rawmodulus, rawexponent, msgid+body+"\r\n"+from, signature);

        if (!has_signature)
        {
//            qDebug() << headerlines;
            has_signature = SpotSignature::verify(rawmodulus, rawexponent, msgid, signature);
        }
        if (!has_signature && msgid.count('.') == 3)
        {
            int pos = msgid.indexOf('@');
            QByteArray bmsgid = msgid.left(pos);
            bmsgid = bmsgid.left( bmsgid.lastIndexOf('.')) + msgid.mid(pos);
            qDebug() << "bmsgid:" << bmsgid;
            has_signature = SpotSignature::verify(rawmodulus, rawexponent, bmsgid+body+"\r\n"+from, signature);
        }

        qDebug() << (has_signature ? "Handtekening OK!" : "Handtekening onjuist!");
        if (!has_signature)
            posted_by_spotter = false;
    }

    if (!hashcash.isEmpty() && !msgid.isEmpty())
    {
        qDebug() << "Checken van hashcash...";
//        qDebug() << "test" << msgid.mid(1, msgid.length()-2) << hashcash;
        has_valid_hashcash = HashCash::valid(hashcash, msgid.mid(1, msgid.length()-2) );
        qDebug() << (has_valid_hashcash ? "Hashcash OK!" : "Hashcash onjuist, reactie verwijderd!");
        if (!has_valid_hashcash)
            return "";
    }

    if (!has_signature /*&& !has_valid_hashcash*/)
    {
        qDebug() << "Reactie mist geldige handtekening. Verwijderd...";
        return "";
    }

    _commentsHashes.insert(hash);
    r = _commentTemplate;
    QByteArray name = _toHTML( _normalizeUsername(from, userid) ), sname;


    if (posted_by_spotter)
        sname = "<span class=\"spotter\">"+name+"</span>";
    else if (_sl->isFriend(userid))
        sname = "<span class=\"friend\">"+name+"</span>";
    else
        sname = name;

    // <a href="action:user:{userid}" class="username">{name}</a>
    //r.replace("{userid}", _toHTML(userid)+"#"+name);
    //r.replace("{name}", name);

    if ( _useActionLinks )
        r.replace("{usernamelink}", "<a href=\"action:user:"+_toHTML(userid)+"#"+name+"\" class=\"username\" title=\""+SpotSignature::crc32base64(userid)+"\">"+sname+"</a>");
    else
        r.replace("{usernamelink}", sname);

    r.replace("{date}",  normalizeDate(date) );
    QByteArray cmsgid;
    if (msgid.length() > 2)
        cmsgid = msgid.mid(1, msgid.length()-2);
    r.replace("{msgid}",  msgid);

    QByteArray encodedbody = _toHTML(bodyText).trimmed().replace("\n", "<br>");

    if ( !references.isEmpty() && _spotMSGID != references )
    {
        encodedbody = "<p><font color='red'>'References' header klopt niet, de reactie hoort mogelijk bij een andere spot! Het kan zijn dat de header overzichten van je provider corrupt zijn, of de berichtnummers niet meer geldig.</font></p>"+encodedbody;
        qDebug() << "Berichtnummer" << msgnr << "References header volgens 'XHDR references' inhoudsopgave: '" << _spotMSGID << "' Daadwerkelijk 'references' header:" << references;
    }

    r.replace("{comment}", encodedbody);

    return r;
}

void SpotView::onWatchlistToggle(bool add)
{
    if (add)
        _sl->addToWatchlist(_spotid);
    else
        _sl->removeFromWatchlist(_spotid);
}

void SpotView::onReply()
{
    SpotReplyWindow *w = new SpotReplyWindow(_spotid, _sl, _spotMSGID, _title);
    connect(w, SIGNAL(newComment(QByteArray)), this, SLOT(onNewComment(QByteArray)));
    w->exec();
}

void SpotView::onReport()
{
    SpotReportWindow *w = new SpotReportWindow(_spotid, _sl, _spotMSGID, _title);
    w->exec();
}

void SpotView::onNewComment(const QByteArray &msg)
{
    _commentsHTML += _parseComment(-1, msg);
    _updateHTML();
}

void SpotView::_downloadRequested(QWebEngineDownloadItem *download)
{
    if (!download)
        return;

    QString defaultFileName = download->downloadFileName();
    QString fileName = QFileDialog::getSaveFileName(_widget, tr("Bestand opslaan"), defaultFileName);
    if (fileName.isEmpty())
    {
        download->cancel();
        return;
    }

    download->setPath(fileName);
    download->accept();
}

void SpotView::contextmenu(const QPoint &p)
{
    QMenu menu;
    if (QAction *copy = _web->pageAction(QWebEnginePage::Copy))
        menu.addAction(copy);
    menu.addSeparator();
    menu.addAction( tr("Venster sluiten"), this, SIGNAL(closeRequested()) );
    menu.exec( _web->mapToGlobal(p) );
}

void SpotView::onDeleteSpot()
{
    QMessageBox msgBox(QMessageBox::Question, tr("Spot verwijderen"), tr("Spot verwijderen?"));
    /*QAbstractButton *yes = */msgBox.addButton(QMessageBox::Yes);
    QAbstractButton *reportButton = msgBox.addButton( tr("Ja, en melden"), QMessageBox::YesRole);
    QAbstractButton *no  = msgBox.addButton(QMessageBox::No);

    msgBox.exec();

    if (msgBox.clickedButton() != no)
    {
        if (msgBox.clickedButton() == reportButton)
        {
            onReport();
        }

        _sl->deleteSpot(_spotid);
        closeRequested();
    }

/*    if ( QMessageBox::question(_widget, tr("Spot verwijderen"), tr("Spot verwijderen?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes)
    {
        _sl->deleteSpot(_spotid);
        closeRequested();
    }*/
}

QByteArray SpotView::_normalizeUsername(QByteArray username, QByteArray userid)
{
    QByteArray prevUsername = _useridsAndNames.value(userid);
    if ( !prevUsername.isEmpty() ) /* userid komt al eerder in thread voor */
    {
        if (username == prevUsername)
            return username;
        else if (prevUsername.startsWith(username+" #"))
            return prevUsername;
        else
            return username+" (alias "+prevUsername+")";
    }

    if ( !_useridsAndNames.key(username).isEmpty() )
    {
        /* username wordt al door iemand anders in de thread gebruikt */

        for (int i=2; i<999; i++)
        {
            QByteArray newuser = username+" #"+QByteArray::number(i);

            if ( _useridsAndNames.key(newuser).isEmpty() )
            {
                username = newuser;
                break;
            }
        }
    }

    _useridsAndNames.insert(userid, username);
    return username;
}

#include "spotview.moc"

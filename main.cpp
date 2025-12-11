#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include "mainwindow.h"

#include <QtGui/QFileOpenEvent>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLoggingCategory::setFilterRules(QStringLiteral("*.debug=false\n*.info=false"));
    a.setOrganizationName("SpotLite");
    a.setApplicationName("Spotlite Release 2026");
    a.setApplicationDisplayName("Spotlite Release 2026");
    QTranslator _qttrans;
    _qttrans.load("qt_nl.qm", /*QLibraryInfo::location(QLibraryInfo::TranslationsPath)*/ a.applicationDirPath() );
    QApplication::installTranslator(&_qttrans);
    MainWindow w;
    w.show();

    QStringList args = a.arguments();
    if ( args.count() > 1)
    {
        foreach (QString arg, args)
        {
            w.openFile(arg);
        }
    }


    return a.exec();
}

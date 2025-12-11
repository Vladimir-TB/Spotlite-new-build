/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *serverEdit;
    QLabel *label_2;
    QLineEdit *userEdit;
    QLabel *label_3;
    QLineEdit *passEdit;
    QCheckBox *sslBox;
    QCheckBox *xzverBox;
    QCheckBox *nntpSwitchCheck;
    QLabel *label_4;
    QLineEdit *portEdit;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QComboBox *maxSpots;
    QLabel *label_6;
    QComboBox *maxDays;
    QLabel *label_7;
    QLineEdit *nickEdit;
    QCheckBox *imagesCheck;
    QCheckBox *nntpImagesCheck;
    QCheckBox *eroCheck;
    QCheckBox *trashCheck;
    QCheckBox *spamCheck;
    QCheckBox *spamDeleteCheck;
    QCheckBox *filterManyCatCheck;
    QLabel *label_8;
    QRadioButton *meteenTonenRadio;
    QRadioButton *naUpdateRadio;
    QCheckBox *updateOnStart;
    QCheckBox *filterHCCheck;
    QLabel *label_9;
    QCheckBox *warmcacheCheck;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(644, 716);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(SettingsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(SettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        serverEdit = new QLineEdit(groupBox);
        serverEdit->setObjectName(QString::fromUtf8("serverEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, serverEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        userEdit = new QLineEdit(groupBox);
        userEdit->setObjectName(QString::fromUtf8("userEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, userEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        passEdit = new QLineEdit(groupBox);
        passEdit->setObjectName(QString::fromUtf8("passEdit"));
        passEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, passEdit);

        sslBox = new QCheckBox(groupBox);
        sslBox->setObjectName(QString::fromUtf8("sslBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, sslBox);

        xzverBox = new QCheckBox(groupBox);
        xzverBox->setObjectName(QString::fromUtf8("xzverBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, xzverBox);

        nntpSwitchCheck = new QCheckBox(groupBox);
        nntpSwitchCheck->setObjectName(QString::fromUtf8("nntpSwitchCheck"));

        formLayout->setWidget(5, QFormLayout::FieldRole, nntpSwitchCheck);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        portEdit = new QLineEdit(groupBox);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, portEdit);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SettingsDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(0, 160));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        maxSpots = new QComboBox(groupBox_2);
        maxSpots->addItem(QString());
        maxSpots->addItem(QString());
        maxSpots->addItem(QString());
        maxSpots->addItem(QString());
        maxSpots->addItem(QString());
        maxSpots->addItem(QString());
        maxSpots->setObjectName(QString::fromUtf8("maxSpots"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(maxSpots->sizePolicy().hasHeightForWidth());
        maxSpots->setSizePolicy(sizePolicy1);
        maxSpots->setMinimumSize(QSize(100, 0));
        maxSpots->setInputMethodHints(Qt::ImhDigitsOnly);
        maxSpots->setEditable(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, maxSpots);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        maxDays = new QComboBox(groupBox_2);
        maxDays->addItem(QString());
        maxDays->addItem(QString());
        maxDays->addItem(QString());
        maxDays->addItem(QString());
        maxDays->addItem(QString());
        maxDays->addItem(QString());
        maxDays->addItem(QString());
        maxDays->addItem(QString());
        maxDays->setObjectName(QString::fromUtf8("maxDays"));
        sizePolicy1.setHeightForWidth(maxDays->sizePolicy().hasHeightForWidth());
        maxDays->setSizePolicy(sizePolicy1);
        maxDays->setMinimumSize(QSize(100, 0));
        maxDays->setInputMethodHints(Qt::ImhDigitsOnly);
        maxDays->setEditable(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, maxDays);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_7);

        nickEdit = new QLineEdit(groupBox_2);
        nickEdit->setObjectName(QString::fromUtf8("nickEdit"));
        nickEdit->setEnabled(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, nickEdit);

        imagesCheck = new QCheckBox(groupBox_2);
        imagesCheck->setObjectName(QString::fromUtf8("imagesCheck"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, imagesCheck);

        nntpImagesCheck = new QCheckBox(groupBox_2);
        nntpImagesCheck->setObjectName(QString::fromUtf8("nntpImagesCheck"));
        nntpImagesCheck->setChecked(true);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, nntpImagesCheck);

        eroCheck = new QCheckBox(groupBox_2);
        eroCheck->setObjectName(QString::fromUtf8("eroCheck"));
        eroCheck->setChecked(true);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, eroCheck);

        trashCheck = new QCheckBox(groupBox_2);
        trashCheck->setObjectName(QString::fromUtf8("trashCheck"));
        trashCheck->setEnabled(true);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, trashCheck);

        spamCheck = new QCheckBox(groupBox_2);
        spamCheck->setObjectName(QString::fromUtf8("spamCheck"));
        spamCheck->setChecked(true);

        formLayout_2->setWidget(9, QFormLayout::FieldRole, spamCheck);

        spamDeleteCheck = new QCheckBox(groupBox_2);
        spamDeleteCheck->setObjectName(QString::fromUtf8("spamDeleteCheck"));
        spamDeleteCheck->setChecked(true);

        formLayout_2->setWidget(10, QFormLayout::FieldRole, spamDeleteCheck);

        filterManyCatCheck = new QCheckBox(groupBox_2);
        filterManyCatCheck->setObjectName(QString::fromUtf8("filterManyCatCheck"));
        filterManyCatCheck->setChecked(true);

        formLayout_2->setWidget(11, QFormLayout::FieldRole, filterManyCatCheck);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(13, QFormLayout::LabelRole, label_8);

        meteenTonenRadio = new QRadioButton(groupBox_2);
        meteenTonenRadio->setObjectName(QString::fromUtf8("meteenTonenRadio"));
        meteenTonenRadio->setChecked(false);

        formLayout_2->setWidget(13, QFormLayout::FieldRole, meteenTonenRadio);

        naUpdateRadio = new QRadioButton(groupBox_2);
        naUpdateRadio->setObjectName(QString::fromUtf8("naUpdateRadio"));
        naUpdateRadio->setChecked(true);

        formLayout_2->setWidget(14, QFormLayout::FieldRole, naUpdateRadio);

        updateOnStart = new QCheckBox(groupBox_2);
        updateOnStart->setObjectName(QString::fromUtf8("updateOnStart"));
        updateOnStart->setEnabled(true);
        updateOnStart->setChecked(true);

        formLayout_2->setWidget(15, QFormLayout::FieldRole, updateOnStart);

        filterHCCheck = new QCheckBox(groupBox_2);
        filterHCCheck->setObjectName(QString::fromUtf8("filterHCCheck"));
        filterHCCheck->setChecked(true);

        formLayout_2->setWidget(12, QFormLayout::FieldRole, filterHCCheck);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_9);

        warmcacheCheck = new QCheckBox(groupBox_2);
        warmcacheCheck->setObjectName(QString::fromUtf8("warmcacheCheck"));
        warmcacheCheck->setChecked(true);

        formLayout_2->setWidget(8, QFormLayout::FieldRole, warmcacheCheck);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLocale(QLocale(QLocale::Dutch, QLocale::Netherlands));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        maxSpots->setCurrentIndex(5);
        maxDays->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Instellingen", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingsDialog", "Nieuwsgroepen server", nullptr));
        label->setText(QCoreApplication::translate("SettingsDialog", "Server adres", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsDialog", "Gebruikersnaam", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsDialog", "Wachtwoord", nullptr));
        sslBox->setText(QCoreApplication::translate("SettingsDialog", "SSL encryptie", nullptr));
        xzverBox->setText(QCoreApplication::translate("SettingsDialog", "Header compressie (Astraweb/XZVER/XZHDR)", nullptr));
        nntpSwitchCheck->setText(QCoreApplication::translate("SettingsDialog", "Provider met  aparte backends voor txt/binary (NNTPswitch)", nullptr));
        label_4->setText(QCoreApplication::translate("SettingsDialog", "Poort", nullptr));
        portEdit->setText(QCoreApplication::translate("SettingsDialog", "119", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingsDialog", "Spots", nullptr));
        label_5->setText(QCoreApplication::translate("SettingsDialog", "Max. aantal headers binnenhalen", nullptr));
        maxSpots->setItemText(0, QCoreApplication::translate("SettingsDialog", "1000", nullptr));
        maxSpots->setItemText(1, QCoreApplication::translate("SettingsDialog", "10000", nullptr));
        maxSpots->setItemText(2, QCoreApplication::translate("SettingsDialog", "100000", nullptr));
        maxSpots->setItemText(3, QCoreApplication::translate("SettingsDialog", "1000000", nullptr));
        maxSpots->setItemText(4, QCoreApplication::translate("SettingsDialog", "10000000", nullptr));
        maxSpots->setItemText(5, QCoreApplication::translate("SettingsDialog", "1000000000", nullptr));

        label_6->setText(QCoreApplication::translate("SettingsDialog", "Max. aantal dagen bewaren", nullptr));
        maxDays->setItemText(0, QCoreApplication::translate("SettingsDialog", "30", nullptr));
        maxDays->setItemText(1, QCoreApplication::translate("SettingsDialog", "60", nullptr));
        maxDays->setItemText(2, QCoreApplication::translate("SettingsDialog", "90", nullptr));
        maxDays->setItemText(3, QCoreApplication::translate("SettingsDialog", "180", nullptr));
        maxDays->setItemText(4, QCoreApplication::translate("SettingsDialog", "365", nullptr));
        maxDays->setItemText(5, QCoreApplication::translate("SettingsDialog", "720", nullptr));
        maxDays->setItemText(6, QCoreApplication::translate("SettingsDialog", "900", nullptr));
        maxDays->setItemText(7, QCoreApplication::translate("SettingsDialog", "99999", nullptr));

        label_7->setText(QCoreApplication::translate("SettingsDialog", "Je schuilnaam (wordt vermeld bij reacties)", nullptr));
        nickEdit->setText(QCoreApplication::translate("SettingsDialog", "Anoniempje", nullptr));
        imagesCheck->setText(QCoreApplication::translate("SettingsDialog", "Plaatjes van externe websites tonen", nullptr));
        nntpImagesCheck->setText(QCoreApplication::translate("SettingsDialog", "Plaatjes uit nieuwsgroepen tonen", nullptr));
        eroCheck->setText(QCoreApplication::translate("SettingsDialog", "Erotiek tonen", nullptr));
        trashCheck->setText(QCoreApplication::translate("SettingsDialog", "Prullenbak tonen", nullptr));
        spamCheck->setText(QCoreApplication::translate("SettingsDialog", "Spam meldingen binnenhalen", nullptr));
        spamDeleteCheck->setText(QCoreApplication::translate("SettingsDialog", "Spots met veel meldingen verwijderen", nullptr));
        filterManyCatCheck->setText(QCoreApplication::translate("SettingsDialog", "Spots met veel categorien weigeren", nullptr));
        label_8->setText(QCoreApplication::translate("SettingsDialog", "Nieuwe spots", nullptr));
        meteenTonenRadio->setText(QCoreApplication::translate("SettingsDialog", "Meteen tonen", nullptr));
        naUpdateRadio->setText(QCoreApplication::translate("SettingsDialog", "Tonen zodra er op \"update\" geklikt wordt", nullptr));
        updateOnStart->setText(QCoreApplication::translate("SettingsDialog", "Bij opstarten automatisch updaten", nullptr));
        filterHCCheck->setText(QCoreApplication::translate("SettingsDialog", "Nieuwe spots moeten met SN 1.7+ gespot zijn", nullptr));
        label_9->setText(QCoreApplication::translate("SettingsDialog", "Anti-spam instellingen", nullptr));
        warmcacheCheck->setText(QCoreApplication::translate("SettingsDialog", "Gegevens in cache laden bij opstarten", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H

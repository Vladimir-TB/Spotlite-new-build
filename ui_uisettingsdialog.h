/********************************************************************************
** Form generated from reading UI file 'uisettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UISETTINGSDIALOG_H
#define UI_UISETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UISettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *listFontinfo;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *singleClickCombo;
    QLabel *label_4;
    QComboBox *doubleClickCombo;
    QLineEdit *spotFontinfo;
    QPushButton *spotFontButton;
    QListWidget *skinsList;
    QLabel *label_5;
    QPushButton *listFontButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UISettingsDialog)
    {
        if (UISettingsDialog->objectName().isEmpty())
            UISettingsDialog->setObjectName(QString::fromUtf8("UISettingsDialog"));
        UISettingsDialog->resize(664, 401);
        verticalLayout = new QVBoxLayout(UISettingsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(UISettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listFontinfo = new QLineEdit(groupBox);
        listFontinfo->setObjectName(QString::fromUtf8("listFontinfo"));
        listFontinfo->setEnabled(true);
        listFontinfo->setReadOnly(true);

        gridLayout->addWidget(listFontinfo, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        singleClickCombo = new QComboBox(groupBox);
        singleClickCombo->addItem(QString());
        singleClickCombo->addItem(QString());
        singleClickCombo->addItem(QString());
        singleClickCombo->setObjectName(QString::fromUtf8("singleClickCombo"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(singleClickCombo->sizePolicy().hasHeightForWidth());
        singleClickCombo->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(singleClickCombo, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        doubleClickCombo = new QComboBox(groupBox);
        doubleClickCombo->addItem(QString());
        doubleClickCombo->addItem(QString());
        doubleClickCombo->addItem(QString());
        doubleClickCombo->setObjectName(QString::fromUtf8("doubleClickCombo"));
        sizePolicy1.setHeightForWidth(doubleClickCombo->sizePolicy().hasHeightForWidth());
        doubleClickCombo->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(doubleClickCombo, 4, 1, 1, 1);

        spotFontinfo = new QLineEdit(groupBox);
        spotFontinfo->setObjectName(QString::fromUtf8("spotFontinfo"));
        spotFontinfo->setEnabled(true);
        spotFontinfo->setReadOnly(true);

        gridLayout->addWidget(spotFontinfo, 2, 1, 1, 1);

        spotFontButton = new QPushButton(groupBox);
        spotFontButton->setObjectName(QString::fromUtf8("spotFontButton"));

        gridLayout->addWidget(spotFontButton, 2, 2, 1, 1);

        skinsList = new QListWidget(groupBox);
        skinsList->setObjectName(QString::fromUtf8("skinsList"));
        skinsList->setIconSize(QSize(150, 150));
        skinsList->setViewMode(QListView::IconMode);

        gridLayout->addWidget(skinsList, 5, 1, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        listFontButton = new QPushButton(groupBox);
        listFontButton->setObjectName(QString::fromUtf8("listFontButton"));

        gridLayout->addWidget(listFontButton, 0, 2, 1, 1);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(UISettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(UISettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), UISettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UISettingsDialog, SLOT(reject()));

        singleClickCombo->setCurrentIndex(1);
        doubleClickCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(UISettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *UISettingsDialog)
    {
        UISettingsDialog->setWindowTitle(QCoreApplication::translate("UISettingsDialog", "Gebruikersinterface", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UISettingsDialog", "Gebruikersinterface aanpassen", nullptr));
        label->setText(QCoreApplication::translate("UISettingsDialog", "Lettergrootte van overzicht", nullptr));
        label_2->setText(QCoreApplication::translate("UISettingsDialog", "Minimale lettergrootte spotinfo ", nullptr));
        label_3->setText(QCoreApplication::translate("UISettingsDialog", "Enkel klikken", nullptr));
        singleClickCombo->setItemText(0, QCoreApplication::translate("UISettingsDialog", "-niets-", nullptr));
        singleClickCombo->setItemText(1, QCoreApplication::translate("UISettingsDialog", "Spot laden", nullptr));
        singleClickCombo->setItemText(2, QCoreApplication::translate("UISettingsDialog", "Spot laden + openen", nullptr));

        label_4->setText(QCoreApplication::translate("UISettingsDialog", "Dubbel klikken", nullptr));
        doubleClickCombo->setItemText(0, QCoreApplication::translate("UISettingsDialog", "-niets-", nullptr));
        doubleClickCombo->setItemText(1, QCoreApplication::translate("UISettingsDialog", "Spot laden", nullptr));
        doubleClickCombo->setItemText(2, QCoreApplication::translate("UISettingsDialog", "Spot laden + openen", nullptr));

        spotFontButton->setText(QCoreApplication::translate("UISettingsDialog", "Aanpassen", nullptr));
        label_5->setText(QCoreApplication::translate("UISettingsDialog", "Skin (thema)", nullptr));
        listFontButton->setText(QCoreApplication::translate("UISettingsDialog", "Aanpassen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UISettingsDialog: public Ui_UISettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UISETTINGSDIALOG_H

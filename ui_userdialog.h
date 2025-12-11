/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QAction *actionAan_vrienden_toevoegen;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QPlainTextEdit *useridLabel;
    QLabel *crcLabel;
    QLabel *usernameLabel;
    QWidget *widget;
    QPushButton *friendButton;
    QPushButton *banButton;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName(QString::fromUtf8("UserDialog"));
        UserDialog->resize(382, 245);
        actionAan_vrienden_toevoegen = new QAction(UserDialog);
        actionAan_vrienden_toevoegen->setObjectName(QString::fromUtf8("actionAan_vrienden_toevoegen"));
        verticalLayout = new QVBoxLayout(UserDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(UserDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        useridLabel = new QPlainTextEdit(groupBox);
        useridLabel->setObjectName(QString::fromUtf8("useridLabel"));
        useridLabel->setReadOnly(true);

        gridLayout->addWidget(useridLabel, 4, 0, 1, 1);

        crcLabel = new QLabel(groupBox);
        crcLabel->setObjectName(QString::fromUtf8("crcLabel"));

        gridLayout->addWidget(crcLabel, 2, 0, 1, 1);

        usernameLabel = new QLabel(groupBox);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        gridLayout->addWidget(usernameLabel, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        widget = new QWidget(UserDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 50));
        friendButton = new QPushButton(widget);
        friendButton->setObjectName(QString::fromUtf8("friendButton"));
        friendButton->setGeometry(QRect(0, 20, 181, 24));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(friendButton->sizePolicy().hasHeightForWidth());
        friendButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/vriend.png"), QSize(), QIcon::Normal, QIcon::Off);
        friendButton->setIcon(icon);
        friendButton->setIconSize(QSize(24, 24));
        banButton = new QPushButton(widget);
        banButton->setObjectName(QString::fromUtf8("banButton"));
        banButton->setGeometry(QRect(190, 20, 151, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/ban.png"), QSize(), QIcon::Normal, QIcon::Off);
        banButton->setIcon(icon1);
        banButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(widget);


        retranslateUi(UserDialog);

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QCoreApplication::translate("UserDialog", "Gebruikersinfo", nullptr));
        actionAan_vrienden_toevoegen->setText(QCoreApplication::translate("UserDialog", "Aan vrienden toevoegen", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UserDialog", "Gebruikersinformatie", nullptr));
        label->setText(QCoreApplication::translate("UserDialog", "Gebruiker-ID (volledig): ", nullptr));
        crcLabel->setText(QCoreApplication::translate("UserDialog", "Gebruiker-ID (kort): ", nullptr));
        usernameLabel->setText(QCoreApplication::translate("UserDialog", "Gebruikersnaam: ", nullptr));
        friendButton->setText(QCoreApplication::translate("UserDialog", "zet op vriendenlijst", nullptr));
        banButton->setText(QCoreApplication::translate("UserDialog", "bannen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H

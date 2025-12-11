/********************************************************************************
** Form generated from reading UI file 'spotreplywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPOTREPLYWINDOW_H
#define UI_SPOTREPLYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SpotReplyWindow
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QListWidget *smileys;
    QLabel *label;

    void setupUi(QDialog *SpotReplyWindow)
    {
        if (SpotReplyWindow->objectName().isEmpty())
            SpotReplyWindow->setObjectName(QString::fromUtf8("SpotReplyWindow"));
        SpotReplyWindow->resize(400, 300);
        gridLayout = new QGridLayout(SpotReplyWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(1);
        gridLayout->setContentsMargins(-1, 1, -1, 1);
        buttonBox = new QDialogButtonBox(SpotReplyWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        textEdit = new QTextEdit(SpotReplyWindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        smileys = new QListWidget(SpotReplyWindow);
        smileys->setObjectName(QString::fromUtf8("smileys"));
        smileys->setMaximumSize(QSize(9999, 60));
        smileys->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        smileys->setIconSize(QSize(50, 40));
        smileys->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        smileys->setFlow(QListView::LeftToRight);

        gridLayout->addWidget(smileys, 2, 0, 1, 1);

        label = new QLabel(SpotReplyWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(SpotReplyWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), SpotReplyWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SpotReplyWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(SpotReplyWindow);
    } // setupUi

    void retranslateUi(QDialog *SpotReplyWindow)
    {
        SpotReplyWindow->setWindowTitle(QCoreApplication::translate("SpotReplyWindow", "Reactie plaatsen", nullptr));
        label->setText(QCoreApplication::translate("SpotReplyWindow", "Bericht:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpotReplyWindow: public Ui_SpotReplyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPOTREPLYWINDOW_H

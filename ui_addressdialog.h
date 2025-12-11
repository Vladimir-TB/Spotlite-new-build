/********************************************************************************
** Form generated from reading UI file 'addressdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSDIALOG_H
#define UI_ADDRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddressDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QToolButton *delButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView_2;

    void setupUi(QDialog *AddressDialog)
    {
        if (AddressDialog->objectName().isEmpty())
            AddressDialog->setObjectName(QString::fromUtf8("AddressDialog"));
        AddressDialog->resize(451, 307);
        verticalLayout = new QVBoxLayout(AddressDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(AddressDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(100, 25));
        delButton = new QToolButton(widget);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setEnabled(false);
        delButton->setGeometry(QRect(0, 0, 111, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        delButton->setIcon(icon);
        delButton->setIconSize(QSize(24, 24));
        delButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(widget);

        tabWidget = new QTabWidget(AddressDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(tableView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_3->addWidget(tableView_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(AddressDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AddressDialog);
    } // setupUi

    void retranslateUi(QDialog *AddressDialog)
    {
        AddressDialog->setWindowTitle(QCoreApplication::translate("AddressDialog", "Adresboek", nullptr));
        delButton->setText(QCoreApplication::translate("AddressDialog", "Verwijderen", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AddressDialog", "Vrienden", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AddressDialog", "Banlijst", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddressDialog: public Ui_AddressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSDIALOG_H

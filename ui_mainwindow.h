/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "spotimagelist.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConfiguratie;
    QAction *actionAfsluiten;
    QAction *actionOver_SpotLite;
    QAction *actionDatabase_optimalizeren;
    QAction *actionHeaders_verwijderen_en_opnieuw_downloaden;
    QAction *actionGebruikersinterface_aanpassen;
    QAction *actionDonker_thema;
    QAction *actionAdresboek;
    QAction *actionSpotMobiel;
    QAction *actionDatabase_importeren;
    QAction *actionDatabase_exporteren;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLineEdit *queryEdit;
    QPushButton *zoekButton;
    QTreeWidget *treeWidget;
    QCheckBox *onlycat_checkbox;
    QPushButton *updateButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_4;
    SpotImageList *imagelist;
    QMenuBar *menuBar;
    QMenu *menuProgramma;
    QMenu *menuOpties;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionConfiguratie = new QAction(MainWindow);
        actionConfiguratie->setObjectName(QString::fromUtf8("actionConfiguratie"));
        actionAfsluiten = new QAction(MainWindow);
        actionAfsluiten->setObjectName(QString::fromUtf8("actionAfsluiten"));
        actionOver_SpotLite = new QAction(MainWindow);
        actionOver_SpotLite->setObjectName(QString::fromUtf8("actionOver_SpotLite"));
        actionDatabase_optimalizeren = new QAction(MainWindow);
        actionDatabase_optimalizeren->setObjectName(QString::fromUtf8("actionDatabase_optimalizeren"));
        actionHeaders_verwijderen_en_opnieuw_downloaden = new QAction(MainWindow);
        actionHeaders_verwijderen_en_opnieuw_downloaden->setObjectName(QString::fromUtf8("actionHeaders_verwijderen_en_opnieuw_downloaden"));
        actionGebruikersinterface_aanpassen = new QAction(MainWindow);
        actionGebruikersinterface_aanpassen->setObjectName(QString::fromUtf8("actionGebruikersinterface_aanpassen"));
        actionDonker_thema = new QAction(MainWindow);
        actionDonker_thema->setObjectName(QString::fromUtf8("actionDonker_thema"));
        actionDonker_thema->setCheckable(true);
        actionAdresboek = new QAction(MainWindow);
        actionAdresboek->setObjectName(QString::fromUtf8("actionAdresboek"));
        actionSpotMobiel = new QAction(MainWindow);
        actionSpotMobiel->setObjectName(QString::fromUtf8("actionSpotMobiel"));
        actionDatabase_importeren = new QAction(MainWindow);
        actionDatabase_importeren->setObjectName(QString::fromUtf8("actionDatabase_importeren"));
        actionDatabase_exporteren = new QAction(MainWindow);
        actionDatabase_exporteren->setObjectName(QString::fromUtf8("actionDatabase_exporteren"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 1, 0, 1);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(175, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setBaseSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        queryEdit = new QLineEdit(frame);
        queryEdit->setObjectName(QString::fromUtf8("queryEdit"));

        gridLayout->addWidget(queryEdit, 2, 0, 1, 1);

        zoekButton = new QPushButton(frame);
        zoekButton->setObjectName(QString::fromUtf8("zoekButton"));

        gridLayout->addWidget(zoekButton, 2, 1, 1, 1);

        treeWidget = new QTreeWidget(frame);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setRootIsDecorated(true);
        treeWidget->setUniformRowHeights(false);
        treeWidget->setHeaderHidden(false);

        gridLayout->addWidget(treeWidget, 4, 0, 1, 2);

        onlycat_checkbox = new QCheckBox(frame);
        onlycat_checkbox->setObjectName(QString::fromUtf8("onlycat_checkbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(onlycat_checkbox->sizePolicy().hasHeightForWidth());
        onlycat_checkbox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(onlycat_checkbox, 3, 0, 1, 2);

        updateButton = new QPushButton(frame);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(updateButton->sizePolicy().hasHeightForWidth());
        updateButton->setSizePolicy(sizePolicy3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/arrow_refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateButton->setIcon(icon1);

        gridLayout->addWidget(updateButton, 1, 0, 1, 2);

        splitter->addWidget(frame);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        tabWidget_2->setTabPosition(QTabWidget::South);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font;
        font.setPointSize(9);
        tableView->setFont(font);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->setGridStyle(Qt::NoPen);
        tableView->setSortingEnabled(true);
        tableView->setCornerButtonEnabled(false);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setMinimumSectionSize(20);
        tableView->verticalHeader()->setDefaultSectionSize(20);
        tableView->verticalHeader()->setHighlightSections(true);

        horizontalLayout_3->addWidget(tableView);

        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_4 = new QHBoxLayout(tab_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        imagelist = new SpotImageList(tab_3);
        imagelist->setObjectName(QString::fromUtf8("imagelist"));

        horizontalLayout_4->addWidget(imagelist);

        tabWidget_2->addTab(tab_3, QString());

        horizontalLayout_2->addWidget(tabWidget_2);

        tabWidget->addTab(tab, QString());
        splitter->addWidget(tabWidget);

        horizontalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 30));
        menuProgramma = new QMenu(menuBar);
        menuProgramma->setObjectName(QString::fromUtf8("menuProgramma"));
        menuOpties = new QMenu(menuBar);
        menuOpties->setObjectName(QString::fromUtf8("menuOpties"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuProgramma->menuAction());
        menuBar->addAction(menuOpties->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuProgramma->addAction(actionDatabase_importeren);
        menuProgramma->addAction(actionDatabase_exporteren);
        menuProgramma->addAction(actionAfsluiten);
        menuOpties->addAction(actionConfiguratie);
        menuOpties->addAction(actionDatabase_optimalizeren);
        menuOpties->addAction(actionHeaders_verwijderen_en_opnieuw_downloaden);
        menuOpties->addAction(actionGebruikersinterface_aanpassen);
        menuOpties->addAction(actionDonker_thema);
        menuOpties->addAction(actionAdresboek);
        menuHelp->addAction(actionOver_SpotLite);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Spotlite Release 2026", nullptr));
        actionConfiguratie->setText(QCoreApplication::translate("MainWindow", "Configuratie", nullptr));
        actionAfsluiten->setText(QCoreApplication::translate("MainWindow", "Afsluiten", nullptr));
        actionOver_SpotLite->setText(QCoreApplication::translate("MainWindow", "Over SpotLite", nullptr));
        actionDatabase_optimalizeren->setText(QCoreApplication::translate("MainWindow", "Database optimaliseren", nullptr));
        actionHeaders_verwijderen_en_opnieuw_downloaden->setText(QCoreApplication::translate("MainWindow", "Headers verwijderen en opnieuw downloaden", nullptr));
        actionGebruikersinterface_aanpassen->setText(QCoreApplication::translate("MainWindow", "Gebruikersinterface aanpassen", nullptr));
        actionDonker_thema->setText(QCoreApplication::translate("MainWindow", "Donker thema", nullptr));
#if QT_CONFIG(tooltip)
        actionDonker_thema->setToolTip(QCoreApplication::translate("MainWindow", "Schakel tussen donker en licht", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAdresboek->setText(QCoreApplication::translate("MainWindow", "Adresboek", nullptr));
        actionSpotMobiel->setText(QCoreApplication::translate("MainWindow", "SpotMobiel", nullptr));
        actionDatabase_importeren->setText(QCoreApplication::translate("MainWindow", "Database importeren", nullptr));
        actionDatabase_exporteren->setText(QCoreApplication::translate("MainWindow", "Database exporteren", nullptr));
        zoekButton->setText(QCoreApplication::translate("MainWindow", "Zoek", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Categorie\303\253n", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "Nieuw", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "Alles", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "Watchlist", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "Beeld", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "Geluid", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("MainWindow", "Spelletjes", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget->topLevelItem(6);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("MainWindow", "Applicaties", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(7);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("MainWindow", "Erotiek", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("MainWindow", "Nieuw", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("MainWindow", "Watchlist", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = treeWidget->topLevelItem(8);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("MainWindow", "Prullenbak", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        onlycat_checkbox->setText(QCoreApplication::translate("MainWindow", "Binnen categorie zoeken", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Lijst", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Plaatjes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Nieuw", nullptr));
        menuProgramma->setTitle(QCoreApplication::translate("MainWindow", "Programma", nullptr));
        menuOpties->setTitle(QCoreApplication::translate("MainWindow", "Opties", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

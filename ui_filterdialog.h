/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *catCombo;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_5;
    QTreeWidget *optionsTree;
    QLabel *label_7;
    QLabel *label_3;
    QLineEdit *titleEdit;
    QLabel *label_4;
    QLabel *label_8;
    QComboBox *sortCombo;
    QLineEdit *spotterEdit;
    QLineEdit *tagEdit;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName(QString::fromUtf8("FilterDialog"));
        FilterDialog->resize(471, 476);
        verticalLayout = new QVBoxLayout(FilterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(FilterDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        catCombo = new QComboBox(groupBox);
        catCombo->addItem(QString());
        catCombo->addItem(QString());
        catCombo->addItem(QString());
        catCombo->addItem(QString());
        catCombo->addItem(QString());
        catCombo->setObjectName(QString::fromUtf8("catCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(catCombo->sizePolicy().hasHeightForWidth());
        catCombo->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, catCombo);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nameEdit);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        optionsTree = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        optionsTree->setHeaderItem(__qtreewidgetitem);
        optionsTree->setObjectName(QString::fromUtf8("optionsTree"));
        optionsTree->header()->setVisible(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, optionsTree);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setWordWrap(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, label_7);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        titleEdit = new QLineEdit(groupBox);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, titleEdit);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

        sortCombo = new QComboBox(groupBox);
        sortCombo->addItem(QString());
        sortCombo->addItem(QString());
        sortCombo->addItem(QString());
        sortCombo->addItem(QString());
        sortCombo->addItem(QString());
        sortCombo->setObjectName(QString::fromUtf8("sortCombo"));
        sizePolicy.setHeightForWidth(sortCombo->sizePolicy().hasHeightForWidth());
        sortCombo->setSizePolicy(sizePolicy);

        formLayout->setWidget(8, QFormLayout::FieldRole, sortCombo);

        spotterEdit = new QLineEdit(groupBox);
        spotterEdit->setObjectName(QString::fromUtf8("spotterEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, spotterEdit);

        tagEdit = new QLineEdit(groupBox);
        tagEdit->setObjectName(QString::fromUtf8("tagEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, tagEdit);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(FilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FilterDialog, SLOT(reject()));

        sortCombo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QCoreApplication::translate("FilterDialog", "Filter bewerken", nullptr));
        groupBox->setTitle(QCoreApplication::translate("FilterDialog", "Filter bewerken", nullptr));
        label_2->setText(QCoreApplication::translate("FilterDialog", "Categorie:", nullptr));
        catCombo->setItemText(0, QCoreApplication::translate("FilterDialog", "Beeld", nullptr));
        catCombo->setItemText(1, QCoreApplication::translate("FilterDialog", "Geluid", nullptr));
        catCombo->setItemText(2, QCoreApplication::translate("FilterDialog", "Spelletjes", nullptr));
        catCombo->setItemText(3, QCoreApplication::translate("FilterDialog", "Applicaties", nullptr));
        catCombo->setItemText(4, QCoreApplication::translate("FilterDialog", "Erotiek", nullptr));

        label->setText(QCoreApplication::translate("FilterDialog", "Naam filter:", nullptr));
        label_5->setText(QCoreApplication::translate("FilterDialog", "Details:", nullptr));
        label_7->setText(QCoreApplication::translate("FilterDialog", "Let op: het gebruik van onderstaande opties kan het tonen van resultaten flink vertragen:", nullptr));
        label_3->setText(QCoreApplication::translate("FilterDialog", "Zoek in titel:", nullptr));
        label_4->setText(QCoreApplication::translate("FilterDialog", "Naam spotter:", nullptr));
        label_8->setText(QCoreApplication::translate("FilterDialog", "Sorteren op:", nullptr));
        sortCombo->setItemText(0, QCoreApplication::translate("FilterDialog", "id (=snel)", nullptr));
        sortCombo->setItemText(1, QCoreApplication::translate("FilterDialog", "datum", nullptr));
        sortCombo->setItemText(2, QCoreApplication::translate("FilterDialog", "subcategorie", nullptr));
        sortCombo->setItemText(3, QCoreApplication::translate("FilterDialog", "titel", nullptr));
        sortCombo->setItemText(4, QCoreApplication::translate("FilterDialog", "spotter", nullptr));

        label_6->setText(QCoreApplication::translate("FilterDialog", "Tag:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDIALOG_H

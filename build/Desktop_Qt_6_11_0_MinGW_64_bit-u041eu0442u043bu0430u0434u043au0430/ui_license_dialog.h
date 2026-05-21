/********************************************************************************
** Form generated from reading UI file 'license_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICENSE_DIALOG_H
#define UI_LICENSE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LicenseDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelEndDate;
    QLineEdit *editEndDate;
    QLabel *labelSoftName;
    QLineEdit *editSoftName;
    QLabel *labelSoftVersion;
    QLineEdit *editSoftVersion;
    QLabel *labelKey;
    QLineEdit *editKey;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *LicenseDialog)
    {
        if (LicenseDialog->objectName().isEmpty())
            LicenseDialog->setObjectName("LicenseDialog");
        LicenseDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(LicenseDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelEndDate = new QLabel(LicenseDialog);
        labelEndDate->setObjectName("labelEndDate");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelEndDate);

        editEndDate = new QLineEdit(LicenseDialog);
        editEndDate->setObjectName("editEndDate");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editEndDate);

        labelSoftName = new QLabel(LicenseDialog);
        labelSoftName->setObjectName("labelSoftName");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelSoftName);

        editSoftName = new QLineEdit(LicenseDialog);
        editSoftName->setObjectName("editSoftName");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, editSoftName);

        labelSoftVersion = new QLabel(LicenseDialog);
        labelSoftVersion->setObjectName("labelSoftVersion");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelSoftVersion);

        editSoftVersion = new QLineEdit(LicenseDialog);
        editSoftVersion->setObjectName("editSoftVersion");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, editSoftVersion);

        labelKey = new QLabel(LicenseDialog);
        labelKey->setObjectName("labelKey");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelKey);

        editKey = new QLineEdit(LicenseDialog);
        editKey->setObjectName("editKey");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, editKey);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnSave = new QPushButton(LicenseDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(LicenseDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LicenseDialog);

        QMetaObject::connectSlotsByName(LicenseDialog);
    } // setupUi

    void retranslateUi(QDialog *LicenseDialog)
    {
        LicenseDialog->setWindowTitle(QCoreApplication::translate("LicenseDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\273\320\270\321\206\320\265\320\275\320\267\320\270\320\270", nullptr));
        labelEndDate->setText(QCoreApplication::translate("LicenseDialog", "\320\224\320\260\321\202\320\260 \320\276\320\272\320\276\320\275\321\207\320\260\320\275\320\270\321\217:", nullptr));
        editEndDate->setPlaceholderText(QCoreApplication::translate("LicenseDialog", "\320\223\320\223\320\223\320\223-\320\234\320\234-\320\224\320\224", nullptr));
        labelSoftName->setText(QCoreApplication::translate("LicenseDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\237\320\236:", nullptr));
        labelSoftVersion->setText(QCoreApplication::translate("LicenseDialog", "\320\222\320\265\321\200\321\201\320\270\321\217 \320\237\320\236:", nullptr));
        labelKey->setText(QCoreApplication::translate("LicenseDialog", "\320\232\320\273\321\216\321\207:", nullptr));
        btnSave->setText(QCoreApplication::translate("LicenseDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("LicenseDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LicenseDialog: public Ui_LicenseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICENSE_DIALOG_H

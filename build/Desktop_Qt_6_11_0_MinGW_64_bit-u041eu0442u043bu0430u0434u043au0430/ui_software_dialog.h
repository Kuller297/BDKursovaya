/********************************************************************************
** Form generated from reading UI file 'software_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOFTWARE_DIALOG_H
#define UI_SOFTWARE_DIALOG_H

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

class Ui_SoftwareDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelSoftName;
    QLineEdit *editSoftName;
    QLabel *labelVersion;
    QLineEdit *editVersion;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *SoftwareDialog)
    {
        if (SoftwareDialog->objectName().isEmpty())
            SoftwareDialog->setObjectName("SoftwareDialog");
        SoftwareDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(SoftwareDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelSoftName = new QLabel(SoftwareDialog);
        labelSoftName->setObjectName("labelSoftName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelSoftName);

        editSoftName = new QLineEdit(SoftwareDialog);
        editSoftName->setObjectName("editSoftName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editSoftName);

        labelVersion = new QLabel(SoftwareDialog);
        labelVersion->setObjectName("labelVersion");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelVersion);

        editVersion = new QLineEdit(SoftwareDialog);
        editVersion->setObjectName("editVersion");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, editVersion);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnSave = new QPushButton(SoftwareDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(SoftwareDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SoftwareDialog);

        QMetaObject::connectSlotsByName(SoftwareDialog);
    } // setupUi

    void retranslateUi(QDialog *SoftwareDialog)
    {
        SoftwareDialog->setWindowTitle(QCoreApplication::translate("SoftwareDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\237\320\236", nullptr));
        labelSoftName->setText(QCoreApplication::translate("SoftwareDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\237\320\236:", nullptr));
        labelVersion->setText(QCoreApplication::translate("SoftwareDialog", "\320\222\320\265\321\200\321\201\320\270\321\217:", nullptr));
        btnSave->setText(QCoreApplication::translate("SoftwareDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("SoftwareDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SoftwareDialog: public Ui_SoftwareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOFTWARE_DIALOG_H

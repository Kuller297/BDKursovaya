/********************************************************************************
** Form generated from reading UI file 'equipment_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPMENT_DIALOG_H
#define UI_EQUIPMENT_DIALOG_H

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

class Ui_EquipmentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelUserId;
    QLineEdit *editUserId;
    QLabel *labelEmpId;
    QLineEdit *editEmpId;
    QLabel *labelCompId;
    QLineEdit *editCompId;
    QLabel *labelSoftId;
    QLineEdit *editSoftId;
    QLabel *labelLicId;
    QLineEdit *editLicId;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *EquipmentDialog)
    {
        if (EquipmentDialog->objectName().isEmpty())
            EquipmentDialog->setObjectName("EquipmentDialog");
        EquipmentDialog->resize(450, 350);
        verticalLayout = new QVBoxLayout(EquipmentDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelUserId = new QLabel(EquipmentDialog);
        labelUserId->setObjectName("labelUserId");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelUserId);

        editUserId = new QLineEdit(EquipmentDialog);
        editUserId->setObjectName("editUserId");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editUserId);

        labelEmpId = new QLabel(EquipmentDialog);
        labelEmpId->setObjectName("labelEmpId");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelEmpId);

        editEmpId = new QLineEdit(EquipmentDialog);
        editEmpId->setObjectName("editEmpId");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, editEmpId);

        labelCompId = new QLabel(EquipmentDialog);
        labelCompId->setObjectName("labelCompId");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelCompId);

        editCompId = new QLineEdit(EquipmentDialog);
        editCompId->setObjectName("editCompId");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, editCompId);

        labelSoftId = new QLabel(EquipmentDialog);
        labelSoftId->setObjectName("labelSoftId");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelSoftId);

        editSoftId = new QLineEdit(EquipmentDialog);
        editSoftId->setObjectName("editSoftId");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, editSoftId);

        labelLicId = new QLabel(EquipmentDialog);
        labelLicId->setObjectName("labelLicId");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelLicId);

        editLicId = new QLineEdit(EquipmentDialog);
        editLicId->setObjectName("editLicId");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, editLicId);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnSave = new QPushButton(EquipmentDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(EquipmentDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EquipmentDialog);

        QMetaObject::connectSlotsByName(EquipmentDialog);
    } // setupUi

    void retranslateUi(QDialog *EquipmentDialog)
    {
        EquipmentDialog->setWindowTitle(QCoreApplication::translate("EquipmentDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        labelUserId->setText(QCoreApplication::translate("EquipmentDialog", "ID \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        labelEmpId->setText(QCoreApplication::translate("EquipmentDialog", "ID \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260:", nullptr));
        labelCompId->setText(QCoreApplication::translate("EquipmentDialog", "ID \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\260:", nullptr));
        labelSoftId->setText(QCoreApplication::translate("EquipmentDialog", "ID \320\237\320\236:", nullptr));
        labelLicId->setText(QCoreApplication::translate("EquipmentDialog", "ID \320\273\320\270\321\206\320\265\320\275\320\267\320\270\320\270:", nullptr));
        btnSave->setText(QCoreApplication::translate("EquipmentDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("EquipmentDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EquipmentDialog: public Ui_EquipmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPMENT_DIALOG_H

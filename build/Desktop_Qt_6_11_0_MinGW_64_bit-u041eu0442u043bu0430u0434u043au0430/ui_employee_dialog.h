/********************************************************************************
** Form generated from reading UI file 'employee_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_DIALOG_H
#define UI_EMPLOYEE_DIALOG_H

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

class Ui_EmployeeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *editName;
    QLabel *labelSurname;
    QLineEdit *editSurname;
    QLabel *labelPatronimic;
    QLineEdit *editPatronimic;
    QLabel *labelPost;
    QLineEdit *editPost;
    QLabel *labelTelephone;
    QLineEdit *editTelephone;
    QLabel *labelAdress;
    QLineEdit *editAdress;
    QLabel *labelUserId;
    QLineEdit *editUserId;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *EmployeeDialog)
    {
        if (EmployeeDialog->objectName().isEmpty())
            EmployeeDialog->setObjectName("EmployeeDialog");
        EmployeeDialog->resize(450, 400);
        verticalLayout = new QVBoxLayout(EmployeeDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelName = new QLabel(EmployeeDialog);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        editName = new QLineEdit(EmployeeDialog);
        editName->setObjectName("editName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editName);

        labelSurname = new QLabel(EmployeeDialog);
        labelSurname->setObjectName("labelSurname");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelSurname);

        editSurname = new QLineEdit(EmployeeDialog);
        editSurname->setObjectName("editSurname");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, editSurname);

        labelPatronimic = new QLabel(EmployeeDialog);
        labelPatronimic->setObjectName("labelPatronimic");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelPatronimic);

        editPatronimic = new QLineEdit(EmployeeDialog);
        editPatronimic->setObjectName("editPatronimic");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, editPatronimic);

        labelPost = new QLabel(EmployeeDialog);
        labelPost->setObjectName("labelPost");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelPost);

        editPost = new QLineEdit(EmployeeDialog);
        editPost->setObjectName("editPost");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, editPost);

        labelTelephone = new QLabel(EmployeeDialog);
        labelTelephone->setObjectName("labelTelephone");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelTelephone);

        editTelephone = new QLineEdit(EmployeeDialog);
        editTelephone->setObjectName("editTelephone");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, editTelephone);

        labelAdress = new QLabel(EmployeeDialog);
        labelAdress->setObjectName("labelAdress");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, labelAdress);

        editAdress = new QLineEdit(EmployeeDialog);
        editAdress->setObjectName("editAdress");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, editAdress);

        labelUserId = new QLabel(EmployeeDialog);
        labelUserId->setObjectName("labelUserId");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, labelUserId);

        editUserId = new QLineEdit(EmployeeDialog);
        editUserId->setObjectName("editUserId");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, editUserId);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnSave = new QPushButton(EmployeeDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(EmployeeDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EmployeeDialog);

        QMetaObject::connectSlotsByName(EmployeeDialog);
    } // setupUi

    void retranslateUi(QDialog *EmployeeDialog)
    {
        EmployeeDialog->setWindowTitle(QCoreApplication::translate("EmployeeDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        labelName->setText(QCoreApplication::translate("EmployeeDialog", "\320\230\320\274\321\217:", nullptr));
        labelSurname->setText(QCoreApplication::translate("EmployeeDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        labelPatronimic->setText(QCoreApplication::translate("EmployeeDialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        labelPost->setText(QCoreApplication::translate("EmployeeDialog", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        labelTelephone->setText(QCoreApplication::translate("EmployeeDialog", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275:", nullptr));
        labelAdress->setText(QCoreApplication::translate("EmployeeDialog", "\320\220\320\264\321\200\320\265\321\201:", nullptr));
        labelUserId->setText(QCoreApplication::translate("EmployeeDialog", "ID \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        btnSave->setText(QCoreApplication::translate("EmployeeDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("EmployeeDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeDialog: public Ui_EmployeeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_DIALOG_H

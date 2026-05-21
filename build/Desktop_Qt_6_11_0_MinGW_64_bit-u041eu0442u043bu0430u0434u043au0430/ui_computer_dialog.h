/********************************************************************************
** Form generated from reading UI file 'computer_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTER_DIALOG_H
#define UI_COMPUTER_DIALOG_H

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

class Ui_ComputerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelProcessor;
    QLineEdit *editProcessor;
    QLabel *labelVideoCard;
    QLineEdit *editVideoCard;
    QLabel *labelRam;
    QLineEdit *editRam;
    QLabel *labelScreen;
    QLineEdit *editScreen;
    QLabel *labelKeyboard;
    QLineEdit *editKeyboard;
    QLabel *labelMouse;
    QLineEdit *editMouse;
    QLabel *labelEmployee;
    QHBoxLayout *employeeLayout;
    QLineEdit *editEmployeeFullName;
    QPushButton *btnSelectEmployee;
    QPushButton *btnClearEmployee;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *ComputerDialog)
    {
        if (ComputerDialog->objectName().isEmpty())
            ComputerDialog->setObjectName("ComputerDialog");
        ComputerDialog->resize(450, 420);
        verticalLayout = new QVBoxLayout(ComputerDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelProcessor = new QLabel(ComputerDialog);
        labelProcessor->setObjectName("labelProcessor");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelProcessor);

        editProcessor = new QLineEdit(ComputerDialog);
        editProcessor->setObjectName("editProcessor");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editProcessor);

        labelVideoCard = new QLabel(ComputerDialog);
        labelVideoCard->setObjectName("labelVideoCard");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelVideoCard);

        editVideoCard = new QLineEdit(ComputerDialog);
        editVideoCard->setObjectName("editVideoCard");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, editVideoCard);

        labelRam = new QLabel(ComputerDialog);
        labelRam->setObjectName("labelRam");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelRam);

        editRam = new QLineEdit(ComputerDialog);
        editRam->setObjectName("editRam");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, editRam);

        labelScreen = new QLabel(ComputerDialog);
        labelScreen->setObjectName("labelScreen");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelScreen);

        editScreen = new QLineEdit(ComputerDialog);
        editScreen->setObjectName("editScreen");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, editScreen);

        labelKeyboard = new QLabel(ComputerDialog);
        labelKeyboard->setObjectName("labelKeyboard");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelKeyboard);

        editKeyboard = new QLineEdit(ComputerDialog);
        editKeyboard->setObjectName("editKeyboard");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, editKeyboard);

        labelMouse = new QLabel(ComputerDialog);
        labelMouse->setObjectName("labelMouse");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, labelMouse);

        editMouse = new QLineEdit(ComputerDialog);
        editMouse->setObjectName("editMouse");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, editMouse);

        labelEmployee = new QLabel(ComputerDialog);
        labelEmployee->setObjectName("labelEmployee");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, labelEmployee);

        employeeLayout = new QHBoxLayout();
        employeeLayout->setObjectName("employeeLayout");
        editEmployeeFullName = new QLineEdit(ComputerDialog);
        editEmployeeFullName->setObjectName("editEmployeeFullName");
        editEmployeeFullName->setReadOnly(true);

        employeeLayout->addWidget(editEmployeeFullName);

        btnSelectEmployee = new QPushButton(ComputerDialog);
        btnSelectEmployee->setObjectName("btnSelectEmployee");

        employeeLayout->addWidget(btnSelectEmployee);

        btnClearEmployee = new QPushButton(ComputerDialog);
        btnClearEmployee->setObjectName("btnClearEmployee");

        employeeLayout->addWidget(btnClearEmployee);


        formLayout->setLayout(6, QFormLayout::ItemRole::FieldRole, employeeLayout);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnSave = new QPushButton(ComputerDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(ComputerDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ComputerDialog);

        QMetaObject::connectSlotsByName(ComputerDialog);
    } // setupUi

    void retranslateUi(QDialog *ComputerDialog)
    {
        ComputerDialog->setWindowTitle(QCoreApplication::translate("ComputerDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\260", nullptr));
        labelProcessor->setText(QCoreApplication::translate("ComputerDialog", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201\320\276\321\200:", nullptr));
        labelVideoCard->setText(QCoreApplication::translate("ComputerDialog", "\320\222\320\270\320\264\320\265\320\276\320\272\320\260\321\200\321\202\320\260:", nullptr));
        labelRam->setText(QCoreApplication::translate("ComputerDialog", "RAM, GB:", nullptr));
        labelScreen->setText(QCoreApplication::translate("ComputerDialog", "\320\255\320\272\321\200\320\260\320\275:", nullptr));
        labelKeyboard->setText(QCoreApplication::translate("ComputerDialog", "\320\232\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\320\260:", nullptr));
        labelMouse->setText(QCoreApplication::translate("ComputerDialog", "\320\234\321\213\321\210\321\214:", nullptr));
        labelEmployee->setText(QCoreApplication::translate("ComputerDialog", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272:", nullptr));
        editEmployeeFullName->setPlaceholderText(QCoreApplication::translate("ComputerDialog", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275", nullptr));
        btnSelectEmployee->setText(QCoreApplication::translate("ComputerDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        btnClearEmployee->setText(QCoreApplication::translate("ComputerDialog", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        btnSave->setText(QCoreApplication::translate("ComputerDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("ComputerDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComputerDialog: public Ui_ComputerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTER_DIALOG_H

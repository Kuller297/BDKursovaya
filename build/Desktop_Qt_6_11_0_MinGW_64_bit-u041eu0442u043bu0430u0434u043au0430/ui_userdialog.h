/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelLogin;
    QLineEdit *editLogin;
    QLabel *labelPassword;
    QLineEdit *editPassword;
    QLabel *labelRole;
    QComboBox *comboRole;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName("UserDialog");
        UserDialog->resize(400, 250);
        verticalLayout = new QVBoxLayout(UserDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelLogin = new QLabel(UserDialog);
        labelLogin->setObjectName("labelLogin");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelLogin);

        editLogin = new QLineEdit(UserDialog);
        editLogin->setObjectName("editLogin");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, editLogin);

        labelPassword = new QLabel(UserDialog);
        labelPassword->setObjectName("labelPassword");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelPassword);

        editPassword = new QLineEdit(UserDialog);
        editPassword->setObjectName("editPassword");
        editPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, editPassword);

        labelRole = new QLabel(UserDialog);
        labelRole->setObjectName("labelRole");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelRole);

        comboRole = new QComboBox(UserDialog);
        comboRole->addItem(QString());
        comboRole->addItem(QString());
        comboRole->addItem(QString());
        comboRole->setObjectName("comboRole");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboRole);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnSave = new QPushButton(UserDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(UserDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserDialog);

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QCoreApplication::translate("UserDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        labelLogin->setText(QCoreApplication::translate("UserDialog", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        labelPassword->setText(QCoreApplication::translate("UserDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        labelRole->setText(QCoreApplication::translate("UserDialog", "\320\240\320\276\320\273\321\214:", nullptr));
        comboRole->setItemText(0, QCoreApplication::translate("UserDialog", "user", nullptr));
        comboRole->setItemText(1, QCoreApplication::translate("UserDialog", "admin", nullptr));
        comboRole->setItemText(2, QCoreApplication::translate("UserDialog", "main_admin", nullptr));

        btnSave->setText(QCoreApplication::translate("UserDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("UserDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H

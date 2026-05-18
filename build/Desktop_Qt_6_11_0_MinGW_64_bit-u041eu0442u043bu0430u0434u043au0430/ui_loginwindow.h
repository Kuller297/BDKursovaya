/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *loginEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QCheckBox *showPasswordCheckBox;
    QPushButton *loginButton;
    QLabel *statusLabel;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(350, 250);
        verticalLayout = new QVBoxLayout(LoginWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(LoginWindow);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        loginEdit = new QLineEdit(LoginWindow);
        loginEdit->setObjectName("loginEdit");

        verticalLayout->addWidget(loginEdit);

        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passwordEdit = new QLineEdit(LoginWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordEdit);

        showPasswordCheckBox = new QCheckBox(LoginWindow);
        showPasswordCheckBox->setObjectName("showPasswordCheckBox");

        verticalLayout->addWidget(showPasswordCheckBox);

        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");
        loginButton->setEnabled(false);

        verticalLayout->addWidget(loginButton);

        statusLabel = new QLabel(LoginWindow);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(statusLabel);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        showPasswordCheckBox->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        statusLabel->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

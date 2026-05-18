#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "database.h"
#include "mainwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
    , dbConnected(false)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(ui->showPasswordCheckBox, &QCheckBox::toggled, this, &LoginWindow::onShowPasswordToggled);

    if (Database::connect()) {
        dbConnected = true;
        ui->loginButton->setEnabled(true);
        ui->statusLabel->setText("Подключено к базе данных");
    } else {
        ui->statusLabel->setText("Ошибка подключения: " + Database::getLastError());
    }

    ui->loginEdit->setFocus();
}

LoginWindow::~LoginWindow()
{
    Database::disconnect();
    delete ui;
}

void LoginWindow::onLoginClicked()
{
    QString login = ui->loginEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите логин и пароль!");
        return;
    }

    QString user_post;
    if (Database::checkUser(login, password, user_post)) {
        MainWindow *mainWin = new MainWindow(user_post, login);
        mainWin->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль!");
        ui->passwordEdit->clear();
        ui->passwordEdit->setFocus();
    }
}

void LoginWindow::onShowPasswordToggled(bool checked)
{
    ui->passwordEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
}
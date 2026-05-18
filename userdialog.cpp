#include "userdialog.h"
#include "ui_userdialog.h"

UserDialog::UserDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserDialog)
    , currentUserId(-1)
    , isEditMode(false)
{
    ui->setupUi(this);

    connect(ui->btnSave, &QPushButton::clicked, this, &UserDialog::onSaveClicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &UserDialog::onCancelClicked);
}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::setEditMode(int userId, const QString& login, const QString& password, const QString& role)
{
    isEditMode = true;
    currentUserId = userId;
    setWindowTitle("Редактирование пользователя");

    ui->editLogin->setText(login);
    ui->editPassword->setText(password);
    ui->comboRole->setCurrentText(role);
}

void UserDialog::setAddMode()
{
    isEditMode = false;
    currentUserId = -1;
    setWindowTitle("Добавление пользователя");

    ui->editLogin->clear();
    ui->editPassword->clear();
    ui->comboRole->setCurrentIndex(0);
}

QString UserDialog::getLogin() const
{
    return ui->editLogin->text().trimmed();
}

QString UserDialog::getPassword() const
{
    return ui->editPassword->text();
}

QString UserDialog::getRole() const
{
    return ui->comboRole->currentText();
}

int UserDialog::getUserId() const
{
    return currentUserId;
}

void UserDialog::onSaveClicked()
{
    if (getLogin().isEmpty()) {
        return;
    }
    if (!isEditMode && getPassword().isEmpty()) {
        return;
    }
    accept();
}

void UserDialog::onCancelClicked()
{
    reject();
}
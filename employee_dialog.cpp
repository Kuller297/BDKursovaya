#include "employee_dialog.h"
#include "ui_employee_dialog.h"

EmployeeDialog::EmployeeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmployeeDialog)
    , currentEmpId(-1)
    , isEditMode(false)
{
    ui->setupUi(this);

    connect(ui->btnSave, &QPushButton::clicked, this, &EmployeeDialog::onSaveClicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &EmployeeDialog::onCancelClicked);
}

EmployeeDialog::~EmployeeDialog()
{
    delete ui;
}

void EmployeeDialog::setEditMode(int empId, const QString& name, const QString& surname,
                                 const QString& patronimic, const QString& post,
                                 const QString& telephone, const QString& adress,
                                 const QString& login, const QString& password, const QString& role)
{
    isEditMode = true;
    currentEmpId = empId;
    setWindowTitle("Редактирование сотрудника");

    ui->editName->setText(name);
    ui->editSurname->setText(surname);
    ui->editPatronimic->setText(patronimic);
    ui->editPost->setText(post);
    ui->editTelephone->setText(telephone);
    ui->editAdress->setText(adress);
    ui->editLogin->setText(login);
    ui->editPassword->setText(password);
    ui->comboRole->setCurrentText(role);
}

void EmployeeDialog::setAddMode()
{
    isEditMode = false;
    currentEmpId = -1;
    setWindowTitle("Добавление сотрудника");

    ui->editName->clear();
    ui->editSurname->clear();
    ui->editPatronimic->clear();
    ui->editPost->clear();
    ui->editTelephone->clear();
    ui->editAdress->clear();
    ui->editLogin->clear();
    ui->editPassword->clear();
    ui->comboRole->setCurrentIndex(0);
}

int EmployeeDialog::getEmpId() const
{
    return currentEmpId;
}

QString EmployeeDialog::getName() const
{
    return ui->editName->text().trimmed();
}

QString EmployeeDialog::getSurname() const
{
    return ui->editSurname->text().trimmed();
}

QString EmployeeDialog::getPatronimic() const
{
    return ui->editPatronimic->text().trimmed();
}

QString EmployeeDialog::getPost() const
{
    return ui->editPost->text().trimmed();
}

QString EmployeeDialog::getTelephone() const
{
    return ui->editTelephone->text().trimmed();
}

QString EmployeeDialog::getAdress() const
{
    return ui->editAdress->text().trimmed();
}

QString EmployeeDialog::getLogin() const
{
    return ui->editLogin->text().trimmed();
}

QString EmployeeDialog::getPassword() const
{
    return ui->editPassword->text();
}

QString EmployeeDialog::getRole() const
{
    return ui->comboRole->currentText();
}

void EmployeeDialog::onSaveClicked()
{
    if (getName().isEmpty() || getSurname().isEmpty()) {
        return;
    }
    if (!isEditMode && (getLogin().isEmpty() || getPassword().isEmpty())) {
        return;
    }
    accept();
}

void EmployeeDialog::onCancelClicked()
{
    reject();
}
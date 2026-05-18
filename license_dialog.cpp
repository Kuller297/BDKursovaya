#include "license_dialog.h"
#include "ui_license_dialog.h"
#include <QRegularExpression>
#include <QMessageBox>

LicenseDialog::LicenseDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LicenseDialog)
    , currentLicId(-1)
    , isEditMode(false)
{
    ui->setupUi(this);

    connect(ui->btnSave, &QPushButton::clicked, this, &LicenseDialog::onSaveClicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &LicenseDialog::onCancelClicked);
}

LicenseDialog::~LicenseDialog()
{
    delete ui;
}

void LicenseDialog::setEditMode(int licId, const QString& end_date, int id_soft, const QString& key)
{
    isEditMode = true;
    currentLicId = licId;
    setWindowTitle("Редактирование лицензии");

    ui->editEndDate->setText(end_date);
    ui->editIdSoft->setText(QString::number(id_soft));
    ui->editKey->setText(key);
}

void LicenseDialog::setAddMode()
{
    isEditMode = false;
    currentLicId = -1;
    setWindowTitle("Добавление лицензии");

    ui->editEndDate->clear();
    ui->editIdSoft->clear();
    ui->editKey->clear();
}

int LicenseDialog::getLicId() const
{
    return currentLicId;
}

QString LicenseDialog::getEndDate() const
{
    return ui->editEndDate->text().trimmed();
}

int LicenseDialog::getIdSoft() const
{
    return ui->editIdSoft->text().toInt();
}

QString LicenseDialog::getKey() const
{
    return ui->editKey->text().trimmed();
}

bool LicenseDialog::validateDate(const QString& date)
{
    QRegularExpression regex("^\\d{4}-\\d{2}-\\d{2}$");
    if (!regex.match(date).hasMatch()) {
        return false;
    }

    QStringList parts = date.split("-");
    int year = parts[0].toInt();
    int month = parts[1].toInt();
    int day = parts[2].toInt();

    if (year < 2000 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return true;
}

void LicenseDialog::onSaveClicked()
{
    QString endDate = getEndDate();
    int idSoft = getIdSoft();

    if (endDate.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите дату окончания!\nФормат: ГГГГ-ММ-ДД");
        ui->editEndDate->setFocus();
        return;
    }

    if (!validateDate(endDate)) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат даты!\nИспользуйте формат: ГГГГ-ММ-ДД\nНапример: 2025-12-31");
        ui->editEndDate->setFocus();
        return;
    }

    if (idSoft <= 0) {
        QMessageBox::warning(this, "Ошибка", "Введите корректный ID ПО!");
        ui->editIdSoft->setFocus();
        return;
    }

    accept();
}

void LicenseDialog::onCancelClicked()
{
    reject();
}
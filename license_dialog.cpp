#include "license_dialog.h"
#include "ui_license_dialog.h"
#include "database.h"
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

void LicenseDialog::setEditMode(int licId, const QString& end_date, const QString& soft_name,
                                const QString& soft_version, const QString& key)
{
    isEditMode = true;
    currentLicId = licId;
    setWindowTitle("Редактирование лицензии");

    ui->editEndDate->setText(end_date);
    ui->editSoftName->setText(soft_name);
    ui->editSoftVersion->setText(soft_version);
    ui->editKey->setText(key);
}

void LicenseDialog::setAddMode()
{
    isEditMode = false;
    currentLicId = -1;
    setWindowTitle("Добавление лицензии");

    ui->editEndDate->clear();
    ui->editSoftName->clear();
    ui->editSoftVersion->clear();
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

QString LicenseDialog::getSoftName() const
{
    return ui->editSoftName->text().trimmed();
}

QString LicenseDialog::getSoftVersion() const
{
    return ui->editSoftVersion->text().trimmed();
}

QString LicenseDialog::getKey() const
{
    return ui->editKey->text().trimmed();
}

int LicenseDialog::findSoftwareId(const QString& name, const QString& version)
{
    QSqlQuery query = Database::getAllSoftware();
    while (query.next()) {
        if (query.value(1).toString() == name && query.value(2).toString() == version) {
            return query.value(0).toInt();
        }
    }
    return -1;
}

int LicenseDialog::getSoftId()
{
    return findSoftwareId(getSoftName(), getSoftVersion());
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
    QString softName = getSoftName();
    QString softVersion = getSoftVersion();

    if (endDate.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите дату окончания!\nФормат: ГГГГ-ММ-ДД");
        ui->editEndDate->setFocus();
        return;
    }

    if (!validateDate(endDate)) {
        QMessageBox::warning(this, "Ошибка", "Неверный формат даты!\nИспользуйте формат: ГГГГ-ММ-ДД");
        ui->editEndDate->setFocus();
        return;
    }

    if (softName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название программы!");
        ui->editSoftName->setFocus();
        return;
    }

    int softId = findSoftwareId(softName, softVersion);
    if (softId == -1) {
        QMessageBox::warning(this, "Ошибка", "Программа не найдена!\nПроверьте название и версию.");
        return;
    }

    accept();
}

void LicenseDialog::onCancelClicked()
{
    reject();
}
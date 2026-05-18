#include "software_dialog.h"
#include "ui_software_dialog.h"

SoftwareDialog::SoftwareDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SoftwareDialog)
    , currentSoftId(-1)
    , isEditMode(false)
{
    ui->setupUi(this);

    connect(ui->btnSave, &QPushButton::clicked, this, &SoftwareDialog::onSaveClicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &SoftwareDialog::onCancelClicked);
}

SoftwareDialog::~SoftwareDialog()
{
    delete ui;
}

void SoftwareDialog::setEditMode(int softId, const QString& soft_name, const QString& version)
{
    isEditMode = true;
    currentSoftId = softId;
    setWindowTitle("Редактирование программного обеспечения");

    ui->editSoftName->setText(soft_name);
    ui->editVersion->setText(version);
}

void SoftwareDialog::setAddMode()
{
    isEditMode = false;
    currentSoftId = -1;
    setWindowTitle("Добавление программного обеспечения");

    ui->editSoftName->clear();
    ui->editVersion->clear();
}

int SoftwareDialog::getSoftId() const
{
    return currentSoftId;
}

QString SoftwareDialog::getSoftName() const
{
    return ui->editSoftName->text().trimmed();
}

QString SoftwareDialog::getVersion() const
{
    return ui->editVersion->text().trimmed();
}

void SoftwareDialog::onSaveClicked()
{
    if (getSoftName().isEmpty()) {
        return;
    }
    accept();
}

void SoftwareDialog::onCancelClicked()
{
    reject();
}
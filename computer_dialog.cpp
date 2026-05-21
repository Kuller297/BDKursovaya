#include "computer_dialog.h"
#include "ui_computer_dialog.h"
#include "employee_search_dialog.h"

ComputerDialog::ComputerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ComputerDialog)
    , currentCompId(-1)
    , selectedEmpId(-1)
    , isEditMode(false)
{
    ui->setupUi(this);

    connect(ui->btnSave, &QPushButton::clicked, this, &ComputerDialog::onSaveClicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &ComputerDialog::onCancelClicked);
    connect(ui->btnSelectEmployee, &QPushButton::clicked, this, &ComputerDialog::onSelectEmployee);
    connect(ui->btnClearEmployee, &QPushButton::clicked, this, &ComputerDialog::onClearEmployee);
}

ComputerDialog::~ComputerDialog()
{
    delete ui;
}

void ComputerDialog::setEditMode(int compId, const QString& processor, const QString& video_card,
                                 int ram, const QString& screen, const QString& keyboard,
                                 const QString& mouse, int id_emp, const QString& employeeName)
{
    isEditMode = true;
    currentCompId = compId;
    selectedEmpId = id_emp;
    selectedEmployeeName = employeeName;
    setWindowTitle("Редактирование компьютера");

    ui->editProcessor->setText(processor);
    ui->editVideoCard->setText(video_card);
    ui->editRam->setText(QString::number(ram));
    ui->editScreen->setText(screen);
    ui->editKeyboard->setText(keyboard);
    ui->editMouse->setText(mouse);
    ui->editEmployeeFullName->setText(employeeName);
}

void ComputerDialog::setAddMode()
{
    isEditMode = false;
    currentCompId = -1;
    selectedEmpId = -1;
    selectedEmployeeName.clear();
    setWindowTitle("Добавление компьютера");

    ui->editProcessor->clear();
    ui->editVideoCard->clear();
    ui->editRam->clear();
    ui->editScreen->clear();
    ui->editKeyboard->clear();
    ui->editMouse->clear();
    ui->editEmployeeFullName->clear();
}

int ComputerDialog::getCompId() const
{
    return currentCompId;
}

QString ComputerDialog::getProcessor() const
{
    return ui->editProcessor->text().trimmed();
}

QString ComputerDialog::getVideoCard() const
{
    return ui->editVideoCard->text().trimmed();
}

int ComputerDialog::getRam() const
{
    return ui->editRam->text().toInt();
}

QString ComputerDialog::getScreen() const
{
    return ui->editScreen->text().trimmed();
}

QString ComputerDialog::getKeyboard() const
{
    return ui->editKeyboard->text().trimmed();
}

QString ComputerDialog::getMouse() const
{
    return ui->editMouse->text().trimmed();
}

int ComputerDialog::getEmpId() const
{
    return selectedEmpId;
}

void ComputerDialog::onSelectEmployee()
{
    EmployeeSearchDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        selectedEmpId = dialog.getSelectedId();
        selectedEmployeeName = dialog.getSelectedFullName();
        ui->editEmployeeFullName->setText(selectedEmployeeName);
    }
}

void ComputerDialog::onClearEmployee()
{
    selectedEmpId = -1;
    selectedEmployeeName.clear();
    ui->editEmployeeFullName->clear();
}

void ComputerDialog::onSaveClicked()
{
    if (getProcessor().isEmpty() && getVideoCard().isEmpty()) {
        return;
    }
    accept();
}

void ComputerDialog::onCancelClicked()
{
    reject();
}
#include "employee_search_dialog.h"
#include "ui_employee_search_dialog.h"
#include "database.h"
#include <QTableWidgetItem>
#include <QHeaderView>

EmployeeSearchDialog::EmployeeSearchDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmployeeSearchDialog)
    , selectedId(-1)
{
    ui->setupUi(this);

    loadEmployees();

    ui->tableEmployees->horizontalHeader()->setStretchLastSection(true);

    connect(ui->btnSearch, &QPushButton::clicked, this, &EmployeeSearchDialog::onSearchClicked);
    connect(ui->btnSelect, &QPushButton::clicked, this, &EmployeeSearchDialog::onSelectClicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->tableEmployees, &QTableWidget::itemSelectionChanged,
            this, &EmployeeSearchDialog::onTableSelectionChanged);
    connect(ui->lineEditSearch, &QLineEdit::returnPressed, this, &EmployeeSearchDialog::onSearchClicked);
}

EmployeeSearchDialog::~EmployeeSearchDialog()
{
    delete ui;
}

void EmployeeSearchDialog::loadEmployees(const QString& searchText)
{
    ui->tableEmployees->setRowCount(0);

    QSqlQuery query;

    if (searchText.isEmpty()) {
        query = Database::getAllEmployees();
    } else {
        QString pattern = "%" + searchText + "%";
        query.prepare("SELECT id_emp, name, surname, patronimic, post FROM employee "
                      "WHERE name ILIKE ? OR surname ILIKE ? OR patronimic ILIKE ? "
                      "OR post ILIKE ? OR CAST(id_emp AS TEXT) ILIKE ? "
                      "ORDER BY surname");
        query.addBindValue(pattern);
        query.addBindValue(pattern);
        query.addBindValue(pattern);
        query.addBindValue(pattern);
        query.addBindValue(pattern);
        query.exec();
    }

    int row = 0;
    while (query.next()) {
        ui->tableEmployees->insertRow(row);
        ui->tableEmployees->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableEmployees->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->tableEmployees->setItem(row, 2, new QTableWidgetItem(query.value(1).toString()));
        ui->tableEmployees->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableEmployees->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        row++;
    }

    for (int i = 0; i < ui->tableEmployees->columnCount() - 1; i++) {
        ui->tableEmployees->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }
    ui->tableEmployees->horizontalHeader()->setSectionResizeMode(ui->tableEmployees->columnCount() - 1, QHeaderView::Stretch);
}

void EmployeeSearchDialog::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);

    int totalWidth = ui->tableEmployees->width();
    if (totalWidth > 0) {
        ui->tableEmployees->setColumnWidth(0, totalWidth * 0.05);
        ui->tableEmployees->setColumnWidth(1, totalWidth * 0.20);
        ui->tableEmployees->setColumnWidth(2, totalWidth * 0.15);
        ui->tableEmployees->setColumnWidth(3, totalWidth * 0.20);
        ui->tableEmployees->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    }
}

void EmployeeSearchDialog::onSearchClicked()
{
    QString searchText = ui->lineEditSearch->text().trimmed();
    loadEmployees(searchText);
}

void EmployeeSearchDialog::onSelectClicked()
{
    if (selectedId != -1) {
        accept();
    }
}

void EmployeeSearchDialog::onTableSelectionChanged()
{
    QList<QTableWidgetItem*> items = ui->tableEmployees->selectedItems();
    if (!items.isEmpty()) {
        int row = items.first()->row();
        selectedId = ui->tableEmployees->item(row, 0)->text().toInt();
        QString surname = ui->tableEmployees->item(row, 1)->text();
        QString name = ui->tableEmployees->item(row, 2)->text();
        QString patronimic = ui->tableEmployees->item(row, 3)->text();
        selectedFullName = QString("%1 %2 %3").arg(surname, name, patronimic).simplified();
    }
}
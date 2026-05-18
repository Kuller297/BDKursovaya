#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QTableWidgetItem>
#include <QMessageBox>

SearchDialog::SearchDialog(QTableWidget *table, const QStringList &headers, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
    , targetTable(table)
    , columnHeaders(headers)
{
    ui->setupUi(this);

    ui->comboColumn->addItems(headers);

    connect(ui->btnSearch, &QPushButton::clicked, this, &SearchDialog::onSearchClicked);
    connect(ui->btnClear, &QPushButton::clicked, this, &SearchDialog::onClearClicked);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::onSearchClicked()
{
    performSearch();
}

void SearchDialog::onClearClicked()
{
    ui->lineEditSearch->clear();
    ui->comboColumn->setCurrentIndex(0);

    for (int row = 0; row < targetTable->rowCount(); row++) {
        targetTable->setRowHidden(row, false);
    }

    QMessageBox::information(this, "Поиск", "Результаты поиска очищены");
}

void SearchDialog::performSearch()
{
    QString searchText = ui->lineEditSearch->text().trimmed();
    int column = ui->comboColumn->currentIndex();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Поиск", "Введите текст для поиска!");
        return;
    }

    int foundCount = 0;

    for (int row = 0; row < targetTable->rowCount(); row++) {
        QTableWidgetItem *item = targetTable->item(row, column);
        if (item && item->text().contains(searchText, Qt::CaseInsensitive)) {
            targetTable->setRowHidden(row, false);
            foundCount++;
        } else {
            targetTable->setRowHidden(row, true);
        }
    }

    if (foundCount == 0) {
        QMessageBox::information(this, "Поиск", "Ничего не найдено");
    } else {
        QMessageBox::information(this, "Поиск", QString("Найдено записей: %1").arg(foundCount));
    }
}
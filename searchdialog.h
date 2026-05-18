#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QTableWidget *table, const QStringList &headers, QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void onSearchClicked();
    void onClearClicked();

private:
    void performSearch();

    Ui::SearchDialog *ui;
    QTableWidget *targetTable;
    QStringList columnHeaders;
};

#endif // SEARCHDIALOG_H
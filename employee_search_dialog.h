#ifndef EMPLOYEE_SEARCH_DIALOG_H
#define EMPLOYEE_SEARCH_DIALOG_H

#include <QDialog>
#include <QResizeEvent>

namespace Ui {
class EmployeeSearchDialog;
}

class EmployeeSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeSearchDialog(QWidget *parent = nullptr);
    ~EmployeeSearchDialog();

    int getSelectedId() const { return selectedId; }
    QString getSelectedFullName() const { return selectedFullName; }

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onSearchClicked();
    void onSelectClicked();
    void onTableSelectionChanged();

private:
    void loadEmployees(const QString& searchText = "");

    Ui::EmployeeSearchDialog *ui;
    int selectedId;
    QString selectedFullName;
};

#endif // EMPLOYEE_SEARCH_DIALOG_H
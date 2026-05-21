#ifndef EMPLOYEE_DIALOG_H
#define EMPLOYEE_DIALOG_H

#include <QDialog>

namespace Ui {
class EmployeeDialog;
}

class EmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeDialog(QWidget *parent = nullptr);
    ~EmployeeDialog();

    void setEditMode(int empId, const QString& name, const QString& surname,
                     const QString& patronimic, const QString& post,
                     const QString& telephone, const QString& adress,
                     const QString& login, const QString& password, const QString& role);
    void setAddMode();

    int getEmpId() const;
    QString getName() const;
    QString getSurname() const;
    QString getPatronimic() const;
    QString getPost() const;
    QString getTelephone() const;
    QString getAdress() const;
    QString getLogin() const;
    QString getPassword() const;
    QString getRole() const;

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    Ui::EmployeeDialog *ui;
    int currentEmpId;
    bool isEditMode;
};

#endif // EMPLOYEE_DIALOG_H
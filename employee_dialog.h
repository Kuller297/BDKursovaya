#ifndef EMPLOYEEDIALOG_H
#define EMPLOYEEDIALOG_H

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

    void setEditMode(int empId, const QString& name, const QString& surname,const QString& patronimic, const QString& post,const QString& telephone, const QString& adress, int userId);
    void setAddMode();

    int getEmpId() const;
    QString getName() const;
    QString getSurname() const;
    QString getPatronimic() const;
    QString getPost() const;
    QString getTelephone() const;
    QString getAdress() const;
    int getUserId() const;

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    Ui::EmployeeDialog *ui;
    int currentEmpId;
    bool isEditMode;
};

#endif // EMPLOYEEDIALOG_H
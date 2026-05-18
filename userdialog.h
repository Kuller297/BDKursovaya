#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = nullptr);
    ~UserDialog();

    void setEditMode(int userId, const QString& login, const QString& password, const QString& role);
    void setAddMode();

    QString getLogin() const;
    QString getPassword() const;
    QString getRole() const;
    int getUserId() const;

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    Ui::UserDialog *ui;
    int currentUserId;
    bool isEditMode;
};

#endif // USERDIALOG_H
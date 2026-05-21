#ifndef COMPUTERDIALOG_H
#define COMPUTERDIALOG_H

#include <QDialog>

namespace Ui {
class ComputerDialog;
}

class ComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerDialog(QWidget *parent = nullptr);
    ~ComputerDialog();

    void setEditMode(int compId, const QString& processor, const QString& video_card,
                     int ram, const QString& screen, const QString& keyboard,
                     const QString& mouse, int id_emp, const QString& employeeName);
    void setAddMode();

    int getCompId() const;
    QString getProcessor() const;
    QString getVideoCard() const;
    int getRam() const;
    QString getScreen() const;
    QString getKeyboard() const;
    QString getMouse() const;
    int getEmpId() const;

private slots:
    void onSaveClicked();
    void onCancelClicked();
    void onSelectEmployee();
    void onClearEmployee();

private:
    Ui::ComputerDialog *ui;
    int currentCompId;
    int selectedEmpId;
    QString selectedEmployeeName;
    bool isEditMode;
};

#endif // COMPUTERDIALOG_H
#ifndef SOFTWAREDIALOG_H
#define SOFTWAREDIALOG_H

#include <QDialog>

namespace Ui {
class SoftwareDialog;
}

class SoftwareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SoftwareDialog(QWidget *parent = nullptr);
    ~SoftwareDialog();

    void setEditMode(int softId, const QString& soft_name, const QString& version);
    void setAddMode();

    int getSoftId() const;
    QString getSoftName() const;
    QString getVersion() const;

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    Ui::SoftwareDialog *ui;
    int currentSoftId;
    bool isEditMode;
};

#endif // SOFTWAREDIALOG_H
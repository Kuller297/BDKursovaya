#ifndef LICENSEDIALOG_H
#define LICENSEDIALOG_H

#include <QDialog>

namespace Ui {
class LicenseDialog;
}

class LicenseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LicenseDialog(QWidget *parent = nullptr);
    ~LicenseDialog();

    void setEditMode(int licId, const QString& end_date, int id_soft, const QString& key);
    void setAddMode();

    int getLicId() const;
    QString getEndDate() const;
    int getIdSoft() const;
    QString getKey() const;

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    bool validateDate(const QString& date);

    Ui::LicenseDialog *ui;
    int currentLicId;
    bool isEditMode;
};

#endif // LICENSEDIALOG_H
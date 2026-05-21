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

    void setEditMode(int licId, const QString& end_date, const QString& soft_name,
                     const QString& soft_version, const QString& key);
    void setAddMode();

    int getLicId() const;
    QString getEndDate() const;
    QString getSoftName() const;
    QString getSoftVersion() const;
    QString getKey() const;
    int getSoftId();

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    bool validateDate(const QString& date);
    int findSoftwareId(const QString& name, const QString& version);

    Ui::LicenseDialog *ui;
    int currentLicId;
    bool isEditMode;
};

#endif // LICENSEDIALOG_H
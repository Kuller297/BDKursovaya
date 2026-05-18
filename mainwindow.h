#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString& userPost, const QString& username, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onAddUser();
    void onEditUser();
    void onDeleteUser();
    void onSearchUsers();

    void onAddEmployee();
    void onEditEmployee();
    void onDeleteEmployee();
    void onSearchEmployees();

    void onAddComputer();
    void onEditComputer();
    void onDeleteComputer();
    void onSearchComputers();

    void onAddSoftware();
    void onEditSoftware();
    void onDeleteSoftware();
    void onSearchSoftware();

    void onAddLicense();
    void onEditLicense();
    void onDeleteLicense();
    void onSearchLicenses();

private:
    void loadUsers();
    void loadEmployees();
    void loadComputers();
    void loadSoftware();
    void loadLicenses();
    void setupPermissions();
    void setupTable(QTableWidget *table);
    void setupUserButtons();
    void setupEmployeeButtons();
    void setupComputerButtons();
    void setupSoftwareButtons();
    void setupLicenseButtons();
    void stretchAllTables();
    void stretchTableColumns(QTableWidget *table);

    Ui::MainWindow *ui;

    QString currentUserPost;
    QString currentUsername;
    int selectedUserId;
    int selectedEmpId;
    int selectedCompId;
    int selectedSoftId;
    int selectedLicId;
};

#endif // MAINWINDOW_H
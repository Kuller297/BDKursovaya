#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "employee_dialog.h"
#include "computer_dialog.h"
#include "software_dialog.h"
#include "license_dialog.h"
#include "searchdialog.h"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMessageBox>

MainWindow::MainWindow(const QString& userPost, const QString& username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentUserPost(userPost.trimmed())
    , currentUsername(username)
    , selectedUserId(-1)
    , selectedEmpId(-1)
    , selectedCompId(-1)
    , selectedSoftId(-1)
    , selectedLicId(-1)
{
    ui->setupUi(this);
    setupPermissions();

    setupTable(ui->tableUsers);
    setupTable(ui->tableEmployees);
    setupTable(ui->tableComputers);
    setupTable(ui->tableSoftware);
    setupTable(ui->tableLicenses);

    setupUserButtons();
    setupEmployeeButtons();
    setupComputerButtons();
    setupSoftwareButtons();
    setupLicenseButtons();

    connect(ui->tableUsers, &QTableWidget::itemSelectionChanged, this, [this]() {
        QList<QTableWidgetItem*> items = ui->tableUsers->selectedItems();
        selectedUserId = items.isEmpty() ? -1 : ui->tableUsers->item(items.first()->row(), 0)->text().toInt();
    });

    connect(ui->tableEmployees, &QTableWidget::itemSelectionChanged, this, [this]() {
        QList<QTableWidgetItem*> items = ui->tableEmployees->selectedItems();
        selectedEmpId = items.isEmpty() ? -1 : ui->tableEmployees->item(items.first()->row(), 0)->text().toInt();
    });

    connect(ui->tableComputers, &QTableWidget::itemSelectionChanged, this, [this]() {
        QList<QTableWidgetItem*> items = ui->tableComputers->selectedItems();
        selectedCompId = items.isEmpty() ? -1 : ui->tableComputers->item(items.first()->row(), 0)->text().toInt();
    });

    connect(ui->tableSoftware, &QTableWidget::itemSelectionChanged, this, [this]() {
        QList<QTableWidgetItem*> items = ui->tableSoftware->selectedItems();
        selectedSoftId = items.isEmpty() ? -1 : ui->tableSoftware->item(items.first()->row(), 0)->text().toInt();
    });

    connect(ui->tableLicenses, &QTableWidget::itemSelectionChanged, this, [this]() {
        QList<QTableWidgetItem*> items = ui->tableLicenses->selectedItems();
        selectedLicId = items.isEmpty() ? -1 : ui->tableLicenses->item(items.first()->row(), 0)->text().toInt();
    });

    loadUsers();
    loadEmployees();
    loadComputers();
    loadSoftware();
    loadLicenses();

    stretchAllTables();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUserButtons()
{
    QWidget *buttonWidget = new QWidget();
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton *btnRefresh = new QPushButton("Обновить");
    QPushButton *btnSearch = new QPushButton("Поиск");

    buttonLayout->addWidget(btnRefresh);
    buttonLayout->addWidget(btnSearch);
    buttonLayout->addStretch();

    QVBoxLayout *userLayout = qobject_cast<QVBoxLayout*>(ui->tabUsers->layout());
    if (userLayout) {
        userLayout->addWidget(buttonWidget);
    }

    connect(btnRefresh, &QPushButton::clicked, this, &MainWindow::loadUsers);
    connect(btnSearch, &QPushButton::clicked, this, &MainWindow::onSearchUsers);
}

void MainWindow::setupEmployeeButtons()
{
    QWidget *buttonWidget = new QWidget();
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton *btnAdd = new QPushButton("Добавить");
    QPushButton *btnEdit = new QPushButton("Редактировать");
    QPushButton *btnDelete = new QPushButton("Удалить");
    QPushButton *btnRefresh = new QPushButton("Обновить");
    QPushButton *btnSearch = new QPushButton("Поиск");

    buttonLayout->addWidget(btnAdd);
    buttonLayout->addWidget(btnEdit);
    buttonLayout->addWidget(btnDelete);
    buttonLayout->addWidget(btnRefresh);
    buttonLayout->addWidget(btnSearch);
    buttonLayout->addStretch();

    QVBoxLayout *employeeLayout = qobject_cast<QVBoxLayout*>(ui->tabEmployees->layout());
    if (employeeLayout) {
        employeeLayout->addWidget(buttonWidget);
    }

    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::onAddEmployee);
    connect(btnEdit, &QPushButton::clicked, this, &MainWindow::onEditEmployee);
    connect(btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteEmployee);
    connect(btnRefresh, &QPushButton::clicked, this, &MainWindow::loadEmployees);
    connect(btnSearch, &QPushButton::clicked, this, &MainWindow::onSearchEmployees);
}

void MainWindow::setupComputerButtons()
{
    QWidget *buttonWidget = new QWidget();
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton *btnAdd = new QPushButton("Добавить");
    QPushButton *btnEdit = new QPushButton("Редактировать");
    QPushButton *btnDelete = new QPushButton("Удалить");
    QPushButton *btnRefresh = new QPushButton("Обновить");
    QPushButton *btnSearch = new QPushButton("Поиск");

    buttonLayout->addWidget(btnAdd);
    buttonLayout->addWidget(btnEdit);
    buttonLayout->addWidget(btnDelete);
    buttonLayout->addWidget(btnRefresh);
    buttonLayout->addWidget(btnSearch);
    buttonLayout->addStretch();

    QVBoxLayout *computerLayout = qobject_cast<QVBoxLayout*>(ui->tabComputers->layout());
    if (computerLayout) {
        computerLayout->addWidget(buttonWidget);
    }

    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::onAddComputer);
    connect(btnEdit, &QPushButton::clicked, this, &MainWindow::onEditComputer);
    connect(btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteComputer);
    connect(btnRefresh, &QPushButton::clicked, this, &MainWindow::loadComputers);
    connect(btnSearch, &QPushButton::clicked, this, &MainWindow::onSearchComputers);
}

void MainWindow::setupSoftwareButtons()
{
    QWidget *buttonWidget = new QWidget();
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton *btnAdd = new QPushButton("Добавить");
    QPushButton *btnEdit = new QPushButton("Редактировать");
    QPushButton *btnDelete = new QPushButton("Удалить");
    QPushButton *btnRefresh = new QPushButton("Обновить");
    QPushButton *btnSearch = new QPushButton("Поиск");

    buttonLayout->addWidget(btnAdd);
    buttonLayout->addWidget(btnEdit);
    buttonLayout->addWidget(btnDelete);
    buttonLayout->addWidget(btnRefresh);
    buttonLayout->addWidget(btnSearch);
    buttonLayout->addStretch();

    QVBoxLayout *softwareLayout = qobject_cast<QVBoxLayout*>(ui->tabSoftware->layout());
    if (softwareLayout) {
        softwareLayout->addWidget(buttonWidget);
    }

    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::onAddSoftware);
    connect(btnEdit, &QPushButton::clicked, this, &MainWindow::onEditSoftware);
    connect(btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteSoftware);
    connect(btnRefresh, &QPushButton::clicked, this, &MainWindow::loadSoftware);
    connect(btnSearch, &QPushButton::clicked, this, &MainWindow::onSearchSoftware);
}

void MainWindow::setupLicenseButtons()
{
    QWidget *buttonWidget = new QWidget();
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton *btnAdd = new QPushButton("Добавить");
    QPushButton *btnEdit = new QPushButton("Редактировать");
    QPushButton *btnDelete = new QPushButton("Удалить");
    QPushButton *btnRefresh = new QPushButton("Обновить");
    QPushButton *btnSearch = new QPushButton("Поиск");

    buttonLayout->addWidget(btnAdd);
    buttonLayout->addWidget(btnEdit);
    buttonLayout->addWidget(btnDelete);
    buttonLayout->addWidget(btnRefresh);
    buttonLayout->addWidget(btnSearch);
    buttonLayout->addStretch();

    QVBoxLayout *licenseLayout = qobject_cast<QVBoxLayout*>(ui->tabLicenses->layout());
    if (licenseLayout) {
        licenseLayout->addWidget(buttonWidget);
    }

    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::onAddLicense);
    connect(btnEdit, &QPushButton::clicked, this, &MainWindow::onEditLicense);
    connect(btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteLicense);
    connect(btnRefresh, &QPushButton::clicked, this, &MainWindow::loadLicenses);
    connect(btnSearch, &QPushButton::clicked, this, &MainWindow::onSearchLicenses);
}

void MainWindow::onSearchUsers()
{
    QStringList headers;
    for (int i = 0; i < ui->tableUsers->columnCount(); i++) {
        headers << ui->tableUsers->horizontalHeaderItem(i)->text();
    }
    SearchDialog dialog(ui->tableUsers, headers, this);
    dialog.exec();
}

void MainWindow::onSearchEmployees()
{
    QStringList headers;
    for (int i = 0; i < ui->tableEmployees->columnCount(); i++) {
        headers << ui->tableEmployees->horizontalHeaderItem(i)->text();
    }
    SearchDialog dialog(ui->tableEmployees, headers, this);
    dialog.exec();
}

void MainWindow::onSearchComputers()
{
    QStringList headers;
    for (int i = 0; i < ui->tableComputers->columnCount(); i++) {
        headers << ui->tableComputers->horizontalHeaderItem(i)->text();
    }
    SearchDialog dialog(ui->tableComputers, headers, this);
    dialog.exec();
}

void MainWindow::onSearchSoftware()
{
    QStringList headers;
    for (int i = 0; i < ui->tableSoftware->columnCount(); i++) {
        headers << ui->tableSoftware->horizontalHeaderItem(i)->text();
    }
    SearchDialog dialog(ui->tableSoftware, headers, this);
    dialog.exec();
}

void MainWindow::onSearchLicenses()
{
    QStringList headers;
    for (int i = 0; i < ui->tableLicenses->columnCount(); i++) {
        headers << ui->tableLicenses->horizontalHeaderItem(i)->text();
    }
    SearchDialog dialog(ui->tableLicenses, headers, this);
    dialog.exec();
}

void MainWindow::setupTable(QTableWidget *table)
{
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
}

void MainWindow::stretchAllTables()
{
    if (currentUserPost == "main_admin") {
        stretchTableColumns(ui->tableUsers);
    }
    stretchTableColumns(ui->tableEmployees);
    stretchTableColumns(ui->tableComputers);
    stretchTableColumns(ui->tableSoftware);
    stretchTableColumns(ui->tableLicenses);
}

void MainWindow::stretchTableColumns(QTableWidget *table)
{
    if (!table || table->columnCount() == 0) return;

    QHeaderView *header = table->horizontalHeader();
    for (int i = 0; i < table->columnCount(); i++) {
        header->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    stretchAllTables();
}

void MainWindow::setupPermissions()
{
    if (currentUserPost != "main_admin") {
        int userTabIndex = ui->tabWidget->indexOf(ui->tabUsers);
        if (userTabIndex != -1) {
            ui->tabWidget->removeTab(userTabIndex);
        }
        ui->tabWidget->setCurrentIndex(0);
    }
}

void MainWindow::loadUsers()
{
    if (currentUserPost != "main_admin") return;

    ui->tableUsers->setRowCount(0);

    QSqlQuery query = Database::getAllUsers();

    int row = 0;
    while (query.next()) {
        ui->tableUsers->insertRow(row);
        ui->tableUsers->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableUsers->setItem(row, 1, new QTableWidgetItem(query.value(4).toString()));
        ui->tableUsers->setItem(row, 2, new QTableWidgetItem(query.value(1).toString()));
        ui->tableUsers->setItem(row, 3, new QTableWidgetItem(query.value(2).toString()));
        ui->tableUsers->setItem(row, 4, new QTableWidgetItem(query.value(3).toString()));
        row++;
    }

    selectedUserId = -1;
}

void MainWindow::loadEmployees()
{
    ui->tableEmployees->setRowCount(0);

    QSqlQuery query = Database::getAllEmployees();

    int row = 0;
    while (query.next()) {
        ui->tableEmployees->insertRow(row);
        ui->tableEmployees->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableEmployees->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableEmployees->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableEmployees->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableEmployees->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->tableEmployees->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        ui->tableEmployees->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
        ui->tableEmployees->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
        row++;
    }

    selectedEmpId = -1;
}

void MainWindow::loadComputers()
{
    ui->tableComputers->setRowCount(0);

    QSqlQuery query = Database::getAllComputers();

    int row = 0;
    while (query.next()) {
        ui->tableComputers->insertRow(row);
        ui->tableComputers->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableComputers->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableComputers->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableComputers->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableComputers->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->tableComputers->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        ui->tableComputers->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
        ui->tableComputers->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
        row++;
    }

    selectedCompId = -1;
}

void MainWindow::loadSoftware()
{
    ui->tableSoftware->setRowCount(0);

    QSqlQuery query = Database::getAllSoftware();

    int row = 0;
    while (query.next()) {
        ui->tableSoftware->insertRow(row);
        ui->tableSoftware->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableSoftware->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableSoftware->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        row++;
    }

    selectedSoftId = -1;
}

void MainWindow::loadLicenses()
{
    ui->tableLicenses->setRowCount(0);

    QSqlQuery query = Database::getAllLicenses();

    int row = 0;
    while (query.next()) {
        ui->tableLicenses->insertRow(row);
        ui->tableLicenses->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableLicenses->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableLicenses->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableLicenses->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        row++;
    }

    selectedLicId = -1;
}

void MainWindow::onAddEmployee()
{
    if (currentUserPost != "main_admin") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для добавления сотрудников!");
        return;
    }

    EmployeeDialog dialog(this);
    dialog.setAddMode();

    if (dialog.exec() == QDialog::Accepted) {
        if (Database::addEmployee(dialog.getName(), dialog.getSurname(), dialog.getPatronimic(),dialog.getPost(), dialog.getTelephone(), dialog.getAdress(),dialog.getLogin(), dialog.getPassword(), dialog.getRole())) {
            QMessageBox::information(this, "Успех", "Сотрудник и учётная запись добавлены!");
            loadEmployees();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить сотрудника!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onEditEmployee()
{
    if (currentUserPost != "main_admin") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для редактирования сотрудников!");
        return;
    }

    if (selectedEmpId == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите сотрудника для редактирования!");
        return;
    }

    int row = -1;
    for (int i = 0; i < ui->tableEmployees->rowCount(); i++) {
        if (ui->tableEmployees->item(i, 0)->text().toInt() == selectedEmpId) {
            row = i;
            break;
        }
    }

    if (row == -1) return;

    QString name = ui->tableEmployees->item(row, 1)->text();
    QString surname = ui->tableEmployees->item(row, 2)->text();
    QString patronimic = ui->tableEmployees->item(row, 3)->text();
    QString post = ui->tableEmployees->item(row, 4)->text();
    QString telephone = ui->tableEmployees->item(row, 5)->text();
    QString adress = ui->tableEmployees->item(row, 6)->text();
    QString role = ui->tableEmployees->item(row, 7)->text();

    QString login;
    QString password;

    QSqlQuery query = Database::getEmployeeByUserId(selectedEmpId);
    if (query.next()) {
        int userId = query.value(0).toInt();
        QSqlQuery userQuery = Database::getUserById(userId);
        if (userQuery.next()) {
            login = userQuery.value(0).toString();
            password = userQuery.value(1).toString();
        }
    }

    EmployeeDialog dialog(this);
    dialog.setEditMode(selectedEmpId, name, surname, patronimic, post, telephone, adress, login, password, role);

    if (dialog.exec() == QDialog::Accepted) {
        if (Database::updateEmployee(selectedEmpId,dialog.getName(), dialog.getSurname(), dialog.getPatronimic(),dialog.getPost(), dialog.getTelephone(), dialog.getAdress(),dialog.getLogin(), dialog.getPassword(), dialog.getRole())) {
            QMessageBox::information(this, "Успех", "Сотрудник и учётная запись обновлены!");
            loadEmployees();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось обновить сотрудника!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onDeleteEmployee()
{
    if (currentUserPost != "main_admin") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для удаления сотрудников!");
        return;
    }

    if (selectedEmpId == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите сотрудника для удаления!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение",
                                                              "Вы уверены, что хотите удалить этого сотрудника?\nУчётная запись пользователя также будет удалена.",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Database::deleteEmployee(selectedEmpId)) {
            QMessageBox::information(this, "Успех", "Сотрудник и его учётная запись удалены!");
            loadEmployees();
            selectedEmpId = -1;
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось удалить сотрудника!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onAddComputer()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для добавления компьютеров!");
        return;
    }

    ComputerDialog dialog(this);
    dialog.setAddMode();

    if (dialog.exec() == QDialog::Accepted) {
        if (Database::addComputer(dialog.getProcessor(), dialog.getVideoCard(), dialog.getRam(),
                                  dialog.getScreen(), dialog.getKeyboard(), dialog.getMouse(),
                                  dialog.getEmpId())) {
            QMessageBox::information(this, "Успех", "Компьютер добавлен!");
            loadComputers();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить компьютер!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onEditComputer()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для редактирования компьютеров!");
        return;
    }

    if (selectedCompId == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите компьютер для редактирования!");
        return;
    }

    int row = -1;
    for (int i = 0; i < ui->tableComputers->rowCount(); i++) {
        if (ui->tableComputers->item(i, 0)->text().toInt() == selectedCompId) {
            row = i;
            break;
        }
    }

    if (row == -1) return;

    ComputerDialog dialog(this);

    int id_emp = -1;
    QString employeeName = ui->tableComputers->item(row, 7)->text();
    if (employeeName != "Не назначен") {
        QSqlQuery query = Database::getAllEmployees();
        while (query.next()) {
            QString fullName = QString("%1 %2 %3")
            .arg(query.value(2).toString(),
                 query.value(1).toString(),
                 query.value(3).toString())
                .simplified();
            if (fullName == employeeName) {
                id_emp = query.value(0).toInt();
                break;
            }
        }
    }

    dialog.setEditMode(selectedCompId,
                       ui->tableComputers->item(row, 1)->text(),
                       ui->tableComputers->item(row, 2)->text(),
                       ui->tableComputers->item(row, 3)->text().toInt(),
                       ui->tableComputers->item(row, 4)->text(),
                       ui->tableComputers->item(row, 5)->text(),
                       ui->tableComputers->item(row, 6)->text(),
                       id_emp, employeeName);

    if (dialog.exec() == QDialog::Accepted) {
        if (Database::updateComputer(selectedCompId, dialog.getProcessor(), dialog.getVideoCard(), dialog.getRam(),
                                     dialog.getScreen(), dialog.getKeyboard(), dialog.getMouse(),
                                     dialog.getEmpId())) {
            QMessageBox::information(this, "Успех", "Компьютер обновлен!");
            loadComputers();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось обновить компьютер!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onDeleteComputer()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для удаления компьютеров!");
        return;
    }

    if (selectedCompId == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите компьютер для удаления!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить этот компьютер?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Database::deleteComputer(selectedCompId)) {
            QMessageBox::information(this, "Успех", "Компьютер удален!");
            loadComputers();
            selectedCompId = -1;
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось удалить компьютер!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onAddSoftware()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для добавления ПО!");
        return;
    }

    SoftwareDialog dialog(this);
    dialog.setAddMode();

    if (dialog.exec() == QDialog::Accepted) {
        if (Database::addSoftware(dialog.getSoftName(), dialog.getVersion())) {
            QMessageBox::information(this, "Успех", "ПО добавлено!");
            loadSoftware();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить ПО!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onEditSoftware()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для редактирования ПО!");
        return;
    }

    if (selectedSoftId == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите ПО для редактирования!");
        return;
    }

    int row = -1;
    for (int i = 0; i < ui->tableSoftware->rowCount(); i++) {
        if (ui->tableSoftware->item(i, 0)->text().toInt() == selectedSoftId) {
            row = i;
            break;
        }
    }

    if (row == -1) return;

    SoftwareDialog dialog(this);
    dialog.setEditMode(selectedSoftId,
                       ui->tableSoftware->item(row, 1)->text(),
                       ui->tableSoftware->item(row, 2)->text());

    if (dialog.exec() == QDialog::Accepted) {
        if (Database::updateSoftware(selectedSoftId, dialog.getSoftName(), dialog.getVersion())) {
            QMessageBox::information(this, "Успех", "ПО обновлено!");
            loadSoftware();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось обновить ПО!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onDeleteSoftware()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для удаления ПО!");
        return;
    }

    if (selectedSoftId == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите ПО для удаления!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить это ПО?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Database::deleteSoftware(selectedSoftId)) {
            QMessageBox::information(this, "Успех", "ПО удалено!");
            loadSoftware();
            selectedSoftId = -1;
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось удалить ПО!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onAddLicense()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для добавления лицензий!");
        return;
    }

    LicenseDialog dialog(this);
    dialog.setAddMode();

    if (dialog.exec() == QDialog::Accepted) {
        int softId = dialog.getSoftId();
        if (softId == -1) {
            QMessageBox::critical(this, "Ошибка", "Программа не найдена!");
            return;
        }

        if (Database::addLicense(dialog.getEndDate(), softId, dialog.getKey())) {
            QMessageBox::information(this, "Успех", "Лицензия добавлена!");
            loadLicenses();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить лицензию!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onEditLicense()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для редактирования лицензий!");
        return;
    }

    if (selectedLicId == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите лицензию для редактирования!");
        return;
    }

    int row = -1;
    for (int i = 0; i < ui->tableLicenses->rowCount(); i++) {
        if (ui->tableLicenses->item(i, 0)->text().toInt() == selectedLicId) {
            row = i;
            break;
        }
    }

    if (row == -1) return;

    LicenseDialog dialog(this);
    dialog.setEditMode(selectedLicId,
                       ui->tableLicenses->item(row, 1)->text(),
                       ui->tableLicenses->item(row, 2)->text(),
                       "", // версию нужно тоже хранить или получать отдельно
                       ui->tableLicenses->item(row, 3)->text());

    if (dialog.exec() == QDialog::Accepted) {
        int softId = dialog.getSoftId();
        if (softId == -1) {
            QMessageBox::critical(this, "Ошибка", "Программа не найдена!");
            return;
        }

        if (Database::updateLicense(selectedLicId, dialog.getEndDate(), softId, dialog.getKey())) {
            QMessageBox::information(this, "Успех", "Лицензия обновлена!");
            loadLicenses();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось обновить лицензию!\n" + Database::getLastError());
        }
    }
}

void MainWindow::onDeleteLicense()
{
    if (currentUserPost == "user") {
        QMessageBox::warning(this, "Доступ запрещён", "У вас недостаточно прав для удаления лицензий!");
        return;
    }

    if (selectedLicId == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите лицензию для удаления!");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить эту лицензию?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Database::deleteLicense(selectedLicId)) {
            QMessageBox::information(this, "Успех", "Лицензия удалена!");
            loadLicenses();
            selectedLicId = -1;
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось удалить лицензию!\n" + Database::getLastError());
        }
    }
}
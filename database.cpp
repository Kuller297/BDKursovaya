#include "database.h"

QSqlDatabase Database::db;
QString Database::lastError;

bool Database::connect()
{
    if (Database::db.isOpen()) {
        Database::db.close();
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    QString connectionString = QString(
        "DRIVER={PostgreSQL ODBC Driver(UNICODE)};"
        "SERVER=localhost;"
        "PORT=5432;"
        "DATABASE=Kursovaya;"
        "UID=postgres;"
        "PWD=!oO1254Oo!;"
        "SSLmode=disable;"
        );

    db.setDatabaseName(connectionString);

    if (!db.open()) {
        lastError = db.lastError().text();
        return false;
    }

    Database::db = db;
    return true;
}

void Database::disconnect()
{
    if (Database::db.isOpen()) {
        Database::db.close();
    }
}

QString Database::getLastError()
{
    return lastError;
}

bool Database::checkUser(const QString& login, const QString& password, QString& user_post)
{
    if (!Database::db.isOpen()) {
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("SELECT user_post FROM \"user\" WHERE login = ? AND password = ?");
    query.addBindValue(login);
    query.addBindValue(password);

    if (!query.exec()) {
        return false;
    }

    if (query.next()) {
        user_post = query.value(0).toString();
        return true;
    }

    return false;
}

QSqlQuery Database::getAllUsers()
{
    QSqlQuery query(Database::db);
    if (!Database::db.isOpen()) {
        return query;
    }

    query.exec("SELECT user_id, login, password, user_post FROM \"user\" ORDER BY user_id");
    return query;
}

bool Database::addUser(const QString& login, const QString& password, const QString& user_post)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO \"user\" (login, password, user_post) VALUES (?, ?, ?)");
    query.addBindValue(login);
    query.addBindValue(password);
    query.addBindValue(user_post);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::updateUser(int user_id, const QString& login, const QString& password, const QString& user_post)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("UPDATE \"user\" SET login = ?, password = ?, user_post = ? WHERE user_id = ?");
    query.addBindValue(login);
    query.addBindValue(password);
    query.addBindValue(user_post);
    query.addBindValue(user_id);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::deleteUser(int user_id)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM \"user\" WHERE user_id = ?");
    query.addBindValue(user_id);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::getAllEmployees()
{
    QSqlQuery query(Database::db);
    if (!Database::db.isOpen()) {
        return query;
    }
    query.exec("SELECT e.id_emp, e.name, e.surname, e.patronimic, e.post, e.telephone, e.adress, "
               "COALESCE(u.user_post, 'Не назначен') FROM employee e "
               "LEFT JOIN \"user\" u ON e.user_id = u.user_id ORDER BY e.id_emp");
    return query;
}

bool Database::addEmployee(const QString& name, const QString& surname, const QString& patronimic,const QString& post, const QString& telephone, const QString& adress, int user_id)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO employee (name, surname, patronimic, post, telephone, adress, user_id) " "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(surname);
    query.addBindValue(patronimic);
    query.addBindValue(post);
    query.addBindValue(telephone);
    query.addBindValue(adress);
    if (user_id == -1) {
        query.addBindValue(QVariant());
    } else {
        query.addBindValue(user_id);
    }

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::updateEmployee(int id_emp, const QString& name, const QString& surname, const QString& patronimic,
                              const QString& post, const QString& telephone, const QString& adress, int user_id)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("UPDATE employee SET name = ?, surname = ?, patronimic = ?, post = ?, "
                  "telephone = ?, adress = ?, user_id = ? WHERE id_emp = ?");
    query.addBindValue(name);
    query.addBindValue(surname);
    query.addBindValue(patronimic);
    query.addBindValue(post);
    query.addBindValue(telephone);
    query.addBindValue(adress);
    if (user_id == -1) {
        query.addBindValue(QVariant());
    } else {
        query.addBindValue(user_id);
    }
    query.addBindValue(id_emp);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::deleteEmployee(int id_emp)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM employee WHERE id_emp = ?");
    query.addBindValue(id_emp);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::getAllComputers()
{
    QSqlQuery query(Database::db);
    if (!Database::db.isOpen()) {
        return query;
    }
    query.exec("SELECT c.id_comp, c.processor, c.video_card, c.\"RAM, gb\", c.screen, c.keyboard, c.mouse, "
               "COALESCE(e.surname, 'Не назначен') FROM computer c "
               "LEFT JOIN employee e ON c.id_emp = e.id_emp ORDER BY c.id_comp");
    return query;
}

bool Database::addComputer(const QString& processor, const QString& video_card, int ram,
                           const QString& screen, const QString& keyboard, const QString& mouse, int id_emp)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO computer (processor, video_card, \"RAM, gb\", screen, keyboard, mouse, id_emp) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(processor);
    query.addBindValue(video_card);
    query.addBindValue(ram);
    query.addBindValue(screen);
    query.addBindValue(keyboard);
    query.addBindValue(mouse);
    if (id_emp == -1) {
        query.addBindValue(QVariant());
    } else {
        query.addBindValue(id_emp);
    }

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::updateComputer(int id_comp, const QString& processor, const QString& video_card, int ram,
                              const QString& screen, const QString& keyboard, const QString& mouse, int id_emp)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("UPDATE computer SET processor = ?, video_card = ?, \"RAM, gb\" = ?, "
                  "screen = ?, keyboard = ?, mouse = ?, id_emp = ? WHERE id_comp = ?");
    query.addBindValue(processor);
    query.addBindValue(video_card);
    query.addBindValue(ram);
    query.addBindValue(screen);
    query.addBindValue(keyboard);
    query.addBindValue(mouse);
    if (id_emp == -1) {
        query.addBindValue(QVariant());
    } else {
        query.addBindValue(id_emp);
    }
    query.addBindValue(id_comp);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::deleteComputer(int id_comp)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM computer WHERE id_comp = ?");
    query.addBindValue(id_comp);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::getAllSoftware()
{
    QSqlQuery query(Database::db);
    if (!Database::db.isOpen()) {
        return query;
    }

    query.exec("SELECT id_soft, soft_name, version FROM software ORDER BY id_soft");
    return query;
}

bool Database::addSoftware(const QString& soft_name, const QString& version)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO software (soft_name, version) VALUES (?, ?)");
    query.addBindValue(soft_name);
    query.addBindValue(version);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::updateSoftware(int id_soft, const QString& soft_name, const QString& version)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("UPDATE software SET soft_name = ?, version = ? WHERE id_soft = ?");
    query.addBindValue(soft_name);
    query.addBindValue(version);
    query.addBindValue(id_soft);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::deleteSoftware(int id_soft)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM software WHERE id_soft = ?");
    query.addBindValue(id_soft);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::getAllLicenses()
{
    QSqlQuery query(Database::db);
    if (!Database::db.isOpen()) {
        return query;
    }
    query.exec("SELECT l.id_lic, l.end_date, COALESCE(s.soft_name, 'Не указано'), l.key FROM license l "
               "LEFT JOIN software s ON l.id_soft = s.id_soft ORDER BY l.id_lic");
    return query;
}

bool Database::addLicense(const QString& end_date, int id_soft, const QString& key)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO license (end_date, id_soft, key) VALUES (?, ?, ?)");
    query.addBindValue(end_date);
    query.addBindValue(id_soft);
    query.addBindValue(key);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::updateLicense(int id_lic, const QString& end_date, int id_soft, const QString& key)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("UPDATE license SET end_date = ?, id_soft = ?, key = ? WHERE id_lic = ?");
    query.addBindValue(end_date);
    query.addBindValue(id_soft);
    query.addBindValue(key);
    query.addBindValue(id_lic);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::deleteLicense(int id_lic)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM license WHERE id_lic = ?");
    query.addBindValue(id_lic);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::getSoftwareForComputer(int id_comp)
{
    QSqlQuery query(Database::db);
    if (!Database::db.isOpen()) {
        return query;
    }

    query.prepare("SELECT s.id_soft, s.soft_name, s.version FROM software s "
                  "JOIN computer_software cs ON s.id_soft = cs.id_soft "
                  "WHERE cs.id_comp = ?");
    query.addBindValue(id_comp);
    query.exec();
    return query;
}

bool Database::addSoftwareToComputer(int id_comp, int id_soft)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO computer_software (id_comp, id_soft) VALUES (?, ?)");
    query.addBindValue(id_comp);
    query.addBindValue(id_soft);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

bool Database::removeSoftwareFromComputer(int id_comp, int id_soft)
{
    if (!Database::db.isOpen()) {
        lastError = "Нет подключения к базе данных";
        return false;
    }

    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM computer_software WHERE id_comp = ? AND id_soft = ?");
    query.addBindValue(id_comp);
    query.addBindValue(id_soft);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::getEmployeeByUserId(int user_id)
{
    QSqlQuery query(Database::db);
    if (!Database::db.isOpen()) {
        return query;
    }

    query.prepare("SELECT id_emp FROM employee WHERE user_id = ?");
    query.addBindValue(user_id);
    query.exec();
    return query;
}

QSqlQuery Database::getComputerByEmployeeId(int id_emp)
{
    QSqlQuery query(Database::db);
    if (!Database::db.isOpen()) {
        return query;
    }

    query.prepare("SELECT id_comp FROM computer WHERE id_emp = ?");
    query.addBindValue(id_emp);
    query.exec();
    return query;
}
#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Database
{
public:
    static bool connect();
    static void disconnect();
    static bool checkUser(const QString& login, const QString& password, QString& user_post);
    static QString getLastError();

    static QSqlQuery getAllUsers();
    static bool addUser(const QString& login, const QString& password, const QString& user_post);
    static bool updateUser(int user_id, const QString& login, const QString& password, const QString& user_post);
    static bool deleteUser(int user_id);

    static QSqlQuery getAllEmployees();
    static bool addEmployee(const QString& name, const QString& surname, const QString& patronimic,const QString& post, const QString& telephone, const QString& adress, int user_id);
    static bool updateEmployee(int id_emp, const QString& name, const QString& surname, const QString& patronimic,const QString& post, const QString& telephone, const QString& adress, int user_id);
    static bool deleteEmployee(int id_emp);

    static QSqlQuery getAllComputers();
    static bool addComputer(const QString& processor, const QString& video_card, int ram,const QString& screen, const QString& keyboard, const QString& mouse, int id_emp);
    static bool updateComputer(int id_comp, const QString& processor, const QString& video_card, int ram,const QString& screen, const QString& keyboard, const QString& mouse, int id_emp);
    static bool deleteComputer(int id_comp);

    static QSqlQuery getAllSoftware();
    static bool addSoftware(const QString& soft_name, const QString& version);
    static bool updateSoftware(int id_soft, const QString& soft_name, const QString& version);
    static bool deleteSoftware(int id_soft);

    static QSqlQuery getAllLicenses();
    static bool addLicense(const QString& end_date, int id_soft, const QString& key);
    static bool updateLicense(int id_lic, const QString& end_date, int id_soft, const QString& key);
    static bool deleteLicense(int id_lic);

    static QSqlQuery getSoftwareForComputer(int id_comp);
    static bool addSoftwareToComputer(int id_comp, int id_soft);
    static bool removeSoftwareFromComputer(int id_comp, int id_soft);
    static QSqlQuery getEmployeeByUserId(int user_id);
    static QSqlQuery getComputerByEmployeeId(int id_emp);

private:
    static QSqlDatabase db;
    static QString lastError;
};

#endif // DATABASE_H
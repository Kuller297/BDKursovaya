/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabUsers;
    QVBoxLayout *verticalLayoutUsers;
    QTableWidget *tableUsers;
    QWidget *tabEmployees;
    QVBoxLayout *verticalLayoutEmployees;
    QTableWidget *tableEmployees;
    QWidget *tabComputers;
    QVBoxLayout *verticalLayoutComputers;
    QTableWidget *tableComputers;
    QWidget *tabSoftware;
    QVBoxLayout *verticalLayoutSoftware;
    QTableWidget *tableSoftware;
    QWidget *tabLicenses;
    QVBoxLayout *verticalLayoutLicenses;
    QTableWidget *tableLicenses;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabUsers = new QWidget();
        tabUsers->setObjectName("tabUsers");
        verticalLayoutUsers = new QVBoxLayout(tabUsers);
        verticalLayoutUsers->setObjectName("verticalLayoutUsers");
        tableUsers = new QTableWidget(tabUsers);
        if (tableUsers->columnCount() < 5)
            tableUsers->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableUsers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableUsers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableUsers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableUsers->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableUsers->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableUsers->setObjectName("tableUsers");

        verticalLayoutUsers->addWidget(tableUsers);

        tabWidget->addTab(tabUsers, QString());
        tabEmployees = new QWidget();
        tabEmployees->setObjectName("tabEmployees");
        verticalLayoutEmployees = new QVBoxLayout(tabEmployees);
        verticalLayoutEmployees->setObjectName("verticalLayoutEmployees");
        tableEmployees = new QTableWidget(tabEmployees);
        if (tableEmployees->columnCount() < 8)
            tableEmployees->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(7, __qtablewidgetitem12);
        tableEmployees->setObjectName("tableEmployees");

        verticalLayoutEmployees->addWidget(tableEmployees);

        tabWidget->addTab(tabEmployees, QString());
        tabComputers = new QWidget();
        tabComputers->setObjectName("tabComputers");
        verticalLayoutComputers = new QVBoxLayout(tabComputers);
        verticalLayoutComputers->setObjectName("verticalLayoutComputers");
        tableComputers = new QTableWidget(tabComputers);
        if (tableComputers->columnCount() < 8)
            tableComputers->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableComputers->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableComputers->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableComputers->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableComputers->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableComputers->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableComputers->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableComputers->setHorizontalHeaderItem(6, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableComputers->setHorizontalHeaderItem(7, __qtablewidgetitem20);
        tableComputers->setObjectName("tableComputers");

        verticalLayoutComputers->addWidget(tableComputers);

        tabWidget->addTab(tabComputers, QString());
        tabSoftware = new QWidget();
        tabSoftware->setObjectName("tabSoftware");
        verticalLayoutSoftware = new QVBoxLayout(tabSoftware);
        verticalLayoutSoftware->setObjectName("verticalLayoutSoftware");
        tableSoftware = new QTableWidget(tabSoftware);
        if (tableSoftware->columnCount() < 3)
            tableSoftware->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableSoftware->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableSoftware->setHorizontalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableSoftware->setHorizontalHeaderItem(2, __qtablewidgetitem23);
        tableSoftware->setObjectName("tableSoftware");

        verticalLayoutSoftware->addWidget(tableSoftware);

        tabWidget->addTab(tabSoftware, QString());
        tabLicenses = new QWidget();
        tabLicenses->setObjectName("tabLicenses");
        verticalLayoutLicenses = new QVBoxLayout(tabLicenses);
        verticalLayoutLicenses->setObjectName("verticalLayoutLicenses");
        tableLicenses = new QTableWidget(tabLicenses);
        if (tableLicenses->columnCount() < 4)
            tableLicenses->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableLicenses->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableLicenses->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableLicenses->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableLicenses->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        tableLicenses->setObjectName("tableLicenses");

        verticalLayoutLicenses->addWidget(tableLicenses);

        tabWidget->addTab(tabLicenses, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableUsers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableUsers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableUsers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableUsers->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableUsers->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUsers), QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableEmployees->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableEmployees->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableEmployees->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableEmployees->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableEmployees->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableEmployees->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableEmployees->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableEmployees->horizontalHeaderItem(7);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\273\321\214 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEmployees), QCoreApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableComputers->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableComputers->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201\320\276\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableComputers->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\265\320\276\320\272\320\260\321\200\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableComputers->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "RAM, GB", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableComputers->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\200\320\260\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableComputers->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableComputers->horizontalHeaderItem(6);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\320\234\321\213\321\210\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableComputers->horizontalHeaderItem(7);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\260\320\264\320\265\320\273\320\265\321\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabComputers), QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableSoftware->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableSoftware->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableSoftware->horizontalHeaderItem(2);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\201\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSoftware), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\275\320\276\320\265 \320\276\320\261\320\265\321\201\320\277\320\265\321\207\320\265\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableLicenses->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableLicenses->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\276\320\272\320\276\320\275\321\207\320\260\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableLicenses->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableLicenses->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabLicenses), QCoreApplication::translate("MainWindow", "\320\233\320\270\321\206\320\265\320\275\320\267\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

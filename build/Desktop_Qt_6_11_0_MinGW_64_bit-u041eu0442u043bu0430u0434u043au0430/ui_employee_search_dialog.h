/********************************************************************************
** Form generated from reading UI file 'employee_search_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_SEARCH_DIALOG_H
#define UI_EMPLOYEE_SEARCH_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EmployeeSearchDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QPushButton *btnSearch;
    QTableWidget *tableEmployees;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnSelect;
    QPushButton *btnCancel;

    void setupUi(QDialog *EmployeeSearchDialog)
    {
        if (EmployeeSearchDialog->objectName().isEmpty())
            EmployeeSearchDialog->setObjectName("EmployeeSearchDialog");
        EmployeeSearchDialog->resize(700, 500);
        verticalLayout = new QVBoxLayout(EmployeeSearchDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelSearch = new QLabel(EmployeeSearchDialog);
        labelSearch->setObjectName("labelSearch");

        horizontalLayout->addWidget(labelSearch);

        lineEditSearch = new QLineEdit(EmployeeSearchDialog);
        lineEditSearch->setObjectName("lineEditSearch");

        horizontalLayout->addWidget(lineEditSearch);

        btnSearch = new QPushButton(EmployeeSearchDialog);
        btnSearch->setObjectName("btnSearch");

        horizontalLayout->addWidget(btnSearch);


        verticalLayout->addLayout(horizontalLayout);

        tableEmployees = new QTableWidget(EmployeeSearchDialog);
        if (tableEmployees->columnCount() < 5)
            tableEmployees->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableEmployees->setObjectName("tableEmployees");

        verticalLayout->addWidget(tableEmployees);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        btnSelect = new QPushButton(EmployeeSearchDialog);
        btnSelect->setObjectName("btnSelect");

        horizontalLayoutButtons->addWidget(btnSelect);

        btnCancel = new QPushButton(EmployeeSearchDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayoutButtons->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayoutButtons);


        retranslateUi(EmployeeSearchDialog);

        QMetaObject::connectSlotsByName(EmployeeSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *EmployeeSearchDialog)
    {
        EmployeeSearchDialog->setWindowTitle(QCoreApplication::translate("EmployeeSearchDialog", "\320\222\321\213\320\261\320\276\321\200 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        labelSearch->setText(QCoreApplication::translate("EmployeeSearchDialog", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("EmployeeSearchDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 ID, \321\204\320\260\320\274\320\270\320\273\320\270\321\216, \320\270\320\274\321\217, \320\276\321\202\321\207\320\265\321\201\321\202\320\262\320\276 \320\270\320\273\320\270 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214...", nullptr));
        btnSearch->setText(QCoreApplication::translate("EmployeeSearchDialog", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEmployees->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EmployeeSearchDialog", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableEmployees->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EmployeeSearchDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableEmployees->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EmployeeSearchDialog", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableEmployees->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EmployeeSearchDialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableEmployees->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("EmployeeSearchDialog", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        btnSelect->setText(QCoreApplication::translate("EmployeeSearchDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("EmployeeSearchDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeSearchDialog: public Ui_EmployeeSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_SEARCH_DIALOG_H

/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelColumn;
    QComboBox *comboColumn;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSearch;
    QPushButton *btnClear;
    QPushButton *btnClose;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName("SearchDialog");
        SearchDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(SearchDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelColumn = new QLabel(SearchDialog);
        labelColumn->setObjectName("labelColumn");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelColumn);

        comboColumn = new QComboBox(SearchDialog);
        comboColumn->setObjectName("comboColumn");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboColumn);

        labelSearch = new QLabel(SearchDialog);
        labelSearch->setObjectName("labelSearch");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelSearch);

        lineEditSearch = new QLineEdit(SearchDialog);
        lineEditSearch->setObjectName("lineEditSearch");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditSearch);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnSearch = new QPushButton(SearchDialog);
        btnSearch->setObjectName("btnSearch");

        horizontalLayout->addWidget(btnSearch);

        btnClear = new QPushButton(SearchDialog);
        btnClear->setObjectName("btnClear");

        horizontalLayout->addWidget(btnClear);

        btnClose = new QPushButton(SearchDialog);
        btnClose->setObjectName("btnClose");

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SearchDialog);
        QObject::connect(btnClose, &QPushButton::clicked, SearchDialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QCoreApplication::translate("SearchDialog", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        labelColumn->setText(QCoreApplication::translate("SearchDialog", "\320\230\321\201\320\272\320\260\321\202\321\214 \320\262 \321\201\321\202\320\276\320\273\320\261\321\206\320\265:", nullptr));
        labelSearch->setText(QCoreApplication::translate("SearchDialog", "\320\230\321\201\320\272\320\260\321\202\321\214:", nullptr));
        btnSearch->setText(QCoreApplication::translate("SearchDialog", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        btnClear->setText(QCoreApplication::translate("SearchDialog", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        btnClose->setText(QCoreApplication::translate("SearchDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H

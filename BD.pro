QT += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = BD
TEMPLATE = app

win32 {
    LIBS += -lodbc32
}

SOURCES += \
    computer_dialog.cpp \
    employee_dialog.cpp \
    employee_search_dialog.cpp \
    license_dialog.cpp \
    main.cpp \
    database.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    searchdialog.cpp \
    software_dialog.cpp

HEADERS += \
    computer_dialog.h \
    database.h \
    employee_dialog.h \
    employee_search_dialog.h \
    license_dialog.h \
    loginwindow.h \
    mainwindow.h \
    searchdialog.h \
    software_dialog.h

FORMS += \
    computer_dialog.ui \
    employee_dialog.ui \
    employee_search_dialog.ui \
    license_dialog.ui \
    loginwindow.ui \
    mainwindow.ui \
    searchdialog.ui \
    software_dialog.ui
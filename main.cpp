#include <QApplication>
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("BD");
    app.setApplicationDisplayName("Просмотр данных");

    LoginWindow loginWin;
    loginWin.show();

    return app.exec();
}
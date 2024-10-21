#include "view_login.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    //QCoreApplication::addLibraryPath("/usr/lib/x86_64-linux-gnu/qt5/plugins");

    LoginWindow w;
    w.show();

    return a.exec();
}

#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login *d = new login;
    d->show();
    
    return a.exec();
}

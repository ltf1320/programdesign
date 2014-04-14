#include <QCoreApplication>
#include <QtCore>
#include "weapon.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    CWeapon weapon;
    weapon.setStatus(fired);
    qDebug()<<"Status"<<weapon.getStatus();
    weapon.setProperty("own",1);
    qDebug()<<"own"<<weapon.property("own").toInt();
    return a.exec();
}

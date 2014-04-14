#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>

typedef enum
{
    nil,ready,fired,exceptional
}Status;

class CWeapon:public QObject
{
    Q_OBJECT
    Q_PROPERTY(Status status READ Status WRITE setStatus)
    Q_ENUMS(Status)

public:
    CWeapon(QObject *parent=0);
    void setStatus(Status s);
    Status getStatus() const;

private:
    Status status;
};



#endif // WEAPON_H

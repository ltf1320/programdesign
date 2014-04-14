#include "connectdatabase.h"
#include <QDebug>
connectDataBase::connectDataBase(QObject *parent) :
    QObject(parent)
{

}
connectDataBase::~connectDataBase()
{
    db.close();
}
bool connectDataBase::dataBaseOpen(QString databaseDrive, QString host,QString user, QString passwd, QString dataBaseName)
{
    db = QSqlDatabase::addDatabase(databaseDrive);
    db.setHostName(host);
    db.setUserName(user);
    db.setPassword(passwd);
    db.setDatabaseName(dataBaseName);
    if(db.open())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool connectDataBase::dataBaseOpen(QString databaseDrive, QString host,int port,QString user, QString passwd, QString dataBaseName)
{
    db = QSqlDatabase::addDatabase(databaseDrive);
    db.setHostName(host);
    db.setPort(port);
    db.setUserName(user);
    db.setPassword(passwd);
    db.setDatabaseName(dataBaseName);
    if(db.open())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void connectDataBase::search(const QString &sentence, int index,QString *result)
{
    QSqlQuery query(db);
    query.exec(sentence);
    if(query.next())
    {
        for(int i=0;i<index;i++)
        {
            result[i] = query.value(i).toString();
        }

    }
}
void connectDataBase::search(const QString &sentence, int index, QVector<char> *note)
{
    QSqlQuery query(db);
    query.exec(sentence);
    char result[query.size()][index];
    while(query.next())
    {
        for(int i=0;i<query.size();i++)
            for(int j=0;j<index;j++)
            {
                note->push_back(result[i][j]);
            }
    }
}
bool connectDataBase::insert(const QString &sentence)
{
    QSqlQuery query(db);
    return query.exec(sentence);
}
bool connectDataBase::update(const QString &sentence)
{
    QSqlQuery query(db);
    return query.exec(sentence);
}
bool connectDataBase::del(const QString &sentence)
{

}
bool connectDataBase::disconnectDatabase()
{
    db.close();
    if(!db.isOpen())
    {
        return true;
    }
    else
    {
        return false;
    }
}

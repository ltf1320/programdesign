#ifndef CONNECTDATABASE_H
#define CONNECTDATABASE_H

#include <QObject>
#include <QtSql>
#include <QVector>
#include <QStringList>
class connectDataBase : public QObject
{
    Q_OBJECT
public:
    explicit connectDataBase(QObject *parent = 0);
    ~connectDataBase();
    bool dataBaseOpen(QString databaseDrive,QString host,QString user,
                      QString passwd,QString dataBaseName);
    bool dataBaseOpen(QString databaseDrive, QString host,int port,QString user, QString passwd, QString dataBaseName);
    virtual void search(const QString &sentence,int index,QString *result);
    virtual void search(const QString &sentence,int index,QVector<char>* note);
    virtual bool insert(const QString& sentence);
    virtual bool update(const QString& sentence);
    virtual bool del(const QString& sentence);
    bool disconnectDatabase();

signals:
    
public slots:
private:
    QSqlDatabase db;
};

#endif // CONNECTDATABASE_H

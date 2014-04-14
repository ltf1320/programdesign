#ifndef FTPLOGIN_H
#define FTPLOGIN_H

#include <QObject>
#include <QFtp>

class FtpLogin : public QObject
{
    Q_OBJECT
public:
    explicit FtpLogin(QObject *parent = 0);
    ~FtpLogin();
    bool logIn(const QUrl &);
signals:
    void done();
    
private slots:
    void ftpDone(bool);
    void ftpcommandStarted(int);
    void ftpcommandFinished(int ,bool);
private:
    int connectId;
    int loginId;
    int closeId;
    QFtp ftp;
};

#endif // FTPLOGIN_H

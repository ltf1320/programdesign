#include "ftplogin.h"

FtpLogin::FtpLogin(QObject *parent) :
    QObject(parent)
{
    connect(&ftp,SIGNAL(done(bool))),this,SLOT(ftpDone(bool));
    connect(&ftp,SIGNAL(commandStarted(int)),this,SLOT(ftpcommandStarted(int)));
    connect(&ftp,SIGNAL(commandFinished(int,bool)),this,SLOT(ftpcommandFinished(int,bool)));
}

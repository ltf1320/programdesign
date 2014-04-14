#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QTranslator>
#include <QProcess>
#include <QDebug>
#include "logindlg.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb18030"));

    QTranslator translator;
    {
        QStringList environment=QProcess::systemEnvironment();
        QString str;
        bool bFinded=false;
        foreach (str, environment) {
            if(str.startsWith("QTDIR="))
            {
                bFinded=true;
                break;
            }
        }
        if(bFinded)
        {
            str=str.mid(6);
            bFinded=translator.load("qt_"+QLocale::system().name(),
                                    str.append("/translations"));
            if(bFinded)
                qApp->installTranslator(&translator);
            else
                qDebug()<<QObject::tr("没有支持中文的Qt国际化翻译文件");
        }
        qDebug()<<QObject::tr("必须设置QTDIR环境变量");
    }

    CLoginDlg dlg;
    return dlg.exec();
}

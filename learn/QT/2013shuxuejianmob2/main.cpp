#include <QApplication>
#include "imagewidget.h"
#include "topsort.h"
#include "mainwindow.h"
#include <QPixmap>
#include <QtCore>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.show();
    /*
    QImage image;
    char file[1000];
    QString kp("/jz");
    QString path("D:/programdesign/learn/QT/2013shuxuejianmob1/p2");
    for(int i=0;i<=18;i++)
    {
        sprintf(file,"/%03d.bmp",i);
        image.load(path+QString(file));
        file[5]=0;
        QFile of(path+kp+QString(file));
        of.open(QIODevice::WriteOnly);
        QTextStream out(&of);
        out<<image.width()<<" "<<image.height()<<" "<<endl;
        for(int i=0;i<image.width();i++)
        {
            for(int j=0;j<image.height();j++)
                out<<image.pixelIndex(i,j)<<" ";
            out<<endl;
        }
    }
    */
    return a.exec();
}

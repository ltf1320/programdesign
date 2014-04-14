#include <QApplication>
#include "imagewidget.h"
#include "topsort.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.show();
    return a.exec();
}

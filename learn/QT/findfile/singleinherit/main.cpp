#include "mainwindow.h"
#include <QApplication>
#include "findfileform.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CFindFileForm form;
    form.show();
    return a.exec();
}

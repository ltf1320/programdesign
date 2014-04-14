#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QLabel>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec:: setCodecForLocale(QTextCodec::codecForName("gb23121"));
    QWidget* pWidget =new QWidget;
    QLabel label(pWidget);
    label.setText("同一个世界，同一个梦想");

    QPushButton* btn=new QPushButton(QObject::tr("关闭"),pWidget);
    QVBoxLayout* layout=new QVBoxLayout;
    layout->addWidget(&label);
    layout->addWidget(btn);
    pWidget->setLayout(layout);
    pWidget->setWindowTitle("bool luo");
    pWidget->resize(QSize(1000,600));
    QObject::connect(btn,SIGNAL(clicked()),pWidget,SLOT(close()));
    pWidget->show();
    return app.exec();

}

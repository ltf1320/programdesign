#include "samelinewidget.h"
#include <QtCore>
SameLineWidget::SameLineWidget(topSort *tp,QWidget *parent) :
    QMainWindow(parent)
  ,Ui_SameLineWidget()
{
    setupUi(this);
    this->tp=tp;
    lst=tp->listSameLine();
    index=0;
    connect(actNext,SIGNAL(triggered()),this,SLOT(getNext()));
    connect(actPre,SIGNAL(toggled()),this,SLOT(getPre()));
}


void SameLineWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int x=0,y=0;
    int dx,dy;
    QImage fixImage;
    int fd=2.5;
    fixImage=tp->pics[0].scaled(fd*width()/Wid,fd*height()/Hei,Qt::KeepAspectRatio);
    dx=fixImage.width();
    dy=fixImage.height();
    for(int i=0;i<lst[index].size();i++)
    {
        for(int j=0;j<Wid;j++)
        {
            if(lst[index][i][j]!=-1)
            {
                fixImage=tp->pics[lst[index][i][j]].scaled(fd*width()/Wid,fd*height()/Hei,Qt::KeepAspectRatio);
                painter.drawImage(x,y,fixImage);
            }
            painter.drawText(x,y+dy+20,QString::number(lst[index][i][j]));
            x+=dx;
            painter.drawLine(x,y,x,y+2*dy);
        }
        y+=2*dy;
        x=0;
    }
}

void SameLineWidget::getNext()
{
    if(lst.empty()) return;
    index++;
    if(index>=lst.size())
    {
        index=0;
        qDebug()<<"end";
    }
    update();
}

void SameLineWidget::getPre()
{
    if(lst.empty()) return;
    index--;
    if(index<0)
        index=lst.size()-1;
    update();
}

#include "findwidget.h"

FindWidget::FindWidget(MainWindow *mw,topSort *tp, QWidget *parent) :
    QWidget(parent),Ui_findWidget()
{
    setupUi(this);
    connect(nextBtn,SIGNAL(clicked()),this,SLOT(getNext()));
    connect(preBtn,SIGNAL(clicked()),this,SLOT(getPre()));
    this->tp=tp;
    this->mw=mw;
}


void FindWidget::findMatch(int now,int dis)
{
    lst=tp->findMatch(now,dis);
    if(lst.empty())
    {
        picnoLabel->setText(tr("找不到"));
        nextBtn->setVisible(false);
        preBtn->setVisible(false);
        updatej();
    }
    index=0;
    updatej();
}


void FindWidget::findSameLine(int now)
{
    lst=tp->findSameLine(now);
    if(lst.empty())
    {
        picnoLabel->setText(tr("找不到"));
        nextBtn->setVisible(false);
        preBtn->setVisible(false);
        updatej();
    }
    index=0;
    updatej();
}

void FindWidget::getNext()
{
    if(lst.size()==0) return;
    index++;
    if(index>=lst.size())
        index=0;
    updatej();
    update();
}

void FindWidget::getPre()
{
    if(lst.size()==0) return;
    index--;
    if(index<0)
        index=lst.size()-1;
    updatej();
    update();
}

void FindWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(!lst.empty())
    {
        picnoLabel->setText(QString::number(lst[index].picno));
        difLabel->setText(QString::number(lst[index].dif));
        painter.drawImage(width()/3,10,tp->pics[lst[index].picno]);
    }
}

void FindWidget::updatej()
{
    if(lst.size()==0) return;
    mw->jEdit->setText(QString::number(lst[index].picno));
}

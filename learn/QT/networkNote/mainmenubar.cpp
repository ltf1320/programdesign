#include "mainmenubar.h"
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>
mainMenuBar::mainMenuBar(QWidget *parent) :
    QWidget(parent)
{
    maxWin = false;
}
void mainMenuBar::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void mainMenuBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(event->y()<5||event->x()<5)
        {
            event->ignore();
            return;
        }
            mouse_pressed_pos = event->globalPos();
            mouse_press=true;
    }
    event->ignore();
}
void mainMenuBar::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
    {

        mouse_moveto_pos=event->globalPos();
        mainwindow->move(mainwindow->pos()+mouse_moveto_pos-mouse_pressed_pos);
        mouse_pressed_pos = mouse_moveto_pos;
       /* if(maxWin)
        {
            mainwindow->setGeometry(mouse_pressed_pos.x(),mouse_pressed_pos.y(),mainWindowSize.width(),mainWindowSize.height());
        }*/
    }
    event->ignore();
}
void mainMenuBar::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = false;
    }
    event->ignore();
}
void mainMenuBar::settarget(QMainWindow *m)
{
    mainwindow = m;
}
/*void mainMenuBar::getWindowSize(QRect m,bool state)
{
    mainWindowSize = m;
    maxWin = state;
}*/

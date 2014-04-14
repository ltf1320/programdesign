#include "mainwindow.h"
#include <QTextCodec>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QRect>
#include <QMessageBox>
#include <QRect>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    maxWin = this->isMaximized();
    menubar->settarget(this);
    Function = new mainFunction(includeContentWidget,includeEditWidget,contentWidget,listView,editWidget,searchLineedit,searchBtn,noteBookList);

    //installEventfilter();
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    mousepressed = false;
     initSignalSlot();
}
MainWindow::~MainWindow()
{

}
void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标按下事件
{
    if(event->button() == Qt::LeftButton)
    {
        if((this->width()-event->x())<5 || (this->height()-event->y())<5)
        {
            mouse_pressed_pos = event->globalPos();
            mousepressed = true;
        }
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent*)//鼠标释放事件
{
    mousepressed = false;
}
void MainWindow::initSignalSlot()
{
    connect(closeBtn,SIGNAL(clicked()),this,SLOT(close_all()));
    connect(minimumBtn,SIGNAL(clicked()),this,SLOT(showMinimized()));
    //connect(this,SIGNAL(mousepos(int,int)),this,SLOT(displaymousepos(int,int)));
    connect(logoutBtn,SIGNAL(clicked()),this,SIGNAL(logout()));
    connect(newNoteBtn,SIGNAL(clicked()),Function,SLOT(createNewNote()));
    //connect(createNoteBookBtn,SIGNAL(clicked()),Function,SLOT(createNewNoteBook()));
}
void MainWindow::close_all()
{
    this->close();
    emit login_close();
}
void MainWindow::setUid(QString id)
{
        uid = id;
}

/*void MainWindow::maximum()//放大按钮点击放大
{
    if(!maxWin)
     {
        mainWindowSize = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
     }
    else
    {
        setGeometry(mainWindowSize);
    }
    maxWin = !maxWin;
    //menubar->getWindowSize(mainWindowSize,maxWin);
}*/
/*void MainWindow::mouseMoveEvent(QMouseEvent *event)//鼠标移动事件
{
    //top = event->y()<=5;
    bottom = (this->height()-event->y())<=5;
    right = (this->width()-event->x())<=5;
    //textEdit->setText(QString("x:%1;y:%2").arg(QString::number(left),QString::number(top)));
    if(!mousepressed)
    {
        if(right && bottom)
        {
            setCursor(Qt::SizeFDiagCursor);
        }
        else if(right)
        {
            setCursor(Qt::SizeHorCursor);
        }
        else if(bottom)
        {
            setCursor(Qt::SizeVerCursor);
        }
        else
        {
            setCursor(Qt::ArrowCursor);
        }
     }
    else
    {
        mouse_moveto_pos = event->globalPos();
        if(this->cursor().shape() == Qt::SizeHorCursor)
            {
                this->setGeometry(this->x(),this->y(),this->width()+mouse_moveto_pos.x()-mouse_pressed_pos.x(),this->height());
            }
        else if(this->cursor().shape() == Qt::SizeVerCursor)
            {
                this->setGeometry(this->x(),this->y(),this->width(),this->height()+
                                  mouse_moveto_pos.y()-mouse_pressed_pos.y());
            }
        else if(this->cursor().shape() == Qt::SizeFDiagCursor)
            {
                this->setGeometry(this->x(),this->y(),this->width()+mouse_moveto_pos.x()-mouse_pressed_pos.x(),
                                  this->height()+mouse_moveto_pos.y()-mouse_pressed_pos.y());
            }
        mouse_pressed_pos = mouse_moveto_pos;
    }
}*/
/*void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)//鼠标双击事件 放大窗口
{
       if(event->button() == Qt::LeftButton)
        {
            if(event->y()<5||event->x()<5)
            {
                event->ignore();
                return;
            }
            else if(event->y()>5&&event->y()<menubar->height())
            {
                if(!maxWin)
                 {
                    mainWindowSize = this->geometry();
                    this->setGeometry(qApp->desktop()->availableGeometry());
                 }
                else
                {
                    this->setGeometry(mainWindowSize);

                }
                maxWin = !maxWin;
             }  //menubar->getWindowSize(mainWindowSize,maxWin);
         }
}*/

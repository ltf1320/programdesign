#include "login.h"

#include <QMouseEvent>
#include <QTextCodec>
#include <QVector>
#include <QMovie>
#include <QStateMachine>
#include <QState>
#include <QPropertyAnimation>
#include <QPalette>
#include <QMessageBox>


login::login(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    initslots();
    userLineEdit->setFocus();
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    fadeEffect = new QGraphicsOpacityEffect;
    animation = new QPropertyAnimation(fadeEffect,"opacity");

   // currentTime.currentTime().toString()


}

login::~login()
{

}
void login::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(event->y()<30)
        {
            mouse_pressed_pos = event->globalPos();
            mouse_press=true;
        }
        else
        {
            event->ignore();
        }

    }
    event->ignore();

}
void login::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
    {

        mouse_moveto_pos=event->globalPos();
        this->move(this->pos()+mouse_moveto_pos-mouse_pressed_pos);
        mouse_pressed_pos = mouse_moveto_pos;
    }

        event->ignore();
}
void login::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = false;
    }
    event->ignore();
}
void login::initslots()
{
    connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(minimumBtn,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect(loginBtn,SIGNAL(clicked()),this,SLOT(login_note()));
    connect(pushButton,SIGNAL(clicked()),this,SLOT(sign_in_page()));
}
void login::login_note()
{
    if(!userLineEdit->isModified())
    {
        if(!passWdLineEdit->isModified())
        {
            login_state_label->setText(tr("用户名和密码不能为空！"));
        }
        else
        {
            login_state_label->setText(tr("用户名不能为空!"));
        }
    }
    else if(!passWdLineEdit->isModified())
    {
        login_state_label->setText(tr("密码不能为空!"));
    }
    else
    {
        login_state_label->setText("");
        QString user = userLineEdit->text();
        QString passwd = passWdLineEdit->text();
        QString result[5];
        //l
         connectDb = new connectDataBase;
         if(connectDb->dataBaseOpen("QMYSQL","localhost","root","","note"))
         {
             connectDb->search(QString("SELECT user,passwd,uid FROM user WHERE user='%1'")
                                                     .arg(user)
                                                     ,3,result);//验证登录
             if(!result[0].isEmpty())
            {
                 if(result[1] == passwd)
                 {
                    mainwindow = new MainWindow;
                    mainwindow->show();
                    connect(mainwindow,SIGNAL(logout()),this,SLOT(logout_note()));
                    connect(mainwindow,SIGNAL(login_close()),this,SLOT(close_note()));
                    mainwindow->userNameLabel->setText(tr("欢迎,%1,%2").arg(user).arg(result[2]));
                    mainwindow->setUid(result[2]);
                    this->hide();
                    connectDb->disconnectDatabase();
                    connectDb->deleteLater();
                 }
                 else
                 {
                     login_state_label->setText(tr("密码错误"));
                     connectDb->disconnectDatabase();
                     connectDb->deleteLater();
                 }
            }
             else
            {
                 login_state_label->setText(tr("用户名不存在"));
                 connectDb->disconnectDatabase();
                 connectDb->deleteLater();
            }
          }
         else
         {
             login_state_label->setText(tr("数据库连接失败"));
             connectDb->deleteLater();
         }
    }

}
void login::logout_note()
{
    this->show();
    mainwindow->close();
}
void login::close_note()
{
    this->close();

}
void login::sign_in_page()
{

   signinLayout();
}
void login::sign_in()//注册账户
{
    QString user = signWidget->signinUser->text();
    QString passwd = signWidget->signinPasswd->text();
    QString confirm_passwd = signWidget->confirmPasswd->text();
    QString test_code = signWidget->test_code->text();
    QString result[5];
    if(passwd != confirm_passwd)
    {
        signWidget->signinState->setText(tr("密码不一致"));
    }
    else if(test_code != signWidget->getCheckCode())
    {
        signWidget->signinState->setText(tr("验证码错误"));
    }
    else
    {
        connectDb = new connectDataBase;
        if(connectDb->dataBaseOpen("QMYSQL","localhost","root","","note"))
        {
            /*if(connectDb->insert(QString("INSERT INTO user (user,passwd) VALUES('%1','%2')").arg(user).arg(passwd)))
            {
                signWidget->signinState->setText(tr("注册成功请返回登录"));
                delete connectDb;
            }*/
            connectDb->search(QString("SELECT uid FROM user WHERE user='%1'").arg(user),1,result);
            if(!result[0].isEmpty())
            {
                signWidget->signinState->setText(tr("用户名已存在"));
                connectDb->disconnectDatabase();
                connectDb->deleteLater();
            }
            else if(connectDb->insert(QString("INSERT INTO user (user,passwd) VALUES('%1','%2')").arg(user).arg(passwd)))
            {
                qDebug() << "sign in success";
                signWidget->signinState->setText(tr("注册成功请返回登录"));
                connectDb->disconnectDatabase();
                connectDb->deleteLater();
            }
            else
            {
                signWidget->signinState->setText(tr("注册失败"));
                connectDb->disconnectDatabase();
                connectDb->deleteLater();
            }

         }
        else
        {
            signWidget->signinState->setText(tr("数据库连接失败"));
            connectDb->deleteLater();
        }
    }
}
void login::signinLayout()
{
    signWidget = new sign_in_widget(this);
    signWidget->setGeometry(loginWidget->x(),loginWidget->y(),loginWidget->width(),loginWidget->height());
    signWidget->returnloginBtn->setDefault(false);
    widget_fade_in_effect(signWidget);
    if(fadeEffect->opacity()==1.0)
    {
        signWidget->returnloginBtn->setDefault(true);
    }
    connect(signWidget->returnloginBtn,SIGNAL(clicked()),this,SLOT(restore_login()));
    connect(signWidget->sign_inBtn,SIGNAL(clicked()),this,SLOT(sign_in()));
    widget_fade_out_effect(loginWidget);
}
void login::restore_login()
{
    widget_fade_out_effect(signWidget);
    widget_fade_in_effect(loginWidget);
    pushButton->setDefault(false);
    if(fadeEffect->opacity() == 1.0)
    {
        pushButton->setDefault(true);
    }
}
void login::widget_fade_in_effect(QWidget *widget)
{
    animation->setDuration(600);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->start();
    widget->setGraphicsEffect(fadeEffect);
    widget->setVisible(true);
}
void login::widget_fade_out_effect(QWidget *widget)
{
    widget->setVisible(false);
}


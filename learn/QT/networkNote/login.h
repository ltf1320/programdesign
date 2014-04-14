#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QPoint>
#include "connectdatabase.h"
#include "mainwindow.h"
#include "ui_login.h"
#include <QLineEdit>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <sign_in_widget.h>
class login : public QDialog,public Ui_login
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    ~login();
    void initslots();
    void signinLayout();
    void widget_fade_in_effect(QWidget* widget);
    void widget_fade_out_effect(QWidget* widget);
    QString generation_validator_code();
protected:

public slots:
    void restore_login();
    void login_note();
    void logout_note();
    void sign_in_page();
    void sign_in();
    void close_note();
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
private:
    bool mouse_press;
    QPoint mouse_pressed_pos;
    QPoint mouse_moveto_pos;
    MainWindow *mainwindow;
    connectDataBase *connectDb;
    QTimer *timer;


    sign_in_widget *signWidget;
                        //注册界面控件
    QPropertyAnimation *animation;
    QGraphicsOpacityEffect *fadeEffect;
};

#endif // LOGIN_H

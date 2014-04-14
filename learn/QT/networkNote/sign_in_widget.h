#ifndef SIGN_IN_WIDGET_H
#define SIGN_IN_WIDGET_H

#include <QWidget>
#include "ui_sign_in_widget.h"

#include <QFontDatabase>
#include <QPixmap>
class sign_in_widget : public QWidget,public Ui_sign_in_widget
{
    Q_OBJECT
    
public:
    explicit sign_in_widget(QWidget *parent = 0);
    ~sign_in_widget();
    void generation_validator_code();
    int random(int seed);
    int random(int,int,int);
    QString getCheckCode();
public slots:
    void changeCheckCode();
protected:
    void paintEvent(QPaintEvent *);
private:
    QString color[3];
    QFontDatabase fontDataBase;
    QString code[4];
    QString checkcode;


};

#endif // SIGN_IN_WIDGET_H

#include "sign_in_widget.h"
#include <cstdlib>
#include <ctime>
#include <QTime>
#include <QPixmap>
#include <QPainter>
#include <QPaintEngine>

sign_in_widget::sign_in_widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    checkcode.append("0123456789ABCDEFGHJKLMNPQRTUVWXYZ");

    generation_validator_code();
    this->repaint();
    connect(changeCheckCodeBtn,SIGNAL(clicked()),this,SLOT(changeCheckCode()));
    color[0] = "red";
    color[1] = "green";
    color[2] = "blue";

}

sign_in_widget::~sign_in_widget()
{

}
void sign_in_widget::generation_validator_code()//生成验证码
{

    for(int i=0;i<4;i++){
        code[i] = checkcode[random(i+1,0,32)];
    }
    //signinState->setText(code);

}
int sign_in_widget::random(int seed)//随机生成验证码
{
    srand(seed*QTime::currentTime().msec());
    return rand()%33;
}
int sign_in_widget::random(int seed,int min, int max)
{
    qsrand(seed*(uint)QTime::currentTime().msec());
    return qrand() % ((max + 1) - min) + min;
}
void sign_in_widget::paintEvent(QPaintEvent *)//绘制验证码
{
    QFontDatabase::addApplicationFont("font\font.ttf");



    QPainter painter(this);

    painter.setBrush(QBrush(Qt::white));
    painter.setPen(Qt::transparent);
    painter.drawRect(165,155,95,31);

    painter.setFont(QFont("font",15));
    painter.setPen(QColor(color[random(1,0,2)]));
    painter.translate(165,155);
    painter.shear(-0.7,0);
    painter.drawText(10,16,code[0]);

    painter.setPen(QColor(color[random(4,0,2)]));
    painter.shear(0.5,0);
    painter.drawText(22,16,code[1]);

    painter.setPen(QColor(color[random(3,0,2)]));
    painter.shear(-0.6,0);
    painter.drawText(39,16,code[2]);

    painter.setPen(QColor(color[random(2,0,2)]));
    painter.shear(0.5,0);
    painter.drawText(50,16,code[3]);
}
QString sign_in_widget::getCheckCode()
{
    QString tempcode;
    tempcode.append(code[0]).append(code[1]).append(code[2]).append(code[3]);
    return tempcode;
}
void sign_in_widget::changeCheckCode()
{
    generation_validator_code();


    update();
}

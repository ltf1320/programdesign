#include "editpatr.h"
#include <QDateTime>
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>
editPatr::editPatr(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    noteContent = new QMap<QString,QString>;
}

editPatr::~editPatr()
{

}
void editPatr::setContent(QMap<QString, QString> *content)
{
    noteContent = content;
}
void editPatr::keyPressEvent(QKeyEvent *e)
{
    if(this->hasFocus())
    {
        if(e->key() == Qt::Key_Enter)
        {
            (*noteContent)["title"]=lineEdit->text();
            (*noteContent)["createtime"]=showcreattimeLabel->text();
            (*noteContent)["modifiedtime"]=showcreattimeLabel->text();
            (*noteContent)["content"]=textEdit->toPlainText();
            (*noteContent)["font"] = "song";
            (*noteContent)["fontsize"]="12";
            (*noteContent)["fontcolor"]="black";
        }
        else
            e->ignore();
    }
}


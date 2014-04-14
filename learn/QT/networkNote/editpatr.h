#ifndef EDITPATR_H
#define EDITPATR_H

#include <QWidget>
#include "ui_editpatr.h"
#include <QListWidgetItem>
#include <QMap>
#include <QModelIndex>
namespace Ui {
class editPatr;
}

class editPatr : public QWidget,public Ui_editPatr
{
    Q_OBJECT
    
public:
    explicit editPatr(QWidget *parent = 0);
    ~editPatr();
    void setContent(QMap<QString,QString>* content);
protected:
    void keyPressEvent(QKeyEvent *e);
signals:

public slots:

private:
    QMap<QString,QString>* noteContent ;

};

#endif // EDITPATR_H

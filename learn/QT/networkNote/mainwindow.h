#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QMouseEvent>
#include <QPoint>
#include <QCursor>
#include <QRect>
#include <QHBoxLayout>
#include "ui_mainwindow.h"
#include "mainmenubar.h"
#include "mainfunction.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,public Ui_MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initSignalSlot();
    void setUid(QString);

signals:
    void logout();
    void login_close();

protected:
    //void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    //void mouseDoubleClickEvent(QMouseEvent *);

public slots:
    void close_all();

private:
    QString uid;
    mainFunction *Function;
    bool left;
    bool top;
    bool right;
    bool bottom;
    bool maxWin;
    QRect mainWindowSize;
    bool mousepressed ;
    QPoint mouse_pressed_pos;
    QPoint mouse_moveto_pos;
    QPoint mouseglobal;

};

#endif // MAINWINDOW_H

#ifndef MAINMENUBAR_H
#define MAINMENUBAR_H
#include <QWidget>
#include <QHBoxLayout>
#include <QRect>
#include <QMainWindow>
class mainMenuBar : public QWidget
{
    Q_OBJECT
public:

    explicit mainMenuBar(QWidget *parent = 0);
    void settarget(QMainWindow *m);
   // void getWindowSize(QRect m,bool state);
signals:
protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

public slots:
private:
    QMainWindow *mainwindow;
    bool mouse_press;//标题栏可拖动状态
    QPoint mouse_pressed_pos;
    QPoint mouse_moveto_pos;
    QPoint p;
    bool maxWin;
    QRect mainWindowSize;
};

#endif // MAINMENUBAR_H

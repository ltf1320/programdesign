#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "b2.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "imagewidget.h"
#include "findwidget.h"
#include "samelinewidget.h"
#include <QLineEdit>
#include <QtCore>
#include <QFileDialog>
class MainWindow : public QMainWindow
        ,public Ui_MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    MainWindow *pp;
    ImageWidget *wd;
    FindWidget *fw;
    SameLineWidget *sw;
    QLineEdit arrs[20][20];
    void updateLayout();
    void updatei();
private slots:
    void redo();
    void work();
    void getNext();
    void getPre();
    void fgetNext();
    void fgetPre();

    void addEdge();
    void delEdge();

    void saveMap();
    void loadMap();

    void saveArr();
    void loadArr();

    void disp();

    void findSameLine();
    void findMatch();

    void listSameLine();

    void matchFinall();
    void zoomin();
    void zoomout();
};


#endif // MAINWINDOW_H

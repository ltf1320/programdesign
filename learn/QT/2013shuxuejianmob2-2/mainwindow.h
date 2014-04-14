#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "imagewidget.h"
#include "b2.h"
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
    ImageWidget *wd;
    QLineEdit arrs[20][20];
    void updateLayout();
private slots:
    void redo();
    void work();
    void getNext();
    void getPre();
    void addEdge();
    void delEdge();

    void saveMap();
    void loadMap();

    void saveArr();
    void loadArr();

    void updateArr();
    void disp();
};


#endif // MAINWINDOW_H

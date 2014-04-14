#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "imagewidget.h"

class MainWindow : public QMainWindow
        ,public Ui_MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    ImageWidget *wd;
private slots:
    void work();
};


#endif // MAINWINDOW_H

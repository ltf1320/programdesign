#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagewidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    ImageWidget *imageWidget;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:


    void on_choseAndMove_triggered();

    void on_drawLine_triggered();

    void on_drawRec_triggered();

    void on_drawEllipse_triggered();

    void on_combine_triggered();

    void on_split_triggered();

    void on_save_triggered();

    void on_open_triggered();

private:
    void initConnections();
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

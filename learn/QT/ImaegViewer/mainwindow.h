#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>
#include <imagewidget.h>
#include <QScrollArea>
#include <QFileDialog>
#include <QStatusBar>
class CMainWindow : public QMainWindow,
                   public Ui_MainWindow
{
    Q_OBJECT
    
public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

private slots:
    void doopen();
    void donext();
    void dopre();
    void doclose();
    void doL90();
    void doR90();
    void doFSize();
    void doASize();
    void doLarge();
    void doSmall();

private:
    void initConnects();
    void openFile(QString& fileName);
    void updateActions();
    QStringList imageList;
    QString imageName;
    int index;
    QDir imageDir;
    ImageWidget* imageWidget;
    QScrollArea* scrollArea;

protected:
    void dropEvent(QDropEvent *);
    void dragEnterEvent(QDragEnterEvent *);

};

#endif // MAINWINDOW_H

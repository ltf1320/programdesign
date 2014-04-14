#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDockWidget>
#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QStatusBar>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include "ui_mainwindow.h"
#include "mditextedit.h"
#include <QtCore>
#include "findfileform.h"
#include <QDebug>
#include <QMdiArea>
#include <QMdiSubWindow>

class CMainWindow : public QMainWindow,
                public Ui_MainWindow
{
    Q_OBJECT
    
public:
    CMainWindow(QWidget *parent = 0);
    void OpenFile(const QString &fileName);

private:
    QDockWidget* dockWidget;
    QLabel* label1;
    QLabel* label2;
    enum{MaxRecentFiles = 9};
    QAction* recentFileActs[MaxRecentFiles];
    QAction* separatorAct;
    QMdiArea* workspace;

    void iniDockWidget();
    void iniStatusBar();
    void iniConnect();

    CMDITextEdit* activeWindow();
    CMDITextEdit* createMDITextEdit(bool,const QString&);

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void doNew();
    void doOpen();
    void doClose();
    void doSave();
    void doASave();
    void doQuit();
    void doUndo();
    void doCut();
    void doCopy();
    void doPaste();
    void doAll();
    void doFind();
    void doPrint();
    void openRecentFile();
    void updateMenu();
    void showCount(int);
    void updateRecentFiles();
};

#endif // MAINWINDOW_H

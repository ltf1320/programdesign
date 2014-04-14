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

#include <Qtcore>
#include "findfileform.h"


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
    bool isUntitled;
    QString curFile;
    enum{MaxRecentFiles = 9};
    QAction* recentFileActs[MaxRecentFiles];
    QAction* separatorAct;

    void iniDockWidget();
    void iniStatusBar();
    void iniConnect();
    void setCurrentFile(const QString&);
    bool saveFile(const QString&);
    bool loadFile(const QString&);
    void maybeSave();
    void updateRecentFiles();


private slots:
    void doCursorChanged();
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
    void doModified();
    void openRecentFile();
};

#endif // MAINWINDOW_H

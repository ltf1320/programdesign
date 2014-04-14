#ifndef FINDFILEFORM_H
#define FINDFILEFORM_H

#include <QStringList>
#include <QDir>

#include "mainwindow.h"
#include <QFileDialog>
#include <Qt>
#include <QTextStream>
#include <QDateTime>
#include <QtCore>
#include <ui_findfileform.h>

class CMainWindow;
class CFindFileForm: public QWidget,
                    public Ui_FindFileForm
{
    Q_OBJECT
public:
    CFindFileForm(QWidget* parent =0);
    void setMainWindow(CMainWindow * =0);
private:
    QStringList findFiles(const QDir&,const QString&,const QString&);
    void showFiles(const QDir&,const QStringList&);
    void tranvFolder(const QDir&,const QString&,const QString);
    void clear();
    bool m_bStoped;
    bool m_bSubfolder;
    bool m_bSensitive;
    int m_nCount;\
    CMainWindow* mainWindow;
private slots:
    void openFile();
    void browse();
    void find();
    void stop();
    void doTxtChange(const QString&);
};

#endif // FINDFILEFORM_H

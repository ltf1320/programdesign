#ifndef FINDFILEFORM_H
#define FINDFILEFORM_H

#include <QStringList>
#include <QDir>

#include <ui_findfileform.h>

class CFindFileForm: public QWidget,
                    public Ui_FindFileForm
{
    Q_OBJECT
public:
    CFindFileForm(QWidget* parent =0);
private:
    QStringList findFiles(const QDir&,const QString&,const QString&);
    void showFiles(const QDir&,const QStringList&);
    void tranvFolder(const QDir&,const QString&,const QString);
    void clear();
    bool m_bStoped;
    bool m_bSubfolder;
    bool m_bSensitive;
    int m_nCount;
private slots:
    void browse();
    void find();
    void stop();
    void doTxtChange(const QString&);
};

#endif // FINDFILEFORM_H

#ifndef MDITEXTEDIT_H
#define MDITEXTEDIT_H

#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QCloseEvent>
#include <QSettings>
class CMDITextEdit :public QTextEdit
{
    Q_OBJECT
public:
    CMDITextEdit(bool,const QString &);
    virtual ~CMDITextEdit();
    bool loadFile(const QString &fileName);
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString fileName();
    bool maybeSave();
    static int count;

protected:
    void closeEvent(QCloseEvent *event);
private:
    void setCurrentFile(const QString &fileName);

    QString curFile;
    bool isUntitled;
    enum{MaxRecentFiles = 9};

signals:
    void updateRecentFiles();
    void counted(int);

private slots:
    void doModified();

};


#endif // MDITEXTEDIT_H

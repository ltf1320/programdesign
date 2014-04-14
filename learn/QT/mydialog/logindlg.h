#ifndef LOGINDLG_H
#define LOGINDLG_H


#include <QDialog>
#include <QLineEdit>

class CLoginDlg :public QDialog
{
    Q_OBJECT
    public:
        CLoginDlg(QWidget* = 0);
public slots:
        void accept();
private:
        QLineEdit* usrLineEdit;
        QLineEdit* pwdLineEdit;
};



#endif // LOGINDLG_H

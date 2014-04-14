#include "logindlg.h"
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QPalette>
#include <QColor>
CLoginDlg::CLoginDlg(QWidget* parent):QDialog(parent)
{
    QPalette palette;
    QColor color("blue");
    palette.setColor(QPalette::Window,color);
    color.setRed(255);
    palette.setColor(QPalette::ButtonText,color);
    setPalette(palette);
    QLabel* usrLabel=new QLabel(tr("用户名："));
    QLabel* pwdLabel=new QLabel(tr("密码："));
    usrLineEdit=new QLineEdit;
    pwdLineEdit=new QLineEdit;
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(usrLabel,0,0,1,1);
    gridLayout->addWidget(usrLineEdit,0,1,1,3);
    gridLayout->addWidget(pwdLabel,1,0,1,1);
    gridLayout->addWidget(pwdLineEdit,1,1,1,3);

    QPushButton* okBtn=new QPushButton(tr("确定"));
    QPushButton* cancelBtn=new QPushButton(tr("取消"));
   QHBoxLayout* btnLayout=new QHBoxLayout;
   btnLayout->setSpacing(60);
   btnLayout->addWidget(okBtn);
   btnLayout->addWidget(cancelBtn);

   QVBoxLayout* dlgLayout=new QVBoxLayout;
   dlgLayout->setMargin(40);
   dlgLayout->addLayout(gridLayout);
   dlgLayout->addStretch(40);
   dlgLayout->addLayout(btnLayout);
   setLayout(dlgLayout);

   connect(okBtn,SIGNAL(clicked()),this,SLOT(accept()));
   connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));

   setWindowTitle(tr("登陆"));
   resize(300,200);
}

void CLoginDlg::accept()
{
    if(usrLineEdit->text().trimmed()==tr("bool")&&pwdLineEdit->text()==tr("luo"))
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("登陆成功！"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
        QDialog::accept();
    }
    else
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle(tr("警告"));
        box.setText(tr("用户名或密码错误!"));
        box.setStandardButtons(QMessageBox::Yes);
        box.exec();
        usrLineEdit->setFocus();
    }
}

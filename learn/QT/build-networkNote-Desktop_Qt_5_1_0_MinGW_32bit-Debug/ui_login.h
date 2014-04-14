/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *closeBtn;
    QPushButton *minimumBtn;
    QWidget *loginWidget;
    QLineEdit *userLineEdit;
    QLineEdit *passWdLineEdit;
    QPushButton *loginBtn;
    QLabel *login_state_label;
    QPushButton *pushButton;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(376, 395);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        login->setCursor(QCursor(Qt::ArrowCursor));
        login->setFocusPolicy(Qt::StrongFocus);
        login->setStyleSheet(QLatin1String("#login{\n"
"	background:none;\n"
"	background-image: url(:/button/login_bg.png);\n"
"	border-radius:5px 5px;\n"
"}"));
        closeBtn = new QPushButton(login);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(340, 10, 25, 25));
        closeBtn->setFocusPolicy(Qt::NoFocus);
        closeBtn->setStyleSheet(QLatin1String("#closeBtn{\n"
"	min-width:25px;\n"
"	min-height:25px;\n"
"	max-width:25px;\n"
"	max-height:25px;\n"
"  \n"
"	image: url(:/button/login_close.png);\n"
"	border:0px;\n"
"}\n"
"#closeBtn:hover{\n"
"	\n"
"	\n"
"	image: url(:/button/login_close_2.png);\n"
"}"));
        closeBtn->setIconSize(QSize(20, 20));
        minimumBtn = new QPushButton(login);
        minimumBtn->setObjectName(QStringLiteral("minimumBtn"));
        minimumBtn->setGeometry(QRect(310, 10, 25, 25));
        minimumBtn->setFocusPolicy(Qt::NoFocus);
        minimumBtn->setStyleSheet(QLatin1String("#minimumBtn{\n"
"	border:0px;\n"
"	image: url(:/button/login_min.png);\n"
"}\n"
"#minimumBtn:hover{\n"
"	\n"
"	image: url(:/button/login_min_2.png);\n"
"}"));
        loginWidget = new QWidget(login);
        loginWidget->setObjectName(QStringLiteral("loginWidget"));
        loginWidget->setGeometry(QRect(0, 80, 371, 311));
        userLineEdit = new QLineEdit(loginWidget);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(41, 4, 291, 35));
        userLineEdit->setMinimumSize(QSize(0, 35));
        userLineEdit->setMaximumSize(QSize(16777215, 35));
        userLineEdit->setStyleSheet(QStringLiteral(""));
        userLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        passWdLineEdit = new QLineEdit(loginWidget);
        passWdLineEdit->setObjectName(QStringLiteral("passWdLineEdit"));
        passWdLineEdit->setGeometry(QRect(41, 54, 291, 35));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(passWdLineEdit->sizePolicy().hasHeightForWidth());
        passWdLineEdit->setSizePolicy(sizePolicy1);
        passWdLineEdit->setMinimumSize(QSize(0, 35));
        passWdLineEdit->setMaximumSize(QSize(16777, 35));
        passWdLineEdit->setStyleSheet(QStringLiteral(""));
        passWdLineEdit->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText);
        passWdLineEdit->setEchoMode(QLineEdit::Password);
        passWdLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        loginBtn = new QPushButton(loginWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(129, 150, 121, 41));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy2);
        loginBtn->setMinimumSize(QSize(111, 41));
        loginBtn->setMaximumSize(QSize(1677777, 167777));
        loginBtn->setCursor(QCursor(Qt::PointingHandCursor));
        loginBtn->setStyleSheet(QLatin1String("#loginBtn{\n"
"	margin-left:1px;\n"
"	image: url(:/button/login.png);\n"
"border-style:solid;\n"
"}\n"
"#loginBtn:hover{\n"
"	\n"
"	image: url(:/button/login_2.png);\n"
"}"));
        login_state_label = new QLabel(loginWidget);
        login_state_label->setObjectName(QStringLiteral("login_state_label"));
        login_state_label->setGeometry(QRect(56, 98, 231, 31));
        login_state_label->setStyleSheet(QLatin1String("#login_state_label{\n"
"	\n"
"	color: rgb(239, 249, 34);\n"
"}"));
        login_state_label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(loginWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 240, 31, 21));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("#pushButton{\n"
"	border:1px;\n"
"	color: rgb(241, 241, 241);\n"
"}\n"
"#pushButton:hover{\n"
"	border-bottom-style:solid;\n"
"	\n"
"	border-bottom-color: rgb(235, 235, 235);\n"
"}"));
        QWidget::setTabOrder(userLineEdit, passWdLineEdit);
        QWidget::setTabOrder(passWdLineEdit, loginBtn);
        QWidget::setTabOrder(loginBtn, pushButton);
        QWidget::setTabOrder(pushButton, minimumBtn);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", 0));
        closeBtn->setText(QString());
        minimumBtn->setText(QString());
        userLineEdit->setInputMask(QString());
        userLineEdit->setPlaceholderText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", 0));
        passWdLineEdit->setInputMask(QString());
        passWdLineEdit->setText(QString());
        passWdLineEdit->setPlaceholderText(QApplication::translate("login", "\345\257\206\347\240\201", 0));
        loginBtn->setText(QString());
        login_state_label->setText(QString());
        pushButton->setText(QApplication::translate("login", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

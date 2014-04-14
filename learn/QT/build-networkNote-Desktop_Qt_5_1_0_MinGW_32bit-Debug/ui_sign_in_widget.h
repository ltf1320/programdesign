/********************************************************************************
** Form generated from reading UI file 'sign_in_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_WIDGET_H
#define UI_SIGN_IN_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_in_widget
{
public:
    QLineEdit *signinUser;
    QLineEdit *signinPasswd;
    QLineEdit *confirmPasswd;
    QLineEdit *test_code;
    QLabel *test_code_label;
    QLabel *signinState;
    QPushButton *sign_inBtn;
    QPushButton *returnloginBtn;
    QPushButton *changeCheckCodeBtn;

    void setupUi(QWidget *sign_in_widget)
    {
        if (sign_in_widget->objectName().isEmpty())
            sign_in_widget->setObjectName(QStringLiteral("sign_in_widget"));
        sign_in_widget->resize(400, 300);
        sign_in_widget->setAutoFillBackground(false);
        sign_in_widget->setStyleSheet(QLatin1String("#sign_in_widget{\n"
"	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}"));
        signinUser = new QLineEdit(sign_in_widget);
        signinUser->setObjectName(QStringLiteral("signinUser"));
        signinUser->setGeometry(QRect(60, 10, 271, 31));
        signinUser->setAutoFillBackground(false);
        signinPasswd = new QLineEdit(sign_in_widget);
        signinPasswd->setObjectName(QStringLiteral("signinPasswd"));
        signinPasswd->setGeometry(QRect(60, 60, 271, 31));
        signinPasswd->setAutoFillBackground(false);
        signinPasswd->setEchoMode(QLineEdit::Password);
        confirmPasswd = new QLineEdit(sign_in_widget);
        confirmPasswd->setObjectName(QStringLiteral("confirmPasswd"));
        confirmPasswd->setGeometry(QRect(60, 110, 271, 31));
        confirmPasswd->setAutoFillBackground(false);
        confirmPasswd->setEchoMode(QLineEdit::Password);
        test_code = new QLineEdit(sign_in_widget);
        test_code->setObjectName(QStringLiteral("test_code"));
        test_code->setGeometry(QRect(60, 155, 101, 31));
        test_code->setAutoFillBackground(false);
        test_code_label = new QLabel(sign_in_widget);
        test_code_label->setObjectName(QStringLiteral("test_code_label"));
        test_code_label->setGeometry(QRect(260, 190, 90, 31));
        test_code_label->setAutoFillBackground(false);
        test_code_label->setStyleSheet(QLatin1String("#test_code_label{\n"
"	\n"
"	background-color: rgb(255, 255, 255,0);\n"
"}"));
        signinState = new QLabel(sign_in_widget);
        signinState->setObjectName(QStringLiteral("signinState"));
        signinState->setGeometry(QRect(70, 200, 251, 31));
        signinState->setAutoFillBackground(false);
        signinState->setStyleSheet(QLatin1String("#signinState{\n"
"	\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	color:rgb(241, 241, 241);\n"
"}"));
        signinState->setAlignment(Qt::AlignCenter);
        sign_inBtn = new QPushButton(sign_in_widget);
        sign_inBtn->setObjectName(QStringLiteral("sign_inBtn"));
        sign_inBtn->setGeometry(QRect(60, 242, 91, 31));
        sign_inBtn->setCursor(QCursor(Qt::PointingHandCursor));
        returnloginBtn = new QPushButton(sign_in_widget);
        returnloginBtn->setObjectName(QStringLiteral("returnloginBtn"));
        returnloginBtn->setGeometry(QRect(220, 241, 91, 31));
        returnloginBtn->setCursor(QCursor(Qt::PointingHandCursor));
        changeCheckCodeBtn = new QPushButton(sign_in_widget);
        changeCheckCodeBtn->setObjectName(QStringLiteral("changeCheckCodeBtn"));
        changeCheckCodeBtn->setGeometry(QRect(260, 154, 71, 31));

        retranslateUi(sign_in_widget);

        QMetaObject::connectSlotsByName(sign_in_widget);
    } // setupUi

    void retranslateUi(QWidget *sign_in_widget)
    {
        sign_in_widget->setWindowTitle(QApplication::translate("sign_in_widget", "Form", 0));
        signinUser->setPlaceholderText(QApplication::translate("sign_in_widget", "\347\224\250\346\210\267\345\220\215\346\263\250\345\206\214", 0));
        signinPasswd->setPlaceholderText(QApplication::translate("sign_in_widget", "\345\257\206\347\240\201", 0));
        confirmPasswd->setPlaceholderText(QApplication::translate("sign_in_widget", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        test_code->setPlaceholderText(QApplication::translate("sign_in_widget", "\351\252\214\350\257\201\347\240\201", 0));
        test_code_label->setText(QString());
        signinState->setText(QString());
        sign_inBtn->setText(QApplication::translate("sign_in_widget", "\346\263\250\345\206\214", 0));
        returnloginBtn->setText(QApplication::translate("sign_in_widget", "\350\277\224\345\233\236\347\231\273\345\275\225", 0));
        changeCheckCodeBtn->setText(QApplication::translate("sign_in_widget", "\346\233\264\346\215\242\351\252\214\350\257\201\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class sign_in_widget: public Ui_sign_in_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_WIDGET_H

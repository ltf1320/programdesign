/********************************************************************************
** Form generated from reading UI file 'SameLineWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMELINEWIDGET_H
#define UI_SAMELINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SameLineWidget
{
public:
    QAction *actNext;
    QAction *actPre;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuList;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SameLineWidget)
    {
        if (SameLineWidget->objectName().isEmpty())
            SameLineWidget->setObjectName(QStringLiteral("SameLineWidget"));
        SameLineWidget->resize(800, 600);
        actNext = new QAction(SameLineWidget);
        actNext->setObjectName(QStringLiteral("actNext"));
        actPre = new QAction(SameLineWidget);
        actPre->setObjectName(QStringLiteral("actPre"));
        centralwidget = new QWidget(SameLineWidget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        SameLineWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SameLineWidget);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuList = new QMenu(menubar);
        menuList->setObjectName(QStringLiteral("menuList"));
        SameLineWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(SameLineWidget);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SameLineWidget->setStatusBar(statusbar);

        menubar->addAction(menuList->menuAction());
        menuList->addAction(actNext);
        menuList->addAction(actPre);

        retranslateUi(SameLineWidget);

        QMetaObject::connectSlotsByName(SameLineWidget);
    } // setupUi

    void retranslateUi(QMainWindow *SameLineWidget)
    {
        SameLineWidget->setWindowTitle(QApplication::translate("SameLineWidget", "MainWindow", 0));
        actNext->setText(QApplication::translate("SameLineWidget", "\344\270\213\344\270\200\344\270\252", 0));
        actPre->setText(QApplication::translate("SameLineWidget", "\345\211\215\344\270\200\344\270\252", 0));
        menuList->setTitle(QApplication::translate("SameLineWidget", "list", 0));
    } // retranslateUi

};

namespace Ui {
    class SameLineWidget: public Ui_SameLineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMELINEWIDGET_H

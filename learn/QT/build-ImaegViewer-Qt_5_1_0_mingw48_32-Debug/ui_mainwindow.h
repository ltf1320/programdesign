/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpen;
    QAction *actClose;
    QAction *actNext;
    QAction *actPre;
    QAction *actQuit;
    QAction *actL90;
    QAction *actR90;
    QAction *actLarge;
    QAction *actSmall;
    QAction *actASize;
    QAction *actFSize;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *fileToolBar;
    QToolBar *opeToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(576, 503);
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/fileopen.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon);
        actClose = new QAction(MainWindow);
        actClose->setObjectName(QStringLiteral("actClose"));
        actNext = new QAction(MainWindow);
        actNext->setObjectName(QStringLiteral("actNext"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/next.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actNext->setIcon(icon1);
        actPre = new QAction(MainWindow);
        actPre->setObjectName(QStringLiteral("actPre"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/previous.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actPre->setIcon(icon2);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        actL90 = new QAction(MainWindow);
        actL90->setObjectName(QStringLiteral("actL90"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/redo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actL90->setIcon(icon3);
        actR90 = new QAction(MainWindow);
        actR90->setObjectName(QStringLiteral("actR90"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/undo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actR90->setIcon(icon4);
        actLarge = new QAction(MainWindow);
        actLarge->setObjectName(QStringLiteral("actLarge"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/largen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actLarge->setIcon(icon5);
        actSmall = new QAction(MainWindow);
        actSmall->setObjectName(QStringLiteral("actSmall"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/smallen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSmall->setIcon(icon6);
        actASize = new QAction(MainWindow);
        actASize->setObjectName(QStringLiteral("actASize"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actASize->setIcon(icon7);
        actFSize = new QAction(MainWindow);
        actFSize->setObjectName(QStringLiteral("actFSize"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/monitor.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actFSize->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 576, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        fileToolBar = new QToolBar(MainWindow);
        fileToolBar->setObjectName(QStringLiteral("fileToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, fileToolBar);
        opeToolBar = new QToolBar(MainWindow);
        opeToolBar->setObjectName(QStringLiteral("opeToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, opeToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actOpen);
        menu->addAction(actClose);
        menu->addAction(actNext);
        menu->addAction(actPre);
        menu->addSeparator();
        menu->addAction(actQuit);
        menu_2->addAction(actL90);
        menu_2->addAction(actR90);
        menu_2->addAction(actLarge);
        menu_2->addAction(actSmall);
        menu_2->addAction(actASize);
        menu_2->addAction(actFSize);
        fileToolBar->addAction(actOpen);
        fileToolBar->addAction(actNext);
        fileToolBar->addAction(actPre);
        opeToolBar->addAction(actL90);
        opeToolBar->addAction(actR90);
        opeToolBar->addAction(actLarge);
        opeToolBar->addAction(actSmall);
        opeToolBar->addAction(actASize);
        opeToolBar->addAction(actFSize);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", 0));
        actClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&C)", 0));
        actNext->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240(&N)", 0));
        actPre->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\345\274\240(&P)", 0));
        actQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&Q)", 0));
        actL90->setText(QApplication::translate("MainWindow", "\345\267\246\350\275\25490\345\272\246(&L)", 0));
        actR90->setText(QApplication::translate("MainWindow", "\345\217\263\350\275\25490\345\272\246(&R)", 0));
        actLarge->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247(&L)", 0));
        actSmall->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217(&S)", 0));
        actASize->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\256\236\351\231\205\345\244\247\345\260\217(&A)", 0));
        actFSize->setText(QApplication::translate("MainWindow", "\345\214\271\351\205\215\347\252\227\345\217\243\345\244\247\345\260\217(&P)", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\345\257\274\350\210\252(&F)", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234(&O)", 0));
        opeToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

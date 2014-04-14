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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *choseAndMove;
    QAction *drawLine;
    QAction *drawRec;
    QAction *drawEllipse;
    QAction *combine;
    QAction *split;
    QAction *save;
    QAction *open;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        choseAndMove = new QAction(MainWindow);
        choseAndMove->setObjectName(QStringLiteral("choseAndMove"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        choseAndMove->setIcon(icon);
        drawLine = new QAction(MainWindow);
        drawLine->setObjectName(QStringLiteral("drawLine"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawLine->setIcon(icon1);
        drawRec = new QAction(MainWindow);
        drawRec->setObjectName(QStringLiteral("drawRec"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/rec.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawRec->setIcon(icon2);
        drawEllipse = new QAction(MainWindow);
        drawEllipse->setObjectName(QStringLiteral("drawEllipse"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawEllipse->setIcon(icon3);
        combine = new QAction(MainWindow);
        combine->setObjectName(QStringLiteral("combine"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/combine2.png"), QSize(), QIcon::Normal, QIcon::Off);
        combine->setIcon(icon4);
        split = new QAction(MainWindow);
        split->setObjectName(QStringLiteral("split"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/split.png"), QSize(), QIcon::Normal, QIcon::Off);
        split->setIcon(icon5);
        save = new QAction(MainWindow);
        save->setObjectName(QStringLiteral("save"));
        open = new QAction(MainWindow);
        open->setObjectName(QStringLiteral("open"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(save);
        menu->addAction(open);
        toolBar->addAction(choseAndMove);
        toolBar->addAction(drawLine);
        toolBar->addAction(drawRec);
        toolBar->addAction(drawEllipse);
        toolBar->addAction(combine);
        toolBar->addAction(split);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        choseAndMove->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\222\214\347\247\273\345\212\250", 0));
        drawLine->setText(QApplication::translate("MainWindow", "\347\224\273\347\233\264\347\272\277", 0));
        drawRec->setText(QApplication::translate("MainWindow", "\347\224\273\347\237\251\345\275\242", 0));
        drawEllipse->setText(QApplication::translate("MainWindow", "\347\224\273\345\234\206", 0));
        combine->setText(QApplication::translate("MainWindow", "\347\273\204\345\220\210", 0));
        split->setText(QApplication::translate("MainWindow", "\346\213\206\345\210\206", 0));
        save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0));
        open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

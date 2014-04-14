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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actNew;
    QAction *actOpen;
    QAction *actClose;
    QAction *actSave;
    QAction *actASave;
    QAction *actPrint;
    QAction *actQuit;
    QAction *actUndo;
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actAll;
    QAction *actFind;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_T;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(579, 392);
        actNew = new QAction(MainWindow);
        actNew->setObjectName(QStringLiteral("actNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/new.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actNew->setIcon(icon);
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/fileopen.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon1);
        actClose = new QAction(MainWindow);
        actClose->setObjectName(QStringLiteral("actClose"));
        actSave = new QAction(MainWindow);
        actSave->setObjectName(QStringLiteral("actSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/filesave.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon2);
        actASave = new QAction(MainWindow);
        actASave->setObjectName(QStringLiteral("actASave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/filesaveas.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actASave->setIcon(icon3);
        actPrint = new QAction(MainWindow);
        actPrint->setObjectName(QStringLiteral("actPrint"));
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        actUndo = new QAction(MainWindow);
        actUndo->setObjectName(QStringLiteral("actUndo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/undo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actUndo->setIcon(icon4);
        actCut = new QAction(MainWindow);
        actCut->setObjectName(QStringLiteral("actCut"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/editcut.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon5);
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName(QStringLiteral("actCopy"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/editcopy.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon6);
        actPaste = new QAction(MainWindow);
        actPaste->setObjectName(QStringLiteral("actPaste"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/editpaste.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon7);
        actAll = new QAction(MainWindow);
        actAll->setObjectName(QStringLiteral("actAll"));
        actFind = new QAction(MainWindow);
        actFind->setObjectName(QStringLiteral("actFind"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 579, 21));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_T = new QMenu(menuBar);
        menu_T->setObjectName(QStringLiteral("menu_T"));
        MainWindow->setMenuBar(menuBar);
        fileToolBar = new QToolBar(MainWindow);
        fileToolBar->setObjectName(QStringLiteral("fileToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, fileToolBar);
        editToolBar = new QToolBar(MainWindow);
        editToolBar->setObjectName(QStringLiteral("editToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, editToolBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_T->menuAction());
        menu_F->addAction(actNew);
        menu_F->addAction(actOpen);
        menu_F->addAction(actClose);
        menu_F->addSeparator();
        menu_F->addAction(actSave);
        menu_F->addAction(actASave);
        menu_F->addAction(actPrint);
        menu_F->addSeparator();
        menu_F->addAction(actQuit);
        menu_E->addAction(actUndo);
        menu_E->addAction(actCut);
        menu_E->addAction(actCopy);
        menu_E->addAction(actPaste);
        menu_E->addSeparator();
        menu_E->addAction(actAll);
        menu_T->addAction(actFind);
        fileToolBar->addAction(actNew);
        fileToolBar->addAction(actOpen);
        fileToolBar->addAction(actSave);
        fileToolBar->addAction(actASave);
        editToolBar->addAction(actUndo);
        editToolBar->addAction(actCut);
        editToolBar->addAction(actCopy);
        editToolBar->addAction(actPaste);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", 0));
        actOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", 0));
        actClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&C)", 0));
        actSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", 0));
        actSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S, Enter", 0));
        actASave->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", 0));
        actPrint->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260(&P)", 0));
        actQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", 0));
        actUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&U)", 0));
        actUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actCut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", 0));
        actCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", 0));
        actCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actPaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", 0));
        actPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actAll->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211(&A)", 0));
        actAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        actFind->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\346\226\207\344\273\266(&F)", 0));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", 0));
        menu_T->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", 0));
        editToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openMapact;
    QAction *saveMapact;
    QAction *openArract;
    QAction *saveArract;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *pathE;
    QLineEdit *numE;
    QPushButton *pushButton;
    QPushButton *preBtn;
    QPushButton *nextBtn;
    QWidget *gridLayoutWidget;
    QGridLayout *arrLayout;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QLineEdit *iEdit;
    QLineEdit *jEdit;
    QPushButton *redoBtn;
    QPushButton *dispBtn;
    QLabel *label_3;
    QPushButton *findMBtn;
    QLineEdit *jdisE;
    QLabel *label_4;
    QLineEdit *nowE;
    QPushButton *findSBtn;
    QPushButton *listSBtn;
    QPushButton *matchFBtn;
    QLabel *label_5;
    QPushButton *zinBtn;
    QPushButton *zoutBtn;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1100, 506);
        openMapact = new QAction(MainWindow);
        openMapact->setObjectName(QStringLiteral("openMapact"));
        saveMapact = new QAction(MainWindow);
        saveMapact->setObjectName(QStringLiteral("saveMapact"));
        openArract = new QAction(MainWindow);
        openArract->setObjectName(QStringLiteral("openArract"));
        saveArract = new QAction(MainWindow);
        saveArract->setObjectName(QStringLiteral("saveArract"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 54, 12));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 110, 54, 12));
        pathE = new QLineEdit(centralwidget);
        pathE->setObjectName(QStringLiteral("pathE"));
        pathE->setGeometry(QRect(180, 50, 113, 20));
        numE = new QLineEdit(centralwidget);
        numE->setObjectName(QStringLiteral("numE"));
        numE->setGeometry(QRect(180, 100, 113, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 160, 75, 23));
        preBtn = new QPushButton(centralwidget);
        preBtn->setObjectName(QStringLiteral("preBtn"));
        preBtn->setGeometry(QRect(140, 160, 75, 23));
        nextBtn = new QPushButton(centralwidget);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));
        nextBtn->setGeometry(QRect(240, 160, 75, 23));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(320, 0, 391, 251));
        arrLayout = new QGridLayout(gridLayoutWidget);
        arrLayout->setSpacing(0);
        arrLayout->setObjectName(QStringLiteral("arrLayout"));
        arrLayout->setSizeConstraint(QLayout::SetMinimumSize);
        arrLayout->setContentsMargins(0, 0, 0, 0);
        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(50, 270, 75, 23));
        delBtn = new QPushButton(centralwidget);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        delBtn->setGeometry(QRect(140, 270, 75, 23));
        iEdit = new QLineEdit(centralwidget);
        iEdit->setObjectName(QStringLiteral("iEdit"));
        iEdit->setGeometry(QRect(50, 220, 81, 21));
        jEdit = new QLineEdit(centralwidget);
        jEdit->setObjectName(QStringLiteral("jEdit"));
        jEdit->setGeometry(QRect(220, 220, 91, 21));
        redoBtn = new QPushButton(centralwidget);
        redoBtn->setObjectName(QStringLiteral("redoBtn"));
        redoBtn->setGeometry(QRect(230, 270, 75, 23));
        dispBtn = new QPushButton(centralwidget);
        dispBtn->setObjectName(QStringLiteral("dispBtn"));
        dispBtn->setGeometry(QRect(630, 260, 75, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 220, 54, 12));
        findMBtn = new QPushButton(centralwidget);
        findMBtn->setObjectName(QStringLiteral("findMBtn"));
        findMBtn->setGeometry(QRect(230, 350, 75, 23));
        jdisE = new QLineEdit(centralwidget);
        jdisE->setObjectName(QStringLiteral("jdisE"));
        jdisE->setGeometry(QRect(142, 350, 71, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 330, 54, 12));
        nowE = new QLineEdit(centralwidget);
        nowE->setObjectName(QStringLiteral("nowE"));
        nowE->setGeometry(QRect(50, 350, 71, 20));
        findSBtn = new QPushButton(centralwidget);
        findSBtn->setObjectName(QStringLiteral("findSBtn"));
        findSBtn->setGeometry(QRect(330, 350, 75, 23));
        listSBtn = new QPushButton(centralwidget);
        listSBtn->setObjectName(QStringLiteral("listSBtn"));
        listSBtn->setGeometry(QRect(430, 350, 75, 23));
        matchFBtn = new QPushButton(centralwidget);
        matchFBtn->setObjectName(QStringLiteral("matchFBtn"));
        matchFBtn->setGeometry(QRect(290, 400, 141, 23));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 400, 161, 21));
        zinBtn = new QPushButton(centralwidget);
        zinBtn->setObjectName(QStringLiteral("zinBtn"));
        zinBtn->setGeometry(QRect(370, 270, 75, 23));
        zoutBtn = new QPushButton(centralwidget);
        zoutBtn->setObjectName(QStringLiteral("zoutBtn"));
        zoutBtn->setGeometry(QRect(480, 270, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1100, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(openMapact);
        menu->addAction(saveMapact);
        menu->addAction(openArract);
        menu->addAction(saveArract);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openMapact->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200map", 0));
        saveMapact->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230map", 0));
        openArract->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200arr", 0));
        saveArract->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230arr", 0));
        label->setText(QApplication::translate("MainWindow", "path", 0));
        label_2->setText(QApplication::translate("MainWindow", "number", 0));
        pathE->setText(QApplication::translate("MainWindow", "D:\\programdesign\\learn\\QT\\2013shuxuejianmob2\\p3", 0));
        numE->setText(QApplication::translate("MainWindow", "208", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        preBtn->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252", 0));
        nextBtn->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", 0));
        addBtn->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", 0));
        delBtn->setText(QApplication::translate("MainWindow", "\345\210\240\345\216\273", 0));
        redoBtn->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232", 0));
        dispBtn->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272", 0));
        label_3->setText(QApplication::translate("MainWindow", "to", 0));
        findMBtn->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\345\214\271\351\205\215", 0));
        jdisE->setText(QApplication::translate("MainWindow", "250", 0));
        label_4->setText(QApplication::translate("MainWindow", "jdis", 0));
        findSBtn->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\345\220\214\350\241\214", 0));
        listSBtn->setText(QApplication::translate("MainWindow", "\345\210\227\345\207\272\345\220\214\350\241\214", 0));
        matchFBtn->setText(QApplication::translate("MainWindow", "\345\214\271\351\205\215\346\234\200\347\273\210\347\273\223\346\236\234", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\211\276\345\210\26011\350\241\214\344\272\206\357\274\232", 0));
        zinBtn->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        zoutBtn->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

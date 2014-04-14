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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mainmenubar.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QWidget *editWidget;
    QWidget *includeContentWidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *contentWidget;
    QPushButton *controlBtn;
    QLineEdit *searchLineedit;
    QPushButton *searchBtn;
    QListView *listView;
    QListView *noteBookList;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *createNoteBookBtn;
    QWidget *includeEditWidget;
    QHBoxLayout *horizontalLayout_6;
    mainMenuBar *menubar;
    QLabel *userNameLabel;
    QWidget *btnContainer;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *logoutBtn;
    QPushButton *minimumBtn;
    QPushButton *closeBtn;
    QWidget *toolBar;
    QPushButton *returnBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *newNoteBtn;
    QPushButton *deleteNote;
    QPushButton *syncBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(777, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMouseTracking(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMouseTracking(true);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        editWidget = new QWidget(centralWidget);
        editWidget->setObjectName(QStringLiteral("editWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editWidget->sizePolicy().hasHeightForWidth());
        editWidget->setSizePolicy(sizePolicy2);
        editWidget->setMouseTracking(true);
        editWidget->setStyleSheet(QLatin1String("#editWidget{\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0.028, x2:0, y2:1, stop:0 rgba(64, 172, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        includeContentWidget = new QWidget(editWidget);
        includeContentWidget->setObjectName(QStringLiteral("includeContentWidget"));
        includeContentWidget->setGeometry(QRect(0, 0, 777, 496));
        horizontalLayout_4 = new QHBoxLayout(includeContentWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        contentWidget = new QWidget(includeContentWidget);
        contentWidget->setObjectName(QStringLiteral("contentWidget"));
        contentWidget->setMouseTracking(true);
        controlBtn = new QPushButton(contentWidget);
        controlBtn->setObjectName(QStringLiteral("controlBtn"));
        controlBtn->setGeometry(QRect(710, 198, 61, 101));
        controlBtn->setMinimumSize(QSize(61, 101));
        controlBtn->setMaximumSize(QSize(61, 101));
        searchLineedit = new QLineEdit(contentWidget);
        searchLineedit->setObjectName(QStringLiteral("searchLineedit"));
        searchLineedit->setGeometry(QRect(160, 0, 131, 35));
        searchBtn = new QPushButton(contentWidget);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        searchBtn->setGeometry(QRect(290, 0, 91, 37));
        listView = new QListView(contentWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(150, 65, 221, 431));
        listView->setMouseTracking(true);
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setContextMenuPolicy(Qt::CustomContextMenu);
        listView->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
"    background: url(images/scrollbar-vertical-bg.png);\n"
"    width: 9px;\n"
"    margin: 0px 0 0px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: rgb(195, 195, 195);\n"
"    min-height: 20px;\n"
"    margin: 0 1px 0 2px;\n"
"    border-radius: 3px;\n"
"    border: none;\n"
"    /*background: qlineargradient(spread:reflect, \n"
"        x1:0, y1:0, x2:1, y2:0, \n"
"        stop:0 rgba(164, 164, 164, 255), \n"
"        stop:0.5 rgba(120, 120, 120, 255),\n"
"        stop:1 rgba(164, 164, 164, 255));*/\n"
"    /*border-image: url(images/scrollbar-vertical-thumb.png) 8px 0 8px 0 fixed;*/\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"    background: url(images/scrollbar-vertical-bg.png);\n"
"    height: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    background: url(images/scrollbar-vertical-bg.png);\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
""
                        "}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"    border: 1px solid grey;\n"
"    width: 3px;\n"
"    height: 3px;\n"
"    background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"QListView {\n"
"	background-color: rgb(248,246,245);\n"
"   	\n"
"    selection-background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
"}\n"
"QListView::item{\n"
"	border-top:1px solid rgb(186,211,233);\n"
"	border-right:1px solid rgb(186,211,233);\n"
"	border-bottom:1px solid rgb(186,211,233);\n"
"	border-left:1px solid rgb(186,211,233);\n"
"}\n"
"QListView::item:alternate {\n"
"     background: red;\n"
" }\n"
"QListView::item:hover{\n"
"	background-color:rgb(223,233,242);\n"
"}\n"
"QListView::item:selected { /*\350\242\253\351\200\211\344\270\255\347\232\204index*/\n"
"    background-color: rgb(223,233,242);\n"
"	border-top:1px solid rgb(186,211,233);\n"
""
                        "	border-right:1px solid rgb(186,211,233);\n"
"	border-bottom:1px solid rgb(186,211,233);\n"
"	border-left:1px solid rgb(186,211,233);\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #FAFBFE, \n"
"        stop: 1 #DCDEF1);\n"
"    \n"
"}\n"
""));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setDragDropMode(QAbstractItemView::DragOnly);
        listView->setAlternatingRowColors(false);
        listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listView->setSelectionBehavior(QAbstractItemView::SelectItems);
        listView->setMovement(QListView::Free);
        listView->setViewMode(QListView::ListMode);
        noteBookList = new QListView(contentWidget);
        noteBookList->setObjectName(QStringLiteral("noteBookList"));
        noteBookList->setGeometry(QRect(0, 65, 151, 431));
        noteBookList->setFocusPolicy(Qt::ClickFocus);
        noteBookList->setContextMenuPolicy(Qt::CustomContextMenu);
        noteBookList->setStyleSheet(QLatin1String("QListView::item{\n"
"	height:30;\n"
"}\n"
"QListView::item:focused{\n"
"	padding:0;\n"
"}"));
        noteBookList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        label_2 = new QLabel(contentWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 39, 151, 24));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(contentWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 42, 221, 20));
        label_3->setAlignment(Qt::AlignCenter);
        createNoteBookBtn = new QPushButton(contentWidget);
        createNoteBookBtn->setObjectName(QStringLiteral("createNoteBookBtn"));
        createNoteBookBtn->setGeometry(QRect(0, 0, 151, 41));

        horizontalLayout_4->addWidget(contentWidget);

        includeEditWidget = new QWidget(editWidget);
        includeEditWidget->setObjectName(QStringLiteral("includeEditWidget"));
        includeEditWidget->setGeometry(QRect(777, 0, 777, 496));

        gridLayout_2->addWidget(editWidget, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        menubar = new mainMenuBar(centralWidget);
        menubar->setObjectName(QStringLiteral("menubar"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy3);
        menubar->setMinimumSize(QSize(0, 41));
        menubar->setMaximumSize(QSize(16777215, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(55, 144, 206, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(122, 201, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(88, 172, 230, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(27, 72, 103, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(36, 96, 137, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(155, 199, 230, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        menubar->setPalette(palette);
        menubar->setMouseTracking(false);
        menubar->setStyleSheet(QLatin1String("#menubar{\n"
"	background-color: rgb(55, 144, 206);\n"
"}"));
        userNameLabel = new QLabel(menubar);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));
        userNameLabel->setGeometry(QRect(0, 0, 91, 41));
        userNameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(menubar);

        btnContainer = new QWidget(centralWidget);
        btnContainer->setObjectName(QStringLiteral("btnContainer"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnContainer->sizePolicy().hasHeightForWidth());
        btnContainer->setSizePolicy(sizePolicy4);
        btnContainer->setMinimumSize(QSize(0, 0));
        btnContainer->setMaximumSize(QSize(150, 41));
        btnContainer->setMouseTracking(true);
        btnContainer->setStyleSheet(QLatin1String("#btnContainer{\n"
"background-color: rgb(55, 144, 206);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(btnContainer);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logoutBtn = new QPushButton(btnContainer);
        logoutBtn->setObjectName(QStringLiteral("logoutBtn"));
        sizePolicy3.setHeightForWidth(logoutBtn->sizePolicy().hasHeightForWidth());
        logoutBtn->setSizePolicy(sizePolicy3);
        logoutBtn->setMinimumSize(QSize(50, 0));
        logoutBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(logoutBtn);

        minimumBtn = new QPushButton(btnContainer);
        minimumBtn->setObjectName(QStringLiteral("minimumBtn"));
        minimumBtn->setStyleSheet(QLatin1String("#minimumBtn{\n"
"	min-width:25px;\n"
"	min-height:25px;\n"
"	max-width:25px;\n"
"	max-height:25px;\n"
"	image: url(:/button/min1.png);\n"
"	background-color:rgb(55, 144, 206);\n"
"	border:0px;\n"
"}\n"
"#minimumBtn:hover{\n"
"	image:url(:/button/min.png);\n"
"}"));

        horizontalLayout->addWidget(minimumBtn);

        closeBtn = new QPushButton(btnContainer);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setStyleSheet(QLatin1String("#closeBtn{\n"
"	min-width:25px;\n"
"	min-height:25px;\n"
"	max-width:25px;\n"
"	max-height:25px;\n"
"	image: url(:/button/close.png);\n"
"	background-color:  rgb(55, 144, 206);\n"
"	border:0px;\n"
"}\n"
"#closeBtn:hover{\n"
"	\n"
"	image: url(:/button/closeHover.png);\n"
"}"));
        closeBtn->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(closeBtn);


        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_6->addWidget(btnContainer);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        toolBar = new QWidget(centralWidget);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        sizePolicy4.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy4);
        toolBar->setMinimumSize(QSize(0, 61));
        toolBar->setMaximumSize(QSize(16777215, 61));
        toolBar->setMouseTracking(true);
        toolBar->setStyleSheet(QLatin1String("#toolBar{\n"
"background-color: rgb(255, 255, 255);\n"
"border-bottom-width:3px;\n"
"border-style:outset;\n"
"border-bottom-color: qlineargradient(spread:pad, x1:0.414, y1:0.943, x2:0.544955, y2:0.341, stop:0 rgba(175, 180, 177, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        returnBtn = new QPushButton(toolBar);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));
        returnBtn->setGeometry(QRect(20, 10, 75, 41));
        layoutWidget = new QWidget(toolBar);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 20, 239, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        newNoteBtn = new QPushButton(layoutWidget);
        newNoteBtn->setObjectName(QStringLiteral("newNoteBtn"));
        sizePolicy.setHeightForWidth(newNoteBtn->sizePolicy().hasHeightForWidth());
        newNoteBtn->setSizePolicy(sizePolicy);
        newNoteBtn->setMouseTracking(false);

        horizontalLayout_3->addWidget(newNoteBtn);

        deleteNote = new QPushButton(layoutWidget);
        deleteNote->setObjectName(QStringLiteral("deleteNote"));
        sizePolicy.setHeightForWidth(deleteNote->sizePolicy().hasHeightForWidth());
        deleteNote->setSizePolicy(sizePolicy);
        deleteNote->setMouseTracking(false);

        horizontalLayout_3->addWidget(deleteNote);

        syncBtn = new QPushButton(layoutWidget);
        syncBtn->setObjectName(QStringLiteral("syncBtn"));
        sizePolicy.setHeightForWidth(syncBtn->sizePolicy().hasHeightForWidth());
        syncBtn->setSizePolicy(sizePolicy);
        syncBtn->setMouseTracking(false);

        horizontalLayout_3->addWidget(syncBtn);


        gridLayout_2->addWidget(toolBar, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        controlBtn->setText(QApplication::translate("MainWindow", "PushButton", 0));
        searchBtn->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\347\254\224\350\256\260\346\234\254", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\347\254\224\350\256\260", 0));
        createNoteBookBtn->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\254\224\350\256\260\346\234\254", 0));
        userNameLabel->setText(QString());
        logoutBtn->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200", 0));
        minimumBtn->setText(QString());
        closeBtn->setText(QString());
        returnBtn->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236\347\233\256\345\275\225", 0));
        newNoteBtn->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\254\224\350\256\260", 0));
        deleteNote->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", 0));
        syncBtn->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

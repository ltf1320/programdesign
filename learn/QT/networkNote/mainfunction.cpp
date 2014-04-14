#include "mainfunction.h"
#include <QDateTime>
#include <QDebug>
#include <QHeaderView>


/******************************************************/
mainFunction::mainFunction(QObject *parent) :
    QObject(parent)
{
}
mainFunction::mainFunction(QWidget *_includecontentWidget, QWidget *_includeeditWidget, QWidget *_contentWidget, QListView *list, QWidget *_editwidget, QLineEdit *_searchLineEdit, QPushButton *_searchBtn,QListView *_notebooklist)
{
          includeContentWidget =_includecontentWidget;
          includeEditWidget=_includeeditWidget;
          contentWidget=_contentWidget;
          noteList= list;
          editWidget = _editwidget;
          searchLineEdit = _searchLineEdit;
          searchBtn = _searchBtn;
          noteBookList = _notebooklist;
    //CatalogueOutAnimation = new QPropertyAnimation;
    //CatalogueInAnimation = new QPropertyAnimation;
    editPanelInAnimation = new QPropertyAnimation;
    editPanelOutAnimation = new QPropertyAnimation;
    //goToEditAnimationGroup = new QParallelAnimationGroup;
    //goToEditAnimationGroup = new QParallelAnimationGroup;

    editPanel = new editPatr(includeEditWidget);

    //editPanel->setGeometry(0,0,777,496);
    pNotebookListmodel = new noteBookListModel(this);
    pNoteListmodel = new noteListModel(this);


    noteBookList->setModel(pNotebookListmodel);
    noteList->setModel(pNoteListmodel);


    midConnection  = new midLayer(noteBookList,pNotebookListmodel,noteList,pNoteListmodel,editPanel);

    noteBook defaultNote;
    defaultNote.setNoteBookId("0");
    defaultNote.setNoteBookName(tr("默认笔记本"));

    midConnection->creatNewNoteBook(defaultNote);

    noteBookList->setCurrentIndex(pNotebookListmodel->index(0));

    initSignal_Slot();
    iniAnimation();
}
mainFunction::~mainFunction()
{

}
/*************初始化动画、信号槽*************/
void mainFunction::initSignal_Slot()
{
    qDebug() << "in signal slot";
    connect(noteList,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(goToEdit()));
    connect(noteBookList,SIGNAL(clicked(QModelIndex)),midConnection,SLOT(connectNoteBookModelToNoteModel(QModelIndex)));
    connect(noteList,SIGNAL(doubleClicked(QModelIndex)),midConnection,SLOT(connectNoteModelToEditPannel(QModelIndex)));
    connect(noteBookList,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(rightButtonToNoteBookView(QPoint)));
    connect(noteList,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(rightButtonToNoteView(QPoint)));
    connect(noteList,SIGNAL(clicked(QModelIndex)),this,SLOT(printCurrentRow(QModelIndex)));

}
void mainFunction::printCurrentRow(const QModelIndex &index)
{
    qDebug() << "current row in noteListView" << index.row();
}
void mainFunction::iniAnimation()
{
    qDebug() << "in animation";
    /*CatalogueInAnimation->setTargetObject(includeContentWidget);
    CatalogueInAnimation->setPropertyName("geometry");
    CatalogueInAnimation->setDuration(1000);
    CatalogueInAnimation->setEasingCurve(QEasingCurve::InCubic);
    CatalogueInAnimation->setStartValue(QRect(-777,0,777,496));
    CatalogueInAnimation->setEndValue(QRect(0,0,777,496));

    CatalogueOutAnimation->setTargetObject(includeContentWidget);
    CatalogueOutAnimation->setPropertyName("geometry");
    CatalogueOutAnimation->setDuration(1000);
    CatalogueOutAnimation->setEasingCurve(QEasingCurve::OutCubic);
    CatalogueOutAnimation->setStartValue(QRect(0,0,777,496));
    CatalogueOutAnimation->setEndValue(QRect(-777,0,777,496));*/

    editPanelInAnimation->setTargetObject(includeEditWidget);
    editPanelInAnimation->setPropertyName("geometry");
    editPanelInAnimation->setDuration(1000);
    editPanelInAnimation->setEasingCurve(QEasingCurve::InCubic);
    //editPanelInAnimation->setStartValue(QRect(777,0,777,496));
    editPanelInAnimation->setEndValue(QRect(0,0,777,496));

    editPanelOutAnimation->setTargetObject(includeEditWidget);
    editPanelOutAnimation->setPropertyName("geometry");
    editPanelOutAnimation->setDuration(1000);
    editPanelOutAnimation->setEasingCurve(QEasingCurve::OutCubic);
    //editPanelOutAnimation->setStartValue(QRect(0,0,777,496));
    editPanelOutAnimation->setEndValue(QRect(777,0,777,496));

    /*goToEditAnimationGroup->addAnimation(CatalogueOutAnimation);
    goToEditAnimationGroup->addAnimation(editPanelInAnimation);

    goToCatalogueAnimationGroup->addAnimation(CatalogueInAnimation);
    goToCatalogueAnimationGroup->addAnimation(editPanelOutAnimation);*/

}
/**************************************************/



/******************新建笔记**************************/
void mainFunction::createNewNote()
{

    content.setTitle(tr("无标题笔记"));
    content.setCreateTime(QString(tr("%1")).arg(QDateTime::currentDateTime().toString(
                                                "yyyy/M/d/h:m:s")));

    content.setModifiedTime(QString(tr("%1")).arg(QDateTime::currentDateTime().toString(
                                                           "yyyy/M/d/h:m:s")));
    midConnection->creatNewNote(content,noteBookList->currentIndex());
}
/*****************新建笔记本****************************/
void mainFunction::createNewNoteBook()
{

    newNoteBook.setNoteBookId(QString("1"));
    newNoteBook.setNoteBookName(tr("新的笔记"));
    midConnection->creatNewNoteBook(newNoteBook);

}
/************************************************************/

/**********************删除笔记本*****************************/
void mainFunction::removeNoteBook()
{

    //midConnection->removeNoteBook(noteBookList->currentIndex());
    midConnection->removeNoteBook();
}
/***********************************************************/

/**********************重命名笔记本**************************/
void mainFunction::reNameNoteBook()
{
    midConnection->renameNoteBook();
}
/**********************************************************/
/****************跳转到编辑区域***********************/

void mainFunction::goToEdit()
{
    editPanelInAnimation->start();
}
/******************************************************/





/*********************NoteBookView响应右键****************/
void mainFunction::rightButtonToNoteBookView(const QPoint &pos)
{

    QPoint globalPos = noteBookList->mapToGlobal(pos);

    QMenu noteBookMenu;

    QAction* deleteNoteBook;
    QAction* createNewNoteBook;
    QAction* renameNoteBook;
    if(noteBookList->indexAt(pos).isValid())
    {
        deleteNoteBook = noteBookMenu.addAction(tr("删除笔记本"));
        renameNoteBook = noteBookMenu.addAction(tr("重命名笔记本"));
        connect(deleteNoteBook,SIGNAL(triggered()),this,SLOT(removeNoteBook()));
        connect(renameNoteBook,SIGNAL(triggered()),this,SLOT(reNameNoteBook()));
    }
    else
    {
        createNewNoteBook = noteBookMenu.addAction(tr("新建笔记本"));
        connect(createNewNoteBook,SIGNAL(triggered()),this,SLOT(createNewNoteBook()));
    }


    noteBookMenu.exec(globalPos);
}
/********************************************************/


/***********************noteView响应右键******************/
void mainFunction::rightButtonToNoteView(const QPoint &pos)
{

}
/*************************今天编到这里*******************************/

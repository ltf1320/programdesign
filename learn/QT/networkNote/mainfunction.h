#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H

#include <QObject>
#include <QTableView>
#include <QListView>
#include <QAbstractListModel>
#include <QList>
#include <QMap>
#include <QModelIndex>
#include "notedatamodel.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QRect>
#include <QPushButton>
#include <QItemSelectionModel>
/***********************功能*******************************/
class mainFunction : public QObject
{
    Q_OBJECT
public:
    explicit mainFunction(QObject *parent = 0);
    mainFunction(QWidget *_includecontentWidget,QWidget *_includeeditWidget,QWidget *_contentWidget,QListView* list,QWidget* _editwidget
                 ,QLineEdit *_searchLineEdit,QPushButton *_searchBtn,QListView *_notebooklist);
    ~mainFunction();

signals:

public slots:
    void createNewNote();
    void createNewNoteBook();
    void removeNoteBook();
    void reNameNoteBook();
    void goToEdit();

    void rightButtonToNoteBookView(const QPoint& pos);
    void rightButtonToNoteView(const QPoint& pos);

    void printCurrentRow(const QModelIndex& index);
private:
    QWidget *includeContentWidget;
    QWidget *includeEditWidget;
    QWidget *contentWidget;
    QListView *noteList;
    QListView *noteBookList;
    QWidget *editWidget;
    QLineEdit *searchLineEdit;
    QPushButton *searchBtn;

    noteBookListModel *pNotebookListmodel;
    noteListModel *pNoteListmodel;
    midLayer* midConnection;
    editPatr *editPanel;
    QItemSelectionModel *notebookSelectModel;
    QItemSelectionModel *noteSelectModel;
    //QPropertyAnimation *CatalogueOutAnimation;
    //QPropertyAnimation *CatalogueInAnimation;
    QPropertyAnimation *editPanelOutAnimation;
    QPropertyAnimation *editPanelInAnimation;
    //QParallelAnimationGroup *goToEditAnimationGroup;
    //QParallelAnimationGroup *goToCatalogueAnimationGroup;

    noteContent content;
    noteBook newNoteBook;
    void initSignal_Slot();
    void iniAnimation();
};

#endif // MAINFUNCTION_H

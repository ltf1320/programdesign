#ifndef NOTEDATAMODEL_H
#define NOTEDATAMODEL_H


#include <QString>
#include <QObject>
#include <QMap>
#include <QVector>
#include <QListView>
#include "editpatr.h"
#include <QModelIndexList>
#include <QModelIndex>
#include <QPoint>
#include <QMenu>
#include <QAction>
#include <QtCore>
/***********************笔记内容存储**************/
class noteContent
{
public:
    noteContent();
    //noteContent(const noteContent& other);
    virtual ~noteContent();
    void setUserID(QString _userID);
    void setTitle(QString _title);
    void setNoteID(QString _noteid);
    void setCreateTime(QString _crtime);
    void setModifiedTime(QString _motime);
    void setContent(QString _content);
    void setFontType(QString _type);
    void setFontSize(QString _size);
    void setFontColor(QString _color);
    QMap<QString,QString>* returnNoteInfo();
    void operator = (const noteContent& other);
    //const noteContent& operator < (const noteContent& other);
    void setMap(const QMap<QString,QString>& _noteinfo);

    friend bool sortCreateTime(const noteContent& n1,const noteContent& n2);
    friend bool sortModifiedTime(const noteContent& n1,const noteContent& n2);
private:
    QMap<QString,QString> noteInfo;
    //依次存储用户ID、笔记ID、标题、
    //创建时间、修改时间、字体、字体大小、字体颜色
    QString userID,noteID,title,
    createTime,modifiedTime,content,font,fontSize,
    fontColor,noteBookId;

};
/********************************************/

/*****************笔记本数据*****************/
class noteBook
{
public:
    noteBook();
    virtual ~noteBook();
    //noteBook(const noteBook& other);
    void setNoteBookId(const QString& id);
    void setNoteBookName(const QString& name);
    bool addNote(const noteContent& _note);

    const QString& getNoteBookId() const;
    const QString& getNoteBookName() const;
    QVector<noteContent>* getNoteList();

    void operator =(const noteBook& other);
private:
    QString noteBookID;
    QString noteBookName;
    QVector<noteContent> *noteList;

};
/***************************************/

/******************************笔记本列模型***********************/
class noteBookListModel:public QAbstractListModel
{
        Q_OBJECT
public:
    friend class midLayer;
    explicit noteBookListModel(QObject *parent = 0);
    ~noteBookListModel();
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRows(int row, int count, const QModelIndex &parent=QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent=QModelIndex());

    void setNoteBook(const noteBook& _notebook);

    noteBook* getNoteBook(const QModelIndex& index);

    QVector<noteBook>* getNoteBookList();


signals:

public slots:

private:
    QVector<noteBook>* noteBookList;
    noteBook notebook;
    noteContent note;
};
/**********************笔记列模型********************************/
class noteListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    friend class midLayer;
    enum sortMethod{createtime,modifiedtime};
    explicit noteListModel(QObject *parent=0);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool insertRows(int row, int count, const QModelIndex &parent=QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent=QModelIndex());
    //void setNote(const noteContent& _note);
    void setNote(noteContent _note);

    void setNoteList(QVector<noteContent>* _notelist);
    void usingSort(sortMethod method);
    QMap<QString,QString>* getNote(const QModelIndex& index);
    QVector<noteContent>* getNoteList();


public slots:

signals:
private:
    QVector<noteContent> *noteList;
    noteContent _noteContent;

};

/*****************************中间层NEW**************************/
class midLayer : public QObject
{
    Q_OBJECT
public:
    explicit midLayer(QObject *parent =0);
    ~midLayer();
    midLayer(QListView* _noteBookView,noteBookListModel* _noteBookModel,
             QListView* _noteView,noteListModel* _noteModel,
             editPatr* _editPannel);
    void creatNewNote(noteContent newNote,const QModelIndex& noteBookIndex);
    void creatNewNoteBook(noteBook _newNoteBook);
    void removeNote(const QModelIndex& noteIndex,const QModelIndex& noteBookIndex);
    void removeNoteBook(const QModelIndex& noteBookIndex);
    void removeNoteBook();
    void renameNoteBook();
signals:

public slots:

     void connectNoteBookModelToNoteModel(const QModelIndex& index);
     //单击NoteBookView中的item显示笔记

     void connectNoteModelToEditPannel(const QModelIndex& index);
     //双击NoteView中的item在编辑区域显示内容


private:
     QListView* noteBookList;
     QListView* noteList;
     noteBookListModel* noteBookModel;
     noteListModel* noteModel;
     editPatr* editPannel;

    QItemSelectionModel *notebookSelectModel;
    QItemSelectionModel *noteSelectModel;

};


/***************************************************************/



/*************************中间层OLD************************/
/*class midWare : public QObject
{
    Q_OBJECT
public:
    explicit midWare(QObject *parent = 0);
    ~midWare();
     midWare(QListView* _noteBookView,noteBookListModel* _noteBookModel,QListView* _noteView,noteListModel* _noteModel,editPatr* _editPannel);
    //void setConnection(QListView* _noteBookView,noteBookListModel* _noteBookModel,QListView* _noteView,noteBook* _noteModel);
     void creatNewNote(const noteContent& newNote);
     void removeNote(const QModelIndex& index);
signals:
     void currentNoteRemoved();
public slots:
     void connectNoteBookModelToNoteModel(const QModelIndex& index);
     void connectNoteModelToEditPannel(const QModelIndex& index);
private:
     QListView* noteBookList;
     QListView* noteList;
     noteBookListModel* noteBookModel;
     noteListModel* noteModel;
     editPatr* editPannel;
};*/


/*************************************************************/

#endif // NOTEDATAMODEL_H

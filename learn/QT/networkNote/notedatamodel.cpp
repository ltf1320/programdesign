#include "notedatamodel.h"
#include <QDebug>
/**********************笔记数据**********************/
noteContent::noteContent()
{

    noteInfo.insert("userid","");
    noteInfo.insert("noteid","");
    noteInfo.insert("title","");
    noteInfo.insert("createtime","");
    noteInfo.insert("modifiedtime","");
    noteInfo.insert("content","");
    noteInfo.insert("font","");
    noteInfo.insert("fontcolor","");
    noteInfo.insert("fontsize","");
    noteInfo.insert("notebookid","");
}
/*noteContent::noteContent(const noteContent &other)
{
    userID=other.userID;
    noteID = other.noteID;
    title = other.title;
    createTime = other.createTime;
    modifiedTime = other.modifiedTime;
    content = other.content;
    font = other.font;
    fontSize = other.fontSize;
    fontColor = other.fontColor;
    noteInfo = other.noteInfo;
    noteBookId = other.noteBookId;
}*/
void noteContent::operator =(const noteContent& other)
{
    userID=other.userID;
    noteID = other.noteID;
    title = other.title;
    createTime = other.createTime;
    modifiedTime = other.modifiedTime;
    content = other.content;
    font = other.font;
    fontSize = other.fontSize;
    fontColor = other.fontColor;
    noteInfo = other.noteInfo;
    noteBookId = other.noteBookId;
}
/*const noteContent& noteContent::operator <(const noteContent& other)
{
    if(createTime<other.createTime)
        return *this;
    else
        return other;

}*/
noteContent::~noteContent()
{

}
void noteContent::setUserID(QString _userID)
{
    userID = _userID;
    noteInfo["userid"] = userID;
}
void noteContent::setTitle(QString _title)
{
    title = _title;
    noteInfo["title"] = title;
}
void noteContent::setNoteID(QString _noteid)
{
    noteID = _noteid;
    noteInfo["noteid"] = noteID;
}
void noteContent::setCreateTime(QString _crtime)
{
    createTime = _crtime;
    noteInfo["createtime"] = createTime;
}
void noteContent::setModifiedTime(QString _motime)
{
    modifiedTime = _motime;
    noteInfo["modifiedtime"] = modifiedTime;
}
void noteContent::setContent(QString _content)
{
    content = _content;
    noteInfo["content"] = content;
}
void noteContent::setFontType(QString _type)
{
    font = _type;
    noteInfo["font"] = font;
}
void noteContent::setFontSize(QString _size)
{
    fontSize = _size;
    noteInfo["fontsize"]=fontSize;
}
void noteContent::setFontColor(QString _color)
{
    fontColor = _color;
    noteInfo["fontcolor"] = fontColor;
}
QMap<QString,QString>* noteContent::returnNoteInfo()
{
    return &noteInfo;
}
void noteContent::setMap(const QMap<QString, QString>& _noteinfo)
{
    noteInfo = _noteinfo;
}
bool sortCreateTime(const noteContent& n1,const noteContent& n2)
{
    if(n1.createTime<n1.createTime)
        return true;
    else
        return false;
}
bool sortModifiedTime(const noteContent& n1,const noteContent& n2)
{
    if(n1.modifiedTime<n2.modifiedTime)
        return true;
    else
        return false;
}
/*********************************************************/




/************************笔记本数据***********************/
noteBook::noteBook()

{
    noteList = new QVector<noteContent>;
}
/*noteBook::noteBook(const noteBook &other)
{
    noteBookID = other.noteBookID;
    noteBookName = other.noteBookName;
    *noteList = *other.noteList;

}*/
noteBook::~noteBook()
{

}
void noteBook::setNoteBookId(const QString &id)
{
    noteBookID = id;
}
void noteBook::setNoteBookName(const QString &name)
{
    noteBookName = name;
}
bool noteBook::addNote(const noteContent &_note)
{

    noteList->insert(0,_note);
    return true;
}
const QString& noteBook::getNoteBookId() const
{
    return noteBookID;
}
const QString& noteBook::getNoteBookName() const
{
    return noteBookName;
}

QVector<noteContent>* noteBook::getNoteList()
{
    return noteList;
}
void noteBook::operator =(const noteBook& other)
{
    noteBookID = other.noteBookID;
    noteBookName= other.noteBookName;
    *noteList = *other.noteList;

}
/*******************************************************/




/*******************笔记列模型*****************************************/
noteListModel::noteListModel(QObject *parent)
    :QAbstractListModel(parent)
{
    noteList = new QVector<noteContent>;

}
int noteListModel::rowCount(const QModelIndex &parent) const
{
    if(!noteList->isEmpty())
        return noteList->count();
    else
        return 0;
}
QVariant noteListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(noteList->isEmpty())
        return QVariant();
    if(index.row()>=noteList->size())
        return QVariant();
    if(role == Qt::DisplayRole)
    {

        return QString(QString(tr("标题:%1\n创建时间:%2")).arg((*noteList)[index.row()].returnNoteInfo()
                       ->value("title")).arg((*noteList)[index.row()]
                                                          .returnNoteInfo()
                                                          ->value("createtime")));
    }
    else
        return QVariant();
}
void noteListModel::setNote(noteContent _note)
{
    _noteContent = _note;
}
bool noteListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row+count-1);
    endInsertRows();
    return true;
}
bool noteListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent,row,row+count-1);
    endRemoveRows();
    return true;
}
void noteListModel::setNoteList(QVector<noteContent> *_notelist)
{
    noteList = _notelist;
}
void noteListModel::usingSort(sortMethod method)
{
    switch(method)
    {
    case createtime:
        qSort(noteList->begin(),noteList->end(),sortCreateTime);break;
    case modifiedtime:qSort(noteList->begin(),noteList->end(),sortModifiedTime);break;
    }
}
QMap<QString,QString>* noteListModel::getNote(const QModelIndex &index)
{
    return (*noteList)[index.row()].returnNoteInfo();
}
QVector<noteContent>* noteListModel::getNoteList()
{
    return noteList;
}
/***********************************************************************/








/***************************笔记本列模型**********************************/
noteBookListModel::noteBookListModel(QObject *parent)
    :QAbstractListModel(parent)
{

    noteBookList = new QVector<noteBook>;

}
noteBookListModel::~noteBookListModel()
{

}
int noteBookListModel::rowCount(const QModelIndex &parent) const
{

    if(noteBookList->isEmpty())
    {
        return 0;
    }
        return noteBookList->count();
}
QVariant noteBookListModel::data(const QModelIndex &index, int role) const
{

    if(!index.isValid())
        return QVariant();
    if(index.row()>noteBookList->count())
        return QVariant();
    if(noteBookList->isEmpty())
        return QVariant();
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        QString temp = (*noteBookList)[index.row()].getNoteBookName();
        return temp;
    }
    else
        return QVariant();
}
Qt::ItemFlags noteBookListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    if(index.row() == noteBookList->count()-1)
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    return QAbstractListModel::flags(index)|Qt::ItemIsEditable;
}
bool noteBookListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole && index.isValid())
    {

        (*noteBookList)[index.row()].setNoteBookName(value.toString());
        emit dataChanged(index,index);

    }
    return true;
}
void noteBookListModel::setNoteBook(const noteBook &_notebook)
{
    notebook = _notebook;
    //qDebug() << notebook.getNoteBookId();
}
noteBook* noteBookListModel::getNoteBook(const QModelIndex &index)
{

}
QVector<noteBook>* noteBookListModel::getNoteBookList()
{
    return  noteBookList;
}
bool noteBookListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row+count-1);
    endInsertRows();
    return true;
}
bool noteBookListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent,row,row+count-1);
    endRemoveRows();
    return true;
}



/*********************************中间层NEW******************************/
midLayer::midLayer(QObject *parent)
    :QObject(parent)
{

}
midLayer::midLayer(QListView *_noteBookView, noteBookListModel *_noteBookModel,
                   QListView *_noteView, noteListModel *_noteModel,
                   editPatr *_editPannel)
{
    noteBookList = _noteBookView;
    noteList = _noteView;
    noteBookModel = _noteBookModel;
    noteModel = _noteModel;
    editPannel = _editPannel;

    notebookSelectModel = noteBookList->selectionModel();
    noteSelectModel = noteList->selectionModel();
}
midLayer::~midLayer()
{

}
void midLayer::connectNoteBookModelToNoteModel(const QModelIndex &index)
{
    /********************编到这里*********************/
    qDebug() << "current row in notebookview" << index.row();
    QVector<noteBook>* _notebooklist = noteBookModel->noteBookList;
    if(noteModel->noteList == (*_notebooklist)[index.row()].getNoteList())
        return;
    noteModel->noteList = (*_notebooklist)[index.row()].getNoteList();
    noteModel->insertRows(1,noteModel->noteList->count());

}
void midLayer::connectNoteModelToEditPannel(const QModelIndex &index)
{
    QVector<noteContent>* _notecontent = noteModel->noteList;
    editPannel->setContent((*_notecontent)[index.row()].returnNoteInfo());
}
void midLayer::creatNewNote(noteContent newNote,const QModelIndex& noteBookIndex)
{
     QVector<noteBook>* _notebooklist = noteBookModel->noteBookList;
     (*_notebooklist)[noteBookIndex.row()].addNote(newNote);
     noteModel->noteList = (*_notebooklist)[noteBookIndex.row()].getNoteList();
     noteModel->insertRows(1,noteModel->noteList->count());

     noteList->setCurrentIndex(noteModel->index(0));
}
void midLayer::creatNewNoteBook(noteBook _newNoteBook)
{
    QVector<noteBook>* _notebooklist = noteBookModel->noteBookList;
    _notebooklist->insert(0,_newNoteBook);
    noteBookModel->insertRows(1,1);
    noteModel->insertRows(1,0);

    noteBookList->setCurrentIndex(noteBookModel->index(0));
}
void midLayer::removeNote(const QModelIndex &noteIndex, const QModelIndex &noteBookIndex)
{
    QVector<noteBook>* _notebooklist = noteBookModel->noteBookList;
    noteModel->noteList = (*_notebooklist)[noteBookIndex.row()].getNoteList();
    noteModel->removeRows(noteIndex.row(),1);

    noteList->setCurrentIndex(noteModel->index(0));
}
void midLayer::removeNoteBook(const QModelIndex &noteBookIndex)
{
    QVector<noteBook>* _notebooklist = noteBookModel->noteBookList;

    if(noteBookIndex.row() == noteBookModel->noteBookList->count()-1)
        return;
    noteModel->noteList = (*_notebooklist)[noteBookIndex.row()].getNoteList();

    noteModel->removeRows(1,noteModel->noteList->count());
    noteModel->noteList->clear();


    noteBookModel->removeRows(noteBookIndex.row(),1);
    noteBookModel->noteBookList->remove(noteBookIndex.row());

    noteBookList->setCurrentIndex(noteBookModel->index(0));
}
void midLayer::removeNoteBook()
{
    QModelIndexList modelIndexList = notebookSelectModel->selectedIndexes();


    QVector<noteBook>* _notebooklist = noteBookModel->noteBookList;

    for(int i=0;i<modelIndexList.count();i++)
    {
        qDebug() << "row of index tend to delete" << modelIndexList[i].row();
        if(modelIndexList[i].row() == noteBookModel->noteBookList->count()-1)
            return;
        qDebug() << "1";
        noteModel->noteList = (*_notebooklist)[modelIndexList[i].row()].getNoteList();
        qDebug() << "2";
        if(noteModel->removeRows(1,noteModel->noteList->count()))
        {
            qDebug() << "3";
            noteModel->noteList->clear();
        }
        qDebug() <<"4";
        if(noteBookModel->removeRows(modelIndexList[i].row(),1))
        {
            qDebug() << "5";
            noteBookModel->noteBookList->remove(i);
        }
        qDebug() << "6";

    }
    noteBookList->setCurrentIndex(noteBookModel->index(0));

}
void midLayer::renameNoteBook()
{
    noteBookList->edit(noteBookList->currentIndex());
}
/***********************************************************************/

/****************************中间层old*************************************/
/*midWare::midWare(QObject *parent)
    :QObject(parent)
{

}
midWare::~midWare()
{

}
midWare::midWare(QListView *_noteBookView, noteBookListModel *_noteBookModel, QListView *_noteView, noteListModel *_noteModel,editPatr *_editPannel)
{
    noteBookList = _noteBookView;
    noteList = _noteView;
    noteBookModel = _noteBookModel;
    noteModel = _noteModel;
    editPannel = _editPannel;
}
void midWare::connectNoteBookModelToNoteModel(const QModelIndex &index)
{
    noteModel->setNoteList(noteBookModel->getNoteBook(index)->getNoteList());
}
void midWare::connectNoteModelToEditPannel(const QModelIndex &index)
{
    editPannel->setContent(noteModel->getNote(index));

}
void midWare::creatNewNote(const noteContent& newNote)
{
    if(noteModel->getNoteList()->isEmpty())
    {
        noteModel->setNoteList(noteBookModel->getNoteBook(noteBookList->currentIndex())->getNoteList());
        noteModel->setNote(newNote);
        noteModel->insertRows(0,1);
        noteList->setCurrentIndex(noteModel->index(0));
    }
    else
    {
        noteModel->setNote(newNote);
        noteModel->insertRows(0,1);
        noteList->setCurrentIndex(noteModel->index(0));
    }
}
void midWare::removeNote(const QModelIndex &index)
{
    if(noteModel->getNoteList()->isEmpty())
    {
        noteModel->setNoteList(noteBookModel->getNoteBook(noteBookList->currentIndex())->getNoteList());
        noteModel->removeRows(index.row(),1);
        noteList->setCurrentIndex(noteModel->index(0));
    }
    else
    {

        noteModel->removeRows(index.row(),1);
        noteList->setCurrentIndex(noteModel->index(0));
    }
    emit currentNoteRemoved();
}*/
/********************************************************************/

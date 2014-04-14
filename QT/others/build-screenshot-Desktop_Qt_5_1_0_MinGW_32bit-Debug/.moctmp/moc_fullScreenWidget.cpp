/****************************************************************************
** Meta object code from reading C++ file 'fullScreenWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../screenshot/fullScreenWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fullScreenWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fullScreenWidget_t {
    QByteArrayData data[11];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_fullScreenWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_fullScreenWidget_t qt_meta_stringdata_fullScreenWidget = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 12),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 20),
QT_MOC_LITERAL(4, 52, 8),
QT_MOC_LITERAL(5, 61, 1),
QT_MOC_LITERAL(6, 63, 1),
QT_MOC_LITERAL(7, 65, 5),
QT_MOC_LITERAL(8, 71, 6),
QT_MOC_LITERAL(9, 78, 18),
QT_MOC_LITERAL(10, 97, 10)
    },
    "fullScreenWidget\0finishPixmap\0\0"
    "loadBackgroundPixmap\0bgPixmap\0x\0y\0"
    "width\0height\0cancelSelectedRect\0"
    "savePixmap\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fullScreenWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   42,    2, 0x0a,
       3,    5,   45,    2, 0x0a,
       9,    0,   56,    2, 0x0a,
      10,    0,   57,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    1,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap,    4,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void fullScreenWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fullScreenWidget *_t = static_cast<fullScreenWidget *>(_o);
        switch (_id) {
        case 0: _t->finishPixmap((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 1: _t->loadBackgroundPixmap((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 2: _t->loadBackgroundPixmap((*reinterpret_cast< const QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: _t->cancelSelectedRect(); break;
        case 4: _t->savePixmap(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fullScreenWidget::*_t)(const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fullScreenWidget::finishPixmap)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject fullScreenWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fullScreenWidget.data,
      qt_meta_data_fullScreenWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *fullScreenWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fullScreenWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fullScreenWidget.stringdata))
        return static_cast<void*>(const_cast< fullScreenWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int fullScreenWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void fullScreenWidget::finishPixmap(const QPixmap & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'graphscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graphscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphScene_t {
    QByteArrayData data[11];
    char stringdata[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphScene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphScene_t qt_meta_stringdata_GraphScene = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GraphScene"
QT_MOC_LITERAL(1, 11, 12), // "itemInserted"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(4, 40, 10), // "mouseEvent"
QT_MOC_LITERAL(5, 51, 12), // "itemSelected"
QT_MOC_LITERAL(6, 64, 7), // "setMode"
QT_MOC_LITERAL(7, 72, 4), // "Mode"
QT_MOC_LITERAL(8, 77, 5), // "_mode"
QT_MOC_LITERAL(9, 83, 11), // "setModified"
QT_MOC_LITERAL(10, 95, 1) // "m"

    },
    "GraphScene\0itemInserted\0\0QGraphicsItem*\0"
    "mouseEvent\0itemSelected\0setMode\0Mode\0"
    "_mode\0setModified\0m"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   45,    2, 0x0a /* Public */,
       9,    1,   48,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,

       0        // eod
};

void GraphScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphScene *_t = static_cast<GraphScene *>(_o);
        switch (_id) {
        case 0: _t->itemInserted((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 1: _t->itemSelected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 2: _t->setMode((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        case 3: _t->setModified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setModified(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphScene::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphScene::itemInserted)) {
                *result = 0;
            }
        }
        {
            typedef void (GraphScene::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphScene::itemSelected)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GraphScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_GraphScene.data,
      qt_meta_data_GraphScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphScene.stringdata))
        return static_cast<void*>(const_cast< GraphScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int GraphScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void GraphScene::itemInserted(QGraphicsItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphScene::itemSelected(QGraphicsItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

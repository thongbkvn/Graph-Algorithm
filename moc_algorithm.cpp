/****************************************************************************
** Meta object code from reading C++ file 'algorithm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "algorithm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'algorithm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Algorithm_t {
    QByteArrayData data[13];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Algorithm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Algorithm_t qt_meta_stringdata_Algorithm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Algorithm"
QT_MOC_LITERAL(1, 10, 9), // "setSource"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "setDest"
QT_MOC_LITERAL(4, 29, 9), // "addVertex"
QT_MOC_LITERAL(5, 39, 7), // "Vertex*"
QT_MOC_LITERAL(6, 47, 12), // "removeVertex"
QT_MOC_LITERAL(7, 60, 15), // "finishAnimation"
QT_MOC_LITERAL(8, 76, 11), // "initAllItem"
QT_MOC_LITERAL(9, 88, 4), // "play"
QT_MOC_LITERAL(10, 93, 4), // "next"
QT_MOC_LITERAL(11, 98, 4), // "prev"
QT_MOC_LITERAL(12, 103, 4) // "stop"

    },
    "Algorithm\0setSource\0\0setDest\0addVertex\0"
    "Vertex*\0removeVertex\0finishAnimation\0"
    "initAllItem\0play\0next\0prev\0stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Algorithm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    1,   66,    2, 0x0a /* Public */,
       6,    1,   69,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x09 /* Protected */,
       8,    0,   73,    2, 0x09 /* Protected */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Algorithm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Algorithm *_t = static_cast<Algorithm *>(_o);
        switch (_id) {
        case 0: _t->setSource(); break;
        case 1: _t->setDest(); break;
        case 2: _t->addVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 3: _t->removeVertex((*reinterpret_cast< Vertex*(*)>(_a[1]))); break;
        case 4: _t->finishAnimation(); break;
        case 5: _t->initAllItem(); break;
        case 6: _t->play(); break;
        case 7: _t->next(); break;
        case 8: _t->prev(); break;
        case 9: _t->stop(); break;
        default: ;
        }
    }
}

const QMetaObject Algorithm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Algorithm.data,
      qt_meta_data_Algorithm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Algorithm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Algorithm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Algorithm.stringdata))
        return static_cast<void*>(const_cast< Algorithm*>(this));
    return QObject::qt_metacast(_clname);
}

int Algorithm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

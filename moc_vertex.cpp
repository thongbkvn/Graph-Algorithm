/****************************************************************************
** Meta object code from reading C++ file 'vertex.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vertex.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vertex.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Vertex_t {
    QByteArrayData data[8];
    char stringdata[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Vertex_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Vertex_t qt_meta_stringdata_Vertex = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Vertex"
QT_MOC_LITERAL(1, 7, 5), // "color"
QT_MOC_LITERAL(2, 13, 11), // "VertexColor"
QT_MOC_LITERAL(3, 25, 4), // "Init"
QT_MOC_LITERAL(4, 30, 7), // "Visited"
QT_MOC_LITERAL(5, 38, 6), // "Source"
QT_MOC_LITERAL(6, 45, 11), // "Destination"
QT_MOC_LITERAL(7, 57, 10) // "Discovered"

    },
    "Vertex\0color\0VertexColor\0Init\0Visited\0"
    "Source\0Destination\0Discovered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Vertex[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       1,   17, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x0009510b,

 // enums: name, flags, count, data
       2, 0x0,    5,   21,

 // enum data: key, value
       3, uint(Vertex::Init),
       4, uint(Vertex::Visited),
       5, uint(Vertex::Source),
       6, uint(Vertex::Destination),
       7, uint(Vertex::Discovered),

       0        // eod
};

void Vertex::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Vertex::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_Vertex.data,
      qt_meta_data_Vertex,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Vertex::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vertex::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Vertex.stringdata))
        return static_cast<void*>(const_cast< Vertex*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int Vertex::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< VertexColor*>(_v) = color(); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setColor(*reinterpret_cast< VertexColor*>(_v)); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE

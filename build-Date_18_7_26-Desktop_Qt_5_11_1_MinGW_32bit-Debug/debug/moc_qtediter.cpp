/****************************************************************************
** Meta object code from reading C++ file 'qtediter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Date_18_7_26/qtediter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtediter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtEditer_t {
    QByteArrayData data[18];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtEditer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtEditer_t qt_meta_stringdata_QtEditer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QtEditer"
QT_MOC_LITERAL(1, 9, 7), // "newFile"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "openFile"
QT_MOC_LITERAL(4, 27, 8), // "saveFile"
QT_MOC_LITERAL(5, 36, 10), // "saveAsFile"
QT_MOC_LITERAL(6, 47, 11), // "alignCenter"
QT_MOC_LITERAL(7, 59, 4), // "undo"
QT_MOC_LITERAL(8, 64, 4), // "redo"
QT_MOC_LITERAL(9, 69, 4), // "copy"
QT_MOC_LITERAL(10, 74, 3), // "cut"
QT_MOC_LITERAL(11, 78, 5), // "paste"
QT_MOC_LITERAL(12, 84, 6), // "zoomIn"
QT_MOC_LITERAL(13, 91, 7), // "zoomOut"
QT_MOC_LITERAL(14, 99, 4), // "help"
QT_MOC_LITERAL(15, 104, 8), // "setColor"
QT_MOC_LITERAL(16, 113, 7), // "setFont"
QT_MOC_LITERAL(17, 121, 5) // "print"

    },
    "QtEditer\0newFile\0\0openFile\0saveFile\0"
    "saveAsFile\0alignCenter\0undo\0redo\0copy\0"
    "cut\0paste\0zoomIn\0zoomOut\0help\0setColor\0"
    "setFont\0print"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtEditer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtEditer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtEditer *_t = static_cast<QtEditer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newFile(); break;
        case 1: _t->openFile(); break;
        case 2: _t->saveFile(); break;
        case 3: _t->saveAsFile(); break;
        case 4: _t->alignCenter(); break;
        case 5: _t->undo(); break;
        case 6: _t->redo(); break;
        case 7: _t->copy(); break;
        case 8: _t->cut(); break;
        case 9: _t->paste(); break;
        case 10: _t->zoomIn(); break;
        case 11: _t->zoomOut(); break;
        case 12: _t->help(); break;
        case 13: _t->setColor(); break;
        case 14: _t->setFont(); break;
        case 15: _t->print(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QtEditer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtEditer.data,
      qt_meta_data_QtEditer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtEditer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtEditer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtEditer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtEditer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

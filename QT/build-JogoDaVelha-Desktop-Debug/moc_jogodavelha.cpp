/****************************************************************************
** Meta object code from reading C++ file 'jogodavelha.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../JogoDaVelha/jogodavelha.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jogodavelha.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_JogoDaVelha_t {
    QByteArrayData data[5];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JogoDaVelha_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JogoDaVelha_t qt_meta_stringdata_JogoDaVelha = {
    {
QT_MOC_LITERAL(0, 0, 11), // "JogoDaVelha"
QT_MOC_LITERAL(1, 12, 20), // "on_tabuleiro_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "index"
QT_MOC_LITERAL(4, 40, 28) // "on_actionNovo_Jogo_triggered"

    },
    "JogoDaVelha\0on_tabuleiro_clicked\0\0"
    "index\0on_actionNovo_Jogo_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JogoDaVelha[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,

       0        // eod
};

void JogoDaVelha::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JogoDaVelha *_t = static_cast<JogoDaVelha *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tabuleiro_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_actionNovo_Jogo_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject JogoDaVelha::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_JogoDaVelha.data,
      qt_meta_data_JogoDaVelha,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *JogoDaVelha::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JogoDaVelha::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_JogoDaVelha.stringdata0))
        return static_cast<void*>(const_cast< JogoDaVelha*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int JogoDaVelha::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'whatsprogmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WhatsProg_cliente/whatsprogmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'whatsprogmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WhatsProgMain_t {
    QByteArrayData data[22];
    char stringdata[385];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WhatsProgMain_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WhatsProgMain_t qt_meta_stringdata_WhatsProgMain = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 19),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 24),
QT_MOC_LITERAL(4, 60, 1),
QT_MOC_LITERAL(5, 62, 19),
QT_MOC_LITERAL(6, 82, 16),
QT_MOC_LITERAL(7, 99, 23),
QT_MOC_LITERAL(8, 123, 17),
QT_MOC_LITERAL(9, 141, 6),
QT_MOC_LITERAL(10, 148, 2),
QT_MOC_LITERAL(11, 151, 5),
QT_MOC_LITERAL(12, 157, 5),
QT_MOC_LITERAL(13, 163, 11),
QT_MOC_LITERAL(14, 175, 23),
QT_MOC_LITERAL(15, 199, 27),
QT_MOC_LITERAL(16, 227, 30),
QT_MOC_LITERAL(17, 258, 23),
QT_MOC_LITERAL(18, 282, 31),
QT_MOC_LITERAL(19, 314, 5),
QT_MOC_LITERAL(20, 320, 29),
QT_MOC_LITERAL(21, 350, 33)
    },
    "WhatsProgMain\0conversasModificada\0\0"
    "numMsgConversaModificado\0I\0"
    "mensagensModificada\0statusModificada\0"
    "slotAtualizaBarraStatus\0slotAceitaUsuario\0"
    "string\0IP\0login\0senha\0novoUsuario\0"
    "on_actionNovo_triggered\0"
    "on_actionConectar_triggered\0"
    "on_actionDesconectar_triggered\0"
    "on_actionSair_triggered\0"
    "on_tableViewConversas_activated\0index\0"
    "on_tableViewConversas_clicked\0"
    "on_lineEditMensagem_returnPressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WhatsProgMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06,
       3,    1,   80,    2, 0x06,
       5,    0,   83,    2, 0x06,
       6,    0,   84,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   85,    2, 0x08,
       8,    4,   86,    2, 0x08,
      14,    0,   95,    2, 0x08,
      15,    0,   96,    2, 0x08,
      16,    0,   97,    2, 0x08,
      17,    0,   98,    2, 0x08,
      18,    1,   99,    2, 0x08,
      20,    1,  102,    2, 0x08,
      21,    0,  105,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, QMetaType::Bool,   10,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   19,
    QMetaType::Void, QMetaType::QModelIndex,   19,
    QMetaType::Void,

       0        // eod
};

void WhatsProgMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WhatsProgMain *_t = static_cast<WhatsProgMain *>(_o);
        switch (_id) {
        case 0: _t->conversasModificada(); break;
        case 1: _t->numMsgConversaModificado((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->mensagensModificada(); break;
        case 3: _t->statusModificada(); break;
        case 4: _t->slotAtualizaBarraStatus(); break;
        case 5: _t->slotAceitaUsuario((*reinterpret_cast< const string(*)>(_a[1])),(*reinterpret_cast< const string(*)>(_a[2])),(*reinterpret_cast< const string(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 6: _t->on_actionNovo_triggered(); break;
        case 7: _t->on_actionConectar_triggered(); break;
        case 8: _t->on_actionDesconectar_triggered(); break;
        case 9: _t->on_actionSair_triggered(); break;
        case 10: _t->on_tableViewConversas_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_tableViewConversas_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_lineEditMensagem_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WhatsProgMain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WhatsProgMain::conversasModificada)) {
                *result = 0;
            }
        }
        {
            typedef void (WhatsProgMain::*_t)(unsigned  );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WhatsProgMain::numMsgConversaModificado)) {
                *result = 1;
            }
        }
        {
            typedef void (WhatsProgMain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WhatsProgMain::mensagensModificada)) {
                *result = 2;
            }
        }
        {
            typedef void (WhatsProgMain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WhatsProgMain::statusModificada)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject WhatsProgMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WhatsProgMain.data,
      qt_meta_data_WhatsProgMain,  qt_static_metacall, 0, 0}
};


const QMetaObject *WhatsProgMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WhatsProgMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WhatsProgMain.stringdata))
        return static_cast<void*>(const_cast< WhatsProgMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WhatsProgMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void WhatsProgMain::conversasModificada()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void WhatsProgMain::numMsgConversaModificado(unsigned  _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WhatsProgMain::mensagensModificada()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void WhatsProgMain::statusModificada()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE

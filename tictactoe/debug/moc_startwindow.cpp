/****************************************************************************
** Meta object code from reading C++ file 'startwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../startwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StartWindow_t {
    QByteArrayData data[14];
    char stringdata[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_StartWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_StartWindow_t qt_meta_stringdata_StartWindow = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 12),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 26),
QT_MOC_LITERAL(4, 53, 26),
QT_MOC_LITERAL(5, 80, 13),
QT_MOC_LITERAL(6, 94, 13),
QT_MOC_LITERAL(7, 108, 13),
QT_MOC_LITERAL(8, 122, 13),
QT_MOC_LITERAL(9, 136, 13),
QT_MOC_LITERAL(10, 150, 13),
QT_MOC_LITERAL(11, 164, 13),
QT_MOC_LITERAL(12, 178, 13),
QT_MOC_LITERAL(13, 192, 13)
    },
    "StartWindow\0mousePressed\0\0"
    "on_btn_selectRobot_clicked\0"
    "on_btn_selectHuman_clicked\0on_m1_clicked\0"
    "on_m2_clicked\0on_m3_clicked\0on_m4_clicked\0"
    "on_m5_clicked\0on_m6_clicked\0on_m7_clicked\0"
    "on_m8_clicked\0on_m9_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StartWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08,
       3,    0,   75,    2, 0x08,
       4,    0,   76,    2, 0x08,
       5,    0,   77,    2, 0x08,
       6,    0,   78,    2, 0x08,
       7,    0,   79,    2, 0x08,
       8,    0,   80,    2, 0x08,
       9,    0,   81,    2, 0x08,
      10,    0,   82,    2, 0x08,
      11,    0,   83,    2, 0x08,
      12,    0,   84,    2, 0x08,
      13,    0,   85,    2, 0x08,

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

       0        // eod
};

void StartWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StartWindow *_t = static_cast<StartWindow *>(_o);
        switch (_id) {
        case 0: _t->mousePressed(); break;
        case 1: _t->on_btn_selectRobot_clicked(); break;
        case 2: _t->on_btn_selectHuman_clicked(); break;
        case 3: _t->on_m1_clicked(); break;
        case 4: _t->on_m2_clicked(); break;
        case 5: _t->on_m3_clicked(); break;
        case 6: _t->on_m4_clicked(); break;
        case 7: _t->on_m5_clicked(); break;
        case 8: _t->on_m6_clicked(); break;
        case 9: _t->on_m7_clicked(); break;
        case 10: _t->on_m8_clicked(); break;
        case 11: _t->on_m9_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject StartWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StartWindow.data,
      qt_meta_data_StartWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *StartWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StartWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StartWindow.stringdata))
        return static_cast<void*>(const_cast< StartWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StartWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

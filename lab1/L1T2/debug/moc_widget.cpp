/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widget_t {
    QByteArrayData data[13];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widget_t qt_meta_stringdata_widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "widget"
QT_MOC_LITERAL(1, 7, 17), // "on_X_valueChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "arg1"
QT_MOC_LITERAL(4, 31, 29), // "on_RotationAngle_valueChanged"
QT_MOC_LITERAL(5, 61, 17), // "on_Y_valueChanged"
QT_MOC_LITERAL(6, 79, 22), // "on_Height_valueChanged"
QT_MOC_LITERAL(7, 102, 20), // "on_Base_valueChanged"
QT_MOC_LITERAL(8, 123, 15), // "on_Draw_clicked"
QT_MOC_LITERAL(9, 139, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(10, 171, 21), // "on_showcenter_clicked"
QT_MOC_LITERAL(11, 193, 21), // "on_angle_valueChanged"
QT_MOC_LITERAL(12, 215, 21) // "on_pushButton_clicked"

    },
    "widget\0on_X_valueChanged\0\0arg1\0"
    "on_RotationAngle_valueChanged\0"
    "on_Y_valueChanged\0on_Height_valueChanged\0"
    "on_Base_valueChanged\0on_Draw_clicked\0"
    "on_comboBox_currentIndexChanged\0"
    "on_showcenter_clicked\0on_angle_valueChanged\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widget[] = {

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
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       7,    1,   76,    2, 0x08 /* Private */,
       8,    0,   79,    2, 0x08 /* Private */,
       9,    1,   80,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widget *_t = static_cast<widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_X_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_RotationAngle_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_Y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_Height_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_Base_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_Draw_clicked(); break;
        case 6: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_showcenter_clicked(); break;
        case 8: _t->on_angle_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject widget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_widget.data,
      qt_meta_data_widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widget.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
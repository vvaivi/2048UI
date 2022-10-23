/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hh'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.hh"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[32];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 10), // "onSecTimer"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 6), // "images"
QT_MOC_LITERAL(30, 20), // "onStartButtonClicked"
QT_MOC_LITERAL(51, 20), // "onResetButtonClicked"
QT_MOC_LITERAL(72, 27), // "on_seedSpinBox_valueChanged"
QT_MOC_LITERAL(100, 4), // "arg1"
QT_MOC_LITERAL(105, 17), // "onUpButtonClicked"
QT_MOC_LITERAL(123, 19), // "onDownButtonClicked"
QT_MOC_LITERAL(143, 20), // "onRightButtonClicked"
QT_MOC_LITERAL(164, 19), // "onLeftButtonClicked"
QT_MOC_LITERAL(184, 33), // "on_goalNumberSpinBox_valueCha..."
QT_MOC_LITERAL(218, 31), // "on_nameLineEdit_editingFinished"
QT_MOC_LITERAL(250, 28), // "on_clearSpinBox_valueChanged"
QT_MOC_LITERAL(279, 26) // "on_pausePushButton_clicked"

    },
    "MainWindow\0onSecTimer\0\0images\0"
    "onStartButtonClicked\0onResetButtonClicked\0"
    "on_seedSpinBox_valueChanged\0arg1\0"
    "onUpButtonClicked\0onDownButtonClicked\0"
    "onRightButtonClicked\0onLeftButtonClicked\0"
    "on_goalNumberSpinBox_valueChanged\0"
    "on_nameLineEdit_editingFinished\0"
    "on_clearSpinBox_valueChanged\0"
    "on_pausePushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    0 /* Private */,
       3,    0,   93,    2, 0x08,    1 /* Private */,
       4,    0,   94,    2, 0x08,    2 /* Private */,
       5,    0,   95,    2, 0x08,    3 /* Private */,
       6,    1,   96,    2, 0x08,    4 /* Private */,
       8,    0,   99,    2, 0x08,    6 /* Private */,
       9,    0,  100,    2, 0x08,    7 /* Private */,
      10,    0,  101,    2, 0x08,    8 /* Private */,
      11,    0,  102,    2, 0x08,    9 /* Private */,
      12,    1,  103,    2, 0x08,   10 /* Private */,
      13,    0,  106,    2, 0x08,   12 /* Private */,
      14,    1,  107,    2, 0x08,   13 /* Private */,
      15,    0,  110,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSecTimer(); break;
        case 1: _t->images(); break;
        case 2: _t->onStartButtonClicked(); break;
        case 3: _t->onResetButtonClicked(); break;
        case 4: _t->on_seedSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onUpButtonClicked(); break;
        case 6: _t->onDownButtonClicked(); break;
        case 7: _t->onRightButtonClicked(); break;
        case 8: _t->onLeftButtonClicked(); break;
        case 9: _t->on_goalNumberSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_nameLineEdit_editingFinished(); break;
        case 11: _t->on_clearSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_pausePushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

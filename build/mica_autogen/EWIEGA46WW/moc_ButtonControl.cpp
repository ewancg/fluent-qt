/****************************************************************************
** Meta object code from reading C++ file 'ButtonControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ButtonControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ButtonControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ButtonControl_t {
    QByteArrayData data[5];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ButtonControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ButtonControl_t qt_meta_stringdata_ButtonControl = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ButtonControl"
QT_MOC_LITERAL(1, 14, 7), // "pressed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "released"
QT_MOC_LITERAL(4, 32, 7) // "toggled"

    },
    "ButtonControl\0pressed\0\0released\0toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ButtonControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    1,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void ButtonControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ButtonControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pressed(); break;
        case 1: _t->released(); break;
        case 2: _t->toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ButtonControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ButtonControl::pressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ButtonControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ButtonControl::released)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ButtonControl::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ButtonControl::toggled)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ButtonControl::staticMetaObject = { {
    QMetaObject::SuperData::link<Control::staticMetaObject>(),
    qt_meta_stringdata_ButtonControl.data,
    qt_meta_data_ButtonControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ButtonControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ButtonControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ButtonControl.stringdata0))
        return static_cast<void*>(this);
    return Control::qt_metacast(_clname);
}

int ButtonControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Control::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ButtonControl::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ButtonControl::released()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ButtonControl::toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'car_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "car_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'car_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CarAdaptor_t {
    QByteArrayData data[13];
    char stringdata0[666];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarAdaptor_t qt_meta_stringdata_CarAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CarAdaptor"
QT_MOC_LITERAL(1, 11, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 27, 9), // "local.Car"
QT_MOC_LITERAL(3, 37, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 57, 540), // "  <interface name=\"local.Car..."
QT_MOC_LITERAL(5, 544, 12), // "speedChanged"
QT_MOC_LITERAL(6, 557, 0), // ""
QT_MOC_LITERAL(7, 558, 10), // "getBattery"
QT_MOC_LITERAL(8, 569, 8), // "getSpeed"
QT_MOC_LITERAL(9, 578, 10), // "setBattery"
QT_MOC_LITERAL(10, 589, 7), // "battery"
QT_MOC_LITERAL(11, 597, 8), // "setSpeed"
QT_MOC_LITERAL(12, 606, 5) // "speed"

    },
    "CarAdaptor\0D-Bus Interface\0local.Car\0"
    "D-Bus Introspection\0"
    "  <interface name=\"local.Car\">\n    <property access=\"read\" type=\""
    "i\" name=\"speed\"/>\n    <signal name=\"speedChanged\"/>\n    <method"
    " name=\"setSpeed\">\n      <arg direction=\"in\" type=\"d\" name=\"spe"
    "ed\"/>\n    </method>\n    <method name=\"setBattery\">\n      <arg di"
    "rection=\"in\" type=\"d\" name=\"battery\"/>\n    </method>\n    <meth"
    "od name=\"getSpeed\">\n      <arg direction=\"out\" type=\"d\"/>\n    "
    "</method>\n    <method name=\"getBattery\">\n      <arg direction=\"ou"
    "t\" type=\"d\"/>\n    </method>\n  </interface>\n\0"
    "speedChanged\0\0getBattery\0getSpeed\0"
    "setBattery\0battery\0setSpeed\0speed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       5,   18, // methods
       1,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    0,   43,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   44,    6, 0x0a /* Public */,
       8,    0,   45,    6, 0x0a /* Public */,
       9,    1,   46,    6, 0x0a /* Public */,
      11,    1,   49,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,

 // properties: name, type, flags
      12, QMetaType::Int, 0x00095001,

       0        // eod
};

void CarAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: { double _r = _t->getBattery();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 2: { double _r = _t->getSpeed();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setBattery((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::speedChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CarAdaptor *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->speed(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CarAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_CarAdaptor.data,
    qt_meta_data_CarAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int CarAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
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
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CarAdaptor::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

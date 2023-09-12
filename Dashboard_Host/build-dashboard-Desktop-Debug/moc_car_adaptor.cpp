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
    QByteArrayData data[23];
    char stringdata0[1274];
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
QT_MOC_LITERAL(4, 57, 1007), // "  <interface name=\"local.Car..."
QT_MOC_LITERAL(5, 969, 14), // "batteryChanged"
QT_MOC_LITERAL(6, 984, 0), // ""
QT_MOC_LITERAL(7, 985, 19), // "batterydisconnected"
QT_MOC_LITERAL(8, 1005, 12), // "canconnected"
QT_MOC_LITERAL(9, 1018, 15), // "candisconnected"
QT_MOC_LITERAL(10, 1034, 10), // "rpmChanged"
QT_MOC_LITERAL(11, 1045, 15), // "rpmdisconnected"
QT_MOC_LITERAL(12, 1061, 12), // "speedChanged"
QT_MOC_LITERAL(13, 1074, 17), // "speeddisconnected"
QT_MOC_LITERAL(14, 1092, 14), // "checkCanStatus"
QT_MOC_LITERAL(15, 1107, 9), // "canstatus"
QT_MOC_LITERAL(16, 1117, 15), // "checkDbusStatus"
QT_MOC_LITERAL(17, 1133, 10), // "setBattery"
QT_MOC_LITERAL(18, 1144, 7), // "battery"
QT_MOC_LITERAL(19, 1152, 6), // "setRPM"
QT_MOC_LITERAL(20, 1159, 3), // "rpm"
QT_MOC_LITERAL(21, 1163, 8), // "setSpeed"
QT_MOC_LITERAL(22, 1172, 5) // "speed"

    },
    "CarAdaptor\0D-Bus Interface\0local.Car\0"
    "D-Bus Introspection\0"
    "  <interface name=\"local.Car\">\n    <property access=\"read\" type=\""
    "d\" name=\"speed\"/>\n    <property access=\"read\" type=\"d\" name=\""
    "rpm\"/>\n    <property access=\"read\" type=\"d\" name=\"battery\"/>\n"
    "    <signal name=\"speedChanged\"/>\n    <signal name=\"rpmChanged\"/>"
    "\n    <signal name=\"batteryChanged\"/>\n    <signal name=\"candisconn"
    "ected\"/>\n    <signal name=\"canconnected\"/>\n    <signal name=\"spe"
    "eddisconnected\"/>\n    <signal name=\"rpmdisconnected\"/>\n    <signa"
    "l name=\"batterydisconnected\"/>\n    <method name=\"setSpeed\">\n    "
    "  <arg direction=\"in\" type=\"d\" name=\"speed\"/>\n    </method>\n  "
    "  <method name=\"setRPM\">\n      <arg direction=\"in\" type=\"d\" nam"
    "e=\"rpm\"/>\n    </method>\n    <method name=\"setBattery\">\n      <a"
    "rg direction=\"in\" type=\"d\" name=\"battery\"/>\n    </method>\n    "
    "<method name=\"checkCanStatus\">\n      <arg direction=\"in\" type=\"b"
    "\" name=\"canstatus\"/>\n    </method>\n    <method name=\"checkDbusSt"
    "atus\"/>\n  </interface>\n\0"
    "batteryChanged\0\0batterydisconnected\0"
    "canconnected\0candisconnected\0rpmChanged\0"
    "rpmdisconnected\0speedChanged\0"
    "speeddisconnected\0checkCanStatus\0"
    "canstatus\0checkDbusStatus\0setBattery\0"
    "battery\0setRPM\0rpm\0setSpeed\0speed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
      13,   18, // methods
       3,  104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    0,   83,    6, 0x06 /* Public */,
       7,    0,   84,    6, 0x06 /* Public */,
       8,    0,   85,    6, 0x06 /* Public */,
       9,    0,   86,    6, 0x06 /* Public */,
      10,    0,   87,    6, 0x06 /* Public */,
      11,    0,   88,    6, 0x06 /* Public */,
      12,    0,   89,    6, 0x06 /* Public */,
      13,    0,   90,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   91,    6, 0x0a /* Public */,
      16,    0,   94,    6, 0x0a /* Public */,
      17,    1,   95,    6, 0x0a /* Public */,
      19,    1,   98,    6, 0x0a /* Public */,
      21,    1,  101,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   18,
    QMetaType::Void, QMetaType::Double,   20,
    QMetaType::Void, QMetaType::Double,   22,

 // properties: name, type, flags
      18, QMetaType::Double, 0x00095001,
      20, QMetaType::Double, 0x00095001,
      22, QMetaType::Double, 0x00095001,

       0        // eod
};

void CarAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->batteryChanged(); break;
        case 1: _t->batterydisconnected(); break;
        case 2: _t->canconnected(); break;
        case 3: _t->candisconnected(); break;
        case 4: _t->rpmChanged(); break;
        case 5: _t->rpmdisconnected(); break;
        case 6: _t->speedChanged(); break;
        case 7: _t->speeddisconnected(); break;
        case 8: _t->checkCanStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->checkDbusStatus(); break;
        case 10: _t->setBattery((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setRPM((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->setSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::batteryChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::batterydisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::canconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::candisconnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::rpmChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::rpmdisconnected)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::speedChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CarAdaptor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarAdaptor::speeddisconnected)) {
                *result = 7;
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
        case 0: *reinterpret_cast< double*>(_v) = _t->battery(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->rpm(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->speed(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CarAdaptor::batteryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CarAdaptor::batterydisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CarAdaptor::canconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CarAdaptor::candisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CarAdaptor::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CarAdaptor::rpmdisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CarAdaptor::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void CarAdaptor::speeddisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

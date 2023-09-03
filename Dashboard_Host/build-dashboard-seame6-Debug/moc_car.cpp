/****************************************************************************
** Meta object code from reading C++ file 'car.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dashboard/car.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'car.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Car_t {
    QByteArrayData data[18];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Car_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Car_t qt_meta_stringdata_Car = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Car"
QT_MOC_LITERAL(1, 4, 12), // "speedChanged"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 10), // "rpmChanged"
QT_MOC_LITERAL(4, 29, 14), // "batteryChanged"
QT_MOC_LITERAL(5, 44, 7), // "canFail"
QT_MOC_LITERAL(6, 52, 11), // "canRestored"
QT_MOC_LITERAL(7, 64, 8), // "setSpeed"
QT_MOC_LITERAL(8, 73, 5), // "speed"
QT_MOC_LITERAL(9, 79, 6), // "setRPM"
QT_MOC_LITERAL(10, 86, 3), // "rpm"
QT_MOC_LITERAL(11, 90, 10), // "setBattery"
QT_MOC_LITERAL(12, 101, 7), // "battery"
QT_MOC_LITERAL(13, 109, 15), // "canDisconnected"
QT_MOC_LITERAL(14, 125, 16), // "checkCanRestored"
QT_MOC_LITERAL(15, 142, 8), // "getSpeed"
QT_MOC_LITERAL(16, 151, 6), // "getRPM"
QT_MOC_LITERAL(17, 158, 10) // "getBattery"

    },
    "Car\0speedChanged\0\0rpmChanged\0"
    "batteryChanged\0canFail\0canRestored\0"
    "setSpeed\0speed\0setRPM\0rpm\0setBattery\0"
    "battery\0canDisconnected\0checkCanRestored\0"
    "getSpeed\0getRPM\0getBattery"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Car[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       3,   98, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   84,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    0,   94,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x0a /* Public */,
      16,    0,   96,    2, 0x0a /* Public */,
      17,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    8,
    QMetaType::Void, QMetaType::QReal,   10,
    QMetaType::Void, QMetaType::QReal,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QReal,
    QMetaType::QReal,
    QMetaType::QReal,

 // properties: name, type, flags
       8, QMetaType::QReal, 0x00495001,
      10, QMetaType::QReal, 0x00495001,
      12, QMetaType::QReal, 0x00495001,

 // properties: notify_signal_id
       1,
       1,
       2,

       0        // eod
};

void Car::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Car *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->rpmChanged(); break;
        case 2: _t->batteryChanged(); break;
        case 3: _t->canFail(); break;
        case 4: _t->canRestored(); break;
        case 5: _t->setSpeed((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 6: _t->setRPM((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->setBattery((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 8: _t->canDisconnected(); break;
        case 9: _t->checkCanRestored(); break;
        case 10: { qreal _r = _t->getSpeed();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 11: { qreal _r = _t->getRPM();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 12: { qreal _r = _t->getBattery();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Car::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::speedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Car::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::rpmChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Car::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::batteryChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Car::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::canFail)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Car::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::canRestored)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Car *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getSpeed(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getRPM(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->getBattery(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Car::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Car.data,
    qt_meta_data_Car,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Car::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Car::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Car.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Car::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Car::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Car::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Car::batteryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Car::canFail()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Car::canRestored()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

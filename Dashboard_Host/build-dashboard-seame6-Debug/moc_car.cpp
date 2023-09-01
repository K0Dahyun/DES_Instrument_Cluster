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
    QByteArrayData data[16];
    char stringdata0[141];
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
QT_MOC_LITERAL(5, 44, 10), // "canTimeout"
QT_MOC_LITERAL(6, 55, 8), // "setSpeed"
QT_MOC_LITERAL(7, 64, 5), // "speed"
QT_MOC_LITERAL(8, 70, 6), // "setRPM"
QT_MOC_LITERAL(9, 77, 3), // "rpm"
QT_MOC_LITERAL(10, 81, 10), // "setBattery"
QT_MOC_LITERAL(11, 92, 7), // "battery"
QT_MOC_LITERAL(12, 100, 13), // "setCanTimeout"
QT_MOC_LITERAL(13, 114, 8), // "getSpeed"
QT_MOC_LITERAL(14, 123, 6), // "getRPM"
QT_MOC_LITERAL(15, 130, 10) // "getBattery"

    },
    "Car\0speedChanged\0\0rpmChanged\0"
    "batteryChanged\0canTimeout\0setSpeed\0"
    "speed\0setRPM\0rpm\0setBattery\0battery\0"
    "setCanTimeout\0getSpeed\0getRPM\0getBattery"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Car[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       3,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   73,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
      10,    1,   79,    2, 0x0a /* Public */,
      12,    0,   82,    2, 0x0a /* Public */,
      13,    0,   83,    2, 0x0a /* Public */,
      14,    0,   84,    2, 0x0a /* Public */,
      15,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    7,
    QMetaType::Void, QMetaType::QReal,    9,
    QMetaType::Void, QMetaType::QReal,   11,
    QMetaType::Void,
    QMetaType::QReal,
    QMetaType::QReal,
    QMetaType::QReal,

 // properties: name, type, flags
       7, QMetaType::QReal, 0x00495001,
       9, QMetaType::QReal, 0x00495001,
      11, QMetaType::QReal, 0x00495001,

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
        case 3: _t->canTimeout(); break;
        case 4: _t->setSpeed((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: _t->setRPM((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 6: _t->setBattery((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->setCanTimeout(); break;
        case 8: { qreal _r = _t->getSpeed();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 9: { qreal _r = _t->getRPM();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 10: { qreal _r = _t->getBattery();
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Car::canTimeout)) {
                *result = 3;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
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
void Car::canTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

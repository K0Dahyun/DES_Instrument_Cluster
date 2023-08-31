/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a car_adaptor car.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef CAR_ADAPTOR_H
#define CAR_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface local.Car
 */
class CarAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "local.Car")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"local.Car\">\n"
"    <signal name=\"speedChanged\"/>\n"
"    <signal name=\"rpmChanged\"/>\n"
"    <signal name=\"batteryChanged\"/>\n"
"    <method name=\"setSpeed\">\n"
"      <arg direction=\"in\" type=\"d\" name=\"speed\"/>\n"
"    </method>\n"
"    <method name=\"setRPM\">\n"
"      <arg direction=\"in\" type=\"d\" name=\"rpm\"/>\n"
"    </method>\n"
"    <method name=\"setBattery\">\n"
"      <arg direction=\"in\" type=\"d\" name=\"battery\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    CarAdaptor(QObject *parent);
    virtual ~CarAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void setBattery(double battery);
    void setRPM(double rpm);
    void setSpeed(double speed);
Q_SIGNALS: // SIGNALS
    void batteryChanged();
    void rpmChanged();
    void speedChanged();
};

#endif

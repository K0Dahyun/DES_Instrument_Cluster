#ifndef BUSMANAGER_H
#define BUSMANAGER_H

#include <QObject>
#include <QDBusConnection>
#include <QDBusInterface>

#include "car.h"

class DBusManager : public QObject
{
    Q_OBJECT

public:
    explicit DBusManager(QObject *parent=nullptr);
    void registerCar(Car *car);
private:
    QDBusConnection connection;
};

#endif // BUSMANAGER_H

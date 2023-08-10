#include "busmanager.h"
#include "car.h"
#include "name_common.h"
#include "car_adaptor.h"

DBusManager::DBusManager(QObject *parent) : QObject(parent), connection(QDBusConnection::sessionBus())
{
}
void DBusManager::registerCar(Car *car)
{
    new CarAdaptor(car);
    if (!connection.registerObject(CAR_OBJECT_NAME, car)) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }
    if (!connection.registerService(CAR_SERVICE_NAME)) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }
}

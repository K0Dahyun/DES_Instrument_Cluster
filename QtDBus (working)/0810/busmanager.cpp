#include "busmanager.h"

DBusManager::DBusManager(QObject *parent) : QObject(parent), connection(QDBusConnection::sessionBus())
{
}
void DBusManager::registerObject(const QString &service, const QString &path, QObject *object)
{
    if (!connection.registerObject(path, object)) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }
    if (!connection.registerService(service)) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }
}

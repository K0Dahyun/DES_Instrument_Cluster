#ifndef BUSMANAGER_H
#define BUSMANAGER_H

#include <QObject>
#include <QDBusConnection>
#include <QDBusInterface>

class DBusManager : public QObject
{
    Q_OBJECT

public:
    explicit DBusManager(QObject *parent=nullptr);
    void registerObject(const QString &service, const QString &path, QObject *object);

private:
    QDBusConnection connection;
};

#endif // BUSMANAGER_H

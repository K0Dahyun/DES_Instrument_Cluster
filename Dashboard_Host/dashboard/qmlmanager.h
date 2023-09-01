#ifndef QMLMANAGER_H
#define QMLMANAGER_H

#include <QQmlApplicationEngine>

class QmlManager : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    QmlManager(QObject *parent = nullptr);

    void addObject(const QString &name, QObject *object);

};
#endif // QMLMANAGER_H



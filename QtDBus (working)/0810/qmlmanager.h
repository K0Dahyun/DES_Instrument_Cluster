#ifndef QMLMANAGER_H
#define QMLMANAGER_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>

class CustomQuickView : public QQuickView
{
    Q_OBJECT

public:
    explicit CustomQuickView(QWindow *parent = nullptr);

    void addObject(const QString &name, QObject *object);

};



#endif // QMLMANAGER_H


#include "qmlmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>

//using namespace std::literals::string_literals;


QmlManager::QmlManager(QObject *parent) : QQmlApplicationEngine(parent)
{
    const QUrl url(QStringLiteral("qrc:/qml/dashboard.qml"));
    QObject::connect(this, &QQmlApplicationEngine::objectCreated,
        this, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    load(url);

/*
    const QUrl url(u"qrc:/qml/dashboard.qml"_qs);
    QObject::connect(this, &QQmlApplicationEngine::objectCreated,
        this, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    load(url);
*/

}

void QmlManager::addObject(const QString &name, QObject *object)
{
    rootContext()->setContextProperty(name, object);
}

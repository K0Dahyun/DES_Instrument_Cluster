#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFont>
#include <QFontDatabase>


#include "car.h"
#include "busmanager.h"
#include "name_common.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/DejaVuSans.ttf");
    app.setFont(QFont("DejaVu Sans"));

    DBusManager dbusmanager;
    Car *car = new Car();
    dbusmanager.registerObject(CAR_SERVICE_NAME,CAR_OBJECT_NAME, car);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("car", car);

    const QUrl url(QStringLiteral("qrc:/qml/dashboard.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl){
                QCoreApplication::exit(-1);
            }

        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

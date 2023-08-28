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

    DBusManager dbusmanager;
    Car *car = new Car();
    dbusmanager.registerObject(CAR_SERVICE_NAME,CAR_OBJECT_NAME, car);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("car", car);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

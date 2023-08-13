#include <QApplication>
#include <QDBusReply>
#include <QDebug>

#include "mainwindow.h"
#include "car.h"
#include "busmanager.h"
#include "name_common.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DBusManager dbusmanager;
    Car *car = new Car();
    dbusmanager.registerCar(car);

    MainWindow w;
    w.show();

    return app.exec();
}

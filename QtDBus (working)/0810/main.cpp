#include <QApplication>

#include "mainwindow.h"
#include "car.h"
#include "busmanager.h"
#include "name_common.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DBusManager dbusmanager;
    Car *car = new Car();
    //Bicycle *bicycle= new Bicycle();

    dbusmanager.registerObject(CAR_SERVICE_NAME,CAR_OBJECT_NAME,car);
    //dbusmanager.registerObject(BICYCLE_SERVICE_NAME,BICYCLE_OBJECT_NAME,bicycle);

    MainWindow w;
    w.show();

    return app.exec();
}

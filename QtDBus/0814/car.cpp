#include "car.h"
#include "car_adaptor.h"
#include <QDebug>

Car::Car(QObject *parent) : QObject(parent)
{
    new CarAdaptor(this);
    speed = 0;
    battery = 0;
}

void Car::setSpeed(qreal speed)
{
    this->speed = speed;
    emit speedChanged();
}
void Car::setBattery(qreal battery)
{
    this->battery = battery;
    emit batteryChanged();
}
qreal Car::getSpeed()
{
    qDebug() << "speed data : " << speed;
    return speed;
}
qreal Car::getBattery()
{
    qDebug() << "battery data : " << battery;
    return battery;
}


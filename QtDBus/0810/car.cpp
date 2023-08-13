#include "car.h"
#include "car_adaptor.h"

Car::Car(QObject *parent) : QObject(parent)
{
    new CarAdaptor(this);
    speed = 50.0;
    battery = 100.0;
}

void Car::setSpeed(qreal speed)
{
    this->speed = speed;
    emit speedChanged();
}
void Car::setBattery(qreal battery)
{
    this->battery = battery;
}
qreal Car::getSpeed()
{
    return speed;
}
qreal Car::getBattery()
{
    return battery;
}


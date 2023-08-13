#include "car.h"
Car::Car(QObject *parent) : QObject(parent)
{
    speed = 50.0;
    battery = 100.0;
}

void Car::setSpeed(qreal speed)
{
    this->speed = speed;
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


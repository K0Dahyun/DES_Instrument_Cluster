#include "car.h"
#include "car_adaptor.h"
#include <QDebug>

Car::Car(QObject *parent) : QObject(parent)
{
    new CarAdaptor(this);
    speed = 0;
    rpm = 0;
    battery = 0;
}

void Car::setSpeed(int speed)
{
    this->speed = speed;
    emit speedChanged();
}

void Car::setRPM(int rpm)
{
    this->rpm = rpm;
    emit rpmChanged();
}

void Car::setBattery(int battery)
{
    this->battery = battery;
    emit batteryChanged();
}

int Car::getSpeed()
{
    qDebug() << "speed data : " << speed;
    return speed;
}

int Car::getRPM()
{
    qDebug() << "rpm data : " << rpm;
    return rpm;
}

int Car::getBattery()
{
    qDebug() << "battery data : " << battery;
    return battery;
}


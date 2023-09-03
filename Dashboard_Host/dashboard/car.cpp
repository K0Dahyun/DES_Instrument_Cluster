#include "car.h"
#include "car_adaptor.h"
#include <QDebug>

Car::Car(QObject *parent) : QObject(parent), speed(0), rpm(0), battery(0), canStatus(false)
{
    new CarAdaptor(this);
}

void Car::setSpeed(qreal speed)
{
    this->speed = speed;
    emit speedChanged();
}

void Car::setRPM(qreal rpm)
{
    this->rpm = rpm;
    emit rpmChanged();
}

void Car::setBattery(qreal battery)
{
    this->battery = battery;
    emit batteryChanged();
}

void Car::candisConnected() {
    qDebug() << "can disconnect ";
    emit candisconnected();
}

void Car::canConnected() {
    emit canconnected();
}

qreal Car::getSpeed()
{
    qDebug() << "speed data : " << speed;
    return speed;
}

qreal Car::getRPM()
{
    qDebug() << "rpm data : " << rpm;
    return rpm;
}

qreal Car::getBattery()
{
    qDebug() << "battery data : " << battery;
    return battery;
}



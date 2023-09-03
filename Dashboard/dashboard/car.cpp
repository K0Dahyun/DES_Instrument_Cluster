#include "car.h"
#include "car_adaptor.h"
#include <QDebug>

Car::Car(QObject *parent) : QObject(parent), speed(0), rpm(0), battery(0), canStatus(false)
{
    new CarAdaptor(this);
}

void Car::setSpeed(qreal speed)
{
    checkCanRestored();
    this->speed = speed;
    emit speedChanged();
}

void Car::setRPM(qreal rpm)
{
    checkCanRestored();
    this->rpm = rpm;
    emit rpmChanged();
}

void Car::setBattery(qreal battery)
{
    checkCanRestored();
    this->battery = battery;
    emit batteryChanged();
}

void Car::canDisconnected() {
    qDebug() << "can disconnect ";
    this->canStatus = true;
    emit canFail();
}

void Car::checkCanRestored() {
    if(canStatus){
        canStatus = false;
        emit canRestored();
    }
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




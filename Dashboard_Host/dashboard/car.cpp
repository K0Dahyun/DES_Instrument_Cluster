#include "car.h"
#include "car_adaptor.h"
#include <QDebug>
#include <QProcess>

Car::Car(QObject *parent) : QObject(parent), speed(0), rpm(0), battery(0), canstatus(false), speedUpdated(false), rpmUpdated(false), batteryUpdated(false)
{
    new CarAdaptor(this);

    timeoutTime = new QTimer(this);
    timeoutTime->setInterval(1000);
    connect(timeoutTime, &QTimer::timeout, this, &Car::checkDbusStatus);
    timeoutTime->start();
}

void Car::setSpeed(qreal speed)
{
    this->speed = speed;
    speedUpdated = true;
    emit speedChanged();
}

void Car::setRPM(qreal rpm)
{
    this->rpm = rpm;
    rpmUpdated = true;
    emit rpmChanged();
}

void Car::setBattery(qreal battery)
{
    this->battery = battery;
    batteryUpdated = true;
    emit batteryChanged();
}

void Car::checkCanStatus(bool canstatus) {
    if (canstatus){
        timeoutTime->stop();
        qDebug() << "can disconnect ";
        emit candisconnected();
    }
    else{
        if(!timeoutTime->isActive()){
            timeoutTime->start();
        }
        qDebug() << "can reconneted ";
        emit canconnected();
    }
}

void Car::checkDbusStatus()
{
    qDebug() << "HAHAHAHAHAHA ";
    if(!speedUpdated)
        emit speeddisconnected();
    if(!rpmUpdated)
        emit rpmdisconnected();
    if(!batteryUpdated)
        emit batterydisconnected();

    speedUpdated = false;
    rpmUpdated = false;
    batteryUpdated = false;
}

qreal Car::getSpeed() const
{
    qDebug() << "speed data : " << speed;
    return speed;
}

qreal Car::getRPM() const
{
    qDebug() << "rpm data : " << rpm;
    return rpm;
}

qreal Car::getBattery() const
{
    qDebug() << "battery data : " << battery;
    return battery;
}



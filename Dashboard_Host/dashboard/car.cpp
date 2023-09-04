#include "car.h"
#include "car_adaptor.h"
#include <QDebug>
#include <QProcess>

Car::Car(QObject *parent) : QObject(parent), speed(0), rpm(0), battery(0), canstatus(false)
{
    new CarAdaptor(this);
/*
    timeoutTime = new QTimer(this);
    timeoutTime->setInterval(3000);
    connect(timeoutTime, &QTimer::timeout, this, &Car::hadleTimeout);
    connect(this, &Car::speedChanged, timeoutTime, QOverload<>::of(&QTimer::start));
    connect(this, &Car::rpmChanged, timeoutTime, QOverload<>::of(&QTimer::start));
    connect(this, &Car::batteryChanged, timeoutTime, QOverload<>::of(&QTimer::start));
    timeoutTime->start();*/
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

void Car::checkCanStatus(bool canstatus) {
    if (canstatus){
        qDebug() << "can disconnect ";
        emit candisconnected();
    }
    else{
        emit canconnected();
    }
}
/*
void Car::canConnected() {
    emit canconnected();
}

void Car::hadleTimeout() {
    timeoutTime->stop();
    dbusdisconnected();
}*/

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



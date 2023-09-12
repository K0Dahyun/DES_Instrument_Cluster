#include "car.h"
#include "car_adaptor.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QVector>

Car::Car(QObject *parent)
    : QObject(parent),
    speed(0), rpm(0), battery(0), canstatus(false),
    speedUpdated(false), rpmUpdated(false), batteryUpdated(false)
{
    new CarAdaptor(this);

    timeoutTime = new QTimer(this);
    timeoutTime->setInterval(200);
    connect(timeoutTime, &QTimer::timeout, this, &Car::checkDbusStatus);
    timeoutTime->start();

    elapsedTimer.start();
}

void Car::setSpeed(qreal speed)
{
    qint64 elapsedTime = elapsedTimer.elapsed();
    intervals.append(elapsedTime);

    qint64 totalElapsed = 0;
    for(int i = 0; i < intervals.size(); ) {
        totalElapsed += intervals[i];
        if(totalElapsed > 60000) {
            intervals.removeAt(0);
        } else {
            ++i;
        }
    }

    qint64 averageInterval = 0;
    if(!intervals.isEmpty()) {
        averageInterval = totalElapsed / intervals.size();
        qDebug() << "Average time between setSpeed calls in the last minute:" << averageInterval << "ms";
    }

    this->speed = speed;
    speedUpdated = true;
    emit speedChanged();

    elapsedTimer.restart();
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

#include "car.h"
#include "car_adaptor.h"

Car::Car(QObject *parent) : QObject(parent)
{
    new CarAdaptor(this);
    m_speed = 50.0;
    m_battery = 100.0;
    m_time = "";
}

void Car::setSpeed(qreal speed)
{
    this->m_speed = speed;
    emit speedChanged();
}
void Car::setBattery(qreal battery)
{
    this->m_battery = battery;
    emit batteryChanged();
}
void Car::setTime()
{
    m_time=QDateTime::currentDateTimeUtc().toString("HH:mm");
    emit timeChanged();
}
qreal Car::getSpeed()
{
    return m_speed;
}
qreal Car::getBattery()
{
    return m_battery;
}
QString Car::getTime()
{
    return m_time;
}


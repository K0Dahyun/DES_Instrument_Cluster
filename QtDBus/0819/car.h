#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal speed READ getSpeed NOTIFY speedChanged)
    Q_PROPERTY(qreal battery READ getBattery NOTIFY batteryChanged)
    Q_PROPERTY(QString time READ getTime NOTIFY timeChanged)

public:
    explicit Car(QObject *parent = nullptr);

public Q_SLOTS:
    void setSpeed(qreal speed);
    void setBattery(qreal battery);
    void setTime();

    qreal getSpeed();
    qreal getBattery();
    QString getTime();

signals :
    void speedChanged();
    void batteryChanged();
    void timeChanged();
private:
    float m_speed;
    float m_battery;
    QString m_time;
};

#endif // CAR_H

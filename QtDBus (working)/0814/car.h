#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int speed READ getSpeed NOTIFY speedChanged)
    Q_PROPERTY(int rpm READ getRPM NOTIFY rpmChanged)
    Q_PROPERTY(int battery READ getBattery NOTIFY batteryChanged)

public:
    explicit Car(QObject *parent = nullptr);

public Q_SLOTS:
    void setSpeed(int speed);
    void setRPM(int rpm);
    void setBattery(int battery);

    int getSpeed();
    int getRPM();
    int getBattery();

signals :
    void speedChanged();
    void rpmChanged();
    void batteryChanged();

private:
    int speed;
    int rpm;
    int battery;
};

#endif // CAR_H

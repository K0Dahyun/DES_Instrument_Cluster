#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QTimer>

class Car : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal speed READ getSpeed NOTIFY rpmChanged)
    Q_PROPERTY(qreal rpm READ getRPM NOTIFY rpmChanged)
    Q_PROPERTY(qreal battery READ getBattery NOTIFY batteryChanged)

public:
    explicit Car(QObject *parent = nullptr);
    qreal getSpeed() const;
    qreal getRPM() const;
    qreal getBattery() const;

public Q_SLOTS:
    void setSpeed(qreal speed);
    void setRPM(qreal rpm);
    void setBattery(qreal battery);

    void checkCanStatus(bool canstatus);
    //void canConnected();

    //void hadleTimeout();

signals :
    void speedChanged();
    void rpmChanged();
    void batteryChanged();

    void candisconnected();
    void canconnected();

private:
    qreal speed;
    qreal rpm;
    qreal battery;
    bool canstatus;
    //QTimer* timeoutTime;

    //void runPython();
};

#endif // CAR_H

#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int speed READ getSpeed NOTIFY speedChanged)
public:
    explicit Car(QObject *parent = nullptr);
public Q_SLOTS:
    void setSpeed(qreal speed);
    void setBattery(qreal battery);
    qreal getSpeed();
    qreal getBattery();

    //Q_SIGNALS:
    //    Q_SCRIPTABLE qreal blabla();
signals :
    void speedChanged();
private:
    float speed;
    float battery;
};

#endif // CAR_H

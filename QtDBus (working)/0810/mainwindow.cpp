#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "name_common.h"

#include <QDebug>
#include <QDBusReply>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    timer->start(1000.0f/60.0f);

    iface = new QDBusInterface(CAR_SERVICE_NAME, CAR_OBJECT_NAME, CAR_INTERFACE_NAME, QDBusConnection::sessionBus());

    connect(timer, SIGNAL(timeout()), this, SLOT(gui_update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gui_update()
{
    QDBusReply<qreal> a = iface->call("getSpeed");
    qDebug()<<a.value();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QApplication>
#include <QDBusInterface>
#include <QWidget>
#include <QTimer>
#include <QDBusConnection>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void gui_update();

private:
    Ui::MainWindow *ui;
    QDBusInterface *iface;
    QTimer *timer;

};
#endif // MAINWINDOW_H

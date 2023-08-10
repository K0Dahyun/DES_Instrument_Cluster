import can
import dbus
import dbus.service

class DataReceiver:
    def __init__(self):
        self.counter = 0
    
    def receive_temp_data(self):
        self.counter += 1
        print(self.counter)
        return self.counter

if __name__ == "__main__":
    bus = dbus.SessionBus()

    service = bus.get_object("org.example.CarExample", "/Car")
    car_interface = dbus.Interface(service, "local.Car")

    receiver = DataReceiver()
    data = receiver.receive_temp_data()

    car_interface.setSpeed(data)
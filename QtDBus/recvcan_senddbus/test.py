import can
import dbus
import dbus.service
import time

class DataReceiver:
    def __init__(self):
        self.counter = 0
        self.counter1 = 0
    	
    def receive_temp_data(self):
        self.counter += 1
        
        print(self.counter)
        return self.counter

    def receive_temp_data1(self):
        
        self.counter1 += 1
        print(self.counter1)
        return self.counter1

if __name__ == "__main__":
    bus = dbus.SessionBus()

    service = bus.get_object("org.example.CarExample", "/Car")
    car_interface = dbus.Interface(service, "local.Car")

    receiver = DataReceiver()
    
    while receiver.counter < 280:
        data = receiver.receive_temp_data()
        data1= receiver.receive_temp_data1()
        car_interface.setSpeed(data)
        car_interface.setBattery(data1)
        time.sleep(0.1) 
        

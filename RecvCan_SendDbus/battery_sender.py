import os
import can
import time
import dbus
import dbus.service
from piracer.vehicles import PiRacerStandard

piracer = PiRacerStandard()

class DataReceiver:
    def __init__(self, filter_size=30):
        self.data_queue = []
        self.filter_size = filter_size

    def getBattery(self):
        battery = piracer.get_battery_voltage()
        battery_level = (battery/3-3.1)*100/1.1
        return int(battery_level)

    def moving_average(self, data):
        self.data_queue.append(data) 

        if len(self.data_queue) > self.filter_size:
            self.data_queue.pop(0)
        
        return sum(self.data_queue) / len(self.data_queue)

if __name__ == "__main__":


    bus=dbus.SessionBus()
    service = bus.get_object("org.example.CarExample","/Car")
    car_interface = dbus.Interface(service,"local.Car")


    receiver = DataReceiver()
    moving_average_list = []

    while 1: 
        raw_data=receiver.getBattery()
        print(raw_data)

        if isinstance(raw_data, int):
            if receiver.filter_size == 30:
                filtering_data = receiver.moving_average(raw_data)
                print(filtering_data)
                car_interface.setBattery(filtering_data)
            else:
                car_interface.setBattery(raw_data)

        time.sleep(0.1)


import os
import can
import dbus
import time
import dbus.service
import time  
from piracer.vehicles import PiRacerStandard
from gi.repository import GLib

piracer = PiRacerStandard()
CAN_ID = "can0"

class DataReceiver:
    def __init__(self):
        os.system(f'sudo ifconfig {CAN_ID} down')
        os.system(f'sudo ip link set {CAN_ID} up type can bitrate 500000 dbitrate 8000000 restart-ms 1000 berr-reporting on fd on')
        self.can = can.interface.Bus(channel = CAN_ID, bustype = 'socketcan')
        self.battery=0
    def rpm2speed(self, rpm) -> float:
        #todo:add some equation here
        speed = rpm 
        return speed

    def getDistance(self) -> float:
        msg = self.can.recv();
        if msg is None:
            return "No message recieved"
        distance = msg.data[2] + msg.data[3]*256
        return distance

    def getSpeed(self) -> float:
        msg = self.can.recv();
        if msg is None:
            return "No message recieved"
        rpm = msg.data[0] + msg.data[1]*256
        speed = self.rpm2speed(rpm)
        return speed
        
    def print_battery_report(self)-> int:
    	self.battery= piracer.get_battery_voltage()
    	battery=(self.battery/3-2.5)*100/1.7
    	return battery
    	

if __name__ == "__main__":
    bus = dbus.SessionBus()

    service = bus.get_object("org.example.CarExample", "/Car")
    car_interface = dbus.Interface(service, "local.Car")

    receiver = DataReceiver()

    loop = GLib.MainLoop()
    loop.run()
    while receiver.counter < 280:
        data = receiver.receive_temp_data()
        #data1= receiver.receive_temp_data1()
        data1= receiver.print_battery_report()
        car_interface.setSpeed(data)
        car_interface.setBattery(data1)
        time.sleep(0.5) 
        

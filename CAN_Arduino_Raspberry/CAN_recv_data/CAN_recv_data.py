import os
import can
import time
from piracer.vehicles import PiRacerStandard

piracer = PiRacerStandard()
CAN_ID = "can0"

class DataReceiver:
    def __init__(self):
        os.system(f'sudo ifconfig {CAN_ID} down')
        os.system(f'sudo ip link set {CAN_ID} up type can bitrate 500000 dbitrate 8000000 restart-ms 1000 berr-reporting on fd on')
        self.can = can.interface.Bus(channel = CAN_ID, bustype = 'socketcan')
        self.battery=0

    def getSpeed(self) -> float:
        msg = self.can.recv()
        if msg is None:
            return "No message recieved"
        rpm = msg.data[0] + msg.data[1]*256
        speed = self.rpm2speed(rpm)
        return speed
    	
if __name__ == "__main__":
    receiver = DataReceiver()

    while 1:
        data = receiver.getSpeed()
        print(data)
        

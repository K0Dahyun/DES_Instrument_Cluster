import os
import can
import dbus
import dbus.service
import time
import struct
from pykalman import KalmanFilter
import numpy as np

CAN_ID = "can0" 

class DataReceiver:
    def __init__(self, filter_size=5):
        os.system(f'sudo ifconfig {CAN_ID} down')
        os.system(f'sudo ip link set {CAN_ID} up type can bitrate 500000 dbitrate 8000000 restart-ms 1000 berr-reporting on fd on')
        self.can = can.interface.Bus(channel = CAN_ID, bustype = 'socketcan')

        # Kalman Filter
        self.kf = KalmanFilter(initial_state_mean=0, n_dim_obs=1)
        self.kf = self.kf.em(np.zeros(filter_size), n_iter=5)
        self.kf_state = self.kf.initial_state_mean

        self.kf1 = KalmanFilter(initial_state_mean=0, n_dim_obs=1)
        self.kf1 = self.kf1.em(np.zeros(filter_size), n_iter=5)
        self.kf1_state = self.kf1.initial_state_mean

        
    def getdata(self):
        msg = self.can.recv(timeout=0.2)
        if msg is None : 
            print("Can disconnect")
            return None, None

        rpm = struct.unpack('f', msg.data[0:4])[0]
        speed = struct.unpack('f', msg.data[4:8])[0]
        return rpm, speed

    def kalman_filter(self, measurement, measurement1):
        filtered_state_mean, filtered_state_covariance = self.kf.filter_update(
            self.kf_state, self.kf.initial_state_covariance, observation=measurement
        )
        self.kf_state = filtered_state_mean

        filtered_state_mean1, filtered_state_covariance1 = self.kf1.filter_update(
            self.kf1_state, self.kf1.initial_state_covariance, observation=measurement1
        )
        self.kf1_state = filtered_state_mean1

        return filtered_state_mean, filtered_state_mean1

    

if __name__ == "__main__":

    bus=dbus.SessionBus()
    service = bus.get_object("org.example.CarExample","/Car")
    car_interface = dbus.Interface(service,"local.Car")
    
    receiver = DataReceiver()

    while 1:
        rpm, speed = receiver.getdata()

        if rpm is None and speed is None :
            car_interface.setCanTimeout()
            car_interface.setRPM(0)
            car_interface.setSpeed(0)
            continue

        filtering_RPM_data, filtering_Speed_data = receiver.kalman_filter(rpm, speed)
        print(filtering_RPM_data)
        print(filtering_Speed_data)
        car_interface.setRPM(filtering_RPM_data)
        car_interface.setSpeed(filtering_Speed_data)

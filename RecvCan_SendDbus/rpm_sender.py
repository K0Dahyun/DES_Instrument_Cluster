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
        self.can = can.interface.Bus(channel = CAN_ID, bustype = 'socketcan')

        # Kalman Filter
        self.kf = KalmanFilter(initial_state_mean=0, n_dim_obs=1)
        self.kf = self.kf.em(np.zeros(filter_size), n_iter=5)
        self.kf_state = self.kf.initial_state_mean
    
    def getdata(self):
        msg = self.can.recv(timeout=0.2)
        if msg is None : 
            print("Can disconnect")
            return None

        rpm = struct.unpack('f', msg.data[0:4])[0]
        return rpm

    def kalman_filter(self, measurement):
        filtered_state_mean, filtered_state_covariance = self.kf.filter_update(
            self.kf_state, self.kf.initial_state_covariance, observation=measurement
        )
        self.kf_state = filtered_state_mean

        return filtered_state_mean

    

if __name__ == "__main__":

    bus=dbus.SessionBus()
    service = bus.get_object("org.example.CarExample","/Car")
    car_interface = dbus.Interface(service,"local.Car")
    
    receiver = DataReceiver()

    while 1:
        rpm = receiver.getdata()

        if rpm is None :
            car_interface.checkCanStatus(True)

        else :
            car_interface.checkCanStatus(False)
            filtering_RPM_data = receiver.kalman_filter(rpm)
            print(filtering_RPM_data)
            car_interface.setRPM(filtering_RPM_data)

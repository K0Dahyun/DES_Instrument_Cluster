import os
import can
import time
from piracer.vehicles import PiRacerStandard
from pykalman import KalmanFilter
import matplotlib.pyplot as plt
import numpy as np

piracer = PiRacerStandard()
CAN_ID = "can0"

class DataReceiver:
    def __init__(self, filter_size=5):
        os.system(f'sudo ifconfig {CAN_ID} down')
        os.system(f'sudo ip link set {CAN_ID} up type can bitrate 500000 dbitrate 8000000 restart-ms 1000 berr-reporting on fd on')
        self.can = can.interface.Bus(channel = CAN_ID, bustype = 'socketcan')

        # moving_average
        self.data_queue = []
        self.filter_size = filter_size
        
        # low_pass
        self.prev_filtered = 0
        self.alpha = 0.3

        # Kalman Filter
        self.kf = KalmanFilter(initial_state_mean=0, n_dim_obs=1)
        self.kf = self.kf.em(np.zeros(filter_size), n_iter=5)
        self.kf_state = self.kf.initial_state_mean

    def getRPM(self):
        msg = self.can.recv()
        if msg is None:
            return "No message recieved"
        rpm = msg.data[0] + msg.data[1]*256
        speed = msg.data[2] + msg.data[3]*256
        return rpm, speed

    def moving_average(self, data):
        self.data_queue.append(data) 

        if len(self.data_queue) > self.filter_size:
            self.data_queue.pop(0)
        
        return sum(self.data_queue) / len(self.data_queue)

    def low_pass_filter(self, current_value):
        filtered = self.alpha * current_value + (1 - self.alpha) * self.prev_filtered
        self.prev_filtered = filtered
        return filtered

    def kalman_filter(self, measurement):
        filtered_state_mean, filtered_state_covariance = self.kf.filter_update(
            self.kf_state, self.kf.initial_state_covariance, observation=measurement
        )
        self.kf_state = filtered_state_mean
        return filtered_state_mean
    
def plot_time_response(raw, filtered1, filtered2, filtered3):
    plt.figure()
    plt.plot(raw, label="Raw Speed")
    plt.plot(filtered1, label="moving Speed")
    plt.plot(filtered2, label="low_pass Speed")
    plt.plot(filtered3, label="Kalman Speed")
    plt.legend()
    plt.title("Time Response")
    plt.xlabel("Time")
    plt.ylabel("Speed")
    plt.show()

def plot_results(raw, filtered1, filtered2,filtered3, fs):
    fig, axs = plt.subplots(2, 2, figsize=(14,10))
    
    # Time Response
    axs[0, 0].plot(raw, label="Raw Speed")
    axs[0, 0].plot(filtered1, label="Moving Speed")
    axs[0, 0].plot(filtered2, label="Low Pass Speed")
    axs[0, 0].plot(filtered3, label="Kalman Speed")
    axs[0, 0].legend()
    axs[0, 0].set_title("Time Response")
    axs[0, 0].set_xlabel("Time")
    axs[0, 0].set_ylabel("Speed")


    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    receiver = DataReceiver()

    raw_data_list = []
    moving_average_list = []
    low_pass_list=[]
    kalman_list = []

    start = time.time()

    while time.time() - start < 60: 
        rpm, speed = receiver.getRPM()
        if isinstance(speed, int): 
            moving_average_data = receiver.moving_average(speed)
            low_pass_data = receiver.low_pass_filter(speed)
            kalman_data = receiver.kalman_filter(speed)
            print(rpm)

            raw_data_list.append(speed)
            moving_average_list.append(moving_average_data)
            low_pass_list.append(low_pass_data)
            kalman_list.append(kalman_data)
       

    # After collecting data for 1 minute, plot the results
    plot_time_response(raw_data_list, moving_average_list, low_pass_list, kalman_list)
    plot_results(raw_data_list, moving_average_list, low_pass_list, kalman_list, 1)

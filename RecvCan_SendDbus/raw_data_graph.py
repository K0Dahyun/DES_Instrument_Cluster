import os
import can
import time
import struct
from pykalman import KalmanFilter
from piracer.vehicles import PiRacerStandard
import matplotlib.pyplot as plt
import numpy as np

piracer = PiRacerStandard()
piracer.set_throttle_percent(0.3)

CAN_ID = "can0"

class DataReceiver:
    def __init__(self, filter_size=5):
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

    def getdata(self):
        msg = self.can.recv(timeout=0.2)
        if msg is None : 
            print("Can disconnect")
            return None

        rpm = struct.unpack('f', msg.data[4:8])[0]
        speed = struct.unpack('f', msg.data[0:4])[0]

        battery = piracer.get_battery_voltage()
        battery = (battery/3-3.1)*100/1.1

        return rpm,speed, battery

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

def plot_time_raw_data(rpm, speed, battery):
    fig, axs = plt.subplots(2, 2, figsize=(14,10))
    
    # Time Response
    axs[0, 0].plot(rpm, label="Raw RPM")
    axs[0, 0].legend()
    axs[0, 0].set_title("Time Response")
    axs[0, 0].set_xlabel("Time")
    axs[0, 0].set_ylabel("rpm")

    axs[0, 1].plot(speed, label="Raw Speed")
    axs[0, 1].legend()
    axs[0, 1].set_title("Time Response")
    axs[0, 1].set_xlabel("Time")
    axs[0, 1].set_ylabel("Speed")

    axs[1, 0].plot(battery, label="Raw battery")
    axs[1, 0].legend()
    axs[1, 0].set_title("Time Response")
    axs[1, 0].set_xlabel("Time")
    axs[1, 0].set_ylabel("battery")

    plt.tight_layout()
    plt.show()

def plot_filtering_compare_speed(raw, filtered1, filtered2, filtered3):
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

def plot__filterin_frequency_response(*data_lists):
    plt.figure()
    fs = len(data_lists[0]) / 60
    
    labels = ["Raw Speed", "Moving Average Speed", "Low Pass Speed", "Kalman Speed"]
    
    for idx, data in enumerate(data_lists):
        n = len(data)
        k = np.arange(n)
        T = n/fs
        frq = k/T 
        frq = frq[range(n//2)]
        
        Y = np.fft.fft(data)/n
        Y = Y[range(n//2)]
        
        plt.plot(frq, abs(Y), label=labels[idx])
        
    plt.title('Frequency Response')
    plt.xlabel('Freq (Hz)')
    plt.ylabel('|Y(freq)|')
    plt.legend()
    plt.show()

def plot_mean_and_kalman(speed_list, kalman_list):
    plt.figure()
    mean_speed = np.mean(speed_list)
    mean_list = [mean_speed] * len(speed_list)
    plt.plot(mean_list, label="Mean Speed", linestyle='--')
    plt.plot(kalman_list, label="Kalman Speed")
    plt.legend()
    plt.title("Mean and Kalman Speed Comparison")
    plt.xlabel("Time")
    plt.ylabel("Speed")
    
    plt.show()


if __name__ == "__main__":
    receiver = DataReceiver()

    rpm_list = []
    speed_list = []
    battery_List=[]

    moving_average_list = []
    low_pass_list=[]
    kalman_list = []

    start = time.time()

    while time.time() - start < 60: 
        rpm, speed, battery = receiver.getdata()

        rpm_list.append(rpm)
        speed_list.append(speed)
        battery_List.append(battery)

        moving_average_data = receiver.moving_average(speed)
        low_pass_data = receiver.low_pass_filter(speed)
        kalman_data = receiver.kalman_filter(speed)

        moving_average_list.append(moving_average_data)
        low_pass_list.append(low_pass_data)
        kalman_list.append(kalman_data)

    # After collecting data for 1 minute, plot the results
    plot_time_raw_data(rpm_list, speed_list, battery_List)
    plot_filtering_compare_speed(speed_list, moving_average_list, low_pass_list, kalman_list)
    plot__filterin_frequency_response(speed_list, moving_average_list, low_pass_list, kalman_list)
    plot_mean_and_kalman(speed_list, kalman_list)

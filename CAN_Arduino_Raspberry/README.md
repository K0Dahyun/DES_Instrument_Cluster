# Communication between the Raspberry Pi and the Arduino
Now, we transmit data through CAN communication between the Raspberry Pi and the Arduino. Both the Raspberry Pi and Arduino use CAN shields.
First, we check the transmission and reception of random data without including sensor data.
Once CAN communication is confirmed to be working, we transmit and receive data including sensor data.


## Reference
[2-CH_CAN_FD_HAT](https://www.waveshare.com/wiki/2-CH_CAN_FD_HAT)

[github](https://github.com/SeeedDocument/2-Channel-CAN-BUS-FD-Shield-for-Raspberry-Pi)

## Materials required
| Arduino Uno       | CAN-Bus Shield V2       |
| :-------------:|:-------------: |
| <img src="https://github.com/K0Dahyun/Project-2/assets/119277948/44f1cfcf-119d-409c-ae7f-25e8c696cb19" width="200" /> | <img src="https://github.com/K0Dahyun/Project-2/assets/119277948/2fdb748a-a24b-45be-95ac-43f2b8c1cc63" width="200" /> |

| Raspberry Pi 4        | 2-Channel CAN-BUS(FD) Shield       |
| :-------------:|:-------------: |
| <img src="https://github.com/K0Dahyun/Project-2/assets/119277948/65a02c04-b620-4a19-b523-c5c34eed8484" width="200" /> | <img src="https://github.com/K0Dahyun/Project-2/assets/119277948/d772e2df-4d43-4c5c-b343-d855383ae532" width="200" /> |


## HardWare Setting
First, You connect the CAN hat and the Raspberry Pi as shown in the picture and table below.

<img src="https://github.com/K0Dahyun/Project-2/assets/119277948/6c8f61e0-805f-4c1b-b890-d61d6d348519" width="350" height="300"/>


| 2-Channel CAN-BUS(FD) Shield        | CAN-BUS Shield V2       |
| :-------------:|:-------------: |
| CAN_0_L | CANL |
| CAN_0_H | CANH |


## Software Setting
1. Install CAN Hat
```c
  git clone https://github.com/seeed-Studio/pi-hats
  cd pi-hats/CAN-HAT
  sudo ./install.sh 
  sudo reboot
```


2. Check the kernel log to see if MCP2517 was initialized successfully.You will also see can0 and can1 appear in the list of ifconfig results
```c
  dmesg | grep spi
  /pi-hats/CAN-HAT $ ifconfig -a
```


3. Set the can fd protocol, and the dbitrate can be set to 8M speed.
```c
sudo ip link set can0 up type can bitrate 1000000   dbitrate 8000000 restart-ms 1000 berr-reporting on fd on
sudo ip link set can1 up type can bitrate 1000000   dbitrate 8000000 restart-ms 1000 berr-reporting on fd on

sudo ifconfig can0 txqueuelen 65536
sudo ifconfig can1 txqueuelen 65536
```
It appears that data is being generated from the "can0" interface and then received back on the "can0" interface.

The first four commands are used to set up and enable two CAN interfaces named "can0" and "can1". The standard data bit rate of each interface is set to 1 Mbit/s, the bit rate of the data portion is set to 8 Mbit/s, and the bus error reporting function and CAN FD mode are enabled.

**The important point here is that the bitrate or dbitrate of the transmitting can and the receiving can must be the same. Both nodes need to receive data at the same speed for normal CAN communication to be possible**

The next two commands set the transmit queue length for each "can0" and "can1" interface. This queue regulates the number of packets waiting for transmission on the interface.


4. Open two terminal windows and enter the following commands in the Windows to test can fd protocol.
```
#send data
cangen can0 -mv 
#dump data
candump can0
```
Then the "cangen can0 -mv" command is executed, which generates random CAN frames on the "can0" interface. The "-mv" option generates CAN messages with randomly varying data lengths and data values.

Finally, the "candump can0" command outputs all CAN frames received on the "can0" interface. So it will show the CAN frames that were previously generated with the "cangen" command.

Therefore, looking at these commands as a whole, it can be seen as an example showing data being generated on "can0" and then received back on "can0". However, as the "can1" interface is also set up, similar operations can be performed on "can1" as well.


## Communication betweeen Arduino and Raspberry
We have now completed the settings for CAN communication. 

We proceed with the CAN communication between the Arduino connected to the sensor and the Raspberry Pi that intends to receive the sensor data.

First, execute the [CAN_send_data](https://github.com/K0Dahyun/Project-2/blob/main/CAN_Arduino_Raspberry/CAN_send_data/CAN_send_data.ino) code to transmit sensor data from the Arduino. 

Then, on the Raspberry Pi, use the [CAN_recv_data](https://github.com/K0Dahyun/Project-2/blob/main/CAN_Arduino_Raspberry/CAN_recv_data/CAN_recv_data.py) code to confirm the reception of the data.



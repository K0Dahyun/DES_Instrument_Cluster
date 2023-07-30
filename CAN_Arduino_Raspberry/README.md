# Communication between the Raspberry Pi and the Arduino
Now, we transmit data through CAN communication between the Raspberry Pi and the Arduino. Both the Raspberry Pi and Arduino use CAN shields.
First, to confirm that CAN communication is proceeding normally, we check the transmission and reception of random data without including sensor data.
Once CAN communication is confirmed to be working, we transmit and receive data including sensor data.


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

4. Open two terminal windows and enter the following commands in the Windows to test can fd protocol.
```
#send data
cangen can0 -mv 
#dump data
candump can0





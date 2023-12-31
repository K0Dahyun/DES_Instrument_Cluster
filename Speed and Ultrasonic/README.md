# Connect the Speed and Ultrasonic Sensor
Connect the speed sensor and ultrasonic sensor wires to the Arduino Uno and verify that it receives data correctly.
At this point, steps 1 and 2 are not for CAN communication, but solely for checking if the sensor data is properly received by the Arduino Uno. Then, in step 3, we attempt CAN communication between Arduino Uno and Arduino Nano.


## 1. Speed Sensor(Model : LM393)
Whether you’re building a small robot or using any kind of motors in your projects, it might be useful to know the speed at which your are driving them.
In this section, we will see how to connect and use an infrared speed sensor based on the LM393 chip.
The speed sensor uses a disc with holes (encoder disc) to block the infrared beam, thus by counting the number of times the sensors goes from Low to High we can calculate the number of revolution for a given time period.

In this section, we will connect the speed sensor and the LCD together. However, the final goal is to connect the LCD to the Raspberry Pi, not the Arduino. The LCD connection discussed here is merely a test.
[Reference]([https://www.brainy-bits.com/post/how-to-use-a-speed-sensor-with-arduino](https://srituhobby.com/ir-infrared-speed-sensor-with-arduino-how-does-work-ir-speed-sensor/?utm_content=cmp-true))


### First, we need to wire it as shown in the picture below.
<img src="https://github.com/K0Dahyun/Project-2/assets/119277948/21710b9f-f7cd-4fee-ba04-134a9d7eacd3" width="600" height="300"/>


### Second, run the code below to check if the data is being received correctly.
[speed_sensor.ino](https://github.com/K0Dahyun/Project-2/blob/main/Speed%20and%20Ultrasonic/speed_sensor/speed_sensor.ino)

[speed_sensor_LCD.ino](https://github.com/K0Dahyun/Project-2/tree/main/Speed%20and%20Ultrasonic/speed_sensor_LCD)

These are the necessary libraries and reference links.
[l2C](https://drive.google.com/file/d/15-vg0hSKDJ9EafxvWnjkg-o3WERHccBx/view?usp=sharing)
[Reference](https://srituhobby.com/ir-infrared-speed-sensor-with-arduino-how-does-work-ir-speed-sensor/?utm_content=cmp-true)

At this point, the interrupt pin number is specified as 2. If you have connected to a different pin, you need to modify _attachInterrupt(digitalPinToInterrupt(2), Pulse_Event, RISING);_**


## 2. Ultrasonic Sensor(Model : HC-SR04)
The HC-SR04 Ultrasonic Sensor operates by using ultrasonic waves to measure distance. 
In the reception phase, the sensor measures the time it takes for the ultrasonic waves to bounce back after hitting an object. 
Using the speed of sound and the measured time, the sensor calculates the distance to the object. 
### First, connect as shown in the picture below.
<img src="https://github.com/K0Dahyun/Project-2/assets/119277948/c2f3eb9b-9ecf-47c3-a7be-74f8253c4b4b" width="400" height="300"/>


### Second, You can run the code below to check if the sensor is working correctly.
[Ultrasonic_sensor](https://github.com/K0Dahyun/Project-2/blob/main/Speed%20and%20Ultrasonic/Ultrasonic_sensor/Ultrasonic_sensor/Ultrasonic_sensor.ino)
[Reference](https://www.brainy-bits.com/post/using-the-hc-sr04-ultrasonic-range-sensor-with-an-arduino)

At this point, ECHOPIN and TRIGPIN are the pin numbers that you connected to the Arduino. However, it is recommended to use pin numbers from 3 to 8. Depending on the module, the pin number may already be determined, and the pin numbers should not overlap.


## 3. CAN Communicate including sensor data between Arduino and Arduino
Our goal is to communicate via CAN protocol between Raspberry Pi and Arduino. However, we first attempt CAN communication between two Arduinos.
Before starting this chapter, I recommend you study what CAN communication is.

### First, we test CAN communication between Arduino Uno and Nano.

| Arduino Uno       | CAN-Bus Shield V2       |
| :-------------:|:-------------: |
| <img src="https://github.com/K0Dahyun/Project-2/assets/119277948/44f1cfcf-119d-409c-ae7f-25e8c696cb19" width="200" /> | <img src="https://github.com/K0Dahyun/Project-2/assets/119277948/2fdb748a-a24b-45be-95ac-43f2b8c1cc63" width="200" /> |

| Arduino Nano       | CAN MCP2515       |
| :-------------:|:-------------: |
| <img src="https://github.com/K0Dahyun/Project-2/assets/119277948/6788c7c0-271d-4c74-a048-2d0491f66015" width="200" /> | <img src="https://github.com/K0Dahyun/Project-2/assets/119277948/7b87e1d3-e0cc-4ce3-9334-a5b466a3f42a" width="200" /> |


If you are using mcp2515, you need to download [here](https://github.com/autowp/arduino-mcp2515)  library.

Using a CAN shield eliminates the need for complex wiring, but when connecting a CAN module to an Arduino Nano, wiring is required. Connect as shown in the picture below.

<img src="https://github.com/K0Dahyun/Project-2/assets/119277948/bddd10a2-3c45-43f7-bbcd-61695f267226" width="400" height="300"/>

The wiring is the same as before, you just need to newly connect the High and Low of the CAN.
| CAN-Bus Shield V2 | CAN MCP2515 |
| ------------ | ------------- |
| CAN_H | CAN_H  |
| CAN_L | CAN_L  |


You can verify the CAN communication through the following code. The Arduino Uno calculates the RPM and distance values and transmits them, while the Arduino Nano receives these data.
Plus, _mcp2515.setBitrate(CAN_125KBPS,MCP_16MHZ);_
Here, you need to modify _MCP_(yourClockSpeed)MHZ_ to match your Arduino's clock speed.

[CAN_Speed_Ultrasonic](https://github.com/K0Dahyun/Project-2/blob/main/Speed%20and%20Ultrasonic/CAN_speed_Ultrasonic/CAN_speed_distance/CAN_speed_distance.ino)

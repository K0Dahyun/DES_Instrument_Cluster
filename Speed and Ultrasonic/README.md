# Connect the Speed and Ultrasonic Sensor
Connect the speed sensor and ultrasonic sensor wires to the Arduino Uno and verify that it receives data correctly.
At this point, steps 1 and 2 are not for CAN communication, but solely for checking if the sensor data is properly received by the Arduino Uno. Then, in step 3, we attempt CAN communication between Arduino Uno and Arduino Nano.


## 1. Speed Sensor(Model : LM393)
Whether you’re building a small robot or using any kind of motors in your projects, it might be useful to know the speed at which your are driving them.
In this section, we will see how to connect and use an infrared speed sensor based on the LM393 chip.
The speed sensor uses a disc with holes (encoder disc) to block the infrared beam, thus by counting the number of times the sensors goes from Low to High we can calculate the number of revolution for a given time period.

In this section, we will connect the speed sensor and the LCD together. However, the final goal is to connect the LCD to the Raspberry Pi, not the Arduino. The LCD connection discussed here is merely a test.


### First, we need to wire it as shown in the picture below.
<img src="https://github.com/K0Dahyun/Project-2/assets/119277948/21710b9f-f7cd-4fee-ba04-134a9d7eacd3" width="600" height="300"/>


### Second, run the code below to check if the data is being received correctly.
[speed_sensor.ino](https://github.com/K0Dahyun/Project-2/blob/main/Speed%20and%20Ultrasonic/speed_sensor/speed_sensor.ino)

These are the necessary libraries and reference links.
[l2C](https://drive.google.com/file/d/15-vg0hSKDJ9EafxvWnjkg-o3WERHccBx/view?usp=sharing)
[Reference](https://srituhobby.com/ir-infrared-speed-sensor-with-arduino-how-does-work-ir-speed-sensor/?utm_content=cmp-true)

**At this point, the interrupt pin number is specified as 2. If you have connected to a different pin, you need to modify _attachInterrupt(digitalPinToInterrupt(2), Pulse_Event, RISING);_**


## 2. Ultrasonic Sensor(Model : HC-SR04)
The HC-SR04 Ultrasonic Sensor operates by using ultrasonic waves to measure distance. 
In the reception phase, the sensor measures the time it takes for the ultrasonic waves to bounce back after hitting an object. 
Using the speed of sound and the measured time, the sensor calculates the distance to the object. 
Similarly, connect as shown in the picture below.


<img src="https://github.com/K0Dahyun/Project-2/assets/119277948/c2f3eb9b-9ecf-47c3-a7be-74f8253c4b4b" width="400" height="300"/>
And, You can check 
[Reference](https://www.brainy-bits.com/post/using-the-hc-sr04-ultrasonic-range-sensor-with-an-arduino)


# Project2-DES_Instrument_Cluster
PiRacer instrument cluster Qt application running on RPi and receiving speed data from a speed sensor via CAN


## Development Period
23.07.25~23.09.09


## Introduction
The main objective of the PiRacer dashboard Qt application project is to create a functioning dashboard of a race car that displays real-time speed data from the speed sensor via the CAN bus.

In this project, I will be using Raspberry Pi as the platform for the dashboard application, and the Qt framework for user interface and data processing. The speed data is received from the speed sensor through the CAN bus and is displayed in real-time on the dashboard application.


## Specific Goals
1. Design and implement a Qt-based Graphical User Interface (GUI) for the dashboard.
2. Integrate the speed sensor with the Raspberry Pi using the CAN bus protocol.
3. Display real-time speed data on the dashboard GUI.
4. Test the functionality of the dashboard using realistic racing scenarios.
5. Document the project comprehensively, including detailed descriptions of the system architecture, software design, implementation, results, and conclusions.


## System Architecture
The system architecture of the PiRacer dashboard application is a combination of hardware and software components working together to provide a user-friendly interface for monitoring vehicle speed.

- The hardware components : the Raspberry Pi (RPi) board, the speed sensor, and the Controller Area Network (CAN) bus.

- The software component : Qt-based application running on the RPi that communicates with the speed sensor via the CAN bus to receive speed data.

### Technical Requirements
The RPi serves as the main processing unit for the dashboard application, with its display tasked with presenting speed data. 
The speed sensor measures the vehicle's speed and sends this data to the RPi via the CAN bus. 
The Qt application on the RPi takes this data and displays it in an easily readable format on the screen.
The CAN bus is a communication protocol that allows multiple devices to communicate with each other and exchange data. In the case of the PiRacer dashboard, the speed sensor and the RPi use the CAN bus to exchange speed data. The CAN bus makes the data transmission between the speed sensor and the RPi reliable and efficient.

Overall, the system architecture of the PiRacer dashboard application is designed to provide a simple and user-friendly interface for monitoring vehicle speed. The combination of hardware and software components work together to provide users with accurate and real-time speed data.


##Software Design
The software design of the PiRacer dashboard application is based on the Qt framework, a widely used cross-platform application development framework.

In this project, Qt will be used in the following ways:

- GUI Development: It designs and implements the user interface of the dashboard application. For instance, it displays gauges like the speedometer, odometer, etc., in a digital format on the screen.
- Data Processing: It processes data received from the speed sensor via the CAN bus. After converting the data into an appropriate format, it displays it on the screen.
- Communication with Hardware: Since Qt supports various communication protocols, it handles communication with the Raspberry Pi, the CAN bus, and the speed sensor.
The software design of the PiRacer dashboard consists of several key components, such as the main application, CAN communication module, and speed data display module.

The main application manages the overall functionality of the dashboard. It creates the GUI, manages communication with the speed sensor via the CAN bus, and displays speed data on the screen.

The CAN communication module communicates with the speed sensor via the CAN bus. It retrieves speed data from the speed sensor and passes it to the main application for display. This module uses the CAN library provided by Qt to communicate with the speed sensor.

The speed data display module is responsible for displaying speed data on the screen. It takes speed data from the main application and displays it in an easily readable format on the screen. This module can be customized to display speed data in various ways, such as through a speedometer or numerical display.


# Specific System Architecture

<img src="https://github.com/K0Dahyun/Project-2/assets/119277948/362cce4e-5380-4ab8-a6a0-3b87dde8499f" width="600" height="600"/>

## Part_1 : Attach the speed sensor's rotating plate to the tire's rotating axis.
1. The speed sensor's rotation plate should rotate at the same rate as the tire. Therefore, the rotation plate and the tire must be perfectly attached.
 - Solution1 - Enlarge the hole in the rotation plate to connect it to the tire's rotating shaft. 
 - Solution2 - Connect a rod to the bolt on the outside of the tire, and then connect that rod to the rotation plate.
2. fix the Speed sensor


## Part-2 : Connect speed sensor and Arduino
1. Verify that the Arduino is properly receiving data from the speed sensor.
2. Verify that the Arduino is properly receiving data from the Ultrasonic sensor.
2. Create a calculation code on Arduino that computes the RPM and distance from the data received from the sensor.
3. Check that the Arduino's output is correctly showing a value corresponding to the speed.
[Speed&Ultrasonic](https://github.com/K0Dahyun/Project-2/tree/main/Speed%20and%20Ultrasonic)
   

## Part-3 : Arduino and Raspberry Pi communicate using the CAN protocol.
1. Connect Arduino(including speed and distance data) and CAN Shield.
2. Connect the Raspberry Pi with a CAN Hat, and connect the Arduino with a CAN Shield.
3. The Arduino and Raspberry Pi communicate via the CAN protocol.
4. Verify that the speed data received from the Raspberry Pi is correct.
   
If you want to study CAN communication first, you can try CAN communication between two Arduinos. This, while different from the project topic, allows for a simple test and understanding of the CAN communication method.
### [Reference](https://github.com/autowp/arduino-mcp2515/blob/master/README.md)


## Part-4 : Create a Qt dashboard GUI using cross-compilation.
1. Visualize the vehicle dashboard GUI using the Qt framework on a standard laptop, not the Raspberry Pi.
2. Create code to display the dashboard correctly according to the data type received by the Raspberry Pi.
3. Create an executable file that can be run on the Raspberry Pi by cross-compiling.
4. Copy the code to the Raspberry Pi, execute it, and check if it runs correctly.
### [Crosscompile in Qt](https://www.interelectronix.com/kr/keuloseu-keompaileul-wihae-ubuntu-20-ltseseo-qt-creator-guseong.html)
### [Dashboard Example in Qt](https://doc.qt.io/qt-5/qtquickextras-dashboard-example.html)


## Part-5 : Implement speed data visualization on the LCD.
1. Connect the LCD to the Raspberry Pi.
2. Display the Raspberry Pi's GUI on the LCD.




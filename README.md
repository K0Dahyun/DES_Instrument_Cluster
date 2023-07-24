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

## Part-1
The speed sensor's rotation plate should rotate at the same rate as the tire. Therefore, the rotation plate and the tire must be perfectly attached.
  Solution1 - Enlarge the hole in the rotation plate to connect it to the tire's rotating shaft. 
  Solution2 - Connect a rod to the bolt on the outside of the tire, and then connect that rod to the rotation plate.

## Par

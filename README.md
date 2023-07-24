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

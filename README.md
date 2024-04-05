
# Magnetometer based Vehicle Detection for Parking Systems


The primary aim of this project is to address the ongoing problems of finding a parking spot, which has become a tedious and time-consuming task. The objective is to develop a system that can detect vacant parking slots and provide that information to users, thereby preventing traffic congestion, driver stress, and unwanted fuel wastage. The proposed solution involves using QMC5883L GY-273 MAGNETOMETERS as sensors to detect the presence of a vehicle in a parking slot, wherein the information is wirelessly transmitted, using Ra-02 SX1278 LoRa TRANSCEIVER modules, to a master node that communicates with the user.

## System Design
<img src="https://github.com/AdarshKaran/Hackabot24-Team5/blob/main/hacakbot%20media/Arena.jpg?raw=true" alt="System Design" width="600">

The system includes slave nodes consisting of a magnetometer and LoRa transceiver connected to a microcontroller unit to detect the vacancy in a parking slot. This vacancy information is communicated to the master node for further processing using a LoRa module connected to the microcontroller unit. The QMC5883L magnetometer is connected to the ESP8266 NodeMCU using the Inter-Integrated Circuit (I2C) Protocol, and the Ra-02 LoRa module is connected to the NodeMCU using Serial Peripheral Interface (SPI) protocol. The software side of this system consists of a vehicle dashboard or mobile application which provides real time information about vacant parking slots to users.

The proposed scheme makes use of Arduino IDE to program the microcontroller and the LoRa module to communicate wirelessly. The mobile application for user interface is built using Flutter SDK and FireBase in Android Studio. The proposed scheme has been tested with a single parking slot and can detect the presence of a vehicle over  the sensor at a range up to 400 mm and displays the vacancy of the slot to the driver along  with the path towards the parking slot.

In conclusion, the proposed scheme aims to create a parking system that replaces traditional parking systems that use ultrasonic sensors, and cameras, that require man-force and surveillance to monitor the parking systems. The use of magnetometers and LoRa modules provide a simple, efficient and cost-effective solution to the traditional parking systems, with reduced maintenance and susceptibility to damage.

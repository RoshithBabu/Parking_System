
# Magnetometer-based Vehicle Detection for Parking Systems


The primary aim of this project is to address the ongoing problem of finding a parking spot, which has become a tedious and time-consuming task. The objective is to develop a system that can detect vacant parking slots and provide that information to users, thereby preventing traffic congestion, driver stress, and unwanted fuel wastage. The proposed solution involves using QMC5883L GY-273 MAGNETOMETERS as sensors to detect the presence of a vehicle in a parking slot, wherein the information is wirelessly transmitted, using Ra-02 SX1278 LoRa TRANSCEIVER modules, to a master node that communicates with the user.

## System Design
<p align="center">
  <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/System%20Design.png?raw=true" alt="System Design" width="600">
  <br>
  <em>System Design Diagram</em>
</p>
The system includes slave nodes consisting of a magnetometer and LoRa transceiver connected to a microcontroller unit to detect the vacancy in a parking slot. This vacancy information is communicated to the master node for further processing using a LoRa module connected to the microcontroller unit. The QMC5883L magnetometer is connected to the ESP8266 NodeMCU using the Inter-Integrated Circuit (I2C) Protocol, and the Ra-02 LoRa module is connected to the NodeMCU using Serial Peripheral Interface (SPI) protocol. The software side of this system consists of a vehicle dashboard or mobile application that provides real-time information about vacant parking slots to users.

## Flowchart
<p align="center">
  <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/Flowchart.png?raw=true" alt="Flowchart" height="600">
  <br>
  <em>Flowchart of the System</em>
</p>

## Prototype
The proposed scheme makes use of Arduino IDE to program the microcontroller and the LoRa module to communicate wirelessly. The mobile application for the user interface is built using Flutter SDK and FireBase in Android Studio. The proposed scheme has been tested with a single parking slot and can detect the presence of a vehicle over  the sensor at a range up to 400 mm and display the vacancy of the slot to the driver along  with the path towards the parking slot.
<p align="center">
  <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/Slave%20node%20prototype.png?raw=true" alt="Slave Node" width="400">
  <br>
  <em>Slave Node</em>
</p>
<p align="center">
  <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/Master%20node%20prototype.png?raw=true" alt="Master Node" width="400">
  <br>
  <em>Master Node</em>
</p>
<p align="center">
  <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/Testing.png?raw=true" alt="Prototype Testing" width="400">
  <br>
  <em>Prototype Testing</em>
</p>

## Mobile Interface
<p>
    <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/Mobile%20Interface-1.png?raw=true" alt="UI1" height="400">
    <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/Mobile%20Interface-2.png?raw=true" alt="UI2" height="400">
    <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/Mobile%20Interface-3.png?raw=true" alt="UI3" height="400">
</p>




## Pathfinding Algorithm
The parking layout schematic has been visualized as a Graph Data Structure with the parking spots as the nodes. The shortest distance between the parking spot and the entrance is computed using Dijkstra’s Algorithm. Breadth-First Technique is used which is an unweighted algorithm of Dijkstra's Algorithm.

<p align="center">
  <img src="https://github.com/RoshithBabu/Parking_System/blob/main/Media/Pathfinding.png?raw=true" alt="Pathfinding Prototype" width="600">
  <br>
  <em>Pathfinding Prototype</em>
</p>

## Conclusion
In conclusion, the proposed scheme aims to create a parking system that replaces traditional parking systems that use ultrasonic sensors, and cameras, that require man-force and surveillance to monitor the parking systems. The use of magnetometers and LoRa modules provides a simple, efficient, and cost-effective solution to traditional parking systems, with reduced maintenance and susceptibility to damage.

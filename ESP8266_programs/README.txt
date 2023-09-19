The programs are uploaded into the repective ESP8266 in the transmitter and the receiver nodes.
Libraries are not included. they should be downloaded from the internet.
The transmitter node include QMC5883L magnetometer and Ra-02 LoRa  transceiver connected to ESP8266 NodeMCU. These nodes are placed below every parking slots and the vacancy of the slot is send to the master node or the receiver node.
The receiver node consists of a LoRa transceiver and uploads the details of the vacancy from every slave(transmitter) node to the server. 
Firebase Real -Time Database is used to store the information from the mobile Application and the Parking Lot(Vacancy of the slot)

#include <SPI.h>
#include <LoRa.h>


void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Reciver Callback");

  LoRa.setPins(15,16,2);

  if(!LoRa.begin(473E6))
  { 
    Serial.println("Starting LoRa failed"); 
    while(1);
  }

  LoRa.onReceive(onReceive);

  LoRa.receive();
}

void loop() {

}

void onReceive(int packetSize) {
  byte data[255];
  

  Serial.print("Received packet");
  for(int i=0;i<packetSize;i++){
    data[i]=LoRa.read()
      //Serial.print((char)LoRa.read());
  }
  data[packetSize]='\0';
  String stringData((char*)data);
  Serial.println(stringData);
  //Serial.println(LoRa.packetRssi());
}

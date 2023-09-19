#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);

  while(!Serial);
  Serial.println("LoRa Sender");
  LoRa.setPins(15,16,2);
    if(!LoRa.begin(473E6))
    {
      Serial.println("Starting LoRa failed");
      delay(100);
      while(1);
    }  
    
    delay(2); 

}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println("BABU");
  
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.endPacket();

  delay(1000);  
  }

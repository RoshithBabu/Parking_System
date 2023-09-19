#include <SPI.h>
#include <LoRa.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
// Insert your network credentials
#define WIFI_SSID "Insert ssid"
#define WIFI_PASSWORD "insert password"
// Insert Firebase project API Key
#define API_KEY " "
// Insert RTDB URL define the RTDB URL */
#define DATABASE_URL " "
//Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;
void setup() {
Serial.begin(9600);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("Connecting to Wi-Fi");
while (!Serial);
Serial.println("LoRa Receiver");
if (!LoRa.begin(433E6)) {
Serial.println("Starting LoRa failed!");
while (1);
}
while (WiFi.status() != WL_CONNECTED){
Serial.print(".");
delay(300);
}
/* Assign the api key (required) */
config.api_key = API_KEY;
/* Assign the RTDB URL (required) */
config.database_url = DATABASE_URL;
/* Sign up */
if (Firebase.signUp(&config, &auth, "", "")){
Serial.println("ok");
signupOK = true;
}
else{
Serial.printf("%s\n", config.signer.signupError.message.c_str());
}
/* Assign the callback function for the long running token generation task */
config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
Firebase.begin(&config, &auth);
Firebase.reconnectWiFi(true);

}
void loop() {
// try to parse packet
int packetSize = LoRa.parsePacket();
if (packetSize) {
// received a packet
Serial.print("Received packet '");
// read packet
while (LoRa.available()) {
Serial.print((char)LoRa.read());
}
if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis ==
0)){
sendDataPrevMillis = millis();
// Write an Int number on the database path test/int
if (Firebase.RTDB.setString(&fbdo, "Parking Slots/1/Vacancy", "Occupied")){
Serial.println("PASSED");
Serial.println("PATH: " + fbdo.dataPath());
Serial.println("TYPE: " + fbdo.dataType());
}
else {
Serial.println("FAILED");
Serial.println("REASON: " + fbdo.errorReason());
}
}
}
}
#include <SPI.h>
#include <LoRa.h>
/*
MODE CONTROL (MODE)
Standby 0x00
Continuous 0x01
OUTPUT DATA RATE (ODR)
10Hz 0x00
50Hz 0x04
100Hz 0x08
200Hz 0x0C
FULL SCALE (RNG)
2G 0x00
8G 0x10
OVER SAMPLE RATIO (OSR)
512 0x00
256 0x40
128 0x80
64 0xC0
*/

//Magnetometer
#include <Wire.h>
int x_raw, y_raw, z_raw;
int x_calib, y_calib, z_calib;
int x_mg, y_mg, z_mg, mag, ang;
int x_offset, y_offset, z_offset;
float x_scale, y_scale, z_scale;
int count=0;
int defaultMag=450;
uint8_t _ADDR = 0x0D;
int declinationAngle = -0.025;
int calibValues[3][2];
//Magnetometer section over
int counter = 0;
String vacancy="Vacant";
int magnitude=0;
void setup() {
Serial.begin(9600);
Wire.begin(5, 2);
writeToReg(0x0B, 0x01);
setMode(0x01, 0x00, 0x00, 0X00);
//setCalib(-3365, 2455, -4330, 760, -11902, 0);
delay(100);
//===============================================================
while (!Serial);
Serial.println("LoRa Sender");
if (!LoRa.begin(433E6)) {
Serial.println("Starting LoRa failed!");
while (1);
} }

void loop() {
// Read compass values
readFromReg();
x_mg = x_raw * 0.08333;
y_mg = y_raw * 0.08333;
z_mg = z_raw * 0.08333;
mag = sqrt(pow(x_mg, 2) + pow(y_mg, 2) + pow(z_mg, 2));
vacancy=(mag-defaultMag>200)?"Occupied":"Vacant";
delay(2000);//wait 5 sec
Serial.print("Sending packet: ");
Serial.println(counter);
Serial.println(mag);
// send packet
LoRa.beginPacket();
LoRa.print("Packet count: ");
LoRa.print(counter);
LoRa.print(" Parking spot 1 is: ");
LoRa.print(vacancy);
LoRa.print(" Magnitude is: ");
LoRa.print(mag);
LoRa.endPacket();
counter++;
//delay(5000);
}
// Write register values to chip
void writeToReg(uint8_t r, uint8_t v) {
Wire.beginTransmission(_ADDR);
Wire.write(r);
Wire.write(v);
APPENDIX
34
Wire.endTransmission();
}
//===============================================================
void setMode(uint8_t mode, uint8_t odr, uint8_t rng, uint8_t osr) {
writeToReg(0x09, mode | odr | rng | osr);
}
void readFromReg() {
Wire.beginTransmission(_ADDR);
Wire.write(0x00);
int err = Wire.endTransmission();
if (!err) {
Wire.requestFrom(_ADDR, (uint8_t)6);
x_raw = (int)(int16_t)(Wire.read() | Wire.read() << 8);
y_raw = (int)(int16_t)(Wire.read() | Wire.read() << 8);
z_raw = (int)(int16_t)(Wire.read() | Wire.read() << 8);
}
}
void setCalib(int x_min, int x_max, int y_min, int y_max, int z_min, int z_max) {
calibValues[0][0] = x_min;
calibValues[0][1] = x_max;
calibValues[1][0] = y_min;
calibValues[1][1] = y_max;
calibValues[2][0] = z_min;
calibValues[2][1] = z_max;
x_offset = (calibValues[0][0] + calibValues[0][1]) / 2;
y_offset = (calibValues[1][0] + calibValues[1][1]) / 2;
z_offset = (calibValues[2][0] + calibValues[2][1]) / 2;
}
void calibrateMagnetometer()
{
x_calib = (x_raw - x_offset);
y_calib = (y_raw - y_offset);
z_calib = (z_raw - z_offset);
}
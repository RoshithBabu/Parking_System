#include <Wire.h>

int calibrationData[3][2];
bool changed = false;
bool done = false;
int t = 0;
int c = 0;
int x_raw, y_raw, z_raw;
uint8_t _ADDR = 0x0D;

void setup() {
   Serial.begin(9600);
  Wire.begin(4, 5);
  writeToReg(0x0B, 0x01);
  setMode(0x01, 0x04, 0x00, 0X00);
  
  Serial.println("This will provide calibration settings for your QMC5883L chip. When prompted, move the magnetometer in all directions until the calibration is complete.");
  Serial.println("Calibration will begin in 5 seconds.");
  delay(5000);
  
}

void loop() {
    readFromReg();

  changed = false;

  if(x_raw < calibrationData[0][0]) {
    calibrationData[0][0] = x_raw;
    changed = true;
  }
  if(x_raw > calibrationData[0][1]) {
    calibrationData[0][1] = x_raw;
    changed = true;
  }

  if(y_raw < calibrationData[1][0]) {
    calibrationData[1][0] = y_raw;
    changed = true;
  }
  if(y_raw > calibrationData[1][1]) {
    calibrationData[1][1] = y_raw;
    changed = true;
  }

  if(z_raw < calibrationData[2][0]) {
    calibrationData[2][0] = z_raw;
    changed = true;
  }
  if(z_raw > calibrationData[2][1]) {
    calibrationData[2][1] = z_raw;
    changed = true;
  }

  if (changed && !done) {
    Serial.println("CALIBRATING... Keep moving your sensor around.");
    c = millis();
  }
    t = millis();
  
  
  if ( (t - c > 10000) && !done) {
    done = true;
    Serial.println("DONE. Copy the line below and paste it into your projects sketch.);");
    Serial.println();
      
    Serial.print("compass.setCalibration(");
    Serial.print(calibrationData[0][0]);
    Serial.print(", ");
    Serial.print(calibrationData[0][1]);
    Serial.print(", ");
    Serial.print(calibrationData[1][0]);
    Serial.print(", ");
    Serial.print(calibrationData[1][1]);
    Serial.print(", ");
    Serial.print(calibrationData[2][0]);
    Serial.print(", ");
    Serial.print(calibrationData[2][1]);
    Serial.println(");");
    }
  
 
}


//===============================================================================================================
// Write register values to chip
void writeToReg(uint8_t r, uint8_t v) {
  Wire.beginTransmission(_ADDR);
  Wire.write(r);
  Wire.write(v);
  Wire.endTransmission();
}
//===============================================================================================================
void setMode(uint8_t mode, uint8_t odr, uint8_t rng, uint8_t osr) {
  writeToReg(0x09, mode | odr | rng | osr);
}
//===============================================================================================================
void readFromReg() {
  Wire.beginTransmission(_ADDR);
  Wire.write(0x00);
  int err = Wire.endTransmission();
  if (!err) {
    Wire.requestFrom(_ADDR, (uint8_t)6);
    x_raw = (int)(int16_t)(Wire.read() | Wire.read() << 8);
    y_raw = (int)(int16_t)(Wire.read() | Wire.read() << 8);
    z_raw = (int)(int16_t)(Wire.read() | Wire.read() << 8);



    // if ( _calibrationUse ) {
    // 	_applyCalibration();
    // }

    // if ( _smoothUse ) {
    // 	_smoothing();
    // }

    //byte overflow = Wire.read() & 0x02;
    //return overflow << 2;
  }
}
//===============================================================================================================



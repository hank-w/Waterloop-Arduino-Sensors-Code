//https://learn.sparkfun.com/tutorials/mag3110-magnetometer-hookup-guide-/all

//#include <SparkFun_MAG3110.h>
#include "SparkFun_MAG3110.h"
#include <Wire.h>

MAG3110 mag = MAG3110(); //Instantiate MAG3110

void setup() {
  Serial.begin(9600);

  Wire.begin();             //setup I2C bus
  Wire.setClock(400000);    // I2C fast mode, 400kHz

  mag.initialize(); //Initializes the mag sensor
  mag.start();      //Puts the sensor in active mode
}

void loop() {

  int x, y, z;
  //Only read data when it's ready
  if(mag.dataReady()) {
    //Read the data
    mag.readMag(&x, &y, &z);

    
    Serial.print("X: ");
    Serial.print(x);
    Serial.print(", Y: ");
    Serial.print(y);
    Serial.print(", Z: ");
    Serial.print(z);
    
    Serial.println(sqrt(x*x + y*y));
    Serial.println("--------");
    delay(100);
  }
}

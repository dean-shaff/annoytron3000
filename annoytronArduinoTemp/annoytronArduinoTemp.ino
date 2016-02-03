#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

int piezo = 5 ;
float min_temp = 100.0 ; 

void setup() {
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
//  Serial.println("MCP9808 demo");
  int x = 5 ;
  int y = 4 ;
  // Make sure the sensor is found, you can also pass in a different i2c
  // address with tempsensor.begin(0x19) for example
  if (!tempsensor.begin()) {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  }
  if (!accel.begin()) {
    Serial.println("Couldn't find ADXL345!");
    while(1);
  }
  accel.setRange(ADXL345_RANGE_16_G);
  calibrate(5000);
  Serial.println(min_temp);
//  Serial.println("Calibration done");
//  Serial.println("500");
}

void loop() {
  // Read and print out the temperature, then convert to *F
  sensors_event_t event; 
  accel.getEvent(&event);
 
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  delay(500);
  float c = tempsensor.readTempC();
  float f = c * 9.0 / 5.0 + 32;
  Serial.println(c) ;
  delay(250);
  if (c < min_temp + 5.0){
    tone(piezo, 7000); 
  }else if (c > min_temp + 5.0){
    noTone(piezo) ;
  }
//  if (Serial.available() > 0){
//    int inByte = Serial.read() ; 
//    Serial.println(c); 
//  }
  tempsensor.shutdown_wake(1); // shutdown MSP9808 - power consumption ~0.1 mikro Ampere
  delay(200);
//  Serial.println("wake up MCP9808.... "); // wake up MSP9808 - power consumption ~200 mikro Ampere
  tempsensor.shutdown_wake(0);
}

void calibrate(int calibTime){
  long curTime = millis();
  while (millis() - curTime < calibTime){
    float c = tempsensor.readTempC();
    delay(200); 
    tempsensor.shutdown_wake(1); 
    delay(200);
    tempsensor.shutdown_wake(0);
    if (c < min_temp && c != 0.0){
      min_temp = c ; 
    }
  }
}




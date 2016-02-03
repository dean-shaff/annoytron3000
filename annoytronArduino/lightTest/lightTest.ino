int light1 = A0 ;
int light2 = A1 ; 
int lightVal1 ;
int lightVal2 ; 

int LED1 = 5 ; 
int LEDVal ;

int minVal = 1024;
int maxVal = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  calibrate(4000);
  Serial.println(minVal, maxVal);
}

void loop() {
  lightVal1 = analogRead(light1);
  lightVal2 = analogRead(light2);
  int meanVal = (lightVal1 + lightVal2) / 2.0 ; 
  LEDVal = map(meanVal, 0, 1024, 0, 255);
  Serial.print(meanVal);
  Serial.print(", ");
  Serial.println(LEDVal);
  delay(100);
  analogWrite(LED1, LEDVal);
}

void calibrate(int calibTime) {
  long curTime = millis() ;
  while (millis() - curTime < calibTime) {
    lightVal1 = analogRead(light1);
    lightVal2 = analogRead(light2);
    int meanVal = (lightVal1 + lightVal2) / 2.0 ; 
    if (meanVal < minVal){
      minVal = meanVal ;
    }else if (meanVal > maxVal){
      maxVal = maxVal ;
    }
  }
}
  


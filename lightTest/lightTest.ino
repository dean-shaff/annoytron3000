int light1 = A0;
int light2 = A1;
int led = 13;
int val1;
int val2;

void setup() {

pinMode(led, OUTPUT);
Serial.begin(9600);

}

void loop() {

val1 = analogRead(light1);
val2 = analogRead(light2);
float val3 = (float)val1/(float)val2;
Serial.println(val3);
if (val3 > .8 && val3 < 1.2){
  digitalWrite(led, HIGH);
}
else {
  digitalWrite(led, LOW);
}

}

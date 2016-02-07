int killPin = 2; 
int LED = 13;
void setup() {
  pinMode(killPin, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(killPin, HIGH);
  digitalWrite(LED, HIGH);
//  delay(1000);
//  digitalWrite(killPin, LOW);
//  digitalWrite(LED, LOW);
//  delay(1000);
}

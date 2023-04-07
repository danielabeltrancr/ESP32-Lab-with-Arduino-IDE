/*
 # Product: HC-SR04
*/

const int Trigger = 4;
const int Echo = 14;

long distance, Time;

void setup() {
  Serial.begin(115200);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
}

void loop() {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  Time = pulseIn(Echo, HIGH);
  distance = long(0.017 * Time);
  Serial.print("Distancia: ");
  Serial.print (distance);
  Serial.println("cm");
  delay(500);
}
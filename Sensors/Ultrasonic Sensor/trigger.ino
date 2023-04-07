const int Trigger = 4;         //D2

void setup() {
  Serial.begin(115200);
  pinMode(Trigger, OUTPUT);
  digitalWrite(Trigger, LOW);
}

void loop() {
  //digitalWrite(Trigger, LOW);
  //delayMicroseconds(50);
  static unsigned long timepoint = millis();
  if (millis() - timepoint > 1000) {
    timepoint = millis();
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger, LOW);
  }
}

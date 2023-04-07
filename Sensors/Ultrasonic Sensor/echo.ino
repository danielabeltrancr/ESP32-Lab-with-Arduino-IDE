const int Echo = 5;             //D1

void setup() {
  Serial.begin(115200);
  pinMode(Echo, INPUT);
}

void loop() {
  long distance, Time;
  static unsigned long timepoint = millis();
  if (millis() - timepoint > 1000) {
    timepoint = millis();
    Time = pulseIn(Echo, HIGH); 
    distance = Time/59;
    Serial.print("Distancia: ");
    Serial.print (distance);
    Serial.println("cm");
    delay(100);
  }
}

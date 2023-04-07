/*
 # Product: RGB SMD-LED ky-009
 # More information about the product: https://sensorkit.joy-it.net/de/sensors/ky-009
*/

int Led_Red = 4;
int Led_Green = 5;
int Led_Blue = 0;

void RGB();
void yellow();
void cyan();
void magenta();
void white();

void setup() {
  // Initialize output pins for the LEDs
  pinMode (Led_Red, OUTPUT); 
  pinMode (Led_Green, OUTPUT);
  pinMode (Led_Blue, OUTPUT); 
}

void loop() {
  RGB();
  delay(1000);
  yellow();
  delay(1000);
  cyan();
  delay(1000);
  magenta();
  delay(1000);
  white();
  delay(1000);
}

void RGB(){
  //red
  digitalWrite (Led_Red, HIGH); 
  digitalWrite (Led_Green, LOW); 
  digitalWrite (Led_Blue, LOW); 
  delay (3000); // Wait mode for 3 seconds
  //green
  digitalWrite (Led_Red, LOW); 
  digitalWrite (Led_Green, HIGH); 
  digitalWrite (Led_Blue, LOW); 
  delay (3000); 
  //blue
  digitalWrite (Led_Red, LOW);
  digitalWrite (Led_Green, LOW); 
  digitalWrite (Led_Blue, HIGH); 
  delay (3000); 
}

void yellow(){
  digitalWrite (Led_Red, HIGH); 
  digitalWrite (Led_Green, HIGH); 
  digitalWrite (Led_Blue, LOW); 
  delay (3000); 
}

void cyan(){
  digitalWrite (Led_Red, LOW); 
  digitalWrite (Led_Green, HIGH);
  digitalWrite (Led_Blue, HIGH); 
  delay (3000); 
}

void magenta(){
  digitalWrite (Led_Red, HIGH); 
  digitalWrite (Led_Green, LOW); 
  digitalWrite (Led_Blue, HIGH); 
  delay (3000); 
}

void white(){
  digitalWrite (Led_Red, HIGH);    // LED is switched on
  digitalWrite (Led_Green, HIGH);  // LED is switched on
  digitalWrite (Led_Blue, HIGH);   // LED is switched on
  delay (3000);
}

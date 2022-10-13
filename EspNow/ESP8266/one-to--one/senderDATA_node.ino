#include <ESP8266WiFi.h>
#include <SimpleEspNowConnection.h>

// Replace with receiver MAC Address
uint8_t receiverAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  char a[32];
  int b;
  float c;
  String d;
  bool e;
} struct_message;

// Create a struct_message called myData
struct_message myData;

unsigned long lastTime = 0;  
unsigned long timerDelay = 1000;  // send readings timer

// Callback when data is sent
void OnDataSent(uint8_t *receiver_mac, uint8_t transmissionStatus) {
  Serial.print("Last Packet Send Status: ");
  if (transmissionStatus == 0) {
    Serial.println("Data sent successfully");
  }
  else {
    Serial.println("Delivery fail, error code: ");
    Serial.println(transmissionStatus);
  }
}

void setup() {
  Serial.begin(112500);
  Serial.println();
  Serial.println();
  Serial.println("Initializing controller node...");
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  
  // this function will get called once all data is sent
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(receiverAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  Serial.println("Initialized.");
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    // Set values to send
    strcpy(myData.a, "THIS IS A CHAR");
    myData.b = random(1,20);
    myData.c = 1.2;
    myData.d = "Hello";
    myData.e = false;

    // Send message via ESP-NOW
    esp_now_send(receiverAddress, (uint8_t *) &myData, sizeof(myData));

    lastTime = millis();
  }
}
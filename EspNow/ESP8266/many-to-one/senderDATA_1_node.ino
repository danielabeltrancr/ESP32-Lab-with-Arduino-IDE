#include <ESP8266WiFi.h>
#include <SimpleEspNowConnection.h>

// Replace with receiver MAC Address
uint8_t receiverAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// Set your Board ID (ESP8266 Sender #1 = BOARD_ID 1, ESP8266 Sender #2 = BOARD_ID 2, etc)
#define BOARD_ID 1

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
    int id;
    int x;
    int y;
    int z;
} struct_message;

// Create a struct_message called test to store variables to be sent
struct_message myData;

unsigned long lastTime = 0;
unsigned long timerDelay = 10000; 

// Callback when data is sent
void OnDataSent(uint8_t *receiver_mac, uint8_t sendStatus) {
  Serial.print("\r\nLast Packet Send Status: ");
  if (sendStatus == 0) {
    Serial.println("Delivery success");
  }
  else {
    Serial.println("Delivery fail");
  }
}
 
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println("Initializing controller node 1...");
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  
  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  } 
  
  // Set ESP-NOW role
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);

  // Once ESPNow is successfully init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(receiverAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  Serial.println("Initialized.");
}
 
void loop() {
  if ((millis() - lastTime) > timerDelay) {
    // Set values to send
    myData.id = BOARD_ID;
    myData.x = random(1, 50);
    myData.y = random(1, 50);
    myData.z = random(1, 50);

    // Send message via ESP-NOW
    esp_now_send(receiverAddress, (uint8_t *) &myData, sizeof(myData));
    lastTime = millis();
  }
}
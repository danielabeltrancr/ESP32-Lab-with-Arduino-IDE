#include "Connection.h"
#include "DHTSensor.h"
#include "DS18B20Sensor.h"
#include "EspNow.h"
#include "LightSensor.h"
#include "MuxEcho.h"
#include "pHSensor.h"
#include "Servomotor.h"

Connection objCon;
DHTSensor objDHTSensor("Temperature", "Humidity", pinDHT, DHT_TYPE);
DS18B20Sensor objDS18B20Sensor("Water temperature");
LightSensor objLightSensor("Light", pinLS);
Mux_Echo objMuxEcho("Plant height", pinS0, pinS1, pinS2, pinS3, pinSIG);
pHSensor objpHSensor("pH", pinPH);
ServoMotor objServo(pinServo);
    
void setup() {
  analogReadResolution(10);  // for ESP32
  Serial.begin(115200);
  objCon.init_wifi();
  init_EspNow();
  objServo.initServo();
}

void loop() { 
  objServo.upSensor();
  objServo.downSensor();
  String arrayHeights = objMuxEcho.captureHeights();
  Data.id = BOARD_ID;
  Data.sensorValue_1 = objLightSensor.captureLightValue();
  Data.sensorValue_2 = objDHTSensor.captureTemperatureValue();
  Data.sensorValue_3 = objDHTSensor.captureHumidityValue();
  Data.sensorValue_4 = objDS18B20Sensor.captureWaterTemperature();
  Data.sensorValue_5 = objpHSensor.capturePHValue();
  arrayHeights.toCharArray(Data.heights, 64);
  esp_err_t result = esp_now_send(0, (uint8_t *) &Data, sizeof(Data));
  delay(2000);
}

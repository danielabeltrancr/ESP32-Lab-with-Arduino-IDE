#ifndef DHT_SENSOR_h
#define DHT_SENSOR_h
#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include "Config.h"

class DHTSensor {
  public:  
    DHTSensor(); 
    DHTSensor(String tagTemp, String tagHumd, int pinDHT, int DHT_TYPE);
    String getTempName();  
    String getHumdName();  
    float captureTemperatureValue();
    float captureHumidityValue();
  
  private:  
    String tagTemp;
    String tagHumd;
    int pinDHT;
    float temperature;
    float humidity;
    unsigned long timerDelay = 0; 
    long interval = 5000; // 1000 = 1.008 seconds
    DHT dht;
};

#endif

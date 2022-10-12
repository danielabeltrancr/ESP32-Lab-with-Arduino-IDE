#ifndef DHT_SENSOR_h
#define DHT_SENSOR_h
#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>

class DHTSensor {
  public:  
    DHTSensor(); 
    DHTSensor(String tagTemp, String tagHumd, int pinDHT, int DHT_TYPE);
    String getTempName();  //temperature
    String getHumdName();  //humidity
    float captureTemperatureValue();
    float captureHumidityValue();
  
  private:  
    String tagTemp;
    String tagHumd;
    float temperature;
    float humidity;
    unsigned long timerDelay = 1000; //1000 = 1.028 seconds
    DHT dht;
};

#endif
#ifndef HEADER_CONFIG_H
#define HEADER_CONFIG_H
#include <Arduino.h>

const int pinLS = 36;          // LDR GPIO         
const int pinPH = 39;          // pH sensor GPIO
const int pinDHT = 32;         // DHT22 sensor GPIO
#define DHT_TYPE DHT22         // Type DHT

#define ONE_WIRE_BUS {33}      // DS180B20 GPIO

// Multiplexor GPIOs
const int pinSIG = 13;           
const int pinS3 = 14;            
const int pinS2 = 27;            
const int pinS1 = 26;            
const int pinS0 = 25;   

const int pinServo = 23;        // Servomotor GPIO
 
#endif

#include "pHSensor.h"

pHSensor::pHSensor(){}

pHSensor::pHSensor(String _tagPH, int _pinPH) {
  tagPH = _tagPH;
  pinPH = _pinPH;
}

String pHSensor::getPHName() {
  return tagPH;
}

float pHSensor::capturePHValue() {
  unsigned long samplingTime = millis();
  if (millis() - samplingTime > samplingInterval) {
    pHArray[pHArrayIndex++] = analogRead(pinPH); 
    
    if (pHArrayIndex == ArrayLenth)pHArrayIndex = 0;
    
    voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
    pHValue = 3.5*voltage+Offset;
    samplingTime = millis();
  }
  return pHValue;
}

double pHSensor::avergearray(int* arr, int number){
  int i;
  int max,min;
  double avg;
  long amount = 0;
  if (number <= 0) {
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if (number < 5) {   //less than 5, calculated directly statistics
    for (i = 0; i < number; i++) {
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else {
    if (arr[0] < arr[1]) {
      min = arr[0]; max = arr[1];
    }else {
      min = arr[1]; max = arr[0];
    }
    for (i = 2; i < number; i++) {
      if (arr[i] < min) {
        amount+=min;        //arr<min
        min = arr[i];
      }else {
        if (arr[i] > max) {
          amount+=max;    //arr>max
          max = arr[i];
        }else {
          amount+=arr[i]; //min<=arr<=max
        }
      }
    }
    avg = (double)amount/(number-2);
  }
  return avg;
}

/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
     For ESP8266
     ** MOSI - GPIO13 -> D7
     ** MISO - GPIO12 -> D6
     ** CLK  - GPIO14 -> D5
     ** CS   - GPIO15 -> D8
     * 
 * https://docs.arduino.cc/learn/programming/sd-guide
*/

#include <SPI.h>
#include <SD.h>

File myFile;

void setup(){
  Serial.begin(112500);
  while (!Serial){
  }
  Serial.print("Initializing SD card...");

  if (!SD.begin(15)){
    Serial.println("Initialization failed!");
    while(1);
  }
  Serial.println("Initialization done");
/*
 * Open the file. Note that only one file can be open at a time,
 * so you have to close this one before opening another.
 */
  myFile = SD.open("test.txt", FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3");
    // close the file:
    myFile.close();
    Serial.println("Done!");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening test.txt");
  }
}

void loop(){
  
}



/* blah blah */

#include <SPI.h>
#include <AD7193.h>


AD7193 AD7193;

void setup() {
  
  ///////////////////////////
  // setup Serial and SPI
  ///////////////////////////
  
  Serial.begin(9600);
  delay(1000);
  
  AD7193.begin();


  ///////////////////////////////////
  // Device setup
  ///////////////////////////////////
  
  AD7193.AppendStatusValuetoData();  //This might be a requirement - functions will be simpler if I can assume this is true  
  
  AD7193.SetPGAGain(1);

  AD7193.SetAveraging(100);
  

  /////////////////////////////////////
  // Calibrate with given PGA settings - need to recalibrate if PGA setting is changed
  /////////////////////////////////////
  
  AD7193.Calibrate();

  // Debug - Check register map values
  AD7193.ReadRegisterMap();
  

  //////////////////////////////////////
  
  Serial.println("\nBegin AD7193 conversion - single conversion (pg 35 of datasheet, figure 25)");
}


void loop() {

  unsigned long channel1;
  
  
  // Read channel measurement data
  channel1 = AD7193.ReadADCChannel(1);

  Serial.print("\n\tCH1: ");
  Serial.print(channel1 >> 8, HEX);

  float channel1Voltage = AD7193.BinaryToVoltage(channel1 >> 8);
  
  Serial.print("\n\t\tChannel 1 Voltage Measurement: ");
  Serial.println(channel1Voltage, 3);  
   
  delay(100);
}










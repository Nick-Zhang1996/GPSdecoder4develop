// 
// GPSdecoder 
//
// Description of the project
// Developed with [embedXcode](http://embedXcode.weebly.com)
// 
// Author	 	Nick zhang
// 				Nick Zhang
//
// Date			14-8-19 下午6:02
// Version		<#version#>
// 
// Copyright	© Nick zhang, 2014年
// License		<#license#>
//
// See			ReadMe.txt for references
//

// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"   
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif

// Include application, user and local libraries
#include "NEMAGPS.h"
#include <SofewareSerial.h>

SoftwareSerial gpsSerial(10,11);

GPS myGPS(&gpsSerial);
void setup() {
  
    
    gpsSerial.begin(9600);
    Serial.begin(9600);
    while (!myGPS.isFixed()) {
        
        Serial.println(F("GPS not fixed"));
        delay(3000);
        myGPS.read();
    }
}


void loop() {
    if(myGPS.read()==0){
    
    
    Serial.println(F("GPS fixed"));
    Serial.println(myGPS.getLat());
    Serial.println(myGPS.getLon());
    
    }
    
    
}

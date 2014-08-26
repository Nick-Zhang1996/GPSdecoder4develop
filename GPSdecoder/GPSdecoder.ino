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
#include <Wire.h>
#include "LiquidCrystal.h"
#include "NEMAGPS.h"
#include <SofewareSerial.h>

/*
 
 The circuit:
 * 5V to Arduino 5V pin
 * GND to Arduino GND pin
 * SCL to Analog #5
 * SDA to Analog #4
 */


// Connect via i2c, default address #0 (A0-A2 not jumpered)
LiquidCrystal lcd(0);
SoftwareSerial gpsSerial(10,11);

GPS myGPS(&gpsSerial);
void setup() {
  
    
    gpsSerial.begin(9600);
    Serial.begin(9600);
    
    // set up the LCD's number of rows and columns:
    lcd.begin(16, 2);
    
    
    
    while (!myGPS.isFixed()) {
        
        Serial.println(F("GPS not fixed"));
        Serial.println(myGPS.getSateNumber());
        lcd.setCursor(0, 0);
        lcd.print("GPS not fixed");
        lcd.setCursor(0, 1);
        lcd.print("Sate:");
        lcd.print(myGPS.getSateNumber());
        
        delay(3000);
        myGPS.read();
    }
}


void loop() {
    if(myGPS.read()==0){
    
    
    Serial.println(F("GPS fixed"));
    Serial.println(myGPS.getLat());
    Serial.println(myGPS.getLon());
    
    
    
    lcd.setCursor(0, 0);
    lcd.print("Lat");
    lcd.print(myGPS.getLat());
    lcd.print(myGPS.getNS());
    
    lcd.setCursor(0, 1);
    lcd.print("Lon");
    lcd.print(myGPS.getLon());
    lcd.print(myGPS.getEW());
        
    }
    

    
}

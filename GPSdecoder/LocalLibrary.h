//
// File			LocalLibrary.h
// Brief		Library header
//
// Project	 	GPSdecoder
// Developed with [embedXcode](http://embedXcode.weebly.com)
// 
// Author		Nick zhang
// 				Nick Zhang
// Date			14-8-19 下午6:02
// Version		<#version#>
// 
// Copyright	© Nick zhang, 2014年
// License		<#license#>
//
// See			ReadMe.txt for references
//


// Core library - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430 G2 and F5529, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

#ifndef GPSdecoder_LocalLibrary_h
#define GPSdecoder_LocalLibrary_h

//
// Brief	Blink a LED
// Details	LED attached to pin is light on then light off
// Total cycle duration = ms
// Parameters:
//      pin pin to which the LED is attached
//      times number of times
//      ms cycle duration in ms
//
void blink(uint8_t pin, uint8_t times, uint16_t ms);

#endif

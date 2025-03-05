#include <Arduino.h>
#include <Wire.h>

#include "Rotary.h"
#include "DS3231_Wrapper.h"

Rotary* r1 = new Rotary(9,10,8);
DS3231_Wrapper myRTC;

void setup() {
    Wire.setSDA(0);
    Wire.setSCL(1);
    Wire.begin();

    Serial.begin( 9600 );
    r1->init();
    while (! Serial);
    Serial.println("Hello!");
}


void loop() {
    bool rotary_input[3];
    r1->loop(rotary_input);

    if(rotary_input[0]){
        Serial.println("CW");
    }
    if(rotary_input[1]){
        Serial.println("CCW");
    }
    if(rotary_input[2]){
        //Serial.println("Rotary Button");
        myRTC.printTime();
    }
}
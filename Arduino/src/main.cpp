#include <Arduino.h>
#include <SerialCommandReader.h>
#include "Wheel.h"
#include <ArduinoJson.h>
#include <StreamUtils.h>

Wheel wheel1 = Wheel(2, 4, 3, 90);
Wheel wheel2 = Wheel(5, 7, 6, 210);
Wheel wheel3 = Wheel(8, 10, 9, 330);

DynamicJsonDocument doc(512);
bool LedOn = false;


void ToggleLed()
{
    Serial.begin(9600);
    LedOn = !LedOn;
    digitalWrite(LED_BUILTIN, LedOn);
}

void setup() {  
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    delay(2);
    ToggleLed();

    if(Serial.available())
    {
        //Serial.println("Input Stream:");
        //ReadLoggingStream loggingStream(Serial, Serial);
        //delay(2);
        //Serial.println('\n');
        //DeserializationError dsError = deserializeJson(doc, loggingStream);
        
        DeserializationError dsError = deserializeJson(doc, Serial);
        if (dsError == DeserializationError::Ok)
        {
            //serializeJsonPretty(doc, Serial);
            Serial.println(dsError.c_str());
            
        }
        // else
        // {
        //     Serial.println();
        //     Serial.println();
        //     Serial.print(F("deserializeJson() failed: "));
        //     Serial.println(dsError.c_str());
        //     Serial.println();
        //     Serial.println();
        // }
    }
}
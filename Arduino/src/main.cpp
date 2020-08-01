#include <Arduino.h>
#include <SerialCommandReader.h>
#include "Wheel.h"
#include <ArduinoJson.h>
#include <StreamUtils.h>

//Wheel wheel1 = Wheel(2, 4, 3, 90);
//Wheel wheel2 = Wheel(5, 7, 6, 210);
//Wheel wheel3 = Wheel(8, 10, 9, 330);

Wheel wheel1 = Wheel(2, 4, 3, 0);
Wheel wheel2 = Wheel(5, 7, 6, 120);
Wheel wheel3 = Wheel(8, 10, 9, 240);

DynamicJsonDocument doc(1024);

void setWheelsMotion(double theta, int movementSpeed, int rotationSpeed)
{
    
    wheel1.SetSpeed(theta, movementSpeed, rotationSpeed);
    wheel2.SetSpeed(theta, movementSpeed, rotationSpeed);
    wheel3.SetSpeed(theta, movementSpeed, rotationSpeed);
}

void setMotion(int angle, int movementSpeed, int rotationSpeed)
{
    double theta = radians(angle);
    setWheelsMotion(theta, movementSpeed, rotationSpeed);
    delay (1000);
}

void setup() {
    Serial.begin(9600);

    // setMotion(0, 128, 0);
    // setMotion(180, 128, 0);

    // setMotion(120, 128, 0);
    // setMotion(300, 128, 0);

    // setMotion(90, 128, 0);
    // setMotion(270, 128, 0);

    // setMotion(0, 0, 128);
    // setMotion(0, 0, -128);

    setMotion(0, 0, 0);
}

void loop() {
    
    if(Serial.available())
    {
        DeserializationError dsError = deserializeJson(doc, Serial);
        if (dsError == DeserializationError::Ok)
        {
            serializeJsonPretty(doc, Serial);
            int angle = doc["t"];
            int movementSpeed = doc["m"];
            int rotationSpeed = doc["w"];
            setMotion(angle, movementSpeed, rotationSpeed);
        }
    }
}
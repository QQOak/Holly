#include "wheel.h"


Wheel::Wheel(int clockwisePin, int antiClockwisePin, int speedPin)
    : _clockwisePin(clockwisePin), _antiClockwisePin(antiClockwisePin), _speedPin(speedPin)
{
    pinMode(clockwisePin, OUTPUT);
    pinMode(antiClockwisePin, OUTPUT);
    pinMode(speedPin, OUTPUT);
}

void Wheel::SetSpeed(int speed)
{
    digitalWrite(_clockwisePin, speed > 0);
    digitalWrite(_antiClockwisePin, speed < 0);
    analogWrite(_speedPin, abs(speed));

    Serial.print("Clockwise Pin #");
    Serial.print(_clockwisePin);
    Serial.print(" Direction: ");
    Serial.println(speed > 0);
    Serial.print(" Speed: ");
    Serial.println(abs(speed));
}
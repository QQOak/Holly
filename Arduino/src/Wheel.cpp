#include "wheel.h"


Wheel::Wheel(int clockwisePin, int antiClockwisePin, int speedPin, int wheelAngle)
    : _clockwisePin(clockwisePin), _antiClockwisePin(antiClockwisePin), _speedPin(speedPin)
{
    pinMode(clockwisePin, OUTPUT);
    pinMode(antiClockwisePin, OUTPUT);
    pinMode(speedPin, OUTPUT);

    _wheelAngle = radians(wheelAngle);
}

/// Theta is in radians
void Wheel::SetSpeed(double theta, int magnitude, int rotation)
{
    double speed = magnitude * sin(_wheelAngle + theta);
    speed = constrain(speed+rotation, -_maximumSpeed, _maximumSpeed);
    _setSpeed(speed);
}

void Wheel::_setSpeed(int speed)
{
    digitalWrite(_clockwisePin, speed > 0);
    digitalWrite(_antiClockwisePin, speed < 0);
    analogWrite(_speedPin, abs(speed));
}
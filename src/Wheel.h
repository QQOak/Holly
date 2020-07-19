#include <Arduino.h>

class Wheel {
    public:
        Wheel(int clockwisePin, int antiClockwisePin, int speedPin, int wheelAngle);
        void SetSpeed(double theta, int magnitude, int rotation);

    private:
        void _setSpeed(int speed);
        int _clockwisePin;
        int _antiClockwisePin;
        int _speedPin;
        int _wheelAngle;
        int _maximumSpeed = 255;
};
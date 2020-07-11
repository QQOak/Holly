#include <Arduino.h>

class Wheel {
    public:
        Wheel(int clockwisePin, int antiClockwisePin, int speedPin);
        void SetSpeed(int speed);

    private:
        int _clockwisePin;
        int _antiClockwisePin;
        int _speedPin;
};
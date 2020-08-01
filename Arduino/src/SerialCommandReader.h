#include <Arduino.h>

class SerialCommandReader {
    public:
        SerialCommandReader();
        bool ProcessSerial();
        String GetCommandDestructively();

    private:
        char TerminationCharacter = '\n';
        unsigned char commandLength = 0;
        char command[12];
};
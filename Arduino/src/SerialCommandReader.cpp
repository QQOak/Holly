#include "SerialCommandReader.h"


SerialCommandReader::SerialCommandReader()
{
}

// Returns a boolean indicating if a command has been received.
// Last write wins.  If a new command is processed, the previous command is overwritten if it has not already been destructively read.
bool SerialCommandReader::ProcessSerial()
{
    int bytesToRead = Serial.available();
    if(bytesToRead > 0)
    {
        uint8_t buffer[bytesToRead];
        Serial.readBytes(buffer, bytesToRead);
        Serial.print("Number of bytes read: ");
        Serial.println(bytesToRead);
        Serial.write(buffer, bytesToRead);
    }

    return false;
}


/// Returns the latest xyw command and clears so that future reads will not return the same result.
String SerialCommandReader::GetCommandDestructively()
{
    return "";
}
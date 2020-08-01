#include <Arduino.h>
#include <unity.h>
#include <SerialCommandReader.h>

void test_ReturnsStringWhenReachesTerminator(void) 
{
    SerialCommandReader serialCommandReader = SerialCommandReader();
    while(!serialCommandReader.ProcessSerial());

    const String expected = "x1y1w1";
    TEST_ASSERT_EQUAL_STRING(expected.c_str(), serialCommandReader.GetCommandDestructively().c_str());
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_ReturnsStringWhenReachesTerminator);
    UNITY_END();  
}

void loop()
{



}
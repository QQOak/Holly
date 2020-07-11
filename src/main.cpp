#include <Arduino.h>

int wheel1Angle = 240;
int wheel2Angle = 120;
int wheel3Angle = 0;

// fill input matrix
double a = cos(wheel1Angle);
double b = cos(wheel2Angle);
double c = cos(wheel3Angle);

double d = sin(wheel1Angle);
double e = sin(wheel2Angle);
double f = sin(wheel3Angle);

double g = 1;
double h = 1;
double i = 1;

// Calculate the determinate
double determinate
  = a * e * i
  + b * f * g
  + c * d * h
  - c * e * g
  - a * f * h
  - b * d * i;

// Calcualte the inverse
double aInverse = (e * i - f * h) / determinate;
double bInverse = (h * c - i * b) / determinate;
double cInverse = (b * f - c * e) / determinate;

double dInverse = (g * f - d * i) / determinate;
double eInverse = (a * i - g * c) / determinate;
double fInverse = (d * c - a * f) / determinate;

double gInverse = (d * h - g * e) / determinate;
double hInverse = (g * b - a * h) / determinate;
double iInverse = (a * e - d * b) / determinate;

void SetMotorSpeed(int motorNumber, int speed)
{
  Serial.print("Motor #");
  Serial.print(motorNumber);
  Serial.print(" : ");
  Serial.println(speed);
}

void SetSpeeds(float x, float y, float w)
{
  double motor1Speed = aInverse * x + bInverse * y + cInverse * w;
  double motor2Speed = dInverse * x + eInverse * y + fInverse * w;
  double motor3Speed = gInverse * x + hInverse * y + iInverse * w;

  SetMotorSpeed(1, motor1Speed);
  SetMotorSpeed(2, motor2Speed);
  SetMotorSpeed(3, motor3Speed);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Hello");

  SetSpeeds(0, 0, 0);

  SetSpeeds(0, 100, 0);
  SetSpeeds(0, -100, 0);

  SetSpeeds(100, 0, 0);
  SetSpeeds(-100, 0, 0);

  SetSpeeds(0, 0, 100);
  SetSpeeds(0, 0, -100);
}

void loop() {
  // put your main code here, to run repeatedly:
}
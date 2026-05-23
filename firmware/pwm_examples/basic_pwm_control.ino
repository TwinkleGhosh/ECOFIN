#include <Servo.h>

Servo leftThruster;
Servo rightThruster;
Servo rearThruster;

void setup()
{
    leftThruster.attach(9);
    rightThruster.attach(10);
    rearThruster.attach(11);

    // Neutral signal
    leftThruster.writeMicroseconds(1500);
    rightThruster.writeMicroseconds(1500);
    rearThruster.writeMicroseconds(1500);
}

void loop()
{
    // Forward movement test

    leftThruster.writeMicroseconds(1600);
    rightThruster.writeMicroseconds(1600);
    rearThruster.writeMicroseconds(1700);

    delay(3000);

    // Stop

    leftThruster.writeMicroseconds(1500);
    rightThruster.writeMicroseconds(1500);
    rearThruster.writeMicroseconds(1500);

    delay(2000);
}
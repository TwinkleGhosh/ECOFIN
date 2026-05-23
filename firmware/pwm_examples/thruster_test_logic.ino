#include <Servo.h>

Servo leftThruster;
Servo rightThruster;
Servo rearThruster;

void setup()
{
    leftThruster.attach(9);
    rightThruster.attach(10);
    rearThruster.attach(11);
}

void moveForward()
{
    leftThruster.writeMicroseconds(1600);
    rightThruster.writeMicroseconds(1600);
    rearThruster.writeMicroseconds(1700);
}

void turnLeft()
{
    leftThruster.writeMicroseconds(1450);
    rightThruster.writeMicroseconds(1650);
}

void turnRight()
{
    leftThruster.writeMicroseconds(1650);
    rightThruster.writeMicroseconds(1450);
}

void stopMovement()
{
    leftThruster.writeMicroseconds(1500);
    rightThruster.writeMicroseconds(1500);
    rearThruster.writeMicroseconds(1500);
}

void loop()
{
    moveForward();
    delay(3000);

    turnLeft();
    delay(2000);

    turnRight();
    delay(2000);

    stopMovement();
    delay(3000);
}
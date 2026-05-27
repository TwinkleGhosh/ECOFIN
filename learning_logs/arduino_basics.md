# EcoFin Arduino Nano Foundation Research
## Stage 1 — Arduino Basics for Underwater Robotics

Author: Twinkle Ghosh  
Project: EcoFin  
Board: Arduino Nano  
Goal: Build strong embedded systems fundamentals before full robot integration.

---

# TABLE OF CONTENTS

1. Introduction
2. What is Arduino Nano
3. Why Arduino Nano for EcoFin
4. Arduino Nano Architecture
5. Understanding Microcontrollers
6. Digital Pins
7. Analog Pins
8. PWM (Pulse Width Modulation)
9. Serial Communication
10. Functions and Program Structure
11. Loops
12. Libraries
13. Sensor Reading
14. Servo Control
15. ESC Control
16. TEST LOGIC to learn
17. Common Errors
18. Engineering Best Practices
19. Future Integration with EcoFin
20. Learning Summary

---

# 1. INTRODUCTION

Before building EcoFin’s navigation and AI systems, you MUST understand how embedded electronics work.

Arduino Nano will become the "brain" of the first EcoFin prototype.

It will control:

- Thrusters
- ESCs
- Sensors
- Navigation logic
- PWM signals
- Battery monitoring
- Future autonomous systems

This phase builds the foundational engineering skills required for robotics.

---

# 2. WHAT IS ARDUINO NANO

Arduino Nano is a compact microcontroller development board based on the ATmega328P microcontroller.

It is small, lightweight, cheap, and widely used in robotics.

## Key Specifications

| Feature | Value |
|---|---|
| Microcontroller | ATmega328P |
| Operating Voltage | 5V |
| Input Voltage | 7–12V |
| Digital I/O Pins | 14 |
| PWM Pins | 6 |
| Analog Inputs | 8 |
| Flash Memory | 32 KB |
| SRAM | 2 KB |
| Clock Speed | 16 MHz |

---

# 3. WHY ARDUINO NANO FOR ECOFIN

Arduino Nano is ideal because:

- Compact for waterproof housing
- Low power consumption
- Easy PWM generation
- Easy ESC control
- Massive community support
- Simple coding environment
- Compatible with sensors
- Lightweight for underwater robots

Future versions of EcoFin may upgrade to:

- ESP32
- Raspberry Pi
- STM32
- Pixhawk

But Arduino Nano is excellent for prototype development.

---

# 4. UNDERSTANDING MICROCONTROLLERS

A microcontroller is a miniature computer.

It contains:

- CPU
- Memory
- Input/Output pins
- Timers
- Communication modules

Arduino Nano continuously runs instructions uploaded into it.

Main cycle:

1. Read inputs
2. Process logic
3. Control outputs
4. Repeat forever

This cycle runs thousands of times per second.

---

# 5. ARDUINO PROGRAM STRUCTURE

Every Arduino program has two essential functions:

```cpp
void setup()
{
    
}

void loop()
{
    
}

```
---


# setup()

Runs ONLY ONCE during startup.

Used for:

Pin setup
Serial initialization
Library initialization

Example:
```cpp
void setup()
{
    pinMode(13, OUTPUT);
}


# loop()
```
Runs continuously forever.

Example:
```cpp
void loop()
{
    digitalWrite(13, HIGH);
    delay(1000);

    digitalWrite(13, LOW);
    delay(1000);
}
```
---


# 6. DIGITAL PINS

Digital pins can be:

HIGH (5V)
LOW (0V)

Used for:

LEDs
Buttons
Relays
ESC signals
Direction control
Pin Modes
pinMode(pin, mode);

Modes:

Mode	Purpose
INPUT	Read signal
OUTPUT	Send signal
INPUT_PULLUP	Internal resistor
Writing Digital Output
digitalWrite(13, HIGH);
Reading Digital Input
int buttonState = digitalRead(2);

---


# 7. ANALOG PINS

Analog pins measure voltage levels.

Arduino Nano ADC converts voltage into numbers.

Range:

0V → 0
5V → 1023
Reading Analog Sensor
int sensorValue = analogRead(A0);

Used for:

Potentiometers
Water sensors
Pressure sensors
Battery voltage monitoring


---


# 8. PWM (PULSE WIDTH MODULATION)

PWM is one of the MOST IMPORTANT concepts for EcoFin.

PWM allows Arduino to simulate analog output using digital pulses.

PWM controls:

- ESC speed
- Servo position
- Motor power
- LED brightness

## PWM Pins on Nano

| Pin | PWM |
|-----|-----|
| 3   | Yes |
| 5   | Yes |
| 6   | Yes |
| 9   | Yes |
| 10  | Yes |
| 11  | Yes |

# PWM THEORY

PWM rapidly switches voltage ON and OFF.

Average voltage changes depending on duty cycle.

## Duty Cycle

| Duty Cycle | Average Power |
|------------|----------------|
| 0%         | OFF            |
| 25%        | Low Power      |
| 50%        | Medium         |
| 100%       | Full Power     |

# PWM SIGNAL VISUALIZATION

## 25% Duty Cycle

```text
HIGH __
     | |
LOW__| |________
```

## 50% Duty Cycle

```text
HIGH ____ 
     |  |
LOW__|  |____
```

## 75% Duty Cycle

```text
HIGH ________
     |      |
LOW__|      |__
```

# GENERATING PWM

```cpp
analogWrite(9, 128);
```

Range:

- 0 → OFF
- 255 → FULL POWER
---


# 9. SERIAL COMMUNICATION

Serial communication allows Arduino to communicate with the computer.

VERY IMPORTANT for debugging.

Start Serial
Serial.begin(9600);
Print Data
Serial.println(sensorValue);
WHY SERIAL MONITOR MATTERS

Without Serial Monitor:

You cannot debug sensors
You cannot test values
You cannot diagnose errors

Professional engineers constantly use serial debugging.


---


# 10. FUNCTIONS

Functions organize code into reusable blocks.

Example
```cpp
void moveForward()
{
    analogWrite(9, 180);
}

Benefits:

Cleaner code
Easier debugging
Better modularity
Scalable firmware architecture
```

---


# 11. LOOPS

Loops repeat operations automatically.
```cpp
FOR LOOP
for(int i = 0; i < 10; i++)
{
    Serial.println(i);
}
WHILE LOOP
while(buttonState == HIGH)
{
    
}

```
---


# 12. LIBRARIES

Libraries are prewritten code modules.

Used for:

ESC control
Sensors
Displays
Communication
Include Library
#include <Servo.h>


---


# 13. SENSOR READING

Sensors convert physical information into electrical signals.

EcoFin future sensors may include:

IMU
Depth sensor
Leak sensor
Temperature sensor
Water quality sensor
Example Potentiometer Read
int value = analogRead(A0);

Serial.println(value);


---


# 14. SERVO CONTROL

Servos are position-controlled motors.

ESCs use servo-style PWM signals.

VERY IMPORTANT CONCEPT.

SERVO LIBRARY
#include <Servo.h>

Servo myServo;
Attach Servo
myServo.attach(9);
Move Servo
myServo.write(90);


---


# 15. ESC CONTROL

ESC = Electronic Speed Controller

ESC converts battery DC power into 3-phase motor signals.

Arduino sends PWM control signal to ESC.

ESC drives thruster motor.

ESC SIGNAL FLOW
Arduino Nano
      ↓
PWM Signal
      ↓
ESC
      ↓
3-Phase Power
      ↓
Brushless Thruster
ESC PWM SIGNALS

Typical ESC signals:

Signal	Pulse
Stop	1500 µs
Forward	1600–2000 µs
Reverse	1400–1000 µs
ESC CONTROL CODE
#include <Servo.h>
```cpp
Servo esc;

void setup()
{
    esc.attach(9);

    esc.writeMicroseconds(1500);
}

void loop()
{
    esc.writeMicroseconds(1600);

    delay(3000);

    esc.writeMicroseconds(1500);

    delay(3000);
}
```
IMPORTANT ESC SAFETY

NEVER:

Run propellers dry for long
Power ESC without cooling
Reverse polarity
Use unstable batteries
Touch spinning propellers


---


# 16. TEST LOGIC TO LEARN 

These projects build engineering confidence.


1. — BLINK LED


Objective

Learn digital output.

Circuit
LED + resistor connected to pin 13
Code
```cpp
void setup()
{
    pinMode(13, OUTPUT);
}

void loop()
{
    digitalWrite(13, HIGH);
    delay(1000);

    digitalWrite(13, LOW);
    delay(1000);
}
```
Concepts Learned
Digital output
Timing
Loops
GPIO basics


2. — READ POTENTIOMETER


Objective

Learn analog input.

Code
```cpp
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int value = analogRead(A0);

    Serial.println(value);

    delay(100);
}
```
Concepts Learned
ADC
Sensor reading
Serial Monitor
Voltage measurement


3. — CONTROL SERVO


Objective

Learn PWM servo signals.

Code
#include <Servo.h>
```cpp
Servo myServo;

void setup()
{
    myServo.attach(9);
}

void loop()
{
    myServo.write(0);
    delay(1000);

    myServo.write(90);
    delay(1000);

    myServo.write(180);
    delay(1000);
}
```
Concepts Learned
PWM timing
Servo signals
Libraries
Motor control


4. — GENERATE PWM


Objective

Understand duty cycles.

Code
```cpp
void setup()
{
    pinMode(9, OUTPUT);
}

void loop()
{
    analogWrite(9, 64);
    delay(2000);

    analogWrite(9, 128);
    delay(2000);

    analogWrite(9, 255);
    delay(2000);
}
```
Concepts Learned
PWM output
Duty cycle
Speed/power control


5. — CONTROL ONE ESC


Objective

Control one thruster safely.

Wiring
Arduino GND → ESC GND
Arduino Pin 9 → ESC Signal
Battery → ESC Power Input
ESC → Brushless Thruster
Code


#include <Servo.h>
```cpp
Servo esc;

void setup()
{
    esc.attach(9);

    esc.writeMicroseconds(1500);

    delay(5000);
}

void loop()
{
    esc.writeMicroseconds(1600);

    delay(3000);

    esc.writeMicroseconds(1500);

    delay(3000);
}
```
Concepts Learned
ESC communication
Thruster control
Neutral calibration
Motor safety


---


# 17. COMMON ERRORS

Error 1 — Wrong COM Port

Problem:

Upload failed

Solution:

Select correct COM port
Check USB cable
Error 2 — Missing Drivers

Install CH340 drivers if Nano clone.

Error 3 — Wrong Board

Select:

Arduino Nano
ATmega328P
Error 4 — ESC Not Arming

Causes:

Wrong PWM signal
Wrong calibration
No neutral signal
Low battery
Error 5 — Random Resets

Causes:

Voltage drops
Bad grounding
Weak battery


---


# 18. ENGINEERING BEST PRACTICES

Professional embedded systems engineers:

Use modular code
Add comments
Use proper wiring
Label connections
Use serial debugging
Test incrementally
Keep GitHub logs
Document failures


---


# 19. FUTURE INTEGRATION WITH ECOFIN

Arduino Nano will later control:

System	Purpose
Thrusters	Motion
ESCs	Motor driving
IMU	Orientation
Depth Sensor	Underwater depth
Leak Sensor	Waterproof safety
AI System	Future autonomy


---


# 20. LEARNING SUMMARY

By completing this stage, you now understand:

Microcontroller basics
Arduino architecture
Digital I/O
Analog inputs
PWM generation
Serial debugging
Servo communication
ESC control
Sensor interfacing
Embedded programming fundamentals

This forms the FOUNDATION of EcoFin robotics engineering.

---



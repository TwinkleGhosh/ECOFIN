# PWM NOTES
# ECOFIN CONTROL SYSTEM FOUNDATION

Stage: 1 — Control System Foundation

---

# 1. INTRODUCTION TO PWM

PWM stands for:

Pulse Width Modulation

PWM is one of the MOST IMPORTANT concepts in robotics, embedded systems, drones, underwater vehicles, and motor control systems.

In EcoFin:

PWM is used to control:

- ESCs (Electronic Speed Controllers)
- Thrusters
- Motor speed
- Direction
- Movement precision

Without PWM:

The Arduino cannot communicate movement commands to the ESC.

---

# 2. WHAT IS PWM?

PWM is a digital signal that rapidly switches between:

HIGH (ON)
LOW (OFF)

By changing the amount of ON time compared to OFF time, we can control:

- Motor speed
- Servo angle
- LED brightness
- Thruster power

PWM does NOT change voltage directly.

Instead:

It changes the average power delivered over time.

---

# 3. BASIC PWM THEORY

PWM signal contains:

- Frequency
- Duty cycle
- Pulse width

Important idea:

The signal turns ON and OFF extremely fast.

---

# 4. DUTY CYCLE

Duty cycle represents:

Percentage of time signal stays HIGH.

Formula:

Duty Cycle = (ON Time / Total Time) × 100

Examples:

25% duty cycle:
Signal ON for 25% time

50% duty cycle:
Equal ON/OFF

75% duty cycle:
Mostly ON

Higher duty cycle generally means:

More motor power.

---

# 5. PWM FREQUENCY

Frequency defines:

How many PWM cycles occur every second.

Unit:

Hz (Hertz)

Example:

50 Hz means:
50 cycles every second.

Period formula:

T = 1 / Frequency

At 50 Hz:

T = 20 ms

This is extremely important for ESC control.

---

# 6. ESC PWM CONTROL

ESC = Electronic Speed Controller

ESC acts like a translator between:

Arduino → Brushless Thruster Motor

The Arduino sends PWM signals.

The ESC interprets these signals and powers the motor accordingly.

---

# 7. HOW ESC READS PWM SIGNALS

ESC does NOT read voltage levels for speed.

Instead:

ESC measures pulse width.

Common pulse widths:

1000 µs = Full Reverse
1500 µs = Neutral
2000 µs = Full Forward

µs = microseconds

1 ms = 1000 µs

---

# 8. STANDARD ESC SIGNAL RANGES

Typical bidirectional ESC ranges:

| Pulse Width | Meaning |
|---|---|
| 1000 µs | Maximum Reverse |
| 1300 µs | Slow Reverse |
| 1500 µs | Neutral |
| 1700 µs | Slow Forward |
| 2000 µs | Maximum Forward |

Some ESCs vary slightly.

Always check manufacturer documentation.

---

# 9. PWM TIMING STRUCTURE

Standard ESC PWM frequency:

50 Hz

Meaning:

One signal cycle every 20 milliseconds.

Inside each 20 ms cycle:

The HIGH pulse determines command value.

Examples:

1000 µs HIGH pulse:
Reverse

1500 µs HIGH pulse:
Neutral

2000 µs HIGH pulse:
Forward

---

# 10. WHY ESCs USE PWM

PWM provides:

- Precise motor control
- Noise resistance
- Efficient digital communication
- Low processing requirements
- Stable control system architecture

This is why:
- drones
- submarines
- robotic fish
- RC boats

all use PWM-based ESC systems.

---

# 11. SERVO PWM VS NORMAL PWM

IMPORTANT:

Arduino analogWrite() PWM is NOT the same as servo PWM.

Two PWM types exist:

## A. analogWrite PWM

Used for:
- LEDs
- DC motor drivers

Typical frequency:
490 Hz

Duty-cycle based.

---

## B. Servo/ESC PWM

Used for:
- Servos
- ESCs
- Thrusters

Pulse-width based.

Typical frequency:
50 Hz

ESCs require SERVO STYLE PWM.

NOT analogWrite PWM.

---

# 12. ARDUINO SERVO.H LIBRARY

Arduino uses:

Servo.h

library to generate ESC-compatible PWM signals.

Why?

Because Servo.h creates:

50 Hz pulse-width signals.

Perfect for ESC communication.

---

# 13. BASIC ESC CONNECTION

ESC signal wire connects to:

Arduino PWM-capable pin.

Typical ESC wires:

| Wire | Purpose |
|---|---|
| Red | Power |
| Black/Brown | Ground |
| White/Yellow | Signal |

VERY IMPORTANT:

Arduino ground and ESC ground MUST be shared.

Without common ground:

PWM signals become unstable.

---

# 14. ESC CALIBRATION

ESC calibration teaches ESC:

What signal means:
- minimum throttle
- maximum throttle
- neutral position

Calibration is CRITICAL.

Without calibration:
- unstable movement
- incorrect speed
- startup failure
- dangerous motor behavior

can occur.

---

# 15. BASIC ESC CALIBRATION PROCESS

Typical procedure:

1. Send MAX throttle
2. Power ESC
3. Wait for beep
4. Send MIN throttle
5. Wait for confirmation beeps

ESC stores these limits internally.

---

# 16. ARDUINO PWM EXAMPLE CODE

```cpp
#include <Servo.h>

Servo esc;

void setup()
{
    esc.attach(9);

    // Neutral signal
    esc.writeMicroseconds(1500);

    delay(3000);
}

void loop()
{
    // Forward
    esc.writeMicroseconds(1700);
    delay(3000);

    // Neutral
    esc.writeMicroseconds(1500);
    delay(2000);

    // Reverse
    esc.writeMicroseconds(1300);
    delay(3000);

    // Neutral
    esc.writeMicroseconds(1500);
    delay(2000);
}

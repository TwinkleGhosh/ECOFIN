# ESC RESEARCH
# Electronic Speed Controllers for EcoFin

 Stage 2 — ESC Systems  


---

# TABLE OF CONTENTS

1. Introduction to ESCs
2. What is a Brushless DC Motor
3. What an ESC Actually Does
4. Internal Architecture of an ESC
5. How ESC Generates 3-Phase Signals
6. ESC Working Principle
7. ESC Communication Methods
8. PWM Signal Theory
9. Bidirectional ESCs
10. Waterproof ESCs
11. Current Ratings
12. Voltage Compatibility
13. Li-ion Battery Compatibility
14. BEC vs OPTO ESC
15. ESC Cooling Systems
16. Heat Generation Problems
17. Underwater Thermal Management
18. ESC Calibration Procedures
19. ESC Safety Systems
20. Choosing ESCs for EcoFin
21. Real Engineering Constraints
22. Recommended ESC Architecture


---

# 1. INTRODUCTION TO ESCs

ESC stands for:

Electronic Speed Controller

An ESC is the electronic system responsible for controlling:

- Motor speed
- Motor direction
- Motor startup
- Motor braking
- Motor synchronization

In EcoFin:

ESCs are the "muscles controller" between:

Battery → ESC → Thruster Motor

Without ESCs:

- Brushless motors cannot rotate
- Arduino cannot directly power motors
- Motor direction cannot be controlled
- Speed control becomes impossible

---

# 2. WHAT IS A BRUSHLESS DC MOTOR

EcoFin uses:

Brushless DC Motors (BLDC)

BLDC motors are:

- Highly efficient
- Powerful
- Compact
- Waterproof capable
- Long lifespan
- High torque-to-weight ratio

Unlike normal DC motors:

BLDC motors do NOT contain brushes.

Instead:

Electronic switching is required.

That switching is handled by:

ESCs

---

# 3. WHAT AN ESC ACTUALLY DOES

The battery supplies:

DC power

Example:

12V Li-ion Battery

BUT:

Brushless motors require:

3-phase AC-like signals

The ESC converts:

DC → Controlled 3-phase power

This is called:

Electronic Commutation

---

# 4. INTERNAL ARCHITECTURE OF AN ESC

A modern ESC contains:

## Major Components

### 1. Microcontroller

The ESC brain.

Responsible for:

- Reading PWM input
- Calculating timing
- Switching MOSFETs
- Synchronizing motor phases
- Safety monitoring

Examples:

- STM32
- ATmega
- ARM MCUs

---

### 2. MOSFET Power Stage

MOSFETs act as:

High-speed electronic switches.

They rapidly switch battery power ON/OFF.

Purpose:

Generate 3-phase waveforms.

---

### 3. Gate Drivers

MOSFETs require:

Precise gate control.

Gate drivers amplify control signals.

---

### 4. Capacitors

Used for:

- Voltage stabilization
- Ripple reduction
- Noise filtering

---

### 5. Voltage Regulators

Used for:

- Internal logic power
- BEC systems

---

### 6. Current Sensors

Measure:

- Motor current
- Overcurrent conditions

Used for:

Protection systems.

---

# 5. HOW ESC GENERATES 3-PHASE SIGNALS

A BLDC motor contains:

3 stator windings:

- Phase A
- Phase B
- Phase C

The ESC energizes these phases in sequence.

Example sequence:

A → B  
B → C  
C → A

This rotating electromagnetic field causes:

Motor rotation.

---

# 6. ESC WORKING PRINCIPLE

## Step-by-Step Operation

### Step 1 — PWM Signal Received

Arduino sends PWM pulse.

Example:

1500 µs

---

### Step 2 — ESC Interprets Command

ESC firmware determines:

- Speed
- Direction
- Startup timing

---

### Step 3 — MOSFET Switching Begins

ESC switches MOSFETs rapidly.

Switching frequency may be:

8 kHz  
16 kHz  
24 kHz  
48 kHz

---

### Step 4 — Motor Rotates

Sequential magnetic fields rotate rotor magnets.

---

# 7. ESC COMMUNICATION METHODS

ESCs communicate using:

## PWM

Most common method.

Typical range:

1000–2000 µs

### Signal Meaning

1000 µs → Full reverse  
1500 µs → Neutral  
2000 µs → Full forward

---

## Other Advanced Protocols

### OneShot
### DShot
### CAN Bus
### UART

Used in advanced robotics.

EcoFin initial prototype should use:

Standard PWM.

---

# 8. PWM SIGNAL THEORY

PWM:

Pulse Width Modulation

Arduino sends pulses repeatedly.

Typical refresh rate:

50 Hz

Meaning:

50 pulses per second.

---

# PWM Pulse Example

| Pulse Width | Meaning |
|---|---|
| 1000 µs | Full Reverse |
| 1500 µs | Neutral |
| 1700 µs | Moderate Forward |
| 2000 µs | Full Forward |

---

# Arduino Example

```cpp
#include <Servo.h>

Servo esc;

void setup() {
    esc.attach(9);

    esc.writeMicroseconds(1500);
    delay(3000);
}

void loop() {

    esc.writeMicroseconds(1700);

}

```

---

# 9. BIDIRECTIONAL ESCs

Normal drone ESCs:

Only rotate one direction.

EcoFin requires:

Forward + reverse motion.

Thus:

Bidirectional ESCs are required.

Why Bidirectional ESCs Matter

EcoFin needs:

Reverse movement
Turning
Precise navigation
Station holding
Obstacle avoidance

Without bidirectional ESCs:

Robot maneuverability becomes extremely limited.

Bidirectional Neutral Point

Bidirectional ESCs usually use:

1500 µs = neutral

Above 1500:

Forward

Below 1500:

Reverse

---

# 10. WATERPROOF ESCs

Underwater robotics requires:

Water-resistant or waterproof ESCs.

Problems with Standard ESCs

Normal ESCs fail underwater because of:

Corrosion
Short circuits
Saltwater conductivity
Moisture damage
Waterproofing Methods
Method 1 — Factory Waterproof ESC

Best option.

Method 2 — Epoxy Coating

ESC coated in:

Epoxy resin
Silicone conformal coating
Method 3 — Pressure Enclosure

ESC sealed inside watertight chamber.

Professional method.

---

# 11. CURRENT RATINGS

ESC current rating determines:

Maximum safe current handling.

Example:

30A ESC

Means:

ESC can safely handle:

30 amps continuous.

Burst Current

Some ESCs support:

Short-duration peak current.

Example:

30A continuous
40A burst

Why Current Ratings Matter

If motor draws excessive current:

ESC may:

Overheat
Burn MOSFETs
Fail permanently
Engineering Rule

ESC current rating should exceed:

Motor maximum current by:

20–40%

Example

Thruster max current:

18A

Recommended ESC:

25A–35A

---

# 12. VOLTAGE COMPATIBILITY

ESC must match battery voltage.

Li-ion Battery Configurations
Battery	Voltage
2S	7.4V
3S	11.1V
4S	14.8V
6S	22.2V
Example

If using:

3S Li-ion battery

ESC must support:

11.1V system.

---

# 13. LI-ION BATTERY COMPATIBILITY

EcoFin will likely use:

Li-ion battery packs.

ESC must support:

Low voltage cutoff
Stable high-current operation
Smooth throttle response
Important Li-ion Considerations
Voltage Sag

Li-ion batteries experience:

Voltage drop under load.

ESC must tolerate this.

Low Voltage Protection

ESC should prevent:

Battery over-discharge.

Critical for battery safety.

---

# 14. BEC vs OPTO ESC

This is one of the most important ESC concepts.

BEC ESC

BEC:

Battery Elimination Circuit

Contains:

Built-in voltage regulator.

Can power:

Arduino
Receiver
Sensors
Advantages
Simpler wiring
Fewer components
Lower system complexity
Disadvantages
Electrical noise
Heat generation
Limited current output
OPTO ESC

OPTO ESC:

No internal BEC.

Requires separate power regulator.

Advantages
Cleaner signals
Better for robotics
Better electrical isolation
More stable
Disadvantages
Extra components required
More wiring complexity
Engineering Recommendation

For EcoFin:

OPTO ESCs are preferable.

Reason:

Robotics systems require:

Stable sensors
Clean communication
Reduced interference

---

# 15. ESC COOLING SYSTEMS

ESCs generate significant heat.

Main heat sources:

MOSFET switching
Current flow
Resistance losses
Why Heat is Dangerous

Excessive heat causes:

MOSFET failure
Reduced efficiency
Thermal shutdown
Permanent damage

---

# 16. HEAT GENERATION PROBLEMS

ESC heating increases due to:

High Current

More current = more heat.

Poor Cooling

Trapped heat damages components.

High PWM Frequency

Higher switching frequencies increase:

MOSFET losses.

Water Resistance Coatings

Waterproofing materials may trap heat.

---

# 17. UNDERWATER THERMAL MANAGEMENT

Water cooling is actually a major advantage.

Water absorbs heat efficiently.

Cooling Strategies
Aluminum Heat Sink

Transfers heat to outer shell.

Water-Cooled ESC Plate

Professional underwater systems use:

Metal thermal transfer plates.

Internal Airflow

Useful in dry compartments.

Thermal Pads

Transfer heat from ESC to enclosure.

---

# 18. ESC CALIBRATION PROCEDURES

ESC calibration teaches ESC:

Minimum and maximum throttle values.

Why Calibration Matters

Without calibration:

Motor jitter
Poor throttle response
Inconsistent startup
Reverse issues

may occur.

Generic Calibration Procedure
Step 1

Turn transmitter/Arduino to max throttle.

Step 2

Power ESC.

ESC beeps.

Step 3

Move throttle to minimum.

ESC stores limits.

Step 4

ESC confirms calibration.

Arduino Calibration Example
```cpp
#include <Servo.h>

Servo esc;

void setup() {

  esc.attach(9);

  esc.writeMicroseconds(2000);
  delay(3000);

  esc.writeMicroseconds(1000);
  delay(3000);

  esc.writeMicroseconds(1500);
}

void loop() {

}

``` 
---

# 19. ESC SAFETY SYSTEMS

Modern ESCs include:

Overcurrent Protection

Prevents excessive current damage.

Thermal Shutdown

Stops ESC during overheating.

Low Voltage Cutoff

Protects battery.

Desynchronization Protection

Prevents motor timing failure.

---

# 20. CHOOSING ESCs FOR ECOFIN

EcoFin requires:

Essential Features
Bidirectional
Waterproof
Li-ion compatible
Stable reverse
Smooth low-speed control
High efficiency
Good thermal management
Recommended Current Range

Depends on thruster specifications.

Typical underwater thrusters:

20A–40A ESC range.

---

# 21. REAL ENGINEERING CONSTRAINTS

Underwater robotics is difficult because:

Water causes corrosion
Cooling is uneven
Waterproofing traps heat
ESC tuning affects stability
Noise affects sensors
Battery sag affects performance

Professional underwater systems spend enormous effort on:

Power electronics reliability.

---

# 22. RECOMMENDED ESC ARCHITECTURE

For EcoFin prototype:

Recommended:

Architecture

Battery
↓
Fuse
↓
Power Distribution Board
↓
3 Bidirectional ESCs
↓
3 Thrusters

Control:

Arduino Nano
↓
PWM Signals
↓
ESC Inputs

---

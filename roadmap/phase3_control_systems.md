# Phase 3 — Control Systems Development

## Objective

Develop movement algorithms for EcoFin underwater navigation.

---

# Core Movement Functions

Planned functions:
- moveForward()
- moveBackward()
- turnLeft()
- turnRight()
- stopMotors()

---

# Differential Thrust Logic

Movement achieved through varying thruster speeds.

Example:

| Movement | Left Thruster | Right Thruster |
|----------|---------------|----------------|
| Forward | 1700 | 1700 |
| Left Turn | 1500 | 1800 |
| Right Turn | 1800 | 1500 |

---

# Concepts Studied

- movement control
- thrust balancing
- state machines
- directional logic

---

# Future Goals

- smoother turning
- stable underwater movement
- PID-assisted control

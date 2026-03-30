# Digital Clock System (Hardware Project)

## Overview

This project is a fully functional 12-hour digital clock built using digital logic circuits and integrated circuits. The system tracks time in seconds, minutes, and hours using cascaded counters and displays the output on seven-segment displays.

The goal of this project was to understand how digital systems operate at the hardware level, including counting logic, signal timing, and circuit synchronization.

---

## Demonstration

-Final Working Clock:
https://youtu.be/8n2_f8gFhdw

-Seconds Counter:
https://youtu.be/-XK_WN4RT6E

-Minutes Counter:
https://youtu.be/8R0py8RNqEQ

---

## How It Works

* A **1 Hz clock signal** (from a function generator) drives the system
* Binary-coded decimal (BCD) counters increment time values
* AND gates are used to:

  * detect rollover conditions (e.g., 59 → 00)
  * trigger the next stage (seconds → minutes → hours)
* BCD-to-seven-segment drivers convert binary values into display output

This cascading mechanism ensures accurate time progression across all units.

---

## Hardware Components

* CD4518 – Dual BCD counters (seconds & minutes)
* CD4510 – Pre-settable BCD counters (hours)
* CD4543 – BCD to seven-segment display drivers
* CD4081 – AND gate logic
* Seven-segment displays
* Function generator (1 Hz clock signal)
* Breadboard + wiring + 5V supply

---

## Challenges & Debugging

This project required extensive troubleshooting, including:

* Incorrect counting due to missing power connections
* Counters stopping at incorrect values (e.g., minutes stopping at 10)
* Wiring issues causing unstable signals
* Breadboard faults and loose connections

Through systematic debugging, testing, and rebuilding sections of the circuit, the system was successfully completed.

---

## Project Files

* Full Lab Report: `Digital Clock Lab.pdf`
* Circuit Images: `/images`
* Demonstration Videos: linked above

---

## What I Learned

* Designing sequential digital systems using ICs
* Implementing cascading counters for time tracking
* Using logic gates to control signal flow
* Debugging real-world hardware issues
* Understanding timing signals and synchronization

---

## Key Takeaway

This project strengthened my ability to bridge theoretical digital logic concepts with real hardware implementation, highlighting the importance of debugging, signal integrity, and system design in electrical engineering.

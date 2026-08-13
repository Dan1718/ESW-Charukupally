# Project Overview

## Project Title

Closed-Loop Stepper Control for Precise Angular Motion.

## Course Context

- Course: Embedded System Workshop (EC3.202)
- Faculty: A. Sarje
- Mentor: Goutam Sutradhar
- TA: Geethika

## Project Team

- Daniel Vincent
- Saketh Naga Sibyala
- Suryansh Reddy Charukupally
- Ashwin Hari

## Motivation

Stepper motors are convenient for commanded angular motion, but open-loop operation cannot directly detect missed steps, mechanical disturbances, backlash, or other sources of position error. A feedback system can measure the actual shaft angle and reduce the difference between the target and measured positions.

## Project Goal

Develop and experimentally validate a closed-loop NEMA 17 stepper-motor system capable of precise angular positioning and strict positional repeatability, with a target performance in the arc-second range as defined and refined with the project mentors.

## Scope

The planned scope includes:

- Component selection and justification
- Motor-driver-microcontroller integration
- High-resolution rotary encoder integration
- Open-loop motion generation
- Closed-loop controller implementation
- Noise analysis and mitigation where required
- Calibration and test procedure development
- Precision and repeatability validation using an independent measurement method

## Non-Goals For The Initial Prototype

The following are not yet assumed to be required:

- Cloud or IoT connectivity
- A production-ready enclosure
- Field deployment
- A final choice between PI, PID, FOC, or another control strategy

These may be revisited if the project requirements or mentor guidance changes.

## Open Questions

- What exact angular precision and repeatability thresholds will be used for evaluation?
- Which motors, drivers, encoders, and microcontrollers are available in the lab?
- What independent angular measurement instrument is available?
- What operating speed, load, and angular range are required?
- Is the encoder mounted directly on the motor shaft or after a transmission?
- What are the mechanical mounting and coupling constraints?

## Current Status

The team has not yet performed project work, hardware inspection, component research, or implementation. The project has just started, and component selection is the first planned task.

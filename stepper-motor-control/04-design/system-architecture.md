# System Architecture

## Current Concept

```text
Target angle
     |
     v
Microcontroller -> Motor driver -> NEMA 17 motor -> Physical shaft angle
     ^                                             |
     |                                             v
     +------------- Rotary encoder <--------------+
```

The microcontroller will generate motor commands, acquire encoder feedback, estimate angular error, and adjust the command using a closed-loop controller.

Closed-loop feedback is a fundamental project requirement, not an optional extension. The encoder is currently intended to measure the final geared output shaft. This allows the feedback loop to observe output-side errors, including errors introduced by the gearing, rather than only the motor-shaft position.

This choice increases the importance of encoder mounting, output-shaft coupling, backlash characterization, and mechanical stiffness in the error budget.

## Design Decisions

### Output-Shaft Feedback

- **Decision:** Mount the rotary encoder on the final geared output shaft.
- **Reason:** Measure the angle that the system is actually required to control, including errors introduced by the mechanical transmission.
- **Tradeoffs:** The output-side encoder requires suitable mechanical mounting and coupling. Backlash and compliance will need to be characterized later, once the mechanical arrangement is defined.
- **Status:** Preliminary design decision; mechanical implementation and encoder choice remain open.

## Interfaces To Define

- Microcontroller to motor driver
- Microcontroller to encoder
- Motor and driver power path
- Mechanical motor-to-encoder interface
- Independent measurement setup

## Risks

- Encoder resolution may not be sufficient for the target precision.
- Mechanical backlash or shaft coupling errors may dominate electrical accuracy.
- Microstepping resolution may not equal physical positioning accuracy.
- Stepper resonance, missed steps, and thermal effects may affect repeatability.

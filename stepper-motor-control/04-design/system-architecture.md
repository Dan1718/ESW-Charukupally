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

This architecture follows the supplied system-level guidance that the encoder should measure the load-side result. Industrial Monitor Direct states: “The encoder determines ultimate system accuracy—motors and mechanics must follow the measurement, not dictate it.” [Source](https://industrialmonitordirect.com/it/blogs/knowledgebase/05-arcsecond-precision-rotary-motion-motor-encoder-design-guide) (accessed 2026-08-13). The source is not treated as a final component recommendation because its example has more demanding dynamics than this project.

## Design Decisions

### Output-Shaft Feedback

- **Decision:** Mount the rotary encoder on the final geared output shaft.
- **Reason:** Measure the angle that the system is actually required to control, including errors introduced by the mechanical transmission.
- **Tradeoffs:** The output-side encoder requires suitable mechanical mounting and coupling. Backlash and compliance will need to be characterized later, once the mechanical arrangement is defined.
- **Status:** Preliminary design decision; mechanical implementation and encoder choice remain open.

### Mechanical Reduction Direction

- **Current candidate:** Direct drive if feasible; otherwise fixed synchronous timing-belt pulley reduction.
- **Reason:** Precision and accuracy are the primary objectives. Direct drive minimizes transmission error. A toothed belt is the preferred reduced-drive fallback because it provides a selectable fixed ratio with accessible mechanical characterization and avoids normal friction slip.
- **Baseline interpretation:** A 0.9-degree motor at 32 microsteps gives approximately 101.25 arc-seconds per nominal direct-drive command. This is a closed-loop baseline with very little margin, not the preferred final mechanical arrangement.
- **Preferred improvement:** Investigate a small fixed ratio, initially around 2:1, to move the nominal command increment toward 50.625 arc-seconds. Accept the reduction only if measured backlash, hysteresis, runout, and compliance improve the total output error budget rather than making it worse.
- **Alternatives:** Harmonic/strain-wave, planetary, cycloidal, worm, and direct drive are retained for comparison. A variable-ratio CVT is an exploratory option rather than the baseline precision transmission.
- **Constraint:** The transmission must be evaluated for backlash, elastic compliance, pulley/shaft runout, tension variation, thermal drift, and load-dependent error.
- **Status:** Preliminary direction; motor capability, ratio, packaging, and measured transmission error remain open. Torque is only a feasibility check.

Further comparison is recorded in [`mechanical-reduction-options.md`](mechanical-reduction-options.md).

## Interfaces To Define

- Microcontroller to motor driver
- Microcontroller to encoder
- Motor and driver power path
- Mechanical motor-to-encoder interface
- Independent measurement setup

## Risks

- Encoder resolution may not be sufficient for the target precision.
- Mechanical backlash or shaft coupling errors may dominate electrical accuracy.
- A variable-ratio transmission may add ratio uncertainty, slip, and changing compliance that the output feedback loop must correct.
- Microstepping resolution may not equal physical positioning accuracy.
- Stepper resonance, missed steps, and thermal effects may affect repeatability.

# Angular Resolution and Positioning Accuracy

## Why This Matters

The project brief asks for angular precision in the arc-second range. A stepper system can produce a very small nominal command increment through full steps, microstepping, and mechanical reduction. However, the nominal increment is not automatically the physical accuracy or repeatability of the shaft.

## Nominal Step Resolution

For a motor with step angle `theta_step`, `M` microsteps per full step, and a mechanical reduction ratio `R`:

```text
nominal output increment = theta_step / (M * R)
```

For a typical 1.8-degree motor:

```text
full-step angle = 1.8 degrees = 6480 arc-seconds
```

At 32 microsteps without mechanical reduction:

```text
6480 / 32 = 202.5 arc-seconds per commanded microstep
```

This is a theoretical command increment. It does not establish actual shaft accuracy.

## Factors That Limit Actual Accuracy

- Microsteps may not divide the mechanical angle linearly.
- Motor torque, load, and current regulation affect microstep position.
- Missed steps can occur under acceleration, resonance, or excessive load.
- Mechanical backlash, compliance, and eccentricity can dominate the error.
- Encoder quantization and mounting errors affect measured angle.
- Driver current ripple and electrical noise affect torque and feedback.
- Thermal changes can alter mechanical and electrical behavior.

## Implication For This Project

The rotary encoder and independent measurement method are essential. The encoder provides feedback for the controller, while the independent instrument is needed to validate the final angular performance. Microstepping should be treated as a motion-smoothness and command-resolution feature, not as proof of arc-second positioning accuracy.

## Reference Review

The Cloudy Nights discussion uses an astronomy tracking example and compares step angle, microstepping, and gear reduction. It is useful as an informal illustration of resolution calculations and the need to define the required angular scale.

The discussion includes a numerical inconsistency: for a 1.8-degree motor at 32 microsteps, the direct calculation is 202.5 arc-seconds per microstep, not 15.625 arc-seconds. All numerical claims from the discussion must therefore be independently recalculated before use.

### Direct Quotes

The original post gives the following example configuration:

> “200 step motor, 32 microsteps, 27:1 planetary, 8:1 gear reduction”

The discussion also states:

> “Most steppers 1 full step = 1.8 degrees”

and:

> “The rule is normally 1 to 2 arc seconds per pixel resolution.”

These are statements from an astronomy-tracking discussion, not project requirements or validated specifications for our system. The arc-seconds-per-pixel statement is not directly applicable without an application-specific imaging requirement.

### Citation

Cloudy Nights forum discussion, “Steppers and resolution,” topic 739690, https://www.cloudynights.com/forums/topic/739690-steppers-and-resolution/ (accessed 2026-08-13).

## Consequences For Component Selection

- Encoder resolution must be evaluated against the required closed-loop measurement resolution.
- Driver microstepping settings must be recorded, but not used alone to claim accuracy.
- The mechanical transmission ratio must be included in the resolution and error budget.
- Component selection must consider torque and repeatability, not only the smallest nominal step.

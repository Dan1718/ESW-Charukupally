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

For a `0.9-degree` motor, the same calculation is:

```text
0.9 degrees = 3240 arc-seconds
3240 / 32 = 101.25 arc-seconds per commanded microstep
```

Thus, a 0.9-degree motor at 32 microsteps and direct drive reaches approximately the strict 100-arcsecond command-resolution range. Because this project uses closed-loop output-shaft feedback, the controller can measure and correct the remaining target-versus-shaft error. This makes 100-arcsecond physical performance more plausible than open-loop microstepping alone, provided encoder resolution, control-loop bandwidth, noise, and tuning are sufficient. Closed loop still cannot remove encoder quantization, measurement error, motor torque limits, electrical noise, or mechanical disturbances. A 2:1 reduction would reduce the nominal command increment to approximately 50.625 arc-seconds, but would add transmission errors that must be measured.

## Factors That Limit Actual Accuracy

- Microsteps may not divide the mechanical angle linearly.
- Motor torque, load, and current regulation affect microstep position.
- Missed steps can occur under acceleration, resonance, or excessive load.
- Mechanical backlash, compliance, and eccentricity can dominate the error.
- Encoder quantization and mounting errors affect measured angle.
- Driver current ripple and electrical noise affect torque and feedback.
- Thermal changes can alter mechanical and electrical behavior.

These limitations are consistent with the manufacturer discussion from Lin Engineering, which explicitly distinguishes resolution from accuracy: “During microstepping, you are not necessarily increasing the accuracy, but you are increasing the resolution.” [Lin Engineering](https://www.linengineering.com/news/methods-for-increasing-accuracy-in-stepper-motors) (accessed 2026-08-13).

## Implication For This Project

The rotary encoder and independent measurement method are essential. The encoder provides feedback for the controller, while the independent instrument is needed to validate the final angular performance. Microstepping should be treated as a motion-smoothness and command-resolution feature, not as proof of arc-second positioning accuracy.

The same system-level distinction is emphasized by Industrial Monitor Direct: “The encoder determines ultimate system accuracy—motors and mechanics must follow the measurement, not dictate it.” [Industrial Monitor Direct](https://industrialmonitordirect.com/it/blogs/knowledgebase/05-arcsecond-precision-rotary-motion-motor-encoder-design-guide) (accessed 2026-08-13). This is treated as design guidance, not as a validated specification for our prototype.

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

## What Closed-Loop Accuracy Looks Like Without Reduction

Closed-loop control does not provide a fixed accuracy simply because feedback is present. For a direct-drive motor, the encoder and mechanics determine the achievable result.

For an encoder producing `N` usable counts per revolution at the measured shaft:

```text
encoder count angle = 360 degrees / N
                     = 1,296,000 arc-seconds / N
```

Illustrative ideal quantization values are:

| Usable counts per revolution | Ideal count spacing |
| ---: | ---: |
| 1,000 | 1,296 arc-seconds |
| 4,000 | 324 arc-seconds |
| 10,000 | 129.6 arc-seconds |
| 40,000 | 32.4 arc-seconds |
| 100,000 | 12.96 arc-seconds |
| 1,296,000 | 1 arc-second |

These are resolution values, not accuracy values. Encoder interpolation, quantization, electrical noise, shaft eccentricity, bearing runout, motor torque ripple, structural compliance, controller sampling, and settling behavior can all make the actual error larger. A 1,000-line incremental encoder may provide 4,000 quadrature counts per revolution if all four edges are used, but that does not mean the physical shaft is accurate to 324 arc-seconds.

Closed-loop feedback can detect and correct missed steps, load disturbances, and some repeatable errors. It cannot automatically remove backlash, encoder mounting error, output-shaft runout, or errors that are below the feedback system's effective measurement capability. This is why the Lin Engineering source warns: “During microstepping, you are not necessarily increasing the accuracy, but you are increasing the resolution.” [Lin Engineering](https://www.linengineering.com/news/methods-for-increasing-accuracy-in-stepper-motors) (accessed 2026-08-13).

For our project, an unreduced standard NEMA 17 with a common low-resolution encoder should therefore not be assumed to achieve arc-second-level output accuracy. We need an encoder with sufficiently fine output-shaft measurement resolution and verified accuracy, plus a mechanical and control design that can use it.

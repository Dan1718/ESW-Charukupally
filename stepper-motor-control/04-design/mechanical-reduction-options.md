# Mechanical Reduction Options

## Design Targets

The mechanical transmission must support the strict project goal of approximately `100 arc-seconds` at the final output shaft, while leaving a path toward the `10 arc-second` stretch goal. Precision and accuracy are the primary selection criteria. Torque multiplication is only a feasibility concern because the expected load is low. The output encoder must remain on the final shaft so that transmission errors are included in the feedback loop and validation.

For a 1.8-degree motor operated at 32 microsteps, one motor command is nominally 202.5 arc-seconds. For a 0.9-degree motor at the same setting, it is 101.25 arc-seconds. The approximate command-resolution comparison is therefore:

| Motor and total reduction | Nominal command increment at 32 microsteps |
| --- | --- |
| 1.8-degree, 1:1 | 202.5 arc-sec |
| 0.9-degree, 1:1 | 101.25 arc-sec |
| 1.8-degree, 2:1 | 101.25 arc-sec |
| 0.9-degree, 2:1 | 50.625 arc-sec |
| 1.8-degree, 20:1 | 10.125 arc-sec |

These figures describe command resolution only. They do not establish accuracy, repeatability, or backlash performance. In particular, the 0.9-degree direct-drive case is only slightly below the 100-arcsecond requirement in nominal terms. A better mechanical situation is needed for margin and for the approximately 10-arcsecond stretch goal.

## Required Improvement Below the Baseline

The 0.9-degree motor at 32 microsteps provides a useful closed-loop baseline, but it leaves almost no resolution margin: one nominal command is approximately 101.25 arc-seconds. The practical design should therefore target a smaller command increment, such as 20 to 50 arc-seconds, so that controller correction, measurement noise, settling error, and mechanical nonlinearity do not consume the entire 100-arcsecond budget.

The most practical first approach is a small, fixed, synchronous timing-belt reduction. For example, a 2:1 stage changes the nominal increment from 101.25 to 50.625 arc-seconds with a 0.9-degree motor at 32 microsteps. The stage is worthwhile only if its backlash, elastic hysteresis, runout, and compliance are characterized and remain below the accuracy margin it creates. Closed-loop feedback can correct repeatable output error, but it cannot make a mechanically unstable or poorly measured transmission accurate.

## Candidate Comparison

| Transmission | Precision-relevant strengths | Main precision risks | Position in this project |
| --- | --- | --- | --- |
| Synchronous timing-belt pulley | Low cost, easy to prototype, no intentional tooth slip, flexible ratio, low reflected backlash if correctly tensioned | Belt elasticity, tooth clearance, pulley eccentricity, shaft deflection, tension variation, bearing runout | Strong first candidate for fixed reduction and characterization |
| Harmonic/strain-wave gearbox | Very high reduction in one stage, compact, potentially very low backlash | Expensive, torsional compliance, cyclic error, limited load/life depending on unit, difficult sourcing | Best high-precision gearbox candidate if a suitable unit is available |
| Planetary gearbox | Compact, efficient, fixed ratio, readily available; repeatable backlash may be compensated in closed loop | Backlash commonly specified in arc-minutes, bearing and gear errors, preload and load dependence | Viable only with output-side feedback, a measured backlash model, and bidirectional validation |
| Cycloidal reducer | High reduction and load capacity, robust | Residual backlash, torque ripple, eccentricity, bulky construction | Possible alternative, not the simplest prototype route |
| Worm gear | Very high ratio and sometimes self-locking | Backlash, sliding friction, poor efficiency, thermal sensitivity, stick-slip | Not preferred for arc-second positioning |
| Direct drive | No transmission backlash or ratio error, simplest error chain | Requires a motor capable of the required output angle control; no resolution multiplication | Preferred precision reference if the motor and load permit it |
| Variable-pitch belt/CVT | Can change torque/speed ratio for different operating loads | Slip or creep, ratio calibration, pulley runout, belt compliance, actuator repeatability, changing backlash/hysteresis, difficult error modelling | Not recommended as the primary precision reduction |

## Timing-Belt Pulley Assessment

A fixed synchronous belt stage is not the same as a friction-wheel CVT. A toothed timing belt can transmit a known ratio without normal operating slip. It can therefore be a practical alternative to a planetary gearbox.

For pulley tooth counts `N_motor` and `N_output`, with the output pulley larger:

```text
reduction ratio R = N_output / N_motor
nominal output increment = motor increment / R
```

Example: a 20-tooth motor pulley and a 40-tooth output pulley provide 2:1 reduction. Multiple stages can provide a larger ratio, but every stage adds belt elasticity, alignment error, and assembly tolerance. A single moderate-ratio stage is preferable where packaging permits.

The belt design must specify pitch, tooth count, belt width, centre distance, tensioning method, pulley runout, shaft support, and allowable radial load. The output pulley should be mounted on a rigid bearing-supported shaft rather than relying on the motor bearing to carry the belt load.

The belt stage must be tested for:

- Static bidirectional hysteresis after reversing direction.
- Elastic angular deflection under the expected load and torque changes.
- Repeatability after different belt approaches and tension states.
- Pulley eccentricity and periodic angle error over one revolution.
- Thermal drift and tension change.
- Maximum usable reduction before belt tooth loading, compliance, or resonance becomes unacceptable.

Preloading can reduce free play, but excessive tension increases bearing load and does not eliminate elastic deformation. A belt transmission should not be called backlash-free without measurement.

## Variable-Ratio/CVT Assessment

Changing the ratio to suit different loads is mechanically possible, but it introduces a second control problem: the controller must know the actual instantaneous ratio and the transmission must hold that ratio repeatably. A friction CVT can also slip under load, which directly destroys the commanded-angle relationship. A variable-pitch toothed-belt system avoids some slip but still has ratio-position calibration, belt compliance, pulley runout, actuator backlash, and changing stiffness.

For this project, load adaptation should first be achieved through motor current, acceleration limits, controller gains, or a fixed transmission selected for the worst expected load. If variable reduction is investigated, use discrete, mechanically locked ratios rather than a free-running CVT. Measure the output-side angle after every ratio change and require a homing or calibration procedure before precision positioning.

The CVT should therefore be treated as a separate exploratory experiment, not part of the baseline precision architecture. It may be useful for demonstrating adaptive speed/torque operation, but it makes the 100-arcsecond benchmark harder to satisfy and the 10-arcsecond stretch goal substantially less credible.

## Preliminary Recommendation

1. Treat direct drive with a 0.9-degree motor at 32 microsteps and output-side closed-loop feedback as the first 100-arcsecond baseline to test. The encoder/controller can correct measured shaft error, but the result still depends on encoder resolution, bandwidth, noise, tuning, settling, and motor capability.
2. Use a fixed synchronous timing-belt reduction as the first practical route to smaller output command increments and the 10-arcsecond stretch target, provided measured belt errors remain within the benchmark.
3. Compare the belt stage with a harmonic/strain-wave unit if a suitable unit is available and measured gearbox error justifies its cost.
4. Keep planetary as a viable candidate if its backlash is stable enough for directional control, take-up, and calibrated compensation; its uncompensated and compensated bidirectional errors must both be measured.
5. Do not use a CVT in the first precision prototype. Evaluate it only after the fixed-ratio system has a baseline accuracy and repeatability error budget.

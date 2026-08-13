# Angular Precision Benchmark: 100-Arc-Second Requirement, 10-Arc-Second Stretch

## Purpose

This benchmark tests physical output-shaft performance. It does not infer accuracy from motor full steps, microsteps, or encoder counts. The final claim must be based on an independent angular reference and recorded raw measurements.

## Targets

There are two targets at the final geared output shaft:

- **Strict project goal:** demonstrate performance within `100 arc-seconds`.
- **Stretch goal:** achieve approximately `10 arc-seconds`.

The system passes the main project benchmark if it meets the 100-arcsecond criterion. Results between 10 and 100 arc-seconds are a successful project result but do not meet the stretch goal. A result near or below 10 arc-seconds should be reported as stretch-goal performance, subject to measurement uncertainty.

```text
10 arc-sec = 10 / 3600 degree = 48.485 microradians
linear displacement at radius r = r * 48.485e-6
```

For example, at a 100 mm test radius, 10 arc-seconds corresponds to approximately 4.85 micrometres of tangential motion. This illustrates why an ordinary ruler, low-cost potentiometer, or uncalibrated camera cannot validate the requirement.

## Measurement Arrangement

1. Mount the motor, transmission, output encoder, and load on a rigid base.
2. Measure the final output shaft, not only the motor shaft.
3. Use an independent reference instrument such as a calibrated autocollimator, rotary angle calibrator, or angular interferometer. The reference instrument's uncertainty should be no worse than 2 arc-seconds, preferably 1 arc-second or less.
4. If the reference instrument is unavailable, label the result as an encoder-based characterization rather than an independent accuracy validation.
5. Warm up the electronics and mechanics using a documented duration and operating pattern before collecting results.
6. Record temperature, supply voltage, driver current, microstep setting, gear ratio, load, speed, controller gains, encoder counts, reference angle, and timestamps.

The encoder is feedback for control; it is not independent evidence if the same encoder is used to calculate the reported error.

## Test Sequence

### 1. Static Accuracy Grid

Choose at least 11 target angles spanning the intended operating range, including both end regions and zero. At each target:

- Approach from the positive direction and wait for a fixed settling time.
- Record the reference angle and encoder angle after settling.
- Return to the origin before the next target if the mechanism permits it.
- Repeat the complete grid at least 5 times.

Calculate the error at target `i` as:

```text
error_i = measured_reference_angle_i - commanded_angle_i
```

Report maximum absolute error, mean error, standard deviation, and a plot of error against angle. A linear fit may be removed only if the reason for doing so is explicitly stated; uncorrected and corrected results must not be mixed.

### 2. Bidirectional Repeatability and Backlash

Use at least 10 repeated approaches to the same targets from each direction. Report:

- Repeatability as the maximum range and standard deviation of settled angles.
- Directional hysteresis as the difference between the positive- and negative-approach means.
- Lost motion/backlash as the smallest commanded reversal that produces a reference-instrument response.

Do not call a system 10-arcsecond repeatable if its bidirectional hysteresis is larger than 10 arc-seconds.

### 3. Small-Step Staircase

Command steps around the target size, for example 2, 5, 10, 20, and 50 arc-seconds. Use a fixed settling time and repeat each step at least 20 times. Compare the commanded step with the independent reference displacement.

This separates command resolution from usable motion. A command increment is not demonstrated as physically useful unless the reference instrument detects it consistently and the resulting settled angle is repeatable.

### 4. Drift and Disturbance

Hold the output shaft at a fixed target for at least 30 minutes and record the reference angle continuously. Repeat under the expected load and at the minimum and maximum planned operating speeds. Report peak-to-peak drift, RMS noise, and temperature correlation.

## Acceptance Criteria

The following separates the mandatory benchmark from the stretch target:

| Metric | Proposed criterion |
| --- | --- |
| **Mandatory static accuracy** | Maximum absolute error <= 100 arc-sec over the defined range |
| **Stretch static accuracy** | Maximum absolute error approximately <= 10 arc-sec over the defined range |
| Mandatory unidirectional repeatability | 95% of settled results within +/- 50 arc-sec |
| Stretch unidirectional repeatability | 95% of settled results within +/- 5 arc-sec |
| Bidirectional hysteresis | Measure and report; it must be included in the 100 arc-sec result |
| Mandatory small-step response | 100 arc-sec command detected in at least 90% of trials |
| Stretch small-step response | 10 arc-sec command detected in at least 90% of trials |
| Long-term drift | Report separately; no pass claim until a limit is agreed |
| Measurement uncertainty | Reference uncertainty <= 20 arc-sec for the mandatory claim; <= 2 arc-sec preferred for the stretch claim |

The acceptance result must include the uncertainty budget. The measured result should be reported with the instrument uncertainty rather than as an unsupported single number. For a credible stretch-goal claim, the reference uncertainty should be substantially below 10 arc-seconds.

## Resolution Feasibility Checks

For a `1.8 degree` motor, the output command increment is:

```text
6480 / (microsteps_per_full_step * reduction_ratio) arc-sec
```

The selected encoder must also be evaluated by output-shaft counts per revolution:

```text
arc-sec per count = 1,296,000 / counts_per_revolution
```

At least 129,600 counts/revolution are needed for a nominal 10-arc-second count spacing. This is only a quantisation check. Encoder scale error, eccentricity, mounting error, noise, backlash, and thermal drift still require measurement.

For design screening, a 1.8-degree motor at 32 microsteps produces 202.5 arc-seconds per motor command. Therefore:

- Approximately 2:1 total reduction is needed to make the nominal command increment about 100 arc-seconds.
- Approximately 20:1 total reduction is needed to make the nominal command increment about 10 arc-seconds.

These ratios are resolution estimates only. They do not guarantee either target because backlash, compliance, microstep nonlinearity, encoder error, and missed steps can dominate the physical result.

## Evidence To Preserve

- Raw timestamped command, encoder, and independent-reference data.
- Instrument model, calibration date, range, resolution, and uncertainty.
- Mechanical setup photograph or drawing with the measurement point identified.
- Firmware version, configuration, and controller gains.
- A script or spreadsheet that calculates all reported metrics from raw data.
- Test conditions and any excluded trials with a stated reason.

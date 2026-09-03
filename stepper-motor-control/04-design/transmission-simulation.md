# Transmission and Closed-Loop Simulation

## Purpose

The mechanical options can be screened in simulation before fabrication. The simulation should answer:

- Does a selected motor and reduction produce enough nominal command resolution?
- How much accuracy margin is consumed by backlash, compliance, runout, and encoder quantisation?
- Does closed-loop output feedback correct the motor's quantisation error?
- At what point does adding reduction make transmission error worse than the resolution benefit?

## Feasibility Assessment

The 100-arcsecond strict goal is achievable in principle with a 0.9-degree motor, output-side encoder, deterministic closed-loop control, and a mechanically stable direct-drive or low-error fixed-ratio arrangement. This is conditional on encoder accuracy, mounting, settling, noise, and independent validation.

The approximately 10-arcsecond stretch goal is much harder but not ruled out. It requires substantially better mechanical repeatability and measurement uncertainty, with backlash, compliance, runout, thermal drift, and encoder error all controlled or calibrated. ML-assisted pulse correction may reduce repeatable residual error, but it cannot make an unstable or unobservable mechanical transmission accurate. The project should therefore treat 100 arc-seconds as the credible engineering target and 10 arc-seconds as an experimental stretch result.

For a planetary gearbox, the simulation can be made more specific than a generic ratio block. We first model the ideal gear kinematics, then add the measured non-ideal behaviour of the actual gearbox.

## Planetary Gearbox Model

For a simple planetary set with the sun as input, carrier as output, and the ring fixed, the Willis relation gives:

```text
(omega_s - omega_c) / (omega_r - omega_c) = -N_r / N_s
omega_r = 0
reduction R = omega_s / omega_c = 1 + N_r / N_s
```

The tooth-count compatibility condition is:

```text
N_r = N_s + 2 * N_p
```

For multiple planetary stages, multiply the stage ratios. The simulator should use the real sun, planet, and ring tooth counts from the selected gearbox rather than assuming a catalogue ratio is exact.

The ideal output angle is then:

```text
theta_output_ideal = theta_sun / R
```

The non-ideal planetary model should add the following terms:

```text
theta_output = theta_output_ideal
             + backlash_dead_zone
             + torsional_compliance(load_torque)
             + mesh_transmission_error(theta)
             + bearing_and_carrier_runout(theta)
             + thermal_drift(time)
```

The most important input is output-side backlash or lost motion, preferably measured under the expected preload. If only input-side backlash is available, it must be converted through the ratio and documented. Mesh transmission error should be represented initially as a periodic function whose frequency is based on the gear tooth count; later it should be replaced by a measured angle map. Compliance should vary with load, because a gearbox can appear accurate at no load and move differently when the output load reverses.

The closed-loop simulation then places the output encoder after this error block. The controller sees the gearbox error and attempts to correct it. A repeatable periodic error may be partly mapped and compensated, but backlash, changing load, friction, thermal drift, and encoder uncertainty cannot be assumed to disappear.

## What Closed Loop Improves

Closed-loop output feedback can substantially improve the direct-drive baseline and same-direction positioning. It can correct:

- Motor command quantisation when the controller can issue a useful correction.
- Repeatable motor and transmission position error.
- Slow drift visible to the encoder.
- Some periodic error if it is repeatable and mapped.
- Disturbances that are within motor torque, encoder bandwidth, and controller authority.

Closed loop does not automatically remove bidirectional backlash. If the output target is approached from the opposite direction, the motor may rotate through the gearbox lost-motion gap while the output shaft remains stationary. The controller can detect the remaining error and continue commanding motion, but it cannot make the output respond until the gap is taken up. This creates direction-dependent hysteresis and may make a gearbox with large backlash fail the bidirectional 100-arcsecond benchmark even when its one-direction static error looks good.

The simulation must therefore report at least two cases:

1. **Unidirectional settling:** repeated targets approached from one direction. This estimates what closed-loop correction can achieve when the backlash state is controlled.
2. **Bidirectional settling:** targets approached alternately from both directions. This exposes lost motion and hysteresis that closed loop cannot simply subtract away.

Backlash compensation can improve results if the backlash is stable, measurable, and the mechanism can safely apply preload. It should be treated as a calibrated control feature, not as proof that the mechanical backlash no longer exists.

## Algorithmic Backlash Handling

The closed-loop controller can use several strategies:

1. **Directional approach control:** Always approach the final target from the same direction. If the target is crossed, move beyond it and return using the selected direction rather than accepting an uncontrolled reversal.
2. **Backlash take-up routine:** After a direction change, command a calibrated take-up angle before trusting the output position. The output encoder confirms when the shaft begins responding.
3. **Backlash state estimator:** Track the current direction, estimated tooth clearance, and whether the transmission is loaded against one flank. Use this state to adjust the motor-side command.
4. **Identified hysteresis map:** Measure positive and negative approaches over the operating range and compensate the repeatable difference using a lookup table or fitted model.
5. **Controlled preload or dither:** Apply a small safe bias or dither to keep the transmission loaded against one side. This may reduce reversals but can add vibration, heat, and noise.
6. **Adaptive compensation:** Update the backlash estimate when the measured response differs from the expected response, while limiting adaptation so noise is not learned as mechanical error.

The best initial strategy is directional approach control plus a measured backlash take-up routine. A lookup-table or adaptive method can be added after repeatability data exists. The simulator should compare uncompensated and compensated cases, including backlash variation between trials.

## Pulse Nudging and Learned Compensation

The output encoder makes a pulse-nudging strategy possible. After the controller reaches the neighbourhood of a target, it can issue a small burst of motor micro-pulses, wait for the mechanical response, and use the encoder to determine whether the output moved toward the target. Repeated bursts can search for a better settled position or take up a known direction-dependent gap.

The nudge size must be selected from measured motor torque, driver current, friction, and transmission stiffness. A nominal microstep is not guaranteed to move the shaft, especially inside backlash or below static-friction torque. The controller should measure the response to a pulse burst rather than assume that each pulse produces a fixed angular displacement.

An ML or adaptive model can sit above the deterministic feedback loop. Suitable inputs include target angle, measured angle, direction, reversal history, encoder error, recent pulse bursts, temperature, speed, and load estimate. The model could predict the next pulse-burst size, backlash take-up distance, periodic-error correction, or feed-forward motor command.

The deterministic controller must retain authority to limit pulse rate, current, position error, temperature, and motion range. A safe fallback should use ordinary directional approach and measured take-up when the model is uncertain. Train and test on separate directions, loads, temperatures, and gearbox states so the model does not merely memorize one mechanism condition. Report ordinary closed-loop and ML-assisted results separately.

### Proposed Learning Target

The first ML model should predict a bounded residual correction rather than the entire motor command:

```text
predicted_correction = f(target_angle, measured_angle, error,
                         direction, reversal_history, recent_pulses,
                         temperature, speed, load_estimate)
```

The output can be one of:

- Additional motor micro-pulses in the current direction.
- A backlash take-up pulse count after reversal.
- A feed-forward correction in output arc-seconds converted into motor pulses.
- A confidence value used to decide whether to trust the prediction or use the fixed fallback.

Start with an interpretable lookup table, linear model, small regression model, or small decision tree before trying a neural network. The training label should be the correction that reduced independently measured final output error, not simply the encoder error used by the feedback loop. This avoids training the model to reproduce encoder noise or controller behaviour without improving physical accuracy.

The model should be trained from repeated trajectories that include positive and negative approaches, multiple target angles, intentional reversals, temperature changes, and representative loads. The independent angular reference is required for final evaluation even if the model is trained using the output encoder. A model that performs well only on the same gearbox state and trajectory used for training is not evidence of improved accuracy.

Algorithmic compensation is most credible when:

- The output encoder is genuinely on the load side.
- The backlash is repeatable over time, temperature, speed, and load.
- The controller knows the direction and has enough motor authority to take up the gap.
- The target is allowed a defined settling time.
- The independent reference validates both directions rather than only the compensated direction.

Compensation cannot guarantee accuracy if the clearance changes with wear, load torque, temperature, lubrication, or structural deflection. It also cannot correct an unobservable output state during the interval in which the motor moves but the output remains stationary.

### Planetary Simulation Inputs

| Input | Initial use |
| --- | --- |
| Sun/ring/planet tooth counts | Calculate ideal stage ratio and mesh frequencies. |
| Number of stages | Multiply ideal ratios and accumulate error sources. |
| Rated or measured backlash | Set the reversal dead zone at the output. |
| Torsional stiffness | Convert load torque into angular deflection. |
| Mesh transmission-error amplitude and phase | Represent periodic gear error before measured maps are available. |
| Carrier/bearing runout | Add once-per-revolution or stage-periodic output error. |
| Load torque and direction | Test load-dependent compliance and hysteresis. |
| Encoder counts, error, and noise | Simulate the actual feedback measurement. |

The current script keeps the transmission implementation intentionally compact. Its `reduction`, `backlash_arcsec`, `compliance_arcsec`, and `runout_arcsec` fields are the first-order planetary representation. The next implementation step is to add tooth-count-derived ratio and mesh-frequency terms once a candidate planetary gearbox is selected.

When the illustrative configuration is run, the example planetary can show a smaller nominal command increment but a larger total error because its placeholder backlash is larger than the available accuracy margin. This output is a demonstration of sensitivity, not a prediction of a particular gearbox. Replace every illustrative planetary value with the selected unit's datasheet value or a measured value before using the result in a design decision.

The first model is intentionally simple and transparent. It is an error-budget model, not a replacement for CAD, finite-element analysis, multibody dynamics, or a calibrated experiment.

## Modelled Chain

```text
target angle
    -> quantised motor command
    -> fixed transmission ratio
    -> backlash and compliance
    -> periodic runout/eccentricity
    -> physical output angle
    -> encoder quantisation/noise
    -> closed-loop correction
```

The model can compare:

- Direct drive.
- A fixed synchronous timing-belt reduction.
- Planetary or harmonic stages represented by measured/specification backlash and cyclic error.
- Different motor step angles and microstep settings.
- Different output encoder counts per revolution.

## Parameters

The initial script uses these parameters:

| Parameter | Meaning |
| --- | --- |
| `step_angle_deg` | Motor full-step angle, for example 0.9 or 1.8 degrees. |
| `microsteps` | Driver microstep setting. |
| `reduction` | Motor angle divided by output angle. |
| `backlash_arcsec` | Bidirectional lost motion at the output. |
| `compliance_arcsec` | Load-dependent static output deflection. |
| `runout_arcsec` | Sinusoidal once-per-output-revolution error amplitude. |
| `encoder_counts` | Output encoder counts per revolution. |
| `encoder_noise_arcsec` | Random measurement noise standard deviation. |
| `correction_iterations` | Number of simulated closed-loop settling corrections. |

## Interpretation

The direct-drive 0.9-degree, 32-microstep case has a nominal motor command increment of 101.25 arc-seconds. A 2:1 reduction changes this to 50.625 arc-seconds. The simulation should not declare either configuration accurate unless the complete error distribution, including bidirectional motion and measurement uncertainty, remains within the benchmark.

The model is especially useful for finding crossover points. For example, a 2:1 belt stage may improve resolution, but if it contributes more than approximately 50 arc-seconds of hysteresis and compliance, it may be worse than direct drive for the 100-arcsecond requirement.

## Planned Model Extensions

The first script does not yet model electromagnetic torque in detail. Later versions can add:

- Motor electrical equations and current-loop behaviour.
- Detent torque and nonlinear torque-angle curves.
- Load inertia, acceleration, resonance, and missed-step conditions.
- Belt tooth meshing, tension, pulley eccentricity, and temperature-dependent stiffness.
- Harmonic-drive cyclic transmission error and load-dependent hysteresis.
- Real encoder interpolation and installation-error maps.
- Controller latency, sampling, filtering, and saturation.
- Monte Carlo tolerance analysis and parameter fitting from measured data.

## Running The Initial Model

From the project root:

```text
python3 06-implementation/analysis/transmission_simulation.py
```

The script uses only the Python standard library and prints a comparison table for direct drive, a 2:1 belt stage, and a 20:1 stage. Its outputs are screening results; measured component parameters must replace the illustrative defaults before design decisions are finalized.

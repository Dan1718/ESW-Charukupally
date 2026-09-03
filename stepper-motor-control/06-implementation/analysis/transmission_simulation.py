#!/usr/bin/env python3
"""Screen fixed reductions and output-side closed-loop error.

This is an intentionally small error-budget model. It is not a motor,
multibody, or finite-element simulation.
"""

from dataclasses import dataclass
from math import pi, radians, sin
from random import Random


ARCSEC_PER_REV = 1_296_000.0


@dataclass(frozen=True)
class Configuration:
    name: str
    step_angle_deg: float
    microsteps: int
    reduction: float
    backlash_arcsec: float
    compliance_arcsec: float
    runout_arcsec: float
    encoder_counts: int
    encoder_noise_arcsec: float
    correction_iterations: int = 20
    mesh_cycles_per_output_rev: float = 0.0
    mesh_error_arcsec: float = 0.0

    @property
    def motor_increment_arcsec(self) -> float:
        return self.step_angle_deg * 3600.0 / self.microsteps

    @property
    def output_increment_arcsec(self) -> float:
        return self.motor_increment_arcsec / self.reduction

    @property
    def encoder_increment_arcsec(self) -> float:
        return ARCSEC_PER_REV / self.encoder_counts


def quantise(value: float, increment: float) -> float:
    return round(value / increment) * increment


def physical_output(
    config: Configuration,
    motor_command_arcsec: float,
    previous_output_arcsec: float,
    direction: int,
) -> float:
    ideal_output = motor_command_arcsec / config.reduction

    # A simple dead-zone model for reversal-induced lost motion.
    movement = ideal_output - previous_output_arcsec
    if direction != 0 and movement * direction < 0:
        ideal_output = previous_output_arcsec + movement
    backlash = direction * config.backlash_arcsec / 2.0

    # Periodic output error represents eccentricity or cyclic transmission error.
    output_phase = 2.0 * pi * (ideal_output / ARCSEC_PER_REV)
    periodic_error = config.runout_arcsec * sin(output_phase)
    mesh_phase = output_phase * config.mesh_cycles_per_output_rev
    mesh_error = config.mesh_error_arcsec * sin(mesh_phase)
    return ideal_output + backlash + config.compliance_arcsec + periodic_error + mesh_error


def settle_target(config: Configuration, target_arcsec: float, previous_output: float, rng: Random) -> float:
    motor_command = quantise(
        target_arcsec * config.reduction,
        config.motor_increment_arcsec,
    )
    current_output = previous_output
    direction = 0

    for _ in range(config.correction_iterations):
        requested_output = motor_command / config.reduction
        delta = requested_output - current_output
        new_direction = 0 if abs(delta) < 1e-12 else (1 if delta > 0 else -1)
        direction = new_direction or direction
        current_output = physical_output(config, motor_command, current_output, direction)
        measured = quantise(current_output, config.encoder_increment_arcsec)
        measured += rng.gauss(0.0, config.encoder_noise_arcsec)
        output_error = target_arcsec - measured
        motor_command = quantise(
            motor_command + output_error * config.reduction,
            config.motor_increment_arcsec,
        )

    return current_output


def evaluate(config: Configuration) -> dict[str, float]:
    rng = Random(42)
    targets = [i * 3600.0 for i in range(-5, 6)]
    results = []
    previous = 0.0
    for target in targets:
        result = settle_target(config, target, previous, rng)
        results.append(result - target)
        previous = result

    absolute = [abs(value) for value in results]
    mean = sum(results) / len(results)
    rms = (sum(value * value for value in results) / len(results)) ** 0.5
    return {
        "command_arcsec": config.output_increment_arcsec,
        "encoder_arcsec": config.encoder_increment_arcsec,
        "max_abs_error_arcsec": max(absolute),
        "mean_error_arcsec": mean,
        "rms_error_arcsec": rms,
        "repeatability_range_arcsec": max(results) - min(results),
    }


def main() -> None:
    configurations = [
        Configuration("direct_0.9deg", 0.9, 32, 1.0, 0.0, 0.0, 2.0, 262_144, 0.5),
        Configuration("belt_2to1", 0.9, 32, 2.0, 8.0, 4.0, 2.0, 262_144, 0.5),
        Configuration("belt_20to1", 0.9, 32, 20.0, 20.0, 8.0, 2.0, 262_144, 0.5),
        # Illustrative only: replace ratio, backlash, and mesh error with
        # values from the selected planetary gearbox datasheet or tests.
        Configuration("planetary_example", 0.9, 32, 27.0, 120.0, 12.0, 4.0, 262_144, 0.5, mesh_cycles_per_output_rev=27.0, mesh_error_arcsec=8.0),
    ]
    print("configuration command encoder max_abs rms range")
    for config in configurations:
        result = evaluate(config)
        print(
            f"{config.name:16} "
            f"{result['command_arcsec']:7.2f} "
            f"{result['encoder_arcsec']:7.2f} "
            f"{result['max_abs_error_arcsec']:7.2f} "
            f"{result['rms_error_arcsec']:7.2f} "
            f"{result['repeatability_range_arcsec']:7.2f}"
        )


if __name__ == "__main__":
    main()

# CAD and Mechanical Prototype Workflow

## Purpose

CAD can help develop and compare the planetary, belt, and direct-drive arrangements before fabrication. It can validate geometry, packaging, interference, shaft support, encoder mounting, assembly, and nominal ratios. CAD alone cannot validate arc-second accuracy because real backlash, elastic deformation, surface finish, bearing runout, material properties, and thermal effects are not captured reliably by nominal geometry.

## Recommended CAD Stack

Any parametric mechanical CAD package is suitable. The project can use:

- FreeCAD for an open-source parametric model and exportable assemblies.
- Fusion 360, Onshape, or SolidWorks if the team already has access and experience.
- A gear generator or involute-gear workbench for sun, planet, and ring geometry.
- A separate Python parameter script for ratio and tooth-count calculations.
- The transmission error-budget simulator for backlash and compliance studies.

The software choice is secondary to keeping the model parameter-driven and recording the assumptions.

## Planetary CAD Model

Create separate parametric parts for:

1. Sun gear.
2. Planet gear.
3. Internal ring gear.
4. Planet carrier.
5. Motor shaft and coupler.
6. Output shaft and bearings.
7. Encoder disc, encoder head, and mounting bracket.
8. Housing, spacers, preload features, and fasteners.

Use a common module, pressure angle, and face width for the gear set. Enforce the tooth-count compatibility condition:

```text
N_ring = N_sun + 2 * N_planet
```

For sun input, fixed ring, and carrier output, calculate the nominal reduction as:

```text
R = 1 + N_ring / N_sun
```

The CAD assembly should use concentricity constraints for the sun, ring, and carrier, equal angular spacing for the planet pins, and revolute joints for all rotating parts. Verify that every planet meshes with both the sun and ring without interference through a full revolution.

## Backlash and Tolerance Representation

Do not model gears as perfectly touching solids. Add explicit design parameters for:

- Tooth flank clearance.
- Planet-pin positional tolerance.
- Ring-gear runout.
- Shaft and bearing radial play.
- Carrier tilt.
- Encoder-disc eccentricity.
- Coupling misalignment.
- Housing deformation and mounting flatness.

Create at least three configurations:

- Nominal geometry.
- Best-case minimum clearance.
- Worst-case accumulated tolerance.

Use the transmission simulator to translate these mechanical assumptions into arc-seconds. CAD dimensions should be linked to the simulation parameters where practical.

## Encoder Placement

The encoder should be mounted on the final output shaft. The CAD model must show:

- Rigid encoder-head reference mounting.
- Disc-to-head air gap or sensor spacing.
- Axial and radial adjustment features.
- Access for alignment and calibration.
- Protection against belt, gear, or housing movement.
- A separate independent measurement target or fixture.

Mounting the encoder on the motor shaft would hide gearbox backlash and output-shaft errors from the feedback loop, so that arrangement is not the preferred precision architecture.

## Prototype Stages

### Stage 1: Packaging Prototype

Use CAD and 3D printing to check component fit, shaft spacing, encoder clearance, fastener access, and assembly order. This stage does not make an accuracy claim.

### Stage 2: Functional Transmission Prototype

Use low-cost printed or machined gears to test rotation, ratio, meshing, lubrication, bearing support, and backlash measurement. Do not use printed gears as evidence of 100-arcsecond accuracy.

### Stage 3: Precision Mechanical Prototype

Use an appropriate commercial planetary gearbox or precision-machined parts, rigid bearing-supported shafts, a controlled preload, and a calibrated output encoder. Measure backlash, hysteresis, runout, compliance, and thermal drift before integrating compensation.

### Stage 4: Hardware-in-the-Loop Validation

Connect the real encoder and transmission to the controller. Compare the measured output with the simulation model, fit the unknown error parameters, and rerun the benchmark for unidirectional and bidirectional approaches.

## CAD Motion Study Limits

A CAD motion study can show nominal ratio, interference, and gross motion. It usually will not predict:

- Actual gear flank backlash under load.
- Microstep torque-angle nonlinearity.
- Static friction and stick-slip.
- Bearing runout at the required angular scale.
- Encoder interpolation and installation error.
- Temperature-dependent dimensional changes.
- Controller timing, pulse nudging, or ML compensation.

Those effects belong in the transmission simulation and physical measurements.

## Files To Preserve

- Parametric CAD source files.
- Exported STEP files for parts and assembly.
- Gear tooth-count and ratio worksheet.
- Tolerance and clearance table.
- Assembly drawings with bearings, preload, and encoder datums.
- Versioned renders or screenshots.
- Links between CAD dimensions, simulation parameters, and measured hardware.

# Component Selection

## Objective

Select the components required for a safe, measurable, and sufficiently precise closed-loop stepper-motor prototype.

## Selection Order

1. Record available lab hardware.
2. Establish electrical, mechanical, timing, and measurement constraints.
3. Identify candidate components.
4. Compare candidates against the requirements.
5. Select a preliminary bill of materials.
6. Verify compatibility using datasheets and bench tests.

## First Selection Pass

The first pass is limited to the four core components:

- NEMA 17 stepper motor
- Motor driver
- Rotary encoder for the final geared output shaft
- Microcontroller

Power, protection, mechanical hardware, and independent measurement equipment will be considered after the core motion-control chain is defined.

## Research and Decision Workflow

Component selection will be evidence-driven and iterative. The team will provide resources such as datasheets, product pages, application notes, forum discussions, papers, and mentor guidance. Each resource will be reviewed and integrated into the relevant component document.

For every candidate component, the documentation should cover:

- Required specifications and why they matter
- Candidate parts and relevant variants
- Electrical, mechanical, timing, and software interfaces
- Advantages and disadvantages
- Compatibility with the other core components
- Effect on resolution, accuracy, precision, and repeatability
- Noise, thermal, safety, and reliability considerations
- Cost, availability, and procurement constraints
- Claims that require bench verification
- Sources and confidence in the information

The final selection should include a comparison matrix and a clearly stated rationale. Until the comparison is complete, component choices remain provisional.

## Citation Requirements

Technical claims must be traceable to their source. Every resource review should include:

- A clickable source link
- The source title, author or organization, and access date when available
- A direct quote for important claims or specifications
- The page, section, table, figure, or timestamp when available
- A clear distinction between the source's claim, our interpretation, and our own measurement

Official datasheets and manuals should be preferred for component specifications. Forum posts and informal sources may provide useful engineering context, but their claims must be labeled as informal and independently verified before influencing a final decision.

## Resource Review Record

For each supplied resource, record:

```text
## Resource

## Resource type and authority

## Main technical information

## Relevant specifications or claims

## Implications for this project

## Advantages identified

## Disadvantages and risks identified

## Claims requiring independent verification

## Components or decisions affected

## Source link
```

## Components To Select

- NEMA 17 stepper motor: form factor selected; exact motor specifications still need to be recorded
- Motor driver
- Rotary encoder
- Microcontroller
- Power supply
- Voltage regulation and protection
- Mechanical coupling and mounting hardware
- Independent angular measurement instrument
- Wiring, connectors, and interface components

## Important Compatibility Checks

- Motor phase current versus driver current range
- Motor supply voltage versus driver rating
- Driver logic-level compatibility with the microcontroller
- Step and direction pulse timing
- Encoder resolution, interface, and maximum update rate
- Encoder mechanical mounting and shaft coupling
- Available control-loop sampling rate
- Thermal dissipation at the expected current
- Power-supply current capacity
- Electrical grounding and noise susceptibility

## Resolution-Related Checks

- Calculate the nominal angular increment from motor step angle, microstepping, and any reduction ratio.
- Compare encoder quantization with the target angular precision.
- Check whether the motor and driver can produce enough torque for basic motion and holding at the selected microstepping setting; do not optimize for excess torque.
- Do not treat nominal microstep resolution as guaranteed physical accuracy.
- Include backlash, coupling compliance, and encoder mounting in the mechanical error budget.

These checks are supported by the supplied research. Lin Engineering states that microstepping increases resolution but does not necessarily increase accuracy, while JKONGMOTOR states that “Mechanical components often introduce more error than the motor itself.” [Lin Engineering](https://www.linengineering.com/news/methods-for-increasing-accuracy-in-stepper-motors) [JKONGMOTOR](https://www.jkongmotor.com/how-to-improve-positioning-accuracy-of-stepper-motors-in-industrial-equipment.html) (accessed 2026-08-13).

## Decision Format

Each component-selection document should contain:

```text
## Requirement

## Candidates considered

## Comparison

## Decision

## Rationale

## Tradeoffs and risks

## Evidence

## Status
```

## Status

The NEMA 17 form factor is fixed by the project brief, but the exact motor may be requested based on the system requirements. No motor part number or specifications have been selected yet. The driver, encoder, microcontroller, power supply, mechanical components, and independent measurement instrument also remain open decisions.

## Initial Mechanical Constraints

- Approximate load: 200 g; the corresponding torque requirement is not yet calculated.
- Required angular resolution: arc-second level.
- Gearing or other mechanical reduction is allowed.
- The required angular range, speed, and exact load geometry remain unspecified. These details are deferred until the basic component choices and prototype arrangement are clearer.

The approximately 200 g load is considered low for the initial design. The motor and driver only need sufficient torque to move and hold the load safely; maximizing torque is not a primary selection objective. Component selection should prioritize precision, accuracy, output-side angular resolution, encoder capability, feedback quality, backlash, stiffness, runout, repeatability, controllability, and ease of characterization.

## Feedback Requirement

The system must use closed-loop feedback. A rotary encoder will measure the final geared output angle, and the controller will use that measurement to reduce the difference between the target and actual positions. The encoder resolution, interface, and mounting method remain open decisions.

The output-side feedback direction is supported by the sub-arcsecond design guide, which states: “Direct-drive with encoder feedback on the load is mandatory.” [Industrial Monitor Direct](https://industrialmonitordirect.com/it/blogs/knowledgebase/05-arcsecond-precision-rotary-motion-motor-encoder-design-guide) (accessed 2026-08-13). The source describes a more demanding system than ours, so this is recorded as rationale for measuring the final output, not as a claim that our geared prototype must use direct drive.

### Transmission Options

Mechanical reduction remains an open design choice. The supplied Lin Engineering article notes that gearing can multiply torque and position-holding capability, while also warning that microstepping and gearing solve different problems. [Lin Engineering](https://www.linengineering.com/news/methods-for-increasing-accuracy-in-stepper-motors) (accessed 2026-08-13).

The Arduino pulley discussion provides a belt-and-pulley concept reference. The diagrams are preserved as evidence:

- [Pulley diagram 1](../../../99-evidence/resources/arduino-pulley-diagram/pulley-diagram-1.jpeg)
- [Pulley diagram 2](../../../99-evidence/resources/arduino-pulley-diagram/pulley-diagram-2.jpeg)
- [Original Arduino discussion](https://forum.arduino.cc/t/what-gears-ratio-use-to-have-more-resolution-in-stepper-motors-laser-engraver/607247)

The pulley diagrams are visual references only. If a belt reduction is considered, belt elasticity, tooth clearance, tension, pulley eccentricity, and output-shaft runout must be characterized before it can support an arc-second claim.

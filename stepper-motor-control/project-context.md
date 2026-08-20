# Project Context

This file defines the working context for the project documentation. It should be updated when the project structure, documentation workflow, or major working assumptions change.

## Project

- Course: Embedded System Workshop (EC3.202)
- Project: Closed-Loop Stepper Control for Precise Angular Motion
- Team: Daniel Vincent, Saketh Naga Sibyala, Suryansh Reddy Charukupally, and Ashwin Hari
- Faculty: A. Sarje
- Mentor: Goutam Sutradhar
- TA: Geethika

## Current Goal

Develop a closed-loop NEMA 17 stepper-motor system with arc-second-level angular resolution and output-side feedback. The system will use a rotary encoder on the final geared output shaft and a controller that reduces target-versus-measured angular error.

The project has just started. No hardware work, implementation, or experiments have been completed yet.

## Current First Task

Select the four core components:

- NEMA 17 stepper motor
- Motor driver
- Rotary encoder
- Microcontroller

Power, protection, mechanical hardware, and independent measurement equipment will be considered after the core motion-control chain is better defined.

## Documentation Structure

The project is organized by lifecycle phase. Documentation and code are kept near the work they describe rather than being split into separate top-level `docs/` and `code/` folders.

```text
stepper-motor-control/
├── 00-overview/                    Project purpose, team, scope, and status
├── 01-requirements/                Requirements and verification status
├── 02-background/                  Technical concepts and external research
├── 03-exploration/                 Alternatives and component selection
│   └── component-selection/
├── 04-design/                     Current system and design decisions
├── 05-experiments/                 Test plans, procedures, and results
├── 06-implementation/              Firmware, analysis, libraries, and tests
├── 07-project-log/                 Chronological progress and meeting record
└── 99-evidence/                    Raw data, images, diagrams, and source index
```

The root `README.md` is the entry point and links to the main documents.

## Documentation Rules

- This conversation is part of the project context.
- Every technical requirement, correction, decision, benchmark target, assumption, and limitation stated during project discussions must be patched into the relevant project document. Chat-only decisions are not considered recorded.
- Decisions must be traceable over time. When a later decision replaces, narrows, or reverses an earlier decision, record the sequence, the original choice, the newly discovered problem or evidence, and the reason for the change. Do not silently overwrite the earlier rationale.
- Relevant technical discussion, design decisions, assumptions, alternatives, tradeoffs, questions, and corrections must be added to the applicable project document.
- Decisions are recorded where they apply, not in a separate generic decision log.
- The chronological project log records when something happened; the relevant design or exploration document records the technical reasoning.
- Supplied resources must be linked, quoted, cited, and connected to the specific content they support.
- Summaries must distinguish source claims, team interpretations, and measurements performed by the team.
- Unknowns remain explicitly marked as open rather than being guessed.
- A decision remains provisional until the required evidence or test is available.
- Repeated resources should be listed once and deduplicated.
- Images, diagrams, raw data, and other supporting material should be preserved under `99-evidence/` when possible.

## Agreed Technical Direction

- The target is arc-second-level angular performance.
- The expected load is low, approximately 200 g, so torque capacity is a feasibility constraint rather than the main optimization target.
- Gearing or other mechanical reduction is allowed.
- The encoder should measure the final geared output shaft.
- Resolution, accuracy, precision, and repeatability must be treated as distinct properties.
- Microstepping alone must not be treated as proof of physical angular accuracy.
- Selection should prioritize output-side measurement, feedback quality, backlash, repeatability, controllability, and characterization.

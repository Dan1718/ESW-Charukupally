# Requirements

Requirements are separated into confirmed requirements from the course brief and project-specific values that still need confirmation.

## Confirmed From Course Brief

| ID | Requirement | Verification status |
| --- | --- | --- |
| REQ-01 | Use a microcontroller to control a NEMA 17 stepper motor through a motor driver. | Not started |
| REQ-02 | Support fine open-loop angular movement. | Not started |
| REQ-03 | Integrate a high-resolution rotary encoder as part of the closed-loop feedback system. | Not started |
| REQ-04 | Continuously track the physical motor-shaft angle. | Not started |
| REQ-05 | Implement a closed-loop algorithm to reduce target-versus-actual angular error. | Not started |
| REQ-06 | Perform noise analysis and mitigation if needed. | Not started |
| REQ-07 | Validate angular precision and movement repeatability using an independent, accurate angular measurement tool. | Not started |

## Values To Confirm

| ID | Parameter | Current value |
| --- | --- | --- |
| REQ-08 | Target angular precision | Strict goal: demonstrate performance within 100 arc-seconds at the final geared output shaft. Stretch goal: approximately 10 arc-seconds |
| REQ-09 | Target repeatability | Strict benchmark: 95% of settled results within +/- 50 arc-seconds. Stretch goal: 95% within +/- 5 arc-seconds; bidirectional hysteresis reported separately |
| REQ-10 | Maximum operating speed | To be confirmed |
| REQ-11 | Motor load and torque requirement | Low-load application; basic torque feasibility is required, but torque capacity is not the primary selection criterion |
| REQ-12 | Angular operating range | To be confirmed |
| REQ-13 | Control-loop sampling rate | To be determined |
| REQ-14 | Supply voltage and current limit | To be determined |
| REQ-15 | Approximate mechanical load | Approximately 200 g; considered a low load for initial component selection |
| REQ-16 | Mechanical reduction | Gearing is permitted if required to achieve the angular-resolution target |

## Requirement Interpretation

The phrase “arc-second range” is recorded as a project goal from the course brief. It must not yet be treated as a demonstrated performance result. The final report should state the measured performance, test conditions, uncertainty, and limitations.

For this project, resolution, precision, accuracy, and repeatability will be tracked separately. A system may have a small commanded increment (resolution) without reaching the requested physical angle (accuracy) or reaching it consistently across trials (repeatability).

Closed-loop feedback is expected to improve error correction, but it does not imply a particular accuracy without specifying the encoder, mechanics, controller, and test method. Direct-drive performance must be estimated from the encoder and then verified experimentally.

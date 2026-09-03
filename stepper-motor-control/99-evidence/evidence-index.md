# Evidence Index

This directory stores raw evidence supporting design and validation claims.

## Evidence Categories

- Datasheets and manuals
- Photographs of hardware and wiring
- Circuit diagrams
- Oscilloscope and logic-analyzer captures
- Encoder and motor measurements
- Raw experiment data
- Analysis scripts and generated plots
- Mentor or faculty guidance

## Citation Standard

Every external resource used in the project should be linked from the relevant document and recorded here. Important claims should include direct quotations and enough location information to be checked. Summaries must not replace citations.

## External Resources

### Steppers and Resolution

- URL: https://www.cloudynights.com/forums/topic/739690-steppers-and-resolution/
- Type: Informal technical discussion
- Relevance: Illustrates the relationship between step angle, microstepping, gear reduction, and angular resolution.
- Used in: `02-background/precision-and-resolution.md`
- Limitation: The discussion contains at least one incorrect or inconsistent numerical calculation. Its claims are not used without independent verification.

### Supplied Research Batch

- [Lin Engineering: Methods for Increasing Accuracy in Stepper Motors](https://www.linengineering.com/news/methods-for-increasing-accuracy-in-stepper-motors)
- [Industrial Monitor Direct: Sub-Arcsecond Rotary Motion](https://industrialmonitordirect.com/it/blogs/knowledgebase/05-arcsecond-precision-rotary-motion-motor-encoder-design-guide)
- [JKONGMOTOR: Improving Stepper Positioning Accuracy](https://www.jkongmotor.com/how-to-improve-positioning-accuracy-of-stepper-motors-in-industrial-equipment.html)
- [iFuture Technology: TTB6600 Driver Listing](https://ifuturetech.org/product/ttb6600-stepper-motor-driver-controller-4a-942v-ttl-32-micro-step/)
- [Arduino Forum: Gear Ratio and Pulley Discussion](https://forum.arduino.cc/t/what-gears-ratio-use-to-have-more-resolution-in-stepper-motors-laser-engraver/607247)
- [Arduino Forum: Stepper Motor Basics](https://forum.arduino.cc/t/stepper-motor-basics/275223/2)
- [ThomasNet: Encoder Buying Guide](https://www.thomasnet.com/articles/automation-electronics/types-of-encoders-a-thomasnet-buying-guide/) (blocked during review; pending)
- [Texas Instruments: SLOA293A](https://www.ti.com/lit/an/sloa293a/sloa293a.pdf) (PDF pending direct review)

## Where Sources Are Used

- Lin Engineering: `02-background/precision-and-resolution.md` and `03-exploration/component-selection/README.md`, for the distinction between microstep resolution and physical accuracy, and for gearing tradeoffs.
- Industrial Monitor Direct: `02-background/precision-and-resolution.md`, `03-exploration/component-selection/README.md`, and `04-design/system-architecture.md`, for load-side feedback and the system-level precision perspective.
- JKONGMOTOR: `03-exploration/component-selection/README.md`, for mechanical-error, torque-margin, and system-level selection considerations.
- iFuture Technology: `03-exploration/component-selection/resource-review.md`, for the preliminary TTB6600 candidate specifications only.
- Arduino pulley discussion: `03-exploration/component-selection/README.md` and local pulley evidence under `99-evidence/resources/arduino-pulley-diagram/`.
- Cloudy Nights: `02-background/precision-and-resolution.md`, for the informal resolution-calculation example and its limitations.
- Additional Cloudy Nights discussions: `02-background/cloudy-nights-related-discussions.md`, as a selectable resource index for gearing, belts, harmonic drives, encoders, backlash, and practical stepper systems.
- ThomasNet and Texas Instruments: not yet used for technical claims because retrieval/review is incomplete.

No project-specific hardware evidence has been added yet.

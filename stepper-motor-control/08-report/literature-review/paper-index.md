# Research Paper Index

## 0. Systems That Explicitly Target Arc-Second or Sub-Arcsecond Performance

These sources are especially important for setting realistic expectations. Many use precision encoders, autocollimators, macro/micro stages, direct-drive actuators, telescope structures, or extensive calibration. They demonstrate that an arc-second claim is a complete metrology and mechanical-system problem, not just a microstep calculation.

### Research Papers and Technical Publications

1. **Optimized Design of a Sub-Arc-Second Micro-Drive Rotary Mechanism Based on the Swarm Optimization Algorithm**. [MDPI Micromachines](https://doi.org/10.3390/mi16101190). **Core comparison.** Explicitly targets sub-arcsecond rotary motion using a precision micro-drive and optimization; hardware and metrology are more demanding than this prototype.
2. **Research on Continuous Error Compensation of a Sub-Arc-Second Macro/Micro Dual-Drive Rotary System**. [MDPI Micromachines](https://doi.org/10.3390/mi13101662). **Core comparison.** Reports large reductions in positioning and repeatability error using macro/micro compensation. Relevant to the idea that a coarse actuator can be combined with a fine correction stage.
3. **Arcsecond-Accuracy Angle Encoders for Automated Assembly Lines**. [MDPI Micromachines](https://doi.org/10.3390/mi12091063). **Core metrology comparison.** Explicitly discusses arc-second absolute angular feedback and the effects of thermal expansion, runout, and load deflection.
4. **High Accuracy Eliminating Image Rotation Control System for Optical Telescope**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0967066125001054). **Supporting.** Uses a stepper-motor drive and high-precision position sensing in an optical telescope context; useful for comparing telescope-level requirements with the prototype.
5. **Design and Development of Telescope Control System and Software for the 50/80 cm Schmidt Telescope**. [ResearchGate](https://www.researchgate.net/publication/320613675_Design_and_development_of_telescope_control_system_and_software_for_the_5080_cm_Schmidt_telescope). **Supporting.** Reports a target of less than 10 arc-sec RMS pointing and less than 1 arc-sec unguided tracking error over five minutes; verify full paper and measurement definitions.
6. **Telescope Pointing: What's the Problem?**. [Patrick Wallace PDF](https://galex.caltech.edu/~srk/TP/Literature/Wallace_Telescope_Pointing.pdf). **Supporting.** Technical treatment of telescope pointing, encoders, zero points, and error sources.
7. **High-Precision Motorized Rotary Stages and Goniometers**. [PI technical overview](https://www.pi-usa.us/en/products/motorized-rotary-stages-goniometers). **Background.** Not a research paper, but useful commercial comparison of direct encoders, stage resolution, and accuracy claims. Product specifications must not be copied without checking the actual model datasheet.
8. **The Accuracy of Rotary Encoders**. [Renishaw technical paper search](https://www.google.com/search?q=Renishaw+The+accuracy+of+rotary+encoders+white+paper). **Background.** Relevant to encoder accuracy, interpolation, installation, and calibration; locate the original Renishaw document before citing.

### Open Projects, Builds, and Forums

These are not peer-reviewed evidence. They are useful for practical mechanisms, failure modes, measurement ideas, and real-world expectations.

1. **OnStep: Open-Source Telescope Controller**. [OnStep wiki](https://onstep.groups.io/g/main/wiki/home). **Adjacent project.** Open telescope controller ecosystem using stepper motors, reduction, encoders, and tracking control.
2. **Tracking Precision: How Many Arc-Seconds per Micro-Step?**. [Cloudy Nights discussion](https://www.cloudynights.com/forums/topic/500017-tracking-precision-how-many-arc-seconds-per-micro-step/). **Core practical discussion.** Reports microstep positional errors and discusses the tradeoff between large reduction ratios, gear errors, and belt/timing errors.
3. **Arcsecond to None**. [Design Engineering feature](https://www.design-engineering.com/features/arcsecond-to-none/). **Adjacent practical article.** Discusses high-precision angular drive design and telescope-style requirements.
4. **Motor Calculator and Telescope Drive Resolution**. [BB Astro Design](https://www.bbastrodesigns.com/motorCalc.htm). **Adjacent calculator/project resource.** Useful for exploring encoder counts, gear ratios, and telescope-axis arc-seconds; calculations still require independent verification.
5. **This Is a Project and It's About Encoders**. [Practical Machinist forum](https://www.practicalmachinist.com/forum/threads/this-is-a-project-and-its-about-encoders.383318/). **Adjacent practical discussion.** Real-world discussion of encoder tick density and the difficulty of achieving arc-second angular resolution.
6. **Low-Speed Direct-Drive 3-Phase Motor and Controller**. [Hackaday project](https://hackaday.io/project/9268-telescope-controller/details). **Adjacent project.** Discusses avoiding periodic error and the vibration/drive challenges of telescope tracking.
7. **Can Stepper Motors Be Used for GoTo Telescopes?**. [All About Circuits forum](https://forum.allaboutcircuits.com/threads/low-speed-direct-drive-3-phase-motor-and-controller.183667/). **Adjacent practical discussion.** Telescope tracking, encoders, and very small angular tracking errors.
8. **What Gears Ratio Use to Have More Resolution in Stepper Motors?**. [Arduino Forum](https://forum.arduino.cc/t/what-gears-ratio-use-to-have-more-resolution-in-stepper-motors-laser-engraver/607247). **Adjacent practical discussion.** Pulley reduction concept already preserved in the project evidence directory.
9. **Steppers and Resolution**. [Cloudy Nights discussion](https://www.cloudynights.com/forums/topic/739690-steppers-and-resolution/). **Adjacent practical discussion.** Contains useful reduction examples but also numerical claims that must be independently recalculated.

### What These Sources Show

- Arc-second systems usually measure the load-side output with a high-quality encoder or independent angular instrument.
- Direct drive removes gearbox backlash but does not automatically remove motor cogging, torque ripple, encoder error, runout, or thermal drift.
- High reduction can make the nominal command increment small, but gear and belt transmission error can dominate.
- Macro/micro architectures use a coarse drive for range and a fine actuator or correction loop for final accuracy.
- Telescope projects often report pointing accuracy, tracking error, periodic error, and resolution as different metrics; this project should do the same.
- A forum or product claim is useful for identifying mechanisms and test ideas, but it is not sufficient evidence for the final 100-arcsecond claim.

## 1. Closed-Loop Stepper Motors and Position Control

These are the closest papers to the controller and feedback architecture.

1. **Research on Closed-loop Control of Step Motor Based on Magnetic Encoder**. [ResearchGate](https://www.researchgate.net/publication/361303849_Research_on_Closed-loop_Control_of_Step_Motor_Based_on_Magnetic_Encoder) | [Semantic Scholar PDF](https://pdfs.semanticscholar.org/8678/bea830634c44e3c6b549724ef0508158dddd.pdf). **Core.** Directly relevant to magnetic encoder feedback and closed-loop stepper control.
2. **Encoder-Motor Misalignment Compensation for Closed-Loop Hybrid Stepper Motor Control**. [Springer](https://link.springer.com/chapter/10.1007/978-3-030-11973-7_38) | [ResearchGate](https://www.researchgate.net/publication/333010870_Encoder-Motor_Misalignment_Compensation_for_Closed-Loop_Hybrid_Stepper_Motor_Control). **Core.** Relevant to encoder mounting errors and output-angle accuracy.
3. **An Advanced Closed-Loop Control to Improve the Performance of Hybrid Stepper Motors**. [IEEE Xplore](https://ieeexplore.ieee.org/document/7725965) | [Open PDF copy](https://fab.cba.mit.edu/classes/865.18/motion/steppers/ieee-advanced-step-control-2017.pdf). **Core.** Closed-loop control architecture and performance improvement.
4. **Performance Analysis of Closed-Loop Control Strategies for Hybrid Stepper Motors**. [IEEE Xplore](https://ieeexplore.ieee.org/document/10563771). **Core.** Compare control strategies and evaluation metrics.
5. **A Hybrid Stepper Motor Control Solution Based on a Low-Cost Position Sensor**. [IEEE Xplore](https://ieeexplore.ieee.org/document/8816190). **Core.** Relevant to low-cost encoder/sensor integration.
6. **A Compound Control for Hybrid Stepper Motor Based on PI and Sliding Mode Control**. [IEEE Xplore](https://ieeexplore.ieee.org/document/10741576). **Supporting.** Candidate control structures and disturbance rejection.
7. **Microcomputer Implementation of Optimal Algorithms for Closed-Loop Control of Stepper Motors**. [IEEE Xplore](https://ieeexplore.ieee.org/document/798694). **Supporting.** Historical closed-loop algorithms and embedded implementation.
8. **Closed Loop Low-Velocity Regulation of Hybrid Stepping Motors Amidst Load Torque Disturbances**. [IEEE Xplore](https://ieeexplore.ieee.org/document/382143). **Supporting.** Low-speed regulation and load disturbance rejection.
9. **Position Regulator With Variable Cut-Off Frequency Mechanism for Hybrid Stepper Motors**. [IEEE Xplore](https://ieeexplore.ieee.org/document/9080540). **Supporting.** Position regulator design and bandwidth tradeoffs.
10. **Sliding Mode Control Model of Two-Phase Hybrid Stepping Motor Based on ...**. [IEEE Xplore](https://ieeexplore.ieee.org/document/10715968). **Supporting.** Robust control alternative; title needs full verification.
11. **Enhancing Precision Robotics Through Closed-Loop Control of Hybrid Stepper Motors**. [Springer](https://link.springer.com/chapter/10.1007/978-981-96-9682-6_21). **Verify.** Recent application of closed-loop hybrid stepper control.

## 2. Microstepping, Torque Modulation, and Stepper-Motor Nonlinearity

These papers are important because the nominal microstep angle is not necessarily the physical shaft angle.

1. **Microstepping and High-Performance Control of Permanent-Magnet Stepper Motors**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S019689041400497X) | [ResearchGate](https://www.researchgate.net/publication/277650551_Microstepping_and_high-performance_control_of_permanent-magnet_stepper_motors). **Core.** Microstepping, modelling, and high-performance control.
2. **Influence of Microstepping Signal Shape on Shaft Movement of a Stepper Motor**. [MDPI Energies](https://www.mdpi.com/1996-1073/14/19/6107). **Core.** Directly relevant to command waveform and actual shaft movement.
3. **Microstepping With Nonlinear Torque Modulation for Permanent Magnet Stepper Motors**. [IEEE Xplore](https://ieeexplore.ieee.org/document/6287008) | [ResearchGate](https://www.researchgate.net/publication/254054605_Microstepping_With_Nonlinear_Torque_Modulation_for_Permanent_Magnet_Stepper_Motors). **Core.** Nonlinear torque shaping to improve position behaviour.
4. **Microstepping With Nonlinear Torque Modulation for Position Tracking of Permanent Magnet Stepper Motors**. [IEEE Xplore](https://ieeexplore.ieee.org/document/6161184). **Core.** Position tracking and nonlinear microstep modulation.
5. **Simplified Torque Modulated Microstepping for Position Control of Permanent Magnet Stepper Motors**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0957415816000222). **Core.** Practical control implementation and torque modulation.
6. **Novel Microstepping Technique for Disc Rotor Type Stepper Motor Drive**. [Academia](https://www.academia.edu/17388153/Novel_microstepping_technique_for_disc_rotor_type_stepper_motor_drive). **Supporting.** Alternative microstepping method; full bibliographic details require verification.
7. **Modelling and Simulation of a Stepper Motor Speed/Position Control**. [Academia](https://www.academia.edu/28757893/MODELLING_AND_SIMULATION_OF_A_STEPPER_MOTOR_SPEED_POSITION_CONTROL). **Supporting.** Background model and speed/position control.

## 3. Harmonic and Strain-Wave Drive Error

These papers are relevant to the harmonic-drive option and to understanding why low nominal backlash does not imply zero output error.

1. **Measurement and Analysis of Backlash on Harmonic Drive**. [IOP PDF](https://iopscience.iop.org/article/10.1088/1757-899X/542/1/012005/pdf) | [ResearchGate](https://www.researchgate.net/publication/334262323_Measurement_and_analysis_of_backlash_on_harmonic_drive). **Core.** Directly relevant to backlash measurement.
2. **Modeling of Transmission Compliance and Hysteresis Considering Degradation in a Harmonic Drive**. [MDPI Applied Sciences](https://www.mdpi.com/2076-3417/11/2/665) | [ResearchGate](https://www.researchgate.net/publication/348425005_Modeling_of_Transmission_Compliance_and_Hysteresis_Considering_Degradation_in_a_Harmonic_Drive). **Core.** Compliance, hysteresis, and degradation.
3. **Data-Driven Modeling and Analysis of Transmission Error in Harmonic Drive Systems**. [arXiv](https://arxiv.org/abs/2310.15875) | [HTML](https://ar5iv.labs.arxiv.org/html/2310.15875). **Core.** Transmission-error modelling and data-driven compensation.
4. **Study on the Degradation Law of Harmonic Gear Drive Backlash With Wear ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S1350630722005878). **Supporting.** Backlash change over service life.
5. **Study on Gear Contact Stiffness and Backlash of Harmonic Drive Based on ...**. [SAGE](https://journals.sagepub.com/doi/10.1177/13506501241233843). **Supporting.** Contact stiffness and backlash modelling.
6. **A Novel On-Line Approach for Evaluating Transmission Errors in Harmonic ...**. [SAGE](https://journals.sagepub.com/doi/abs/10.1177/16878132241276666). **Supporting.** Online transmission-error evaluation.
7. **Vibration-Assisted Hysteresis Mitigation for Achieving High ...**. [arXiv](https://arxiv.org/abs/2503.02720) | [HTML](https://arxiv.org/html/2503.02720v1). **Adjacent.** Hysteresis mitigation methods for precision mechanisms.

## 4. Planetary, Gear, and General Transmission Error

These are useful for comparing a readily available planetary stage against a belt or harmonic stage.

1. **Transmission Error Analysis of Planetary Gear Trains ...**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=transmission+error+analysis+planetary+gear+train). **Core.** Search entry for planetary transmission-error papers; select papers after checking geometry and measurement method.
2. **Backlash and Transmission Error in Planetary Gearboxes**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=backlash+transmission+error+planetary+gearbox+precision+positioning). **Core.** Search entry for backlash and gear-train error.
3. **Gear Backlash Modeling and Compensation for Precision Motion Systems**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=gear+backlash+modeling+compensation+precision+motion+system). **Supporting.** Compensation methods applicable to planetary stages.
4. **Nonlinear Friction and Transmission Error Compensation in Robot Gearboxes**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=nonlinear+friction+transmission+error+compensation+robot+gearbox). **Supporting.** Friction, hysteresis, and gearbox compensation.

These search entries are deliberately marked as discovery links rather than individual citations because the search produced many near-duplicates and application-specific papers. A paper should be promoted into the final bibliography only after its title, authors, DOI, and relevance are verified.

## 5. Timing Belts, Pulleys, Compliance, and Slip

These are the most relevant sources for the proposed fixed synchronous-belt reduction.

1. **Measurement of Timing Belt Angle Transfer Accuracy in Angle Metrology Applications**. [ScienceDirect search result](https://www.sciencedirect.com/search?qs=Measurement%20of%20timing%20belt%20angle%20transfer%20accuracy%20in%20angle%20metrology%20applications) | [ResearchGate](https://www.researchgate.net/publication/366387359_Measurement_of_timing_belt_angle_transfer_accuracy_in_angle_metrology_applications). **Core.** Directly relevant to angular transfer error in belt stages.
2. **Analysis and Estimation of Motion Transmission Errors of a Timing Belt Drive**. [ResearchGate discovery page](https://www.researchgate.net/publication/288732775_Analysis_and_estimation_of_motion_transmission_errors_of_a_timing_belt_drive). **Core.** Timing-belt transmission-error analysis.
3. **From Transmission Error Measurement to Pulley-Belt Slip Determination in Serpentine Belt Drives: Influence of Tensioner and Belt Characteristics**. [Academia](https://www.academia.edu/22574945/From_transmission_error_measurement_to_Pulley_Belt_slip_determination_in_serpentine_belt_drives_influence_of_tensioner_and_belt_characteristics). **Supporting.** Measurement of belt slip and tension effects; non-synchronous belt, so transferability must be checked.
4. **Dynamic Modelling of a Single-Axis Belt-Drive System**. [Academia discovery page](https://www.academia.edu/35272943/Modeling_and_Synthesis_of_Tracking_Control_for_the_Belt_Drive_System). **Core.** Belt compliance and servo dynamics.
5. **Modelling and Synthesis of Tracking Control for the Belt Drive System**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S2590123022005199). **Core.** Belt compliance model and tracking control.
6. **Modeling, System Identification and Control of a Belt Drive System**. [Academia discovery page](https://www.academia.edu/29319791/TITLE_Modeling_System_Identification_and_Control_of_a_Belt_Drive_System_AUTHOR). **Supporting.** System identification and control of an elastic belt drive.
7. **Influence of Idler on Transmission Error in Synchronous Belt Drives**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=Influence+of+Idler+on+Transmission+Error+in+Synchronous+Belt+Drives). **Supporting.** Idler placement and meshing-state effects.
8. **Timing Belts in Linear Positioning: Orientation and Topics of Discussion**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=timing+belts+linear+positioning+compliance+accuracy). **Adjacent.** Broader positioning-stage context.

## 6. Rotary Encoder Calibration and Angular Metrology

These papers inform encoder selection, mounting, independent validation, and the uncertainty budget.

1. **Calibration of Rotary Encoders Using a Shift-Angle Method**. [MDPI Applied Sciences](https://www.mdpi.com/2076-3417/12/10/5008). **Core.** Rotary encoder calibration method.
2. **A New Method of Angle Measurement Error Analysis of Rotary Encoders**. [MDPI Applied Sciences](https://www.mdpi.com/2076-3417/9/16/3415). **Core.** Error sources and analysis method.
3. **Calibration of a Rotary Encoder and a Polygon Using a Two ...**. [MDPI Applied Sciences](https://www.mdpi.com/2076-3417/13/3/1865). **Core.** Encoder calibration against an angular reference.
4. **A New Error Model and Compensation Strategy of Angle Encoder in ...**. [MDPI Sensors](https://www.mdpi.com/1424-8220/19/17/3772). **Core.** Encoder error modelling and compensation.
5. **Calibration Method for Angular Positioning Deviation of a High ...**. [MDPI Applied Sciences](https://www.mdpi.com/2076-3417/9/16/3417). **Core.** Angular positioning-deviation calibration.
6. **An FPGA-Based Trigonometric Kalman Filter Approach for Improving the ...**. [MDPI Energies](https://www.mdpi.com/1996-1073/17/23/6122). **Supporting.** Digital filtering and angle-estimation improvement.
7. **Self-Calibratable Absolute Modular Rotary Encoder: Development and ...**. [MDPI Micromachines](https://www.mdpi.com/2072-666X/15/9/1130). **Supporting.** Encoder architecture and self-calibration.
8. **On-Machine Calibration of Angular Position and Runout of a Precision ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0263224119312667). **Core.** Angular position and runout calibration.
9. **A Three-Axis Autocollimator for Detection of Angular Error Motions of a ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0007850611000539). **Core.** Independent angular metrology instrumentation.
10. **A Novel Error Mapping of Bi-Directional Angular Positioning Deviation ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0141635921002671). **Core.** Bidirectional positioning error and mapping.
11. **Modelling and Validation of Eccentricity Effects in Fine Angle Signals ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/abs/pii/S0924424722004101). **Core.** Encoder eccentricity and periodic angle error.
12. **Impact of Encoder-Head Installation Errors and ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0141635926001479). **Core.** Installation errors in encoder measurement.
13. **An Online Angular Self-Calibration Method for Installation Errors of ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0141635926001728). **Supporting.** Online installation-error calibration.

## 7. Precision Rotary Stages and Error Motion

These papers provide system-level methods even when the actuator is not a stepper motor.

1. **Influence of Rotary Axis Angular Positioning Error Motions on Robotic ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0007850624000878). **Supporting.** How angular error propagates into a larger mechanism.
2. **A Miniaturized Capacitive Absolute Angular Positioning Sensor Based on ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0924424719321478). **Adjacent.** Alternative high-resolution angle sensing.
3. **A Novel Error Mapping of Bi-Directional Angular Positioning Deviation ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0141635921002671). **Core.** Applicable to the proposed bidirectional benchmark.
4. **On-Machine Calibration of Angular Position and Runout of a Precision ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0263224119312667). **Core.** Applicable to output-shaft calibration.
5. **A Three-Axis Autocollimator for Detection of Angular Error Motions of a ...**. [ScienceDirect](https://www.sciencedirect.com/science/article/pii/S0007850611000539). **Core.** Applicable to independent angular measurement.
6. **Calibration of Rotary Encoders Using a Shift-Angle Method**. [MDPI](https://www.mdpi.com/2076-3417/12/10/5008). **Core.** Applicable to encoder uncertainty.

## 8. Friction, Hysteresis, and Compensation

These are adjacent but important because closed-loop control cannot make an unstable or poorly characterized mechanism accurate by itself.

1. **Physics-Informed Learning for the Friction Modeling of ...**. [arXiv](https://arxiv.org/abs/2410.12685) | [HTML](https://arxiv.org/html/2410.12685v1). **Supporting.** Friction modelling and compensation.
2. **Non-Linear Hysteresis Compensation of a Tendon-Sheath-Driven Robotic ...**. [arXiv PDF](https://arxiv.org/pdf/2011.01819.pdf). **Adjacent.** Hysteresis compensation method transferable in principle, not in hardware.
3. **Vibration-Assisted Hysteresis Mitigation for Achieving High ...**. [arXiv](https://arxiv.org/abs/2503.02720). **Adjacent.** Hysteresis reduction in precision actuation.
4. **Data-Driven Modeling and Analysis of Transmission Error in Harmonic Drive Systems**. [arXiv](https://arxiv.org/abs/2310.15875). **Core.** Transmission-error compensation.
5. **Modeling of Transmission Compliance and Hysteresis Considering Degradation in a Harmonic Drive**. [MDPI](https://www.mdpi.com/2076-3417/11/2/665). **Core.** Hysteresis and compliance model.

## 9. Variable-Ratio and CVT Background

The project does not currently recommend a CVT for the first precision prototype. These searches are retained because variable ratio, belt compliance, slip, and ratio calibration are directly connected to the rejected alternative.

1. **Continuously Variable Transmission Ratio Control and Efficiency ...**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=continuously+variable+transmission+ratio+control+positioning+accuracy). **Adjacent.** Search for ratio-control methods.
2. **Control and Modelling of Variable-Ratio Belt Transmissions**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=variable+ratio+belt+transmission+control+modeling+slip). **Adjacent.** Search for variable-pitch belt mechanisms.
3. **Belt Drive Transmission Error, Slip, and Tension Control**. [Google Scholar discovery search](https://scholar.google.com/scholar?q=belt+drive+transmission+error+slip+tension+control). **Supporting.** Search for the error mechanisms that make a CVT risky.

## 10. Existing Non-Paper Background Sources

These are not research papers, but they already support the project's initial engineering context and should not be confused with peer-reviewed evidence.

1. [Lin Engineering: Methods for Increasing Accuracy in Stepper Motors](https://www.linengineering.com/news/methods-for-increasing-accuracy-in-stepper-motors). Manufacturer guidance on microstepping, accuracy, and gearing.
2. [Industrial Monitor Direct: Sub-Arcsecond Rotary Motion](https://industrialmonitordirect.com/it/blogs/knowledgebase/05-arcsecond-precision-rotary-motion-motor-encoder-design-guide). Commercial system-level guidance; demanding example, not a project specification.
3. [JKONGMOTOR: Improving Stepper Positioning Accuracy](https://www.jkongmotor.com/how-to-improve-positioning-accuracy-in-stepper-motors-in-industrial-equipment.html). Supplier checklist; claims require verification.
4. [Arduino Forum pulley discussion](https://forum.arduino.cc/t/what-gears-ratio-use-to-have-more-resolution-in-stepper-motors-laser-engraver/607247). Informal pulley concept; local diagrams are preserved under `99-evidence/resources/arduino-pulley-diagram/`.
5. [Cloudy Nights: Steppers and Resolution](https://www.cloudynights.com/forums/topic/739690-steppers-and-resolution/). Informal reduction example; calculations are independently checked in the project documents.

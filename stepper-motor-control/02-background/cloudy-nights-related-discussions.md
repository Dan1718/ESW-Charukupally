# Cloudy Nights Related Discussions

This is a resource index for discussions discovered through Cloudy Nights search. These are candidate sources for later review. They are not project requirements, verified specifications, or design decisions yet.

## How To Use This Index

The discussions are useful for seeing real implementations of stepper motors, belts, planetary gearboxes, harmonic drives, OnStep controllers, encoders, backlash correction, and tracking performance. Forum claims should be treated as practical anecdotes until checked against datasheets, calculations, or experiments.

## Most Relevant Discussions

### 1. DIY $100 Harmonic Drive Mount OnStepX

[Open discussion](https://www.cloudynights.com/forums/topic/1004806-diy-100-harmonic-drive-mount-onstepx/?do=findComment&comment=14733273)

**Topics to inspect:** harmonic-drive reduction, stepper microstepping, and angular-resolution calculations.

**Why it may help us:** compares a compact stepper and reduction architecture with the nominal angular resolution needed at the output.

### 2. DIY Harmonic Drive Stepper Motor Physical Connections

[Open discussion](https://www.cloudynights.com/forums/topic/1002468-diy-harmonic-drive-stepper-motor-physical-connections/?do=findComment&comment=14696458)

**Topics to inspect:** motor-to-driver wiring, additional planetary or belt reduction, torque calculations, and payload sizing.

**Why it may help us:** relevant to the physical implementation of a low-load geared stepper system.

### 3. TeSeek Mini Dual-axis 11 Harmonic Equatorial Mount

[Open discussion](https://www.cloudynights.com/forums/topic/975140-teseek-mini-dual-axis-11-harmonic-equatorial-mount/?do=findComment&comment=14756652)

**Topics to inspect:** stepper-to-strain-wave gearing and comparisons between planetary and belt reduction.

**Why it may help us:** provides alternatives to compare against a simple pulley or planetary reduction.

### 4. AM5 Teardown

[Open discussion](https://www.cloudynights.com/forums/topic/853364-am5-teardown/?do=findComment&comment=12327553)

**Topics to inspect:** NEMA stepper motors, timing belts, strain-wave gears, microstepping, home sensors, and accuracy.

**Why it may help us:** shows how commercial systems combine multiple motion components and where backlash or calibration concerns arise.

### 5. Belt Drive Modification for an Old EQ6

[Open discussion](https://www.cloudynights.com/forums/topic/992814-belt-drive-modification-for-my-old-eq6/?do=findComment&comment=14539568)

**Topics to inspect:** replacing a planetary-reduction stepper with a NEMA 17 and belt gearing.

**Why it may help us:** directly relevant to evaluating a NEMA 17 plus pulley/belt architecture.

### 6. Converting a Broken AVX to OnStep

[Open discussion](https://www.cloudynights.com/forums/topic/992190-converting-a-broken-avx-celestron-advanced-vx-to-onstep/?do=findComment&comment=14530497)

**Topics to inspect:** cycloidal reduction, low backlash, GT2 belts, and worm ratios.

**Why it may help us:** useful for comparing belt, cycloidal, and worm-based transmission choices.

### 7. Absolute Positioning Modification for a Meade Microfocuser

[Open discussion](https://www.cloudynights.com/forums/topic/571149-absolute-positioning-modification-for-meade-zero-image-shift-microfocuser/?do=findComment&comment=7780829)

**Topics to inspect:** gear-reduction stepper positioning, practical resolution, calibration, and backlash.

**Why it may help us:** provides a small-scale example where commanded resolution and actual backlash must be distinguished.

### 8. Meade LXD650 OnStep Retrofit

[Open discussion](https://www.cloudynights.com/forums/topic/738036-meade-lxd650-onstep-retrofit/?do=findComment&comment=10630763)

**Topics to inspect:** stepper conversion, belt reduction, microstepping, and calculated tracking resolution.

**Why it may help us:** useful for checking how reduction ratios are calculated in a practical motion system.

### 9. Understanding Vixen SP and GP Motors and Controllers

[Open discussion](https://www.cloudynights.com/forums/topic/920792-understanding-vixen-sp-and-gp-34old-school34-pre-2000-motors-drive-controllers/?do=findComment&comment=13423646)

**Topics to inspect:** internal stepper gear ratios such as 1:30, 1:120, and 1:300, and their relationship to smoothness.

**Why it may help us:** useful for comparing high-ratio internal gearing with an external belt or gearbox.

### 10. High Periodic Error and Its Consequences

[Open discussion](https://www.cloudynights.com/forums/topic/998603-is-a-high-pe-value-a-major-problem/?do=findComment&comment=14645753)

**Topics to inspect:** stepper resonance, belt/gear reduction, and optical-encoder-related performance.

**Why it may help us:** relevant to separating static angular accuracy from dynamic tracking and periodic error.

### 11. Celestron Ultima C11 Mount Discussion

[Open discussion](https://www.cloudynights.com/forums/topic/982526-question-on-disassembling-the-fork-of-an-old-celestron-ultima-c11-mount/?do=findComment&comment=14380133)

**Topics to inspect:** NEMA steppers, reduction gearing, and mechanical backlash or slack correction.

**Why it may help us:** useful as a practical example of transmission errors in geared telescope motion.

## Search Pages Used

- [Stepper](https://www.cloudynights.com/search/?q=stepper)
- [Encoder and stepper](https://www.cloudynights.com/search/?q=encoder%20stepper)
- [Gear reduction and stepper](https://www.cloudynights.com/search/?q=gear%20reduction%20stepper)
- [Harmonic drive, stepper, and resolution](https://www.cloudynights.com/search/?q=harmonic%20drive%20stepper%20resolution)
- [Periodic error and stepper](https://www.cloudynights.com/search/?q=periodic%20error%20stepper)

## Review Status

The search identified relevant candidates, but direct fetching of the individual discussion pages timed out during this review pass. The links are preserved for manual selection and review. No quotations or technical claims from these additional discussions have been added to the design yet.

## Selection Prompt

The team can choose which discussions to analyze in detail. Recommended first choices are:

1. DIY $100 Harmonic Drive Mount OnStepX
2. Belt Drive Modification for an Old EQ6
3. Absolute Positioning Modification for a Meade Microfocuser
4. AM5 Teardown
5. Meade LXD650 OnStep Retrofit

# 🩸 Glucose Monitoring System (ATmega32)

An embedded C application designed for the **ATmega32** microcontroller following a modular **Layered Software Architecture (MCAL, HAL, LIB)**. The system provides real-time monitoring of simulated blood glucose levels, tracks precise time via an RTC module, supports multiple testing modes (Fasting and Post-Meal), displays status on a 16x2 LCD in 4-bit mode, and provides visual (LED) and audible (Buzzer) alerts for critical medical ranges.

## 🛠 Project Architecture & Directory Structure
Glucose-Monitoring-System/
│
├── INCLUDE/
│   ├── HAL/
│   │   ├── BUZZER/
│   │   │   ├── BUZZER_CFG.h
│   │   │   ├── BUZZER_INTERFACE.h
│   │   │   └── BUZZER_PRIVATE.h
│   │   │
│   │   ├── GLUCOSE_SENSOR/
│   │   │   ├── GLUCOSE_CFG.h
│   │   │   ├── GLUCOSE_INTERFACE.h
│   │   │   └── GLUCOSE_PRIVATE.h
│   │   │
│   │   ├── LCD/
│   │   │   ├── LCD_CFG.h
│   │   │   ├── LCD_INTERFACE.h
│   │   │   └── LCD_PRIVATE.h
│   │   │
│   │   └── RTC/
│   │       ├── RTC_CFG.h
│   │       ├── RTC_INTERFACE.h
│   │       └── RTC_PRIVATE.h
│   │
│   ├── LIB/
│   │   ├── BIT_MATH.h
│   │   └── STD_TYPES.h
│   │
│   └── MCAL/
│       ├── ADC/
│       │   ├── ADC_CFG.h
│       │   ├── ADC_INTERFACE.h
│       │   └── ADC_PRIVATE.h
│       │
│       ├── DIO/
│       │   ├── DIO_CFG.h
│       │   ├── DIO_INTERFACE.h
│       │   └── DIO_PRIVATE.h
│       │
│       ├── EXTI/
│       │   ├── EXTI_CFG.h
│       │   ├── EXTI_INTERFACE.h
│       │   └── EXTI_PRIVATE.h
│       │
│       ├── GL/
│       │   ├── GL_CFG.h
│       │   ├── GL_INTERFACE.h
│       │   └── GL_PRIVATE.h
│       │
│       └── TWI/
│           ├── TWI_CFG.h
│           ├── TWI_INTERFACE.h
│           └── TWI_PRIVATE.h
│
└── SOURCE/
    ├── ADC_PROGRAM.c
    ├── BUZZER_PROGRAM.c
    ├── DIO_PROGRAM.c
    ├── EXTI_PROGRAM.c
    ├── GLUCOSE_PROGRAM.c
    ├── GLUCOSE_SENSOR_PROGRAM.c
    ├── GL_PROGRAM.c
    ├── LCD_PROGRAM.c
    ├── MAIN.C
    ├── RTC_PROGRAM.c
    ├── TWI_PROGRAM.c
    └── main.c
⚡ Key FeaturesAnalog Sensor Simulation: Simulates blood glucose levels using a Potentiometer sampled via the 10-bit Analog-to-Digital Converter (ADC).Medical Range Evaluation: Processes raw voltage and maps it to blood glucose concentrations ($mg/dL$).Dual Testing Modes: Dynamic status evaluation based on selected context:🔴 Fasting Mode🟣 Post-Meal ModeI2C Real-Time Clock (DS1307): Communicates via the TWI (I2C) peripheral driver to fetch real-time clock data.Multi-Level Visual Alert System (LEDs):🟢 Green LED: Normal Glucose Level (Safe).🟡 Yellow LED: Prediabetes / Warning Level.🔴 Red LED: Critical / Diabetes Threshold.Audible Emergency Alarm: Active Buzzer activated automatically upon critical threshold breach.External Interrupts (EXTI): Mode selection buttons and alarm toggles handled via push buttons.16x2 LCD Visualization (4-Bit Mode): Displays system status, current measurement mode, real-time clock, and numerical glucose readings while optimizing GPIO pin usage.📊 Glucose Medical Ranges & ThresholdsStatus CategoryFasting Mode Range (mg/dL)Post-Meal Mode Range (mg/dL)Active LED IndicatorNormal Level$70 - 99$$< 140$🟢 Green LEDWarning / Prediabetes$100 - 125$$140 - 199$🟡 Yellow LEDCritical / Critical Alarm$\ge 126$$\ge 200$🔴 Red LED + Buzzer🔌 Hardware Pin ConfigurationComponentMicrocontroller PinFunction / DescriptionGlucose Sensor (Pot)PA0 (ADC Channel 0)Analog Voltage InputDS1307 RTC ModulePC0 (SCL), PC1 (SDA)TWI / I2C Clock & Data Lines16x2 LCD Data BusPC4 - PC7 (D4 - D7)4-Bit Mode Data Lines16x2 LCD Control LinesPD0 (RS), PD2 (EN)Register Select & Enable Control PinsGreen LED IndicatorOutput PinNormal Range Visual SignalYellow LED IndicatorOutput PinWarning Range Visual SignalRed LED IndicatorOutput PinCritical Range Visual SignalActive BuzzerOutput PinAudible High-Risk AlertFasting Mode SwitchPush Button InputSelect Fasting Medical ThresholdsPost-Meal Mode SwitchPush Button InputSelect Post-Meal Medical ThresholdsAlarm Toggle SwitchPush Button InputManual Alarm Control / Toggle💻 Tech Stack & Embedded ToolsProgramming Language: Embedded CTarget Microcontroller: ATmega32 (16 MHz Clock Speed)Architecture: Layered Software Architecture (MCAL / HAL / LIB)IDE & Toolchain: Eclipse IDE for C/C++ Developers (AVR-GCC Toolchain)Hardware Simulator: Proteus VSM 8.xVersion Control: Git & GitHub🚀 How to Build & Run SimulationClone the Repository:Bashgit clone [https://github.com/axani2039-cpu/Glucose-Monitoring-System.git](https://github.com/axani2039-cpu/Glucose-Monitoring-System.git)
Compile the Software:Import the project into Eclipse IDE.Build the target project using the AVR Toolchain to produce the binary .hex file.Execute Proteus Simulation:Open the .pdsprj file in Proteus VSM.Double-click the ATmega32 chip and attach the compiled .hex file path.Start simulation to interact with the potentiometer, switch between Fasting and Post-Meal modes, monitor real-time RTC time, and inspect LED/Buzzer alert responses.

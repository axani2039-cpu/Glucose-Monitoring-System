# 🩸 Glucose Monitoring System (ATmega32)

An embedded C application designed for the **ATmega32** microcontroller following a modular **Layered Software Architecture (MCAL, HAL, LIB)**. The system provides real-time monitoring of simulated blood glucose levels, tracks precise time via an RTC module, supports multiple testing modes (Fasting and Post-Meal), displays status on a 16x2 LCD in 4-bit mode, and provides visual (LED) and audible (Buzzer) alerts for critical medical ranges.

---

## 🛠 Project Architecture & Directory Structure

```text
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
⚡ Key Features
Analog Sensor Simulation: Simulates blood glucose levels using a Potentiometer sampled via the 10-bit Analog-to-Digital Converter (ADC).

Medical Range Evaluation: Processes raw voltage and maps it to blood glucose concentrations (mg/dL).

Dual Testing Modes: Dynamic status evaluation based on selected context:

Fasting Mode

Post-Meal Mode

I2C Real-Time Clock (DS1307): Communicates via the TWI (I2C) peripheral driver to fetch real-time clock data.

Multi-Level Visual Alert System (LEDs):

🟢 Green LED: Normal Glucose Level (Safe).

🟡 Yellow LED: Prediabetes / Warning Level.

🔴 Red LED: Critical / Diabetes Threshold.

Audible Emergency Alarm: Active Buzzer activated automatically upon critical threshold breach.

External Interrupts (EXTI): Mode selection buttons and alarm toggles handled via push buttons.

16x2 LCD Visualization (4-Bit Mode): Displays system status, current measurement mode, real-time clock, and numerical glucose readings while optimizing GPIO pin usage.

📊 Glucose Medical Ranges & Thresholds
Status Category	Fasting Mode Range (mg/dL)	Post-Meal Mode Range (mg/dL)	Active LED Indicator
Normal Level	70 - 99	< 140	🟢 Green LED
Warning / Prediabetes	100 - 125	140 - 199	🟡 Yellow LED
Critical / Critical Alarm	≥ 126	≥ 200	🔴 Red LED + Buzzer
🔌 Hardware Pin Configuration
Component	Microcontroller Pin	Function / Description
Glucose Sensor (Pot)	PA0 (ADC Channel 0)	Analog Voltage Input
DS1307 RTC Module	PC0 (SCL), PC1 (SDA)	TWI / I2C Clock & Data Lines
16x2 LCD Data Bus	PC4 - PC7 (D4 - D7)	4-Bit Mode Data Lines
16x2 LCD Control Lines	PD0 (RS), PD2 (EN)	Register Select & Enable Control Pins
Green LED Indicator	Output Pin	Normal Range Visual Signal
Yellow LED Indicator	Output Pin	Warning Range Visual Signal
Red LED Indicator	Output Pin	Critical Range Visual Signal
Active Buzzer	Output Pin	Audible High-Risk Alert
Fasting Mode Switch	Push Button Input	Select Fasting Medical Thresholds
Post-Meal Mode Switch	Push Button Input	Select Post-Meal Medical Thresholds
Alarm Toggle Switch	Push Button Input	Manual Alarm Control / Toggle
💻 Tech Stack & Embedded Tools
Programming Language: Embedded C

Target Microcontroller: ATmega32 (16 MHz Clock Speed)

Architecture: Layered Software Architecture (MCAL / HAL / LIB)

IDE & Toolchain: Eclipse IDE for C/C++ Developers (AVR-GCC Toolchain)

Hardware Simulator: Proteus VSM 8.x

Version Control: Git & GitHub

🚀 How to Build & Run Simulation
Clone the Repository:

Bash
git clone [https://github.com/axani2039-cpu/Glucose-Monitoring-System.git](https://github.com/axani2039-cpu/Glucose-Monitoring-System.git)
Compile the Software:

Import the project into Eclipse IDE.

Build the target project using the AVR Toolchain to produce the binary .hex file.

Execute Proteus Simulation:

Open the .pdsprj file in Proteus VSM.

Double-click the ATmega32 chip and attach the compiled .hex file path.

Start simulation to interact with the potentiometer, switch between Fasting and Post-Meal modes, monitor real-time RTC time, and inspect LED/Buzzer alert responses.

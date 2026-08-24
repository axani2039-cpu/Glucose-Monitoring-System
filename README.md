# 🩸 Glucose Monitoring System (ATmega32)

An embedded C application built for the ATmega32 microcontroller using a Layered Software Architecture (MCAL, HAL, LIB). The system simulates blood glucose level measurement, displays real-time readings on a 16x2 LCD, and triggers visual (LED) and audible (Buzzer) alerts when thresholds are exceeded.

---

## 🛠 Project Architecture & Directory Structure

```text
Glucose-Monitoring-System/
│
├── INCLUDE/
│   ├── HAL/
│   │   ├── LCD_config.h
│   │   ├── LCD_interface.h
│   │   └── LCD_private.h
│   │
│   ├── LIB/
│   │   ├── BIT_MATH.h
│   │   └── STD_TYPES.h
│   │
│   └── MCAL/
│       ├── ADC_config.h
│       ├── ADC_interface.h
│       ├── ADC_private.h
│       │
│       ├── DIO_config.h
│       ├── DIO_interface.h
│       └── DIO_private.h
│
└── SOURCE/
    ├── ADC_program.c
    ├── DIO_program.c
    ├── LCD_program.c
    └── MAIN.C

#⚡ Key FeaturesAnalog Sensing:
 - Simulates a glucose sensor using a Potentiometer connected to PA0 (ADC Channel 0).
 - ADC Processing: Uses the ATmega32 10-bit ADC to convert analog voltage into digital values (0 to 1023).
 - Value Mapping: Maps digital ADC values to blood glucose readings (0 to 300 mg/dL).
 - LCD Visualization: Displays live glucose values and system status on a 16x2 LCD.
 - Hardware Alarm: Automatically turns on an LED and Buzzer on PORTB when glucose levels exceed 140 mg/dL.

<img width="962" height="367" alt="image" src="https://github.com/user-attachments/assets/53e2e0f7-e162-4c0e-ace5-b77c9af7bada" />

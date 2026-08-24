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
⚡ Key Features
Analog Sensing: Simulates a glucose sensor using a Potentiometer connected to PA0 (ADC Channel 0).  
PDF

ADC Processing: Uses the ATmega32 10-bit ADC to convert analog voltage into digital values (0 to 1023).  
PDF

Value Mapping: Maps digital ADC values to blood glucose readings (0 to 300 mg/dL).  
PDF

LCD Visualization: Displays live glucose values and system status on a 16x2 LCD.  
PDF

Hardware Alarm: Automatically turns on an LED and Buzzer on PORTB when glucose levels exceed 140 mg/dL.

🔌 Hardware Pin Configuration
Component	Microcontroller Pin	Function / Description
Potentiometer	PA0 (ADC0)	
Glucose Sensor Simulation Input  
PDF

LCD Data Lines	PORTC (PC0 - PC7)	
8-Bit Data Bus  
PDF

LCD Control	PD0 (RS), PD1 (EN)	
Register Select & Enable Control Pins  
PDF

LED Alert	PB0	Visual Warning Indicator
Buzzer Alert	PB1	Audible Alarm Indicator
💻 Tech Stack & Tools
Language: Embedded C  
PDF

Microcontroller: ATmega32 (16 MHz)  
PDF

IDE: Eclipse IDE for C/C++ Developers  
PDF

Simulation: Proteus VSM  
PDF

Version Control: Git & GitHub

🚀 How to Run the Simulation
Clone this repository to your local machine:

Bash
git clone [https://github.com/username/Glucose-Monitoring-System.git](https://github.com/username/Glucose-Monitoring-System.git)
Open the workspace in Eclipse and build the project to generate the .hex file.  
PDF

Open the schematic in Proteus.  
PDF

Double-click the ATmega32 component and select the compiled .hex file[cite: 1].

Start the simulation and adjust the potentiometer value to observe live updates on the LCD and alert triggers[cite: 1].


---

How would you like to update the GitHub repository: by using terminal commands directly, or by creating the `README.md` file from the GitHub web interface?

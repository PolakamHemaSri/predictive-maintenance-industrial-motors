# 🔧 Predictive Maintenance System for Industrial Motors

Embedded systems project developed during Microchip Technology 
Virtual Internship. Monitors motor health using temperature, 
vibration and RPM sensors on dsPIC33EP256MC506.

## 🛠️ Tools & Hardware
- **MCU:** dsPIC33EP256MC506
- **IDE:** MPLAB X IDE v6.30
- **Compiler:** XC-DSC v3.31
- **Simulation:** MATLAB Online

## ⚙️ Features
- 4-state health state machine (Healthy → Degrading → Critical → Fault)
- ADC-based sensor simulation
- UART data logging
- Linked list data structures for sensor history

## 📁 Project Structure
- `main.c` – Main program entry point
- `sensors.c / sensors.h` – Sensor reading & ADC
- `statemachine.c / statemachine.h` – Health state machine
- `datalogger.c / datalogger.h` – UART logging & linked list

## 🏢 Internship
Microchip Technology Virtual Internship – Embedded Systems

## 👩‍💻 Developer
Polakam Hema Sri | ECE, VRSEC

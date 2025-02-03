# RFID Based Tallgate Control System

# RFID Based Tollgate Control System

## Overview
This project implements an **RFID-based tallgate control system** using the **AT89C52 microcontroller**. It integrates **I2C** and **UART** communication protocols to read RFID tags and control a tallgate system. The system verifies the authenticity of a tag, logs entry/exit times, calculates toll charges, and controls the gate.

## Features
- **RFID Authentication**: Reads and verifies RFID tags.
- **Time Logging**: Uses an RTC (Real-Time Clock) for entry and exit time tracking.
- **Automated Toll Calculation**: Calculates the amount to be paid based on time spent.
- **LCD Display**: Provides user feedback for authentication and payments.
- **Motor Control**: Opens and closes the gate automatically.

## Hardware Requirements
- AT89C52 Microcontroller
- RFID Reader & RFID Tags
- 16x2 LCD Display
- Motor Driver Circuit (for gate control)
- External EEPROM (if needed for additional storage)
- RTC Module (e.g., DS1307)
- Push Buttons and Power Supply

## Software Requirements
- Keil µVision IDE (for compiling the C program)
- Flash Magic (for burning the program to AT89C52)
- Proteus (for simulation, if needed)

## Circuit Connections
- **RFID Module** → Connected via UART (TX, RX)
- **LCD Display** → Connected to P0
- **Motor Driver** → Connected to P2
- **RTC (Real-Time Clock)** → Communicates using I2C (SCL, SDA)

## File Structure
- `main.c` - The main logic of the system.
- `i2c_header.h` - Handles I2C communication.
- `uart.h` - Handles UART communication.
- `mtr_driver.h` - Controls gate motor functions.
- `LCD.h` - Manages LCD operations.
- `delay.h` - Provides delay functions.

## How It Works
1. **System Initialization**: Initializes the LCD, UART, and I2C.
2. **Waiting for RFID Tag**: The system waits for an RFID card scan.
3. **Tag Verification**: If the tag is valid, entry time is logged; otherwise, access is denied.
4. **Toll Calculation**: When exiting, the system calculates the amount to be paid based on the duration.
5. **Gate Operation**: The gate opens when access is granted and closes after a delay.

## Usage
1. Power on the system.
2. Scan an RFID tag.
3. If valid, the system logs the time and opens the gate.
4. On exit, scan the RFID tag again.
5. The system calculates the fee and displays it.
6. The gate opens after payment and then closes.

## Future Enhancements
- Implement **online payment integration**.
- Store user data in **EEPROM or database**.
- Add **multiple RFID tag support** for different user categories.

## License
This project is open-source and free to use for educational purposes.

## Author
Akash Sureshbhai Khanpara


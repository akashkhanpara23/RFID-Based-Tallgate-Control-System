# RFID Based Tallgate Control System

## Overview
This project implements an **RFID-based Tallgate Control System** using an **AT89C52 microcontroller**. The system utilizes **I2C and UART communication protocols** to identify RFID tags, log entry and exit times, calculate toll charges, and control a gate mechanism.

## Features
- **RFID Authentication**: Reads and verifies RFID tags.
- **Real-Time Clock Integration**: Uses I2C communication to fetch and store entry/exit times.
- **Automated Toll Calculation**: Computes the toll fee based on time duration.
- **LCD Display**: Displays real-time status messages.
- **Gate Control**: Opens and closes the gate automatically based on authentication.

## Hardware Requirements
- **AT89C52 Microcontroller**
- **RFID Reader and Tags**
- **16x2 LCD Display**
- **RTC Module (DS1307)**
- **DC Motor with Driver Circuit**
- **Push Button Switch (for manual override)**
- **Power Supply (5V DC)**

## Software Requirements
- **Keil uVision (for development and debugging)**
- **Proteus (for simulation, optional)**
- **Embedded C Programming**

## File Structure
```
├── main.c              # Main program logic
├── i2c_header.h        # I2C communication functions
├── mtr_driver.h        # Motor driver functions for gate control
├── uart.h              # UART communication functions
├── delay.h             # Delay function definitions
├── README.md           # Project documentation
```

## Code Explanation
### `main.c`
- Initializes LCD, UART, and I2C modules.
- Waits for an RFID tag input.
- Verifies tag ID and logs time using the RTC module.
- Computes toll charges and displays payment details.
- Controls the gate mechanism accordingly.

### `i2c_header.h`
- Implements I2C communication for reading/writing to the RTC module.

### `mtr_driver.h`
- Controls gate opening and closing using a DC motor.

### `uart.h`
- Handles UART communication to receive RFID tag data.

## Functionality Flow
1. **System Initialization**: LCD displays "Waiting for tag ID."
2. **Tag Scanning**: RFID tag is scanned and verified.
3. **Time Logging**: Entry or exit time is stored.
4. **Toll Calculation**: The system calculates the toll amount based on the duration of stay.
5. **Payment & Gate Control**: After payment confirmation, the gate opens and closes automatically.
6. **Thank You Message**: Displays a farewell message.

## How to Use
1. **Power ON the System.**
2. **Scan an RFID Tag.**
3. **If valid:**
   - First-time entry: Logs entry time and opens the gate.
   - On exit: Calculates toll, prompts for payment, and opens the gate.
4. **If invalid:** Displays "Invalid Tag ID."
5. **Gate Operates Automatically.**
6. **Repeat process for the next vehicle.**

## Future Enhancements
- **Online Payment Integration**
- **Database Logging for Vehicle History**
- **RFID Tag Prepaid System**
- **Mobile App for User Management**

## License
This project is open-source and free to use for educational purposes.

## Author
Akash Sureshbhai Khanpara


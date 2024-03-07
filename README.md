# ESP32-S3: Reading Data from 74HC165 Shift Register

This project demonstrates how to read data from a 74HC165 shift register connected to an ESP32-S3 microcontroller. It also implements a software debounce algorithm to address button bounce, a common issue with physical buttons.

## Features:

- Reads data from an 8-bit 74HC165 shift register.
- Software debounce for button presses connected to the ESP32.
- Prints the received data to the serial monitor.

## Debounce Explanation(Few data pins not working properly):

> **_NOTE:_**  Hold the push button for 50ms to check if Binary data is printed on the serial monitor.

When you press a button, its internal contacts may bounce several times before settling into a stable state. This bouncing can cause the code to misread the button state as multiple presses or miss the press altogether.

The software debounce algorithm filters out these rapid transitions by only registering a button press when the button state remains stable (pressed or released) for a specific time (debounce time). This ensures reliable button press detection.

## Hardware Requirements:

1. ESP32-S3 development board
2. 74HC165 shift register
3. Push buttons (with resistors)
4. Connecting wires
5. ADC (MCP008/ADS1115)
    - https://www.microchip.com/en-us/product/mcp3008
    - https://www.ti.com/product/ADS1115 

## Software Requirements:

- Arduino IDE (or compatible IDE)
or
- Wokwi Arduino Simulator (https://wokwi.com/projects/391703844416611329)

## Setup:

Connect the 74HC165 to the ESP32-S3 according to the datasheet and your desired configuration.
Connect push buttons to the ESP32 with appropriate resistors.
Upload the code (src/main.ino) to your ESP32-S3 board.

## Usage:

- Open the serial monitor in your IDE (usually at 115200 baud).
- Press the buttons connected to the ESP32.
- You should see the binary data received from the shift register printed on the serial monitor.

## License:

Copyright (c) 2024 Devansh Shukla
License: Apache 2.0
```


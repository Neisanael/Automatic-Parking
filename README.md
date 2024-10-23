# Automatic Parking System

This repository contains a program for an automatic parking system implemented using an ESP32 microcontroller and the Blynk platform for remote monitoring. The system controls a servo to open and close a gate based on infrared (IR) sensors that detect cars in parking spots. It also displays the total number of parked cars on an LCD screen.

## Features
   - Automatic gate control based on IR sensor input.
   - Real-time monitoring of parking availability.
   - Integration with Blynk for remote monitoring of the total number of parked cars.
   - LCD display showing parking information.

## Hardware Requirements

   - ESP32 microcontroller board (e.g., ESP32 DevKit)
   - 4 Infrared (IR) sensors (for car detection in parking spots) + 2 for Servo Gate
   - Servo motor (for opening and closing the gate)
   - LCD display (with I2C interface)
   - Wi-Fi access for Blynk integration

## Pin Configuration

   - **SERVO_OPEN_CLOSE**: Pin 12 (Servo for gate)
   - **FRONT_IR**: Pin 18 (IR sensor for front gate)
   - **BACK_IR**: Pin 22 (IR sensor for back gate)
   - **PARKING_LOT_1_IR**: Pin 2 (IR sensor for Parking Lot 1)
   - **PARKING_LOT_2_IR**: Pin 0 (IR sensor for Parking Lot 2)
   - **PARKING_LOT_3_IR**: Pin 4 (IR sensor for Parking Lot 3)
   - **PARKING_LOT_4_IR**: Pin 5 (IR sensor for Parking Lot 4)
   - **SDA_PIN**: Pin 26 (for LCD I2C communication)
   - **SCL_PIN**: Pin 27 (for LCD I2C communication)

## Dependencies

Ensure you have the following libraries installed in your Arduino IDE:

1. **ESP32Servo**
   - Library for controlling servo motors with the ESP32.
   - Installation:
     ```arduino
     #include <ESP32Servo.h>
     ```

2. **WiFi**
   - Library for WiFi connectivity, usually included with the ESP32 core for Arduino.
   - Installation:
     ```arduino
     #include <WiFi.h>
     ```

3. **Blynk**
   - Library for integrating with the Blynk platform.
   - Installation:
     ```arduino
     #include <BlynkSimpleEsp32.h>
     ```

4. **Wire**
   - Library for I2C communication, usually included with the Arduino core.
   - Installation:
     ```arduino
     #include <Wire.h>
     ```

5. **LiquidCrystal_I2C**
   - Library for interfacing with LCD displays via I2C.
   - Installation:
     ```arduino
     #include <LiquidCrystal_I2C.h>
     ```

## Schematic

![Schematic](https://github.com/Neisanael/Automatic-Parking/blob/main/Schematic.png?raw=true)

> **Warning:**
> The schematic provided may vary depending on the specific components you are using. Not all components use the same pins. Please refer to the datasheets of your components before making connections to avoid any damage.

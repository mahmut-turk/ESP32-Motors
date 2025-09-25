# ESP32 Motors Control via Bluetooth & C#

This project demonstrates controlling a **stepper motor**, **servo motor**, and **LED** connected to an ESP32 microcontroller via **Bluetooth**.  
The commands are sent from a **C# Windows Forms application** to the ESP32, enabling real-time motor control and LED toggling.

---

## Features
- Toggle LED ON/OFF via Bluetooth
- Control stepper motor forward and backward
- Control servo motor angle (0° and 90°)
- Bluetooth Serial communication between C# app and ESP32

---

## Hardware
- ESP32 Development Board
- 28BYJ-48 Stepper Motor + Driver
- SG90 Servo Motor
- LED + resistor
- Bluetooth Serial communication (built-in ESP32 Bluetooth)

---

## Software
- **ESP32** code written in C++ using PlatformIO (VS Code)
- **C# Windows Forms** app for GUI-based control
- Communication over **Bluetooth Serial (COM port)**

---

## How to Use
1. Flash the ESP32 with the provided code.
2. Pair ESP32 with your PC over Bluetooth.
3. Run the C# application and select the correct COM port.
4. Use the buttons in the GUI to send commands:
   - `L1` → Toggle LED
   - `S+` → Stepper forward
   - `S-` → Stepper backward
   - `SV0` → Servo at 0°
   - `SV90` → Servo at 90°

---

## Future Improvements
- Add PWM speed control for stepper motor
- Expand servo angle range
- Mobile app version for Android/iOS

---

## License
This project is for learning and personal use. No specific license applied.

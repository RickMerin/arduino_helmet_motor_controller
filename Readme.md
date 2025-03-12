# Helmet Detection and Motor Control System

## Overview

This project ensures a vehicle's motor only runs when the rider is wearing a helmet. An ultrasonic sensor detects helmet presence, and an nRF24L01 transceiver module handles wireless communication between the helmet (transmitter) and the vehicle (receiver). If the helmet is not worn or is too far away, the motor will not run.

---

## Components and Wiring

### Transmitter (Inside the Helmet)
#### Ultrasonic Sensor (HC-SR04)
- **VCC** -> 5V on Arduino Nano  
- **GND** -> GND on Arduino Nano  
- **Trig** -> D8 on Arduino Nano  
- **Echo** -> D7 on Arduino Nano  

#### nRF24L01 Transceiver Module
- **VCC** -> 3.3V on Arduino Nano  
- **GND** -> GND on Arduino Nano  
- **CE** -> D7 on Arduino Nano  
- **CSN** -> D8 on Arduino Nano  
- **SCK** -> D13 on Arduino Nano  
- **MOSI** -> D11 on Arduino Nano  
- **MISO** -> D12 on Arduino Nano  

### Receiver (On the Vehicle)
#### nRF24L01 Transceiver Module
- **VCC** -> 3.3V on Arduino Nano  
- **GND** -> GND on Arduino Nano  
- **CE** -> D7 on Arduino Nano  
- **CSN** -> D8 on Arduino Nano  
- **SCK** -> D13 on Arduino Nano  
- **MOSI** -> D11 on Arduino Nano  
- **MISO** -> D12 on Arduino Nano  

#### L298N Motor Driver
- **IN1** -> D2 on Arduino Nano  
- **IN2** -> D3 on Arduino Nano  
- **IN3** -> D4 on Arduino Nano  
- **IN4** -> D5 on Arduino Nano  
- **ENA** -> D6 on Arduino Nano  
- **ENB** -> D9 on Arduino Nano  
- **12V** -> External Power Supply (e.g., 12V Battery)  
- **GND** -> GND on Arduino Nano and External Power Supply  
- **5V** -> 5V on Arduino Nano (if needed)  

#### DC Motor
- **Motor1** -> OUT1 and OUT2 on L298N  
- **Motor2** -> OUT3 and OUT4 on L298N  

---

## System Operation

1. **Transmitter (Helmet):**  
   - The ultrasonic sensor measures the distance to the rider’s head.  
   - If the distance is less than 10 cm, it signals the receiver that the helmet is worn.  

2. **Receiver (Vehicle):**  
   - The receiver checks the transmitted data.  
   - If the helmet is worn (distance < 10 cm), the motor runs. Otherwise, it remains off.  

---

## Notes
- Ensure proper power connections for the nRF24L01 modules.
- Adjust the helmet detection threshold (default: 10 cm) based on design requirements.
- Use an adequate external power source for the motor driver.
- This system ensures that the vehicle can only operate when the rider is wearing the helmet.


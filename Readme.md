# Helmet Detection and Motor Control System

## Overview

This project ensures that a vehicle's motor only runs when the rider is wearing a helmet. The system uses an ultrasonic sensor to detect the presence of the helmet and an nRF24L01 transceiver module to communicate between the transmitter (inside the helmet) and the receiver (on the vehicle). If the helmet is not worn or is too far away, the motor will not run.

---

## Components

### Transmitter (Inside the Helmet)

#### Ultrasonic Sensor (HC-SR04)

- **VCC** -> 5V on Arduino Nano
- **GND** -> GND on Arduino Nano
- **Trig** -> D9 on Arduino Nano
- **Echo** -> D10 on Arduino Nano

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

## Schematic Diagram

### Transmitter (Inside the Helmet)

#### Ultrasonic Sensor (HC-SR04)

- **VCC** -> 5V on Arduino Nano
- **GND** -> GND on Arduino Nano
- **Trig** -> D9 on Arduino Nano
- **Echo** -> D10 on Arduino Nano

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

## Explanation

**Transmitter:** The ultrasonic sensor measures the distance to the head. If the distance is less than 10 cm, it assumes the helmet is worn and sends this information to the receiver.

**Receiver:** The receiver reads the distance data. If the distance is less than 10 cm, it runs the motor. Otherwise, it stops the motor.

---

## Notes

- Ensure that the nRF24L01 modules are properly powered and connected.
- Adjust the distance threshold (10 cm) as needed based on your helmet design.
- The L298N motor driver should be connected to an external power supply capable of driving the motors.
- This setup should work for your project, ensuring the motor only runs when the helmet is worn.

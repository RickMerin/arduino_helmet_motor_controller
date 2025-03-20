# Ultrasonic Distance Alert with NRF24L01

This Arduino project uses an ultrasonic distance sensor to detect nearby objects and send the measured distance wirelessly using the NRF24L01 transceiver module. The receiver controls a motor and an LED based on the distance received from the transmitter. If the distance is below a specified threshold, the motor is activated, and the LED lights up.

## Features
- Measures distance using an ultrasonic sensor.
- Wireless communication using NRF24L01 transceiver modules.
- Activates a motor and LED when the measured distance is below the threshold.
- Uses SPI communication for fast and efficient data transfer.
- Serial monitor output for debugging and distance monitoring.

## Components
- Arduino (e.g., Uno or Nano)
- NRF24L01 transceiver modules (2 units)
- Ultrasonic distance sensor (HC-SR04)
- L298N Stepper and DC Motor Driver Module
- DC motor
- LED
- Connecting wires
- Breadboard (optional)

## Circuit Diagram
1. **Transmitter Setup**:
   - CE pin to Arduino pin 9
   - CSN pin to Arduino pin 10
   - Trig pin of ultrasonic sensor to Arduino pin 8
   - Echo pin of ultrasonic sensor to Arduino pin 7

2. **Receiver Setup**:
   - CE pin to Arduino pin 9
   - CSN pin to Arduino pin 10
   - Motor A connections:
     - ENA pin to Arduino pin 8
     - IN1 pin to Arduino pin 3
     - IN2 pin to Arduino pin 2
   - LED pin to Arduino pin 5

## Installation
1. Install the RF24 library from the Arduino Library Manager.
2. Clone this repository or download the source code.
3. Open the transmitter and receiver code files in the Arduino IDE.
4. Upload the transmitter code to one Arduino and the receiver code to the other.

## Usage
1. Power on both the transmitter and receiver.
2. Open the Serial Monitor at a baud rate of 9600.
3. Move an object in front of the ultrasonic sensor and observe the distance being sent to the receiver.
4. The motor and LED will activate when the distance is less than or equal to 10 cm.

## Troubleshooting
- Ensure both NRF24L01 modules are using the same channel and data rate.
- Check the wiring connections carefully.
- Adjust the power level or data rate if the signal is not stable.
- Make sure the motor driver is correctly connected and powered.

## License
This project is licensed under the MIT License.

## Acknowledgements
- SPI and RF24 libraries for Arduino
- Arduino community for guidance and inspiration



![image](https://github.com/user-attachments/assets/fd24086b-3e1f-4353-bfac-5d275d9d96db)




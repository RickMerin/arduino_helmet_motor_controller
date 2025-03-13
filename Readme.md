# Ultrasonic Distance Alert with NRF24L01

This Arduino project uses an ultrasonic distance sensor to detect nearby objects and send the measured distance wirelessly using the NRF24L01 transceiver module. If the distance is below a specified threshold, the receiver activates a buzzer to alert the user.

## Features
- Measures distance using an ultrasonic sensor.
- Wireless communication using NRF24L01 transceiver modules.
- Activates a buzzer when the measured distance is below the threshold. **(optional)**
- Uses SPI communication for fast and efficient data transfer.
- Serial monitor output for debugging and distance monitoring.

## Components
- Arduino (e.g., Uno or Nano)
- NRF24L01 transceiver modules (2 units)
- Ultrasonic distance sensor (HC-SR04)
- Buzzer
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
   - Buzzer pin to Arduino pin 6 **(optional)**

## Installation
1. Install the RF24 library from the Arduino Library Manager.
2. Clone this repository or download the source code.
3. Open the transmitter and receiver code files in the Arduino IDE.
4. Upload the transmitter code to one Arduino and the receiver code to the other.

## Usage
1. Power on both the transmitter and receiver.
2. Open the Serial Monitor at a baud rate of 115200.
3. Move an object in front of the ultrasonic sensor and observe the distance being sent to the receiver.
4. The buzzer will sound when the distance is less than or equal to 15 cm. **(optional)**

## Troubleshooting
- Ensure both NRF24L01 modules are using the same channel and data rate.
- Check the wiring connections carefully.
- Adjust the power level or data rate if the signal is not stable.

## License
This project is licensed under the MIT License.

## Acknowledgements
- SPI and RF24 libraries for Arduino
- Arduino community for guidance and inspiration


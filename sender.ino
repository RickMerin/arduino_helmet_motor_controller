/*Transmitter Code (Nano + Ultrasonic Sensor + NRF24L01)*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define trigPin 9
#define echoPin 10

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening(); // Set NRF as transmitter
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm
  
  Serial.print("Distance: ");
  Serial.println(distance);

  radio.write(&distance, sizeof(distance)); // Send distance data
  delay(500);
}

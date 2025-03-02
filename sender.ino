#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define trigPin 9
#define echoPin 10

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 10) { // If the helmet is worn (distance < 10 cm)
    radio.write(&distance, sizeof(distance));
    Serial.println("Helmet is worn");
  } else {
    radio.write(&distance, sizeof(distance));
    Serial.println("Helmet is not worn");
  }
  delay(1000);
}
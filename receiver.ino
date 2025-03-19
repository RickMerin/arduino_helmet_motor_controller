#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Motor A connections
int enA = 9;
int in1 = 4;
int in2 = 5;

// NRF24L01 configuration
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
float distance;

void setup() {
  Serial.begin(9600);

  // Set motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Turn off motor initially
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  // NRF24L01 setup
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening(); // Set NRF as receiver

  Serial.println("Receiver Ready");
}

void loop() {
  if (radio.available()) {
    radio.read(&distance, sizeof(distance));
    Serial.print("Received Distance: ");
    Serial.println(distance);

    // Motor control logic: ON if distance < 50 cm, OFF otherwise
    if (distance < 50) {
      Serial.println("🚨 Motor ON: Distance below threshold!");
      digitalWrite(in1, HIGH);  // Motor forward direction
      digitalWrite(in2, LOW);   // Motor forward direction
      analogWrite(enA, 255);    // Full speed
    } else {
      Serial.println("✅ Motor OFF: Safe distance");
      digitalWrite(in1, LOW);   // Motor OFF
      digitalWrite(in2, LOW);   // Motor OFF
      analogWrite(enA, 0);      // Stop
    }
  }
}

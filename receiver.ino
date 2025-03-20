#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Motor A connections
int enA = 8;
int in1 = 3;
int in2 = 2;

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
float distance;
#define LED 5

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

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  pinMode(LED,OUTPUT);
  radio.startListening(); // Set NRF as receiver
}

void loop() {
  if (radio.available()) {
    radio.read(&distance, sizeof(distance));
    Serial.print("Received Distance: ");
    Serial.println(distance);
    if(distance <= 10){
      digitalWrite(LED,HIGH);
       digitalWrite(in1, HIGH);  // Motor forward direction
      digitalWrite(in2, LOW);   // Motor forward direction
      analogWrite(enA, 255);    // Full speed
    }else{
      digitalWrite(LED,LOW);
      digitalWrite(in1, LOW);   // Motor OFF
      digitalWrite(in2, LOW);   // Motor OFF
      analogWrite(enA, 0);      // Stop
    }
  }
}

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10
#define TRIG_PIN 2
#define ECHO_PIN 3

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";  // Communication address

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.println("Initializing nRF24L01...");

    if (!radio.begin()) {
        Serial.println("❌ nRF24L01 module not detected! Check connections.");
        while (1);  // Halt execution
    }

    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_LOW);
    radio.stopListening();  // Set to transmit mode

    Serial.println("✅ nRF24L01 module detected successfully!");
}

void loop() {
    int distance = getDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance <= 15) {
        Serial.println("⚠️ Object detected within range! Sending trigger signal...");
        const char text[] = "TRIGGER_MOTOR";
        radio.write(&text, sizeof(text));  // Send trigger message
    }

    delay(500);  // Adjust delay to prevent excessive messaging
}

// Function to measure distance using HC-SR04
int getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    int distance = duration * 0.034 / 2;  // Convert to cm

    return (distance > 0 && distance < 400) ? distance : -1;  // Filter out invalid readings
}

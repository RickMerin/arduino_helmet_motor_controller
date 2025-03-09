#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10
#define BUZZER_PIN 6
#define MOTOR_PIN 5

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";  // Must match sender address

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(MOTOR_PIN, OUTPUT);
    digitalWrite(MOTOR_PIN, LOW);  // Ensure motor is off initially

    Serial.println("Initializing nRF24L01...");

    if (!radio.begin()) {
        Serial.println("❌ nRF24L01 module not detected! Check connections.");
        while (1);  // Halt execution
    }

    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_LOW);
    radio.startListening();  // Set to receive mode

    Serial.println("✅ nRF24L01 module detected successfully!");

    // **Buzzer Alert for Successful Module Detection**
    tone(BUZZER_PIN, 1000);  // Play a 1 kHz tone
    delay(500);
    noTone(BUZZER_PIN);
}

void loop() {
    if (radio.available()) {
        char receivedMessage[32] = "";
        radio.read(&receivedMessage, sizeof(receivedMessage));

        Serial.print("📩 Received: ");
        Serial.println(receivedMessage);

        if (strcmp(receivedMessage, "TRIGGER_MOTOR") == 0) {
            Serial.println("⚡ Triggering motor...");
            digitalWrite(MOTOR_PIN, HIGH);  // Turn on motor
            delay(3000);  // Keep motor running for 3 seconds
            digitalWrite(MOTOR_PIN, LOW);  // Turn off motor
        }
    }
}

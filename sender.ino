#include "SPI.h"
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN 9
#define CSN_PIN 10
#define INTERVAL_MS_TRANSMISSION 250

// Ultrasonic Sensor Pins
#define TRIG_PIN 8
#define ECHO_PIN 7

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

struct payload {
    byte data1;
    char data2;
} __attribute__((packed));

payload payloadData;

void setup() {
    Serial.begin(115200);
    
    // Setup Ultrasonic Sensor
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    radio.begin();
    radio.setAutoAck(false);  // Enable ACK
    radio.setRetries(15, 15); // High retry count
    radio.setDataRate(RF24_250KBPS);
    radio.setPALevel(RF24_PA_LOW);  // Try a lower power level
    radio.setPayloadSize(sizeof(payload));
    radio.openWritingPipe(address);
    radio.stopListening();
    radio.setChannel(76);  // Use a common channel

    Serial.print("Payload size: ");
    Serial.println(sizeof(payload));
    radio.printDetails();  // Print radio configuration
}


long readUltrasonicDistance() {
    // Send a 10us pulse to trigger the ultrasonic sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure the time of the echo pulse
    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2;  // Calculate distance in cm
    return distance;
}

void loop() {
    long distance = readUltrasonicDistance();

    // Only send data if distance is 15 cm or below
    if (distance <= 15) {
        // Limit distance to a byte range (0-255)
        payloadData.data1 = (distance > 255) ? 255 : distance;
        payloadData.data2 = 'x';

        Serial.println("\n--- Sending Data ---");
        Serial.print("Distance (cm): ");
        Serial.println(payloadData.data1);
        Serial.print("Data2: ");
        Serial.println(payloadData.data2);

        bool success = radio.write(&payloadData, sizeof(payloadData));

        if (success) {
            Serial.println("Status: ✅ Message sent successfully!");
        } else {
            Serial.println("Status: ❌ Message failed! Retrying...");
        }
    } else {
        Serial.println("Distance is above 15 cm, no data sent.");
    }

    delay(INTERVAL_MS_TRANSMISSION);
}

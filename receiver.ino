#include "SPI.h"
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

struct payload {
    byte data1;
    char data2;
} __attribute__((packed));

payload payloadData;

void setup() {
    Serial.begin(115200);
    Serial.println("Receiver Starting...");

    // Setup Buzzer
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);

    radio.begin();
    radio.setAutoAck(true);  // Enable ACK
    radio.setRetries(15, 15); // High retry count
    radio.setDataRate(RF24_250KBPS);
    radio.setPALevel(RF24_PA_LOW);  // Try a lower power level
    radio.setPayloadSize(sizeof(payload));
    radio.openReadingPipe(1, address);
    radio.startListening();
      radio.setChannel(76);  // Use a common channel

    Serial.print("Payload size: ");
    Serial.println(sizeof(payload));
    radio.printDetails();  // Print radio configuration
}



void loop() {
  if (radio.available()) {
    radio.read(&payloadData, sizeof(payloadData));

    Serial.println("\n--- Received Data ---");
    Serial.print("Distance (cm): ");
    Serial.println(payloadData.data1);
    Serial.print("Data2: ");
    Serial.println(payloadData.data2);

    // Print the raw byte data to debug
    Serial.print("Raw byte 1: ");
    Serial.println(payloadData.data1, HEX);
    Serial.print("Raw byte 2: ");
    Serial.println(payloadData.data2, HEX);

    Serial.println("🚨 Alert: Distance threshold reached!");
} else {
    Serial.println("Waiting for data...");
}

    delay(500);  // Adjust delay as needed
}

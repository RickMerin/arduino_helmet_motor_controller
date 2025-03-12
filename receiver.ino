#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  Serial.println("Receiver is ready");

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_HIGH);
  radio.openReadingPipe(1, address);
  radio.startListening();

  // Verify the module is in listening mode
  if (radio.isChipConnected()) {
    Serial.println("nRF24L01+ connected successfully.");
  } else {
    Serial.println("nRF24L01+ not detected!");
  }

  // Print detailed configuration
  radio.printDetails();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println("Received message: ");
    Serial.println(text);
  }
}

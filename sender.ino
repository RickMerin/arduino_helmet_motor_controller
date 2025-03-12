#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10
#define INTERVAL_MS_TRANSMISSION 1000

RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

void setup() {
  Serial.begin(115200);
  Serial.println("Transmitter is ready");

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_HIGH);
  radio.openWritingPipe(address);
  radio.stopListening();

  Serial.println("Data Rate: " + String(radio.getDataRate()));
  Serial.println("PA Level: " + String(radio.getPALevel()));
  radio.printDetails();
}

void loop() {
  const char text[] = "Hello";

  if (radio.write(&text, sizeof(text))) {
    Serial.println("Transmission successful!");
    Serial.print("Sent message: ");
    Serial.println(text);
  } else {
    Serial.println("Transmission failed!");
  }

  delay(INTERVAL_MS_TRANSMISSION);
}

//arduino code
#include <SPI.h>
#include "Adafruit_MAX31855.h"

#define MAXDO   11
#define MAXCS   12
#define MAXCLK  13
#define RELAY_PIN   8

Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);

  while (!Serial) delay(1);

  if (!thermocouple.begin()) {
    Serial.println("ERROR.");
  }

}

void loop() {
  double c = thermocouple.readCelsius();
  Serial.println(c);

  if (c < 35) {
    Serial.println(c);
    digitalWrite(RELAY_PIN, HIGH);
    delay (200);
    Serial.println(c);
    digitalWrite(RELAY_PIN, LOW);
    delay (200);
    Serial.println(c);
    delay (200);
  } else {
    Serial.println(c);
    delay (200);
    Serial.println(c);
    delay (200);
    Serial.println(c);
    delay (200);
  }
}

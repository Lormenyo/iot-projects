
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define LED 4        // Digital pin connected to the LED
#define LDR A0       // Analog pin for LDR
#define DHTTYPE DHT21   // DHT 21 (AM2301

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor.

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(LED, OUTPUT); 
//  digitalWrite(LED, L);
  dht.begin();
}

void blinkLed (int led) {
  digitalWrite(led, HIGH);
  delay(700);
  digitalWrite(led, LOW);
  delay(1000);
}

void loop() {

  int sensorValue = analogRead(LDR); // read the input on analog pin 0
  float voltage = sensorValue * (5.0 / 1023.0);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  if (t < 33.0 || sensorValue > 200) {
    blinkLed(LED);
  }

  Serial.print(F("LDR: "));
  Serial.print(sensorValue);
  Serial.print(F("  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  LED Status: "));
  digitalRead(LED) == 1 ? Serial.println("ON") : Serial.println("OFF");

  // Wait a few seconds between measurements.
  delay(5000);
}




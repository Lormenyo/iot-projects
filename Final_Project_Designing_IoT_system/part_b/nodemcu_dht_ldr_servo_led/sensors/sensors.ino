
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT21   // DHT 21 (AM2301

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor.

float temperature_threshold = 31.0;
float humidity_threshold = 82.0;


void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(LED, OUTPUT); 

  dht.begin();
}


void blinkLed (int led) {
  digitalWrite(led, HIGH);
  delay(700);
  digitalWrite(led, LOW);
  delay(1000);
}

void loop() {
  
  // Wait a few seconds between measurements.
  delay(2000);

  int sensorValue = analogRead(LDR); // read the input on analog pin 0
//  float voltage = sensorValue * (5.0 / 1023.0);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();


  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

 if (h > humidity_threshold){
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.println("%");
  }
 if (t > temperature_threshold){
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println("°C ");
 }

}

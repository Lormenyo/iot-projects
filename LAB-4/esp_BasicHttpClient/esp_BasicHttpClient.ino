/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT21   // DHT 21 (AM2301

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor.

ESP8266WiFiMulti WiFiMulti;

String sensorLocation = "MyRoom";
String Name = "Hannah";


void setup() {

  pinMode(A0, INPUT); //DECLARING A0 as input for LDR
  
  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("GOD_IS_GOOD", "bjbjb,bjhcxrt68ujkuyjugfy6tyuhugjg tf5656800-0");

   dht.begin();
}

void loop() {

  int ldrStatus = analogRead(A0);  //read the LDR value

      // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();


    // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    
    float sensorValues[3] = {ldrStatus,h,t};
    
    for (int i; i<3;i++){
        String sensorName = i==0?"LDR":"DHT21";
        String sensorType = i==0?"LightIntensity":i==1?"Humidity":"Temperature";
        delay(1000);
       if (http.begin(client, "http://192.168.137.1/iot/LAB/lab4/insert.php?insert&SensorName="
                                                +  sensorName
                                                + "&SensorType="
                                                + sensorType
                                                + "&CurrentReading="+ String(sensorValues[i])
                                                + "&SensorLocation="+
                                                sensorLocation+
                                                "&Name="+ Name)) {  // HTTP



      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } 
      else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }
      }

  }
   else {
      Serial.printf("[HTTP} Unable to connect\n");
    }

  delay(10000);
}

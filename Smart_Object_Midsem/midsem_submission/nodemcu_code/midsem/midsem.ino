#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT21   // DHT 21 (AM2301

#define BUZZER 5 //D1
#define LED 4 //D2
#define WATER_LEVEL A0 //A0

#define THREE_SECONDS 3000
#define FIVE_SECONDS 5000

#define WATER_LEVEL_THRESHOLD 6
#define TEMP_THRESHOLD 32
#define HUMIDITY_THRESHOLD 78

void connectWifi();
void sendSensorData(String sensorName,
                    String sensorType,
                    float averageSensorValue,
                    unsigned long MillisTime,
                    String ActuatorType,
                    String ActuatorValue);

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor.
ESP8266WiFiMulti WiFiMulti;

unsigned long current_time;
unsigned long last_runA = 0;
unsigned long last_runB = 0;

float h, t;
int water_level;
int dht_sensor_reads = 0;
int water_level_reads = 0;
float average_dht_temp = 0;
float average_dht_humidity = 0;
float average_water_level = 0;



String Location = "room";
String Name = "Hannah";

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(WATER_LEVEL, INPUT);
  
  Serial.begin(115200);

  connectWifi();

  dht.begin();

//  digitalWrite(LED, LOW);
}

void loop() {

    current_time = millis();

    if (current_time - last_runA >= THREE_SECONDS ) {
        // save the last time you blinked the LED
        last_runA = current_time;
        
        // Reading temperature or humidity takes about 250 milliseconds!
        // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
       h = dht.readHumidity();
        // Read temperature as Celsius (the default)
        t = dht.readTemperature();

        // Check if any reads failed and exit early (to try again).
        if (isnan(h) || isnan(t)) {
            Serial.println(F("Failed to read from DHT sensor!"));
        return;
        }

         //Check if thresholds have been exceeded
        if (h >= HUMIDITY_THRESHOLD || t >= TEMP_THRESHOLD){
            digitalWrite(LED, HIGH);
          }
         else{
            digitalWrite(LED, LOW);
          }

        


        if (dht_sensor_reads < 3){
            average_dht_temp =  average_dht_temp + (t/3);
            average_dht_humidity = average_dht_humidity + (h/3);
          }
        else{
          String actuatorValue = digitalRead(LED)? "ON" : "OFF";
          //send the average of the 3 readings and reset the values
          sendSensorData("DHT21",  "Humidity", average_dht_humidity, last_runA, "LED", actuatorValue);
          sendSensorData("DHT21",  "Temperature", average_dht_temp, last_runA, "LED", actuatorValue);
          
            dht_sensor_reads = 0;
            average_dht_temp = 0;
            average_dht_humidity = 0;
          }

        //increment sensor reads
        dht_sensor_reads ++;
       
        Serial.print("Temperature: ");
        Serial.print(t);
        Serial.print(" Humidity: ");
        Serial.println(h);
    }

    if (current_time - last_runB >= FIVE_SECONDS ) {
        // save the last time you blinked the LED
        last_runB = current_time;
        
          water_level = analogRead(WATER_LEVEL);

         //CHECK IF THRESHOLD HAS BEEN EXCEEDED
         if (water_level >= WATER_LEVEL_THRESHOLD){
              digitalWrite(BUZZER, HIGH);
          }
         else{
            digitalWrite(BUZZER, LOW);
          }


       if (water_level_reads < 3){
            average_water_level =  average_water_level + (water_level/3);
          }
        else{
          String actuatorValue = digitalRead(BUZZER)? "ON" : "OFF";

 
          //send the average of the 3 readings and reset the values
          sendSensorData("WaterLevel",  "WaterLevel", average_water_level, last_runB, "BUZZER", actuatorValue);
          
            water_level_reads = 0;
            average_water_level = 0;

          }

        //increment sensor reads
        water_level_reads ++;
       
          Serial.print("Water level: ");
          Serial.println(water_level);
    }
  

  delay(2000);


}


void connectWifi(){
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
  }


void sendSensorData(String sensorName,
                    String sensorType,
                    float averageSensorValue,
                    unsigned long MillisTime,
                    String ActuatorType,
                    String ActuatorValue){
    // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    
    if (http.begin(client, "http://192.168.137.1/iot/LAB/midsem/insert.php?insert&SensorName="
                                                +  sensorName
                                                + "&SensorType="
                                                + sensorType
                                                + "&averageSensorValue="+ String(averageSensorValue)
                                                + "&Location="
                                                + Location
                                                + "&Name="+ Name
                                                + "&MillisTime="
                                                + String(MillisTime)
                                                + "&ActuatorType="
                                                + ActuatorType
                                                + "&ActuatorValue="
                                                + ActuatorValue
                                                )) {  // HTTP

    Serial.print(" SensorName= ");
     Serial.print(sensorName);
     Serial.print(" SensorType= ");
     Serial.print(sensorType);
     Serial.print(" averageSensorValue= ");
     Serial.print(averageSensorValue);
     Serial.print(" Location= ");
     Serial.print(Location);
     Serial.print(" Name= ");
     Serial.print(Name);
     Serial.print(" MillisTime= ");
     Serial.print(MillisTime);
          Serial.print(" ActuatorType= ");
     Serial.print(ActuatorType);
          Serial.print(" ActuatorValue= ");
     Serial.println(ActuatorValue);
     
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

   else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

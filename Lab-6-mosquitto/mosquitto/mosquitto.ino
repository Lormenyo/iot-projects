/*
 Basic MQTT example
 This sketch demonstrates the basic capabilities of the library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.

*/
/*this section is to use timere  */
unsigned long previousMillis = 0;
const long interval = 1000;

//modified by N Amanquah
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT21   // DHT 21 (AM2301

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor.

//Use a hotspot
#define wifi_ssid "." 
#define wifi_password "Vivamussitametfaucibusmauriseusodalesex"

#define server "192.168.0.190"
#define mqtt_user ""
#define mqtt_password ""

#define THREE_SECONDS 3000

unsigned long current_time;
unsigned long last_run = 0;

WiFiClient espClient;
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

PubSubClient client(espClient);

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("AshesiOutTopic","Welcome to Hannah's World");
      // ... and resubscribe
      client.subscribe("AshesiOutTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(57600);              //when you open serial terminal, chnge 9600
  client.setServer(server, 1883);
  client.setCallback(callback);
  setup_wifi();
  // Allow the hardware to sort itself out
  delay(1500);

  dht.begin();
}

void loop()
{
  if (!client.connected()) {
    reconnect();   
  }
  client.loop();  
//------------------------------------------
//post after every 3 secondS ---------------------
  //figure out how to post after every few seconds (based on earlier work)
//------------------------------------------
   current_time = millis();

    if (current_time - last_run >= THREE_SECONDS) {
        // save the last time you blinked the LED
        last_run = current_time;
         int sensorValue = analogRead(A0); // read the input on analog pin 0
         String ldrValue = String(sensorValue);
         float t = dht.readTemperature();
         String temp = String(t);
         client.publish("LDRSensorValues", ldrValue.c_str());
         client.publish("TemperatureValues", temp.c_str());
         Serial.print("LDR: ");
         Serial.print(ldrValue);
         Serial.print(" Temperature: ");
         Serial.print(temp);
         Serial.println("Message published");
  }

         client.subscribe("LDRSensorValues");
         client.subscribe("TemperatureValues");
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);
  WiFi.begin(wifi_ssid, wifi_password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

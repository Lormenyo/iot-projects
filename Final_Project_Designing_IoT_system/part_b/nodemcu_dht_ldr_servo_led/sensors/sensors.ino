
#include "DHT.h"
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
 
Servo servo;

#define DHTPIN 2     //D4 Digital pin connected to the DHT sensor
#define DHTTYPE DHT21   // DHT 21
#define SERVOPIN 4    //D2
#define LED1 16 //D0
#define LED2  5//D1
#define LDR A0

#define MQTT_PATH1  "Room/devices/temp"
#define MQTT_PATH2  "Room/devices/ldr"
#define MQTT_PATH3  "Room/devices/humidity"
#define MQTT_PATH4  "Room/devices/led1"
#define MQTT_PATH5  "Room/devices/led2"
#define MQTT_PATH6  "Room/devices/servo"

//Use a hotspot
#define wifi_ssid "." 
#define wifi_password "ex()141499"

#define server "192.168.0.194"
#define mqtt_user ""
#define mqtt_password ""

#define TEN_SECONDS 10000

unsigned long current_time;
unsigned long last_run = 0;

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor.

float temperature_threshold = 32.0;
float humidity_threshold = 82.0;
int ldr_threshold = 200;

bool isClockwise = 1; //less than threshold
bool isLed1Off = 1; //less than threshold
bool isLed2Off = 1; //less than threshold

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


void setup() {
//  Serial.begin(115200);
  Serial.begin(57600);              //when you open serial terminal, chnge 9600
  Serial.println(F("DHTxx test!"));
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  servo.attach(SERVOPIN); 

   
  client.setServer(server, 1883);
  client.setCallback(callback);
  setup_wifi();

  dht.begin();
}


void turnOnLed (int led, int ledNum) {

  //for Led 1
  if (isLed1Off && !(ledNum-1)){
    digitalWrite(led, HIGH);
    isLed1Off = 0;
  }

  //for Led 2
  if (isLed2Off && (ledNum-1)){
    digitalWrite(led, HIGH);
    isLed2Off = 0;
  }
}

void turnOffLed(int led, int ledNum){
  //for led 1
  if (!isLed1Off && !(ledNum-1)){
    digitalWrite(led, LOW);
    isLed1Off = 1;
  }

  //for led 2
  if (!isLed2Off && (ledNum-1)){
    digitalWrite(led, LOW);
    isLed2Off = 1;
  }
  
}

void turnServoClockwise(){
  int pos;

  if (isClockwise){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
    isClockwise = 0;  
  }
}

void turnServoAnticlockwise(){

  if (!isClockwise){
    int pos;
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
    isClockwise = 1;
  }
}




void loop() {
  
  if (!client.connected()) {
    reconnect();   
  }
  client.loop();  
  // Wait a few seconds between measurements.
  delay(2000);

  int sensorValue = analogRead(LDR); // read the input on analog pin 0
  Serial.println(sensorValue);

  if (sensorValue > ldr_threshold){
     turnOnLed(LED1, 1);
  }
  else{
    turnOffLed(LED1, 1);
   }

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

 if (h > humidity_threshold){
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.println("%");
    turnOnLed(LED2, 2);
    Serial.print("Exceeded isLED2On:");
  Serial.println(isLed2Off); //should be 0
  }
 else{
    turnOffLed(LED2, 2);
  }
 
 if (t > temperature_threshold){
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println("°C ");
  turnServoClockwise();
  Serial.print("Exceeded isClockwise:");
  Serial.println(isClockwise); //should be 0
 }
 else{
  turnServoAnticlockwise();
  Serial.print("Not Exceeded isClockwise:");
  Serial.println(isClockwise);  //should be 1
  }

//------------------------------------------
//post after every 10 secondS ---------------------
  //figure out how to post after every few seconds (based on earlier work)
//------------------------------------------
   current_time = millis();

    if (current_time - last_run >= TEN_SECONDS) {
        // save the last time you blinked the LED
        last_run = current_time;
  
         String ldrValue = String(sensorValue);
         String temp = String(t);
         String humidity = String(h);
         String servo = isClockwise ? "CLOCKWISE" : "ANTICLOCKWISE";
         String led1 = isLed1Off ? "OFF" : "ON";
         String led2 = isLed2Off ? "OFF" : "ON";
         client.publish(MQTT_PATH2, ldrValue.c_str());
         client.publish(MQTT_PATH1, temp.c_str());
         client.publish(MQTT_PATH3, humidity.c_str());
         client.publish(MQTT_PATH4, led1.c_str());
         client.publish(MQTT_PATH5, led2.c_str());
         client.publish(MQTT_PATH6, servo.c_str());
         Serial.println("Message published");
  }

}

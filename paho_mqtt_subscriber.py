#ok
import paho.mqtt.client as mqtt
import time
from connect_db import *

# MQTT_SERVER = "broker.hivemq.com"
# MQTT_PATH = "AshesiInTopic"
MQTT_SERVER = "192.168.0.104"
MQTT_PATH_DISTANCE = "AshesiInTopic/Ultrasonic"
MQTT_PATH_TEMP = "AshesiInTopic/dht"
 
# The callback when conected.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc)) 
    # client.subscribe(MQTT_PATH_DISTANCE)
    # client.subscribe(MQTT_PATH_TEMP)
    client.subscribe("AshesiInTopic/#")
 
# Callback when message received
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))
    reading = float(msg.payload.decode('utf-8'))
    print(reading)
    print ("This listens to AshesiInTopic")
    if msg.topic == "AshesiInTopic/Ultrasonic":
        insert_into_db('Ultrasonic', 'Distance', reading, 'Room', 'Hannah')
    if msg.topic == "AshesiInTopic/dht":
        insert_into_db('DHT', 'Temperature', reading, 'Room', 'Hannah')
    # insert_into_db()
    
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
 
client.connect(MQTT_SERVER, 1883, 60)

client.loop_forever()

#client.loop_start() #start the loop
#time.sleep(10) # wait
#client.loop_stop() #stop the loop
 
# Blocking call-  processes messages client.loop_forever()

#ok
import paho.mqtt.client as mqtt
import time
from connect_db import *
import traceback


MQTT_SERVER = "localhost"

MQTT_PATH1 = "IoTClass/devices/temp1"
MQTT_PATH2 = "IoTClass/devices/temp2"
MQTT_PATH3 = "IoTClass/devices/ldr"
MQTT_PATH4 = "IoTClass/devices/heater"
MQTT_PATH5 = "IoTClass/devices/humidity1"
MQTT_PATH6 = "IoTClass/devices/humidity2"
MQTT_PATH7 = "IoTClass/devices/pump"
 

num_of_failed_inserts = 0


# The callback when conected.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc)) 
    # subscribe to topics using the # wildcard
    client.subscribe("IoTClass/devices/#")
 
# Callback when message received
def on_message(client, userdata, msg):
    global num_of_failed_inserts
    print("========= new message ============")
    print(msg.topic+" "+str(msg.payload))
    reading = msg.payload.decode('utf-8')
    # print(reading)
    print ("This listens to IoTClass/devices")

    if reading == "ON":
        reading = 1
    if reading == "OFF":
        reading = 0
    try:
        if msg.topic == MQTT_PATH1:
            insert_into_db("temp1", 'Temperature Sensor', float(reading))
        elif msg.topic == MQTT_PATH2:
            insert_into_db("temp2", 'Temperature Sensor', float(reading))
        elif msg.topic == MQTT_PATH3:
            insert_into_db("ldr", 'Light Intensity Sensor', float(reading))
        elif msg.topic == MQTT_PATH4:
            insert_into_db("heater", 'Heater Actuator', float(reading))
        elif msg.topic == MQTT_PATH5:
            insert_into_db("humidity1", 'Humidity Sensor', float(reading))
        elif msg.topic == MQTT_PATH6:
            insert_into_db("humidity2", 'Humidity Sensor', float(reading))
        else:
            insert_into_db("pump", 'Pump Actuator', float(reading))

    except Exception as e:
        num_of_failed_inserts += 1
        print(f"insert failed {num_of_failed_inserts}")
        print(e)
        print(traceback.format_exc())



    
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
 
client.connect(MQTT_SERVER, 1883, 60)

client.loop_forever()

#client.loop_start() #start the loop
#time.sleep(10) # wait
#client.loop_stop() #stop the loop
 
# Blocking call-  processes messages client.loop_forever()

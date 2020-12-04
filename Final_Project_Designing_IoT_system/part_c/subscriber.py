#ok
import paho.mqtt.client as mqtt
import time
from connect_db import *


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
    print("new message")
    print(msg.topic+" "+str(msg.payload))
    reading = msg.payload.decode('utf-8')
    # print(reading)
    print ("This listens to IoTClass/devices")
    try:
        insert_topic_data(msg.topic, reading)
    except:
        num_of_failed_inserts += 1
        print(f"insert failed {num_of_failed_inserts}")



def insert_temp(name, reading):
    insert_into_db(name, 'Temperature', float(reading))
    return


def insert_humidity(name, reading):
    insert_into_db(name, 'Humidity',  float(reading))
    return


def insert_ldr(reading):
    insert_into_db("ldr", 'Light Intensity',  float(reading))
    return

def insert_heater(reading):
    if reading == "OFF":
        reading = 0.0
    else:
        reading = 1.0
    insert_into_db("heater", 'Heater Actuator', reading)
    return

def insert_pump(reading):
    if reading == "OFF":
        reading = 0.0
    else:
        reading = 1.0
    insert_into_db("pump", 'Pump Actuator', reading)
    return

def insert_topic_data(argument, reading):
    switcher = {
        MQTT_PATH1: insert_temp("temp1", reading),
        MQTT_PATH2: insert_temp("temp2", reading),
        MQTT_PATH3: insert_ldr(reading),
        MQTT_PATH4: insert_heater(reading),
        MQTT_PATH5: insert_humidity("humidity1", reading),
        MQTT_PATH6: insert_humidity("humidity2", reading),
        MQTT_PATH7: insert_pump(reading),
    }
    print(f"Argument - {argument}")
    # Get the function from switcher dictionary
    func = switcher.get(argument, lambda: "Invalid path")
    # if func:
    #     func()

    
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
 
client.connect(MQTT_SERVER, 1883, 60)

client.loop_forever()

#client.loop_start() #start the loop
#time.sleep(10) # wait
#client.loop_stop() #stop the loop
 
# Blocking call-  processes messages client.loop_forever()

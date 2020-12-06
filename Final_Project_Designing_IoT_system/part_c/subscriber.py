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
num_of_successful_inserts = 0
temp1 = 0
temp2 = 0
ldr = 0
heater = 0
humidity1 = 0
humidity2 = 0
pump = 0

# The callback when conected.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc)) 
    # subscribe to topics using the # wildcard
    client.subscribe("IoTClass/devices/#")
 
# Callback when message received
def on_message(client, userdata, msg):
    global num_of_failed_inserts
    global num_of_successful_inserts
    global temp1
    global temp2
    global ldr
    global heater
    global humidity1
    global humidity2
    global pump
    print("========= new message ============")
    print(msg.topic+" "+str(msg.payload))
    reading = msg.payload.decode('utf-8')
    # print(reading)
    print ("This listens to IoTClass/devices")

    try:
        if msg.topic == MQTT_PATH1:
            temp1 = float(reading)
        elif msg.topic == MQTT_PATH2:
            temp2 = float(reading)
        elif msg.topic == MQTT_PATH3:
            ldr = float(reading)
        elif msg.topic == MQTT_PATH4:
            heater = reading
        elif msg.topic == MQTT_PATH5:
            humidity1 = float(reading)
        elif msg.topic == MQTT_PATH6:
            humidity2 = float(reading)
        else:
            pump = reading

        
        
        insert_into_db(temp1, temp2, ldr, heater, humidity1, humidity2, pump)
        temp1 = 0
        temp2 = 0
        ldr = 0
        heater = 0
        humidity1 = 0
        humidity2 = 0
        pump = 0
        num_of_successful_inserts += 1
        print(f"----Insert #{num_of_successful_inserts} Successful----")

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

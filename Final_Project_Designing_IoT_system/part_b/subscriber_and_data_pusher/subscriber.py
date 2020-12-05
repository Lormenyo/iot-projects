import paho.mqtt.client as mqtt
import time
from connect_db import *
import traceback


MQTT_SERVER = "localhost"

MQTT_PATH1 = "Room/devices/temp"
MQTT_PATH2 = "Room/devices/ldr"
MQTT_PATH3 = "Room/devices/humidity"
MQTT_PATH4 = "Room/devices/led1"
MQTT_PATH5 = "Room/devices/led2"
MQTT_PATH6 = "Room/devices/servo"
 

num_of_failed_inserts = 0
ldr = 0
temp = 0
humidity = 0
led1 = 0
led2 = 0
servo = 0


# The callback when conected.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc)) 
    # subscribe to topics using the # wildcard
    client.subscribe("Room/devices/#")
 
# Callback when message received
def on_message(client, userdata, msg):
    global num_of_failed_inserts
    global ldr 
    global temp
    global humidity
    global led1
    global led2
    global servo 
    print("========= new message ============")
    print(msg.topic+" "+str(msg.payload))
    reading = msg.payload.decode('utf-8')
    # print(reading)
    print ("This listens to Room/devices/#")

    try:
        if msg.topic == MQTT_PATH1:
            temp = float(reading)
        elif msg.topic == MQTT_PATH2:
            ldr =  float(reading)
        elif msg.topic == MQTT_PATH3:
            humidity =  float(reading)
        elif msg.topic == MQTT_PATH4:
            led1 = reading
        elif msg.topic == MQTT_PATH5:
            led2 = reading
        else:
            servo = reading
   
        if (servo and ldr and led1 and led2 and temp and humidity):
            insert_into_db(led1, led2, servo, temp, humidity, ldr)
            ldr = 0
            temp = 0
            humidity = 0
            led1 = 0
            led2 = 0
            servo = 0
        

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

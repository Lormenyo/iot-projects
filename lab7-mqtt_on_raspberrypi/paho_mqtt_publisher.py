import paho.mqtt.publish as publish
import time 
from gpiozero import DistanceSensor
import adafruit_dht
import board



MQTT_SERVER = "192.168.0.104"
MQTT_PATH_DISTANCE = "AshesiInTopic/Ultrasonic"
MQTT_PATH_TEMP = "AshesiInTopic/dht"

# ldr = LightSensor(4)  # GPIO4
ultrasonic = DistanceSensor(echo=18, trigger=17)

 
# Initial the dht device, with data pin connected to:
dhtDevice = adafruit_dht.DHT22(board.D4, use_pulseio=False)




while True: 
    distance = ultrasonic.distance

    publish.single(MQTT_PATH_DISTANCE, distance, hostname=MQTT_SERVER)
    time.sleep(2)
    try:
        # read temperature from DHT
        temperature_c = dhtDevice.temperature
        publish.single(MQTT_PATH_TEMP, temperature_c, hostname=MQTT_SERVER)
        time.sleep(1)
    except RuntimeError as error:
        print(error.args[0])
    print(f'Distance: {distance}')
    print(f'Temp: {temperature_c}')

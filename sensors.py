from gpiozero import LightSensor, DistanceSensor
from time import sleep


ldr = LightSensor(18)  # GPIO24
ldr.wait_for_light()
ldrValue = ldr.value
print("Light detected!")


sensor = DistanceSensor(echo=18, trigger=17)
while True:
    print('Distance: ', sensor.distance * 100)
    sleep(1)


# Connect the GND pin of the sensor to a ground pin on the Pi.
# Connect the TRIG pin of the sensor a GPIO pin.
# Connect one end of a 330Ω resistor to the ECHO pin of the sensor.
# Connect one end of a 470Ω resistor to the GND pin of the sensor.
# Connect the free ends of both resistors to another GPIO pin.
#  This forms the required voltage divider.
# Finally, connect the VCC pin of the sensor to a 5V pin on the Pi.
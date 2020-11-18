

void setup() {
  
  Serial.begin(9600); // initialize serial communication at 9600

}

void printSensorValue(int sensorValue){
  Serial.print("Analog: ");
  Serial.print(sensorValue); // print out the sensor value you read
  Serial.print("  Voltage: ");
  float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
  Serial.println(voltage); // print out the value you read
}

void loop() {
  
  int sensorValue = analogRead(A0); // read the input on analog pin 0

  if (sensorValue > 350){
   printSensorValue(sensorValue);
  }

   if (sensorValue < 300){
   printSensorValue(sensorValue);
  }

}

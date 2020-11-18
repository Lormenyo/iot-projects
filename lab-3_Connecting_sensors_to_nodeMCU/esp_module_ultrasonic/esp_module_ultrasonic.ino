
#define  TRIGPIN 2
#define  ECHOPIN 0
long duration;
long distance;

void setup() {
  pinMode(TRIGPIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHOPIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  Serial.println("Measuring Distance......");
}

void loop() {
    
// Clears the trigPin
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);


 
// Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHOPIN, HIGH);

// Calculating the distance
  distance = duration*0.034/2;
//   Serial.println(distance);
// Prints the distance on the Serial Monitor
  if (distance > 10.0){
    Serial.print("Distance: ");
    Serial.println(distance);
    }

delay(2000);
}

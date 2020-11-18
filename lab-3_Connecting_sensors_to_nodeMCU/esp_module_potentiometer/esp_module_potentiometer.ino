

void setup()
{
 Serial.begin(9600); 
 pinMode(A0, INPUT);
 pinMode(LED_BUILTIN, OUTPUT);
}


void loop()
{
 int potentiometer = analogRead(A0);
 Serial.println(potentiometer);
 analogWrite(LED_BUILTIN, potentiometer);
}


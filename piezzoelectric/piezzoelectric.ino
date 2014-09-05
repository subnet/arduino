int inputPin=4;  // connect digital I/O 4 to the ECHO/Rx Pin
int outputPin=5; // connect digital I/O 5 to the TRIG/TX Pin

void setup()
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
}
void loop()
{
   digitalWrite(outputPin, LOW);  // send low pulse for 2μs
   delayMicroseconds(2);
   digitalWrite(outputPin, HIGH); // send high pulse for 10μs
   delayMicroseconds(10);
   digitalWrite(outputPin, LOW);  // back to low pulse
   int distance = pulseIn(inputPin, HIGH);  // read echo value
   int distance1= distance/29/2;  // in cm
   Serial.println(distance1); 
   delay(50);  
}

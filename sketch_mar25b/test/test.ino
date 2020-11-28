#include<Servo.h>
#define danger 6
Servo servo;
const int trigPin = 12;
const int echoPin = 13;
long duration;
int distance;

void setup() {
 servo.attach(7);
  servo.write(0);
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); 

Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,HIGH);
  _delay_ms(500);
  digitalWrite(trigPin, LOW);
  
  duration=pulseIn(echoPin,HIGH); 
  distance=(duration/2)/29.1; 
  Serial.println(distance);
delay (500);

if(distance<=6){
  servo.write(90);
  delay(500);
  servo.write(180);
}
}
int dist(){
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}

#include<Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
servo.attach(7);
servo.write(0);
delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
servo.write(90);
delay(100);
servo.write(390);
delay(100);
}


const int trigPin = 12;
const int echoPin = 13;
long duration;
int distance;
int dist();
int dis1;
int dis2;
int dis;
void stopm(void);
void forward(void);
void inputs(void);
void sharpright(void);
void sharprleft(void);
void backward(void);
void servocon();
void setup() {
   servo.attach(7);
servo.write(0);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
digitalWrite(ENA,75);
  digitalWrite(ENB,75);
//pinMode(SENSOROUTPUT, INPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
dis==dist();
delay(500);
if(dis<=danger){
  stopm();
  delay(300);
  backward();
  delay(100);
  //servocon();
 sharpleft();
  delay(100);
    forward();
}

else{
 servo.write(90);
  forward();
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
void forward(void)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backward(void){
 digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}

void sharpright()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
 
}

void sharpleft()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 
}


void stopm(void)
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}




void servocon(){
servo.write(14);
  delay(500);
   dis1=dist();
  servo.write(144);
  delay(500);
   dis2=dist();
  if(dis1<dis2){
    sharpleft();
    delay(500);
    forward();
  }
  else{
    sharpright();
    delay(500);
     forward();
  }
  
}


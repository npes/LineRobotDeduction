#include <TimerOne.h>

int leftSensor=7;
int rightSensor=8;
int motorLeftA=6;
int motorRightA=10;
int motorLeftB=9;
int motorRightB=3;
int motorLeftSpeed=5;
int motorRightSpeed=11;
const int led = LED_BUILTIN;  // the pin with a LED
volatile int leftCounter = 0; // use volatile for shared variables
volatile int rightCounter = 0; // use volatile for shared variables
void zeroTurnCounters(void);

void setup() {
  // put your setup code here, to run once:
  {
pinMode(led, OUTPUT);
Timer1.initialize(400000); //microseconds
Timer1.attachInterrupt(zeroTurnCounters); // blinkLED to run every 0.15 seconds

pinMode (leftSensor, INPUT);
pinMode (rightSensor, INPUT);
pinMode (motorLeftA, OUTPUT);
pinMode (motorRightA, OUTPUT);
pinMode (motorLeftB, OUTPUT);
pinMode (motorRightB, OUTPUT);
pinMode (motorLeftSpeed, OUTPUT);
pinMode (motorRightSpeed, OUTPUT);
}
}


void loop() {
  // put your main code here, to run repeatedly:
int stateLeftSensor=digitalRead (leftSensor);
int stateRightSensor=digitalRead (rightSensor);
//delay(5);
int spd1=75; //turn speed fast wheel
int spd2=80; //forward speed
int spd3=70; //turn speed slow wheel
int spd4=80; //reverse speed
int cnt=4;

if (stateLeftSensor==LOW &&  stateRightSensor==HIGH) {
leftCounter++;
  if (leftCounter<=cnt){
    analogWrite(motorLeftSpeed, spd1);
    analogWrite(motorRightSpeed, spd3);

    digitalWrite(motorLeftA, HIGH);
    digitalWrite(motorLeftB, LOW);

    digitalWrite(motorRightA, HIGH);
    digitalWrite(motorRightB, LOW);
  }
  else if (leftCounter>cnt) {
    analogWrite(motorLeftSpeed, 150);
    analogWrite(motorRightSpeed, 0);

    digitalWrite(motorLeftA, HIGH);
    digitalWrite(motorLeftB, LOW);

    digitalWrite(motorRightA, HIGH);
    digitalWrite(motorRightB, LOW);
  }
  }
else if (stateLeftSensor==HIGH &&  stateRightSensor==LOW){
rightCounter++;
  if (rightCounter<=cnt){
  analogWrite(motorLeftSpeed, spd3);
  analogWrite(motorRightSpeed, spd1);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
  }
  else if (rightCounter>=cnt){
  analogWrite(motorLeftSpeed, 0);
  analogWrite(motorRightSpeed, 150);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
  }
}
else if (stateLeftSensor==HIGH &&  stateRightSensor==HIGH){

  analogWrite(motorLeftSpeed, spd2);
  analogWrite(motorRightSpeed, spd2);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
}
else if (stateLeftSensor==LOW &&  stateRightSensor==LOW){

  analogWrite(motorLeftSpeed, spd4);
  analogWrite(motorRightSpeed, spd4);

  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, HIGH);

  digitalWrite(motorRightA, LOW);
  digitalWrite(motorRightB, HIGH);
//  delay (200);
}
}

void zeroTurnCounters(void){
leftCounter=0;
rightCounter=0;
}

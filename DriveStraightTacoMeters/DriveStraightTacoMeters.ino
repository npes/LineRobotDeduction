#include <TimerOne.h>
#include <PinChangeInt.h>

#define leftTaco 7
#define rightTaco 8
int leftSensor=12;
int rightSensor=13;

int motorLeftA=6;
int motorRightA=10;
int motorLeftB=9;
int motorRightB=3;
int motorLeftSpeed=5;
int motorRightSpeed=11;

void leftTacoFunc ();
void rightTacoFunc();

volatile int leftCounter = 0; // use volatile for shared variables
volatile int rightCounter = 0; // use volatile for shared variables
volatile int setPoint = 4;
volatile int spdL = 100;
volatile int spdR = 100;
void SpeedCalibrate(void);

void setup() {

Timer1.initialize(60000); //microseconds
Timer1.attachInterrupt(SpeedCalibrate); // blinkLED to run every 0.15 seconds
pinMode(leftTaco, INPUT);
PCintPort::attachInterrupt(leftTaco, leftTacoFunc, RISING);  // add more attachInterrupt code as required
pinMode(rightTaco, INPUT);
PCintPort::attachInterrupt(rightTaco, rightTacoFunc, RISING);
pinMode (leftSensor, INPUT);
pinMode (rightSensor, INPUT);

pinMode (motorLeftA, OUTPUT);
pinMode (motorRightA, OUTPUT);
pinMode (motorLeftB, OUTPUT);
pinMode (motorRightB, OUTPUT);
pinMode (motorLeftSpeed, OUTPUT);
pinMode (motorRightSpeed, OUTPUT);

}


void loop() {
int stateLeftSensor=digitalRead (leftSensor);
int stateRightSensor=digitalRead (rightSensor);
//delay(5);
int spd1=100; //turn speed fast wheel
int spd2=150; //forward speed
int spd3=40; //turn speed slow wheel
int spd4=90; //reverse speed

if (stateLeftSensor==LOW &&  stateRightSensor==HIGH) {

  analogWrite(motorLeftSpeed, spd1);
  analogWrite(motorRightSpeed, spd3);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
}
else if (stateLeftSensor==HIGH &&  stateRightSensor==LOW){

  analogWrite(motorLeftSpeed, spd3);
  analogWrite(motorRightSpeed, spd1);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
}
else if (stateLeftSensor==HIGH &&  stateRightSensor==HIGH){

  analogWrite(motorLeftSpeed, spdL);
  analogWrite(motorRightSpeed, spdR);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
}
else if (stateLeftSensor==LOW &&  stateRightSensor==LOW){

  analogWrite(motorLeftSpeed, spdL);
  analogWrite(motorRightSpeed, spdR);

  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, HIGH);

  digitalWrite(motorRightA, LOW);
  digitalWrite(motorRightB, HIGH);
//  delay (200);
}
}

void SpeedCalibrate(void){
if (leftCounter<setPoint){
  spdL+=5;}
if (leftCounter>setPoint){
  spdL-=5;}
if (rightCounter<setPoint){
  spdR+=5;}
if (rightCounter>setPoint){
  spdR-=5;}
leftCounter=0;  
rightCounter=0;
}

void leftTacoFunc (){
  leftCounter++;
}
void rightTacoFunc(){
  rightCounter++;
}


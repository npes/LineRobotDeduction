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
volatile int setPoint = 8;
volatile int spdL = 30;
volatile int spdR = 30;
void SpeedCalibrate(void);

void setup() {

Timer1.initialize(100000); //microseconds
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
Serial.begin(9600);
}


void loop() {
int stateLeftSensor=digitalRead (leftSensor);
int stateRightSensor=digitalRead (rightSensor);
//delay(5);
int spd1=80; //turn speed fast wheel
//int spd2=150; //forward speed
int spd3=50; //turn speed slow wheel
//int spd4=90; //reverse speed

if (stateLeftSensor==LOW &&  stateRightSensor==HIGH) {

  analogWrite(motorLeftSpeed, spdL);
  analogWrite(motorRightSpeed, spdR-=50);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
}
else if (stateLeftSensor==HIGH &&  stateRightSensor==LOW){

  analogWrite(motorLeftSpeed, spdR-=50);
  analogWrite(motorRightSpeed, spdL);

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
//delay (10);
  analogWrite(motorLeftSpeed, spdL);
  analogWrite(motorRightSpeed, spdR);

  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, HIGH);

  digitalWrite(motorRightA, LOW);
  digitalWrite(motorRightB, HIGH);
//  delay (100);
}
Serial.print(spdL);
Serial.print(" - ");
Serial.println(spdR);
Serial.print(leftCounter);
Serial.print(" - ");
Serial.println(rightCounter);
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


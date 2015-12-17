//libraries
  #include <TimerOne.h>
  #include <PinChangeInt.h>

//pin definitions
  const int leftTaco=7;
  const int rightTaco=8;
  const int leftSensor=12;
  const int rightSensor=13;
  const int motorLeftA=6;
  const int motorRightA=10;
  const int motorLeftB=9;
  const int motorRightB=3;
  const int motorLeftSpeed=5;
  const int motorRightSpeed=11;

//variables used in interrupts, use volatile for shared variables
  volatile int leftCounter = 0;
  volatile int rightCounter = 0;
  volatile int setPoint = 80;
  volatile int spdL = 150;
  volatile int spdR = 150;

//global 
int stateLeftSensor;
int stateRightSensor;

// function prototypes
  void leftTacoFunc ();
  void rightTacoFunc();
  void SpeedCalibrate(void);

void setup() {

// interrupt init
  Timer1.initialize(1000000); //microseconds
  Timer1.attachInterrupt(SpeedCalibrate); // speedCalibrate to run every 1 second
  PCintPort::attachInterrupt(leftTaco, leftTacoFunc, RISING);
  PCintPort::attachInterrupt(rightTaco, rightTacoFunc, RISING);

//pins init
  pinMode(rightTaco, INPUT);
  pinMode(leftTaco, INPUT);
  pinMode (leftSensor, INPUT);
  pinMode (rightSensor, INPUT);
  pinMode (motorLeftA, OUTPUT);
  pinMode (motorRightA, OUTPUT);
  pinMode (motorLeftB, OUTPUT);
  pinMode (motorRightB, OUTPUT);
  pinMode (motorLeftSpeed, OUTPUT);
  pinMode (motorRightSpeed, OUTPUT);
//  Serial.begin(9600);
}


void loop() {

//read the IR sensors
stateLeftSensor=digitalRead (leftSensor);
stateRightSensor=digitalRead (rightSensor);

if (stateLeftSensor==LOW &&  stateRightSensor==HIGH) { //if true turn right 

  analogWrite(motorLeftSpeed, spdL);
  analogWrite(motorRightSpeed, spdR-=50);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
}
//read the IR sensors
stateLeftSensor=digitalRead (leftSensor);
stateRightSensor=digitalRead (rightSensor);

if (stateLeftSensor==HIGH &&  stateRightSensor==LOW){ //if true turn left

  analogWrite(motorLeftSpeed, spdL-=50);
  analogWrite(motorRightSpeed, spdR);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
}
//read the IR sensors
stateLeftSensor=digitalRead (leftSensor);
stateRightSensor=digitalRead (rightSensor);

if (stateLeftSensor==HIGH &&  stateRightSensor==HIGH){ //if true forward

  analogWrite(motorLeftSpeed, spdL);
  analogWrite(motorRightSpeed, spdR);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, HIGH);
  digitalWrite(motorRightB, LOW);
}
//read the IR sensors
stateLeftSensor=digitalRead (leftSensor);
stateRightSensor=digitalRead (rightSensor);

if (stateLeftSensor==LOW &&  stateRightSensor==LOW){ //if true reverse

  analogWrite(motorLeftSpeed, spdL);
  analogWrite(motorRightSpeed, spdR);

  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, HIGH);

  digitalWrite(motorRightA, LOW);
  digitalWrite(motorRightB, HIGH);
}

//debugging
/*Serial.print(spdL);
Serial.print(" - ");
Serial.println(spdR);
Serial.print(leftCounter);
Serial.print(" - ");
Serial.println(rightCounter);*/
}
/***** functions *****/

//increase or decrease speed according to setpoint
void SpeedCalibrate(void){ 
PCintPort::detachInterrupt(leftTaco); //Disable interrupts from taco's while timer1 interrupt 
PCintPort::detachInterrupt(rightTaco);  
if (leftCounter<setPoint){
  spdL+=10;}
if (leftCounter>setPoint){
  spdL-=10;}
if (rightCounter<setPoint){
  spdR+=10;}
if (rightCounter>setPoint){
  spdR-=10;}
leftCounter=0;  
rightCounter=0;
PCintPort::attachInterrupt(leftTaco, leftTacoFunc, RISING);
PCintPort::attachInterrupt(rightTaco, rightTacoFunc, RISING);
}

//increment left taco counter on each interrupt. 20 interrupts per wheel rotation
void leftTacoFunc (){
  leftCounter++;
}
//increment left taco counter on each interrupt. 20 interrupts per wheel rotation
void rightTacoFunc(){
  rightCounter++;
}


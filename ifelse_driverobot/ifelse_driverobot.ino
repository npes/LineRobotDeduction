int leftSensor=7;
int rightSensor=8;
int motorLeftA=6;
int motorRightA=10;
int motorLeftB=9;
int motorRightB=3;
int motorLeftSpeed=5;
int motorRightSpeed=11;

void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
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

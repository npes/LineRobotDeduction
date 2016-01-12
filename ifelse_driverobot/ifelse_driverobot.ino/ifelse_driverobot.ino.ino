int leftSensor=2;
int rightSensor=13;
int motorLeftA=6; //2
int motorRightA=10; //10
int motorLeftB=9;//7
int motorRightB=3;//15
int motorLeftSpeed=5;//1
int motorRightSpeed=11;//9

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
int spd2=100; //forward speed
int spd3=0; //turn speed slow wheel
int spd4=100; //reverse speed

if (stateLeftSensor==LOW &&  stateRightSensor==HIGH) {

  analogWrite(motorLeftSpeed, spd1);
  analogWrite(motorRightSpeed, spd3);

  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);

  digitalWrite(motorRightA, LOW);
  digitalWrite(motorRightB, HIGH);
}
/*else if (stateLeftSensor==HIGH &&  stateRightSensor==LOW){

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

  digitalWrite(motorLeftA, LOW);//2
  digitalWrite(motorLeftB, HIGH);//7

  digitalWrite(motorRightA, LOW);//10
  digitalWrite(motorRightB, HIGH);//15
//  delay (200);
}*/
}

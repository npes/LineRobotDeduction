// test of pins and motor driver
// vores gruppe
//int leftMotorF = 9; // pin 9 på arduino forbunet til pin 7 på motor driver
//int leftMotorR = 6; // pin 6 på arduino forbunet til pin 2 på motor driver
//int leftMotorEnable = 5; // pin 5 på arduino forbunet til pin 1 på motor driver
//int rightMotorF = 3; // pin 3 på arduino forbunet til pin 15 på motor driver
//int rightMotorR = 10; // pin 10 på arduino forbunet til pin 10 på motor driver
//int rightMotorEnable = 11; // pin 11 på arduino forbunet til pin 9 på motor driver

// ruben
int leftMotorF = 4; // pin 9 på arduino forbunet til pin 7 på motor driver
int leftMotorR = 6; // pin 6 på arduino forbunet til pin 2 på motor driver
int leftMotorEnable = 5; // pin 5 på arduino forbunet til pin 1 på motor driver
int rightMotorF = 12; // pin 3 på arduino forbunet til pin 15 på motor driver
int rightMotorR = 11; // pin 10 på arduino forbunet til pin 10 på motor driver
int rightMotorEnable = 10; // pin 11 på arduino forbunet til pin 9 på motor driver


void setup() {
  // put your setup code here, to run once:
  pinMode(leftMotorF,OUTPUT);
  pinMode(leftMotorF,OUTPUT);
  pinMode(leftMotorEnable,OUTPUT);
  pinMode(rightMotorF,OUTPUT);
  pinMode(rightMotorF,OUTPUT);
  pinMode(rightMotorEnable,OUTPUT);

  digitalWrite(leftMotorEnable, HIGH);
  digitalWrite(leftMotorF, HIGH);
  digitalWrite(leftMotorR, LOW);
  digitalWrite(rightMotorEnable, HIGH);
  digitalWrite(rightMotorF, HIGH);
  digitalWrite(rightMotorR, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  

}

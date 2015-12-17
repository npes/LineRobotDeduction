#include <TimerOne.h>

// This example creates a PWM signal with 25 kHz carrier.
//
// Arduino's analogWrite() gives you PWM output, but no control over the
// carrier frequency.  The default frequency is low, typically 490 or
// 3920 Hz.  Sometimes you may need a faster carrier frequency.
//
// The specification for 4-wire PWM fans recommends a 25 kHz frequency
// and allows 21 to 28 kHz.  The default from analogWrite() might work
// with some fans, but to follow the specification we need 25 kHz.
//
// http://www.formfactors.org/developer/specs/REV1_2_Public.pdf
//
// Connect the PWM pin to the fan's control wire (usually blue).  The
// board's ground must be connected to the fan's ground, and the fan
// needs +12 volt power from the computer or a separate power supply.

const int fanPin = 4;

void setup(void)
{
  Timer1.initialize(40);  // 40 us = 25 kHz
  Serial.begin(9600);
}

<<<<<<< HEAD
void loop(void)
{
  // slowly increase the PWM fan speed
  //
  for (float dutyCycle = 30.0; dutyCycle < 100.0; dutyCycle++) {
    Serial.print("PWM Fan, Duty Cycle = ");
    Serial.println(dutyCycle);
    Timer1.pwm(fanPin, (dutyCycle / 100) * 1023);
    delay(500);
  }
=======
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
>>>>>>> origin/master
}


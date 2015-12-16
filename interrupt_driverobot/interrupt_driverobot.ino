// You can reduce the memory footprint of this handler by declaring that there will be no pin change interrupts
// on any one or two of the three ports.  If only a single port remains, the handler will be declared inline
// reducing the size and latency of the handler.
//#define NO_PORTB_PINCHANGES // to indicate that port b will not be used for pin change interrupts
//#define NO_PORTC_PINCHANGES // to indicate that port c will not be used for pin change interrupts
// #define NO_PORTD_PINCHANGES // to indicate that port d will not be used for pin change interrupts
// if there is only one PCInt vector in use the code can be inlined
// reducing latency and code size
// define DISABLE_PCINT_MULTI_SERVICE below to limit the handler to servicing a single interrupt per invocation.
// #define       DISABLE_PCINT_MULTI_SERVICE
//-------- define the above in your sketch, if applicable ------------------------------------------------------

//libraries
#include <PinChangeInt.h>

//pins init
#define leftSensor 7 //Line detect sensor: black=high white=low
#define rightSensor 8 //Line detect sensor: black=high white=low
volatile int stateLeftSensor; //used in interrupt leftSensorFunc
volatile int stateRightSensor; //used in interrupt rightSensorFunc
int motorLeftA=6; // pin 6 på arduino forbunet til pin 2 på motor driver
int motorRightA=10; // pin 10 på arduino forbunet til pin 10 på motor driver
int motorLeftB=9; // pin 9 på arduino forbunet til pin 7 på motor driver
int motorRightB=3; // pin 3 på arduino forbunet til pin 15 på motor driver
int motorLeftSpeed=5; // pin 5 på arduino forbunet til pin 1 på motor driver
int motorRightSpeed=11; // pin 11 på arduino forbunet til pin 9 på motor driver
int spd1=100; //turn speed fast wheel
int spd2=80; //forward speed
int spd3=0; //turn speed slow wheel
int spd4=80; //reverse speed

// Interrupt function prototypes
void leftSensorFunc();
void rightSensorFunc();

void setup() {
  //interrupt init
  pinMode(leftSensor, INPUT);
  PCintPort::attachInterrupt(leftSensor, leftSensorFunc, RISING);  // add more attachInterrupt code as required
  pinMode(rightSensor, INPUT);
  PCintPort::attachInterrupt(rightSensor, rightSensorFunc, RISING);
  //pins init
  pinMode (motorLeftA, OUTPUT);
  pinMode (motorRightA, OUTPUT);
  pinMode (motorLeftB, OUTPUT);
  pinMode (motorRightB, OUTPUT);
  pinMode (motorLeftSpeed, OUTPUT);
  pinMode (motorRightSpeed, OUTPUT);
}

void loop() {

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
    delay (200);
}
}

//functions
void leftSensorFunc() {
  stateLeftSensor=digitalRead (leftSensor);
}
void rightSensorFunc() {
  stateRightSensor=digitalRead (rightSensor);
}

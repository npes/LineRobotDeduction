//PinChangeInt is taken from https://github.com/GreyGnome/PinChangeInt

// PinChangeIntExample, version 1.1 Sun Jan 15 06:24:19 CST 2012
// See the Wiki at http://code.google.com/p/arduino-pinchangeint/wiki for more information.
//-------- define these in your sketch, if applicable ----------------------------------------------------------
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
#include <PinChangeInt.h>

// This example demonstrates a configuration of 3 interrupting pins and 2 interrupt functions.
// All interrupts are serviced immediately, but one of the pins (pin 4) will show you immediately
// on the Terminal.  The other function connected to 2 pins sets an array member that is queried in loop().
// You can then query the array at your leisure.
// This makes loop timing non-critical.

// Add more Pins at your leisure.
// For the Analog Input pins used as digital input pins, and you can use 14, 15, 16, etc.
// or you can use A0, A1, A2, etc. (the Arduino code comes with #define's
// for the Analog Input pins and will properly recognize e.g., pinMode(A0, INPUT);
#define PIN3 4

uint8_t latest_interrupted_pin;
uint8_t interrupt_count[20]={0}; // 20 possible arduino pins
void quicfunc() {
  latest_interrupted_pin=PCintPort::arduinoPin;
  interrupt_count[latest_interrupted_pin]++;
};

// You can assign any number of functions to any number of pins.
// How cool is that?
void pin3func() {
  Serial.print("Pin "); Serial.print(PIN3, DEC); Serial.println("!");
}

void setup() {
  pinMode(PIN3, INPUT); digitalWrite(PIN3, HIGH);
  PCintPort::attachInterrupt(PIN3, pin3func, FALLING);  // add more attachInterrupt code as required
  Serial.begin(9600);
}

//uint8_t i;
void loop() {
}

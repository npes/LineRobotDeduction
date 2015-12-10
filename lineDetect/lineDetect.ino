//PCINT0_vect D8 - D13
// PCINT1_vect A0 - A5
// PCINT2_vect D0 - D7
void pciSetup(byte pin)
{
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
   PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
   PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}
ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
  delay (400);
  digitalRead(12);
  Serial.println(" - int - ");
}
ISR (PCINT1_vect) // handle pin change interrupt for A0 to A5 here
{
  //digitalWrite(13,digitalRead(A0));
}
ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
{
  //digitalWrite(13,digitalRead(7));
}

void setup() 
{
  Serial.begin(9600);
  
// initialise analog port as input and setting pull up resisters
  pinMode(12, INPUT_PULLUP);     // Pin 12 is input to which a switch is connected
//  pinMode(1, INPUT_PULLUP);    // Pin A1 is input to which a switch is connected
//  pinMode(2, INPUT_PULLUP);    // Pin A2 is input to which a switch is connected
//  pinMode(4, INPUT_PULLUP);    // Pin A3 is input to which a switch is connected

//enable interrupt for pin

pciSetup(12);

/* InitialiseInterrupt
  cli();    // switch interrupts off while messing with their settings  
  PCICR =0x04;          // Enable PCINT2 interrupt
  PCMSK2 = 0b00010111;
//  PCIFR &= ~0x04;
  sei();    // turn interrupts back on
  PCIFR &= ~0x04;
*/
}
  

void loop(){
}

// interrupt service routine
/*ISR(PCINT1_vect) {    // Interrupt service routine. Every single PCINT8..14 (=ADC0..5) change
            // will generate an interrupt: but this will always be the same interrupt routine
  if (digitalRead(A0)==0){
    Serial.println("leftTacho");  
  }
  if(digitalRead(A1)==0){
    Serial.println("rightTacho");    
  }
  if (digitalRead(A2)==0){
    Serial.println("L-OFF");
  }
  if(digitalRead(A3)==0){
    Serial.println("R-OFF");
  }
}

ISR(PCINT0_vect){
//  cli();    // switch interrupts off
delay (400);
  Serial.println(" - int - ");
//  sei();    // turn interrupts back on
  PCIFR = 0x04;
*/  


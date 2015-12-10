//PCINT0_vect D8 - D13
// PCINT1_vect A0 - A5
// PCINT2_vect D0 - D7

byte leftTacho = 0;
byte rightTacho = 0;

void setup() 
{
  Serial.begin(9600);
  
// initialise analog port as input and setting pull up resisters
  pinMode(0, INPUT);     // Pin A0 is input to which a switch is connected
  digitalWrite(0, HIGH);   // Configure internal pull-up resistor
  pinMode(1, INPUT);    // Pin A1 is input to which a switch is connected
  digitalWrite(1, HIGH);   // Configure internal pull-up resistor
  pinMode(2, INPUT);    // Pin A2 is input to which a switch is connected
  digitalWrite(2, HIGH);   // Configure internal pull-up resistor
  pinMode(4, INPUT);    // Pin A3 is input to which a switch is connected
  digitalWrite(4, HIGH);   // Configure internal pull-up resistor

// InitialiseInterrupt
  cli();    // switch interrupts off while messing with their settings  
  PCICR =0x04;          // Enable PCINT2 interrupt
  PCMSK2 = 0b00010111;
  PCIFR &= ~0x04;
  sei();    // turn interrupts back on
  PCIFR &= ~0x04;
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
*/
ISR(PCINT2_vect){
  Serial.println(" - int - ");
  PCIFR = 0;
}


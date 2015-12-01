// ruben
/*
const byte L_Motor_A = 4; 
const byte L_Motor_B = 6;
const byte L_Motor_Ena = 5;

const byte R_Motor_A = 11;
const byte R_Motor_B = 12;
const byte R_Motor_Ena = 10;
*/

//grupe
const byte L_Motor_A = 9; // pin 9 på arduino forbunet til pin 7 på motor driver
const byte L_Motor_B = 6; // pin 6 på arduino forbunet til pin 2 på motor driver
const byte L_Motor_Ena = 5; // pin 5 på arduino forbunet til pin 1 på motor driver
const byte R_Motor_A = 3; // pin 3 på arduino forbunet til pin 15 på motor driver
const byte R_Motor_B = 10; // pin 10 på arduino forbunet til pin 10 på motor driver
const byte R_Motor_Ena = 11; // pin 11 på arduino forbunet til pin 9 på motor driver


const byte LED = 13;

const byte BUTTON_FORWARD = 2;
//const byte BUTTON_REVERSE = 3;


void setup() 
{
  // Setup button
  pinMode(BUTTON_FORWARD, INPUT);     // Set pin 2 as button input
  digitalWrite(BUTTON_FORWARD, HIGH); // Enable resistor to Vcc (active Low)
  attachInterrupt(digitalPinToInterrupt(BUTTON_FORWARD), button_forward, FALLING);
  
  // Setup button
//  pinMode(BUTTON_REVERSE, INPUT);     // Set pin 2 as button input
//  digitalWrite(BUTTON_REVERSE, HIGH); // Enable resistor to Vcc (active Low)
//  attachInterrupt(digitalPinToInterrupt(BUTTON_REVERSE), button_reverse, FALLING);

  
  pinMode(LED, OUTPUT);
    
  pinMode(L_Motor_A, OUTPUT);
  pinMode(L_Motor_B, OUTPUT);

  pinMode(R_Motor_A, OUTPUT);
  pinMode(R_Motor_B, OUTPUT);

  pinMode(L_Motor_Ena, OUTPUT);
  pinMode(R_Motor_Ena, OUTPUT);

  digitalWrite(L_Motor_Ena, HIGH);
  digitalWrite(R_Motor_Ena, HIGH);

  digitalWrite(L_Motor_B, LOW);
  digitalWrite(L_Motor_A, HIGH);

  digitalWrite(R_Motor_B, LOW);
  digitalWrite(R_Motor_A, HIGH);
}

void button_forward()
{
  digitalWrite(L_Motor_Ena, LOW);
  digitalWrite(R_Motor_Ena, LOW);
  
  digitalWrite(L_Motor_A, LOW);
  digitalWrite(L_Motor_B, HIGH);

  digitalWrite(R_Motor_A, LOW);
  digitalWrite(R_Motor_B, HIGH);

  digitalWrite(LED, HIGH); 

  digitalWrite(L_Motor_Ena, HIGH);
  digitalWrite(R_Motor_Ena, HIGH);

}

void button_reverse()
{
  digitalWrite(L_Motor_Ena, LOW);
  digitalWrite(R_Motor_Ena, LOW);
  
  digitalWrite(L_Motor_A, HIGH);
  digitalWrite(L_Motor_B, LOW);

  digitalWrite(R_Motor_A, HIGH);
  digitalWrite(R_Motor_B, LOW);

  digitalWrite(LED, LOW); 

  digitalWrite(L_Motor_Ena, HIGH);
  digitalWrite(R_Motor_Ena, HIGH);

}

void loop() {
}

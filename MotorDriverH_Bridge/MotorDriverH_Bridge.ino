//Pin definitions
const byte L_Motor_A = 9; // pin 9 på arduino forbunet til pin 7 på motor driver
const byte L_Motor_B = 6; // pin 6 på arduino forbunet til pin 2 på motor driver
const byte L_Motor_Ena = 5; // pin 5 på arduino forbunet til pin 1 på motor driver
const byte R_Motor_A = 3; // pin 3 på arduino forbunet til pin 15 på motor driver
const byte R_Motor_B = 10; // pin 10 på arduino forbunet til pin 10 på motor driver
const byte R_Motor_Ena = 11; // pin 11 på arduino forbunet til pin 9 på motor driver

//function prototypes
int driveforward(int distance, int spd); //distance=meters spd=0-255
int drivereverse(int distance, int spd); //distance=meters spd=0-255
void sharpturn(int dir, int angle, int spd); //1=left 2=right angle=delay in milisecs, spd=0-255

void setup() 
{

//  attachInterrupt(digitalPinToInterrupt(BUTTON_FORWARD), button_forward, FALLING);
pinMode (L_Motor_A, OUTPUT); // pin 9 på arduino forbunet til pin 7 på motor driver
pinMode (L_Motor_B, OUTPUT); // pin 6 på arduino forbunet til pin 2 på motor driver
pinMode (L_Motor_Ena, OUTPUT); // pin 5 på arduino forbunet til pin 1 på motor driver
pinMode (R_Motor_A, OUTPUT); // pin 3 på arduino forbunet til pin 15 på motor driver
pinMode (R_Motor_B, OUTPUT); // pin 10 på arduino forbunet til pin 10 på motor driver
pinMode (R_Motor_Ena, OUTPUT); // pin 11 på arduino forbunet til pin 9 på motor driver  
}
  

void loop(){
  delay (200);  
  driveforward (2,200);
  delay (200);
  sharpturn (1,500,200);
  delay (200);
  sharpturn (2,500,200);
  delay (200);
  drivereverse (2,200);
  delay (200);
  drivereverse (2,200);
  delay (200);
  sharpturn (1,500,200);
  delay (200);
  drivereverse (2,200);
  delay (200);
  sharpturn (1,500,200);
  delay (200);
  drivereverse (2,200);
  delay (200);
  sharpturn (1,500,200);
  delay (200);
  drivereverse (2,200);
  delay (200);
  sharpturn (1,500,200);
  delay (200);
}

// Function declarations

/*** drive forward***/
int driveforward(int distance, int spd){
  int meter = 2800 * distance;
  analogWrite(L_Motor_Ena, spd);
  analogWrite(R_Motor_Ena, spd);

  digitalWrite(L_Motor_B, HIGH);
  digitalWrite(L_Motor_A, LOW);

  digitalWrite(R_Motor_B,HIGH);
  digitalWrite(R_Motor_A, LOW);
  delay(meter);
  analogWrite(L_Motor_Ena, spd);
  analogWrite(R_Motor_Ena, spd);

  digitalWrite(L_Motor_B, LOW);
  digitalWrite(L_Motor_A, LOW);

  digitalWrite(R_Motor_B, LOW);
  digitalWrite(R_Motor_A, LOW);
  return 0; 
}
/*** drive reverse distance=meters spd=0-255***/
int drivereverse(int distance, int spd){
  int meter = 2800 * distance;
  analogWrite(L_Motor_Ena, spd);
  analogWrite(R_Motor_Ena, spd);

  digitalWrite(L_Motor_B, LOW);
  digitalWrite(L_Motor_A, HIGH);

  digitalWrite(R_Motor_B, LOW);
  digitalWrite(R_Motor_A, HIGH);
  delay(meter);
  analogWrite(L_Motor_Ena, spd);
  analogWrite(R_Motor_Ena, spd);

  digitalWrite(L_Motor_B, LOW);
  digitalWrite(L_Motor_A, LOW);

  digitalWrite(R_Motor_B, LOW);
  digitalWrite(R_Motor_A, LOW);
  return 0; 
}
/*** sharpturn 1=left 2=right angle=delay in milisecs***/
void sharpturn(int dir, int angle, int spd){
//  digitalWrite(enable, 1);
  switch(dir){
    case 1: // turn left
  analogWrite(L_Motor_Ena, spd);
  analogWrite(R_Motor_Ena, spd);

  digitalWrite(L_Motor_B, HIGH);
  digitalWrite(L_Motor_A, LOW);

  digitalWrite(R_Motor_B, LOW);
  digitalWrite(R_Motor_A, LOW);    
      delay(angle);
      break;
    case 2: // turn right
      analogWrite(L_Motor_Ena, spd);
  analogWrite(R_Motor_Ena, spd);

  digitalWrite(L_Motor_B, LOW);
  digitalWrite(L_Motor_A, LOW);

  digitalWrite(R_Motor_B, HIGH);
  digitalWrite(R_Motor_A, LOW);
      delay(angle);
      break;
  }
}

int enable = 2;
int pushButton = 12;
int buttonState;
int start = 0;
int motorL = 3;
int motorR = 5;
int mode = 0; 

/*** function prototypes ***/
int drive(int distance);
void sharpturn(int dir, int angle);
void smootturn(int dir);
/*** function prototypes ***/

void setup()
{
  Serial.begin(9600);
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
}
 
void loop()
{
  digitalWrite(enable, 0);
  analogWrite(motorL, 0);
  analogWrite(motorR, 0);    
  

    
/* knap aktivering */
  buttonState = digitalRead(pushButton);
  if(buttonState == 0){
    delay(1500);
    start = 1;
  }

  if(start == 1){
       smootturn(1,11500);
    }
    start = 0;
}

/*** function ***/
/*** drive ***/
int drive(int distance){
  int meter = 2800 * distance;
  digitalWrite(enable, 1);
  analogWrite(motorL, 145);
  analogWrite(motorR, 155);
  delay(meter);
  digitalWrite(enable, 0);
  analogWrite(motorL, 0);
  analogWrite(motorR, 0);
  return 0; 
}

/*** sharpturn ***/
void sharpturn(int dir, int angle){
  digitalWrite(enable, 1);
  switch(dir){
    case 1: // turn left
      analogWrite(motorL, 255);
      analogWrite(motorR, 0);    
      delay(angle);
      break;
    case 2: // turn right
      analogWrite(motorR, 255);
      analogWrite(motorL, 0);
      delay(angle);
      break;
  }
}

/*** smoothturn ***/
void smootturn(int dir, int timedel){
  digitalWrite(enable, 1);
  switch(dir){
    case 1: // turn left
      analogWrite(motorL, 154);
      analogWrite(motorR, 125);    
      delay(timedel);
      break;
    case 2: // turn right
      analogWrite(motorR, 127);
      analogWrite(motorL, 100);
      delay(timedel);
      break;
  }
}
/*** function ***/



int enable = 2;
int pushButton = 12;
int buttonState;
int start = 0;
int motorL = 3;
int motorR = 5;
int mode = 0; 

/*** function prototypes ***/
int drive(int distance);
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
    mode++; 
  }

  if(start == 1){
    switch(mode){
      case 1:
        drive(1);
        break;
      case 2:
        drive(2);
        break;
      case 3:
        drive(5);
        break;
      default:
        mode = 0;
        break;
    }
    start = 0;
  }
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
/*** function ***/



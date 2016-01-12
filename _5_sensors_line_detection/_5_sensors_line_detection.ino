// sensors
//int leftSSensor=12;
//int rightSSensor=13;
int center = 8;
int centerLeftS = 13;
int centerRightS = 7;
int leftS = 12;
int rightS = 4;

// motor pins
int motorleftSA=6;
int motorrightSA=10;
int motorleftSB=9;
int motorrightSB=3;
int motorleftSSpeed=5;
int motorrightSSpeed=11;

void setup() {
  Serial.begin(9600);
  
  pinMode (center, INPUT);
  pinMode (centerLeftS, INPUT);
  pinMode (centerRightS, INPUT);
  pinMode (leftS, INPUT);
  pinMode (rightS, INPUT);
  
  pinMode (motorleftSA, OUTPUT);
  pinMode (motorrightSA, OUTPUT);
  pinMode (motorleftSB, OUTPUT);
  pinMode (motorrightSB, OUTPUT);
  pinMode (motorleftSSpeed, OUTPUT);
  pinMode (motorrightSSpeed, OUTPUT);
}

void loop() {

// Sensor state
int stateCenter = digitalRead (center);
int stateCenterLeftS = digitalRead (centerLeftS);
int stateCenterRightS = digitalRead (centerRightS);
int stateLeftS = digitalRead (leftS);
int stateRightS = digitalRead (rightS);

// Motor speeds
int middle = 125;
int slow = 100;
int fast = 150;
int off = 0;

// motor correction
  if (stateLeftS == LOW && stateCenterLeftS == LOW && stateCenter == HIGH && stateCenterRightS == LOW && stateRightS == LOW){
  
    // motor configuration
    digitalWrite(motorleftSA, HIGH);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA, HIGH);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, middle);
    analogWrite(motorrightSSpeed, middle);
  
    Serial.println("Center");
    
  }
  /*else if (stateLeftS == LOW && stateCenterLeftS == LOW && stateCenter == HIGH && stateCenterRightS == HIGH && stateRightS == LOW){
  
    // motor configuration
    digitalWrite(motorleftSA, HIGH);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA,HIGH);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, middle);
    analogWrite(motorrightSSpeed, slow);
  
    Serial.println("Center - Center right");
    
  }*/
  /*else if (stateLeftS == LOW && stateCenterLeftS == LOW && stateCenter == LOW && stateCenterRightS == HIGH && stateRightS == LOW){
  
    // motor configuration
    digitalWrite(motorleftSA, HIGH);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA,HIGH);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, middle);
    analogWrite(motorrightSSpeed, middle);
    
    Serial.println("Center right");
    
  }*/
  /*else if (stateLeftS == LOW && stateCenterLeftS == LOW && stateCenter == LOW && stateCenterRightS == HIGH && stateRightS == HIGH){
  
    // motor configuration
    digitalWrite(motorleftSA, HIGH);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA,HIGH);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, fast);
    analogWrite(motorrightSSpeed, slow);
    
    Serial.println("Center right - Right");
    
  }*/
  /*else if (stateLeftS == LOW && stateCenterLeftS == LOW && stateCenter == LOW && stateCenterRightS == LOW && stateRightS == HIGH){
  
    // motor configuration
    digitalWrite(motorleftSA, HIGH);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA, LOW);
    digitalWrite(motorrightSB, HIGH);
  
    // speed configuration
    analogWrite(motorleftSSpeed, middle);
    analogWrite(motorrightSSpeed, middle);
  
    Serial.println("Right");
    
  }*/
  /*else if (stateLeftS == LOW && stateCenterLeftS == HIGH && stateCenter == HIGH && stateCenterRightS == LOW && stateRightS == LOW){
  
    // motor configuration
    digitalWrite(motorleftSA, HIGH);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA, HIGH);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, slow);
    analogWrite(motorrightSSpeed, middle);
    
    Serial.println("Center - Center left");
    
  }*/
  /*else if (stateLeftS == LOW && stateCenterLeftS == HIGH && stateCenter == LOW && stateCenterRightS == LOW && stateRightS == LOW){
  
    // motor configuration
    digitalWrite(motorleftSA, HIGH);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA, HIGH);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, middle);
    analogWrite(motorrightSSpeed, middle);
    
    Serial.println("Center left");
    
  }*/
  /*else if (stateLeftS == HIGH && stateCenterLeftS == HIGH && stateCenter == LOW && stateCenterRightS == LOW && stateRightS == LOW){
  
    // motor configuration
    digitalWrite(motorleftSA, HIGH);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA, HIGH);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, slow);
    analogWrite(motorrightSSpeed, fast);
    
    Serial.println("Center left - Left");
    
  }*/
  /*else if (stateLeftS == HIGH && stateCenterLeftS == LOW && stateCenter == LOW && stateCenterRightS == LOW && stateRightS == LOW){
  
    // motor configuration
    digitalWrite(motorleftSA, LOW);
    digitalWrite(motorleftSB, HIGH);
  
    digitalWrite(motorrightSA, HIGH);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, middle);
    analogWrite(motorrightSSpeed, middle);
    
    Serial.println("left");
    
  }*/
  /*else if (stateLeftS == LOW && stateCenterLeftS == LOW && stateCenter == LOW && stateCenterRightS == LOW && stateRightS == LOW){
  
    // motor configuration
    digitalWrite(motorleftSA, LOW);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA, LOW);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, off);
    analogWrite(motorrightSSpeed, off);
    
    Serial.println("None");
    
  }*/
  /*else if (stateLeftS == HIGH && stateCenterLeftS == HIGH && stateCenter == HIGH && stateCenterRightS == HIGH && stateRightS == HIGH){
  
    // motor configuration
    digitalWrite(motorleftSA, LOW);
    digitalWrite(motorleftSB, LOW);
  
    digitalWrite(motorrightSA, LOW);
    digitalWrite(motorrightSB, LOW);
  
    // speed configuration
    analogWrite(motorleftSSpeed, off);
    analogWrite(motorrightSSpeed, off);
  
    Serial.println("All");
    
  }*/
}

/*
 Fading

 This example shows how to fade an LED using the analogWrite() function.

 The circuit:
 * LED attached from digital pin 9 to ground.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */

int SerialInput; // test val
int light = 0;
int ledPin = 9;    // LED connected to digital pin 9

void setup() {
  Serial.begin(9600);
  // nothing happens in setup
}

void loop() {
  // Transmit SOS while in destress
  if (Serial.available()) {
    /* read the most recent byte */
    SerialInput = Serial.parseInt();
    // you what you entered
    Serial.print("duty: ");
    Serial.println(SerialInput);
    light = 1;
  } 
  if(light == 1){
    analogWrite(ledPin, SerialInput);
    delay(2000);
    light = 0;
  }
  /*
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  */
}

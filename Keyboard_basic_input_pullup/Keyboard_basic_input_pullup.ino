#include "Keyboard.h"

//declaring button pins
const int buttonPin = 2;  
const int ledRed = 6;
const int ledGreen = 5;
const int ledBlue = 4;        

int previousButtonState = HIGH; 

void setup() {
  Serial.begin(9600);
  Serial.print("Setup");
  //declare the buttons as input_pullup
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT); 
  Keyboard.begin();
}

void loop() {
  //checking the state of the button
  int buttonState = digitalRead(buttonPin);
 //replaces button press with UP arrow
  if (buttonState == LOW && previousButtonState == HIGH) {
      // and it's currently pressed:
    Keyboard.press(97);
    analogWrite(ledRed,255);
    analogWrite(ledGreen,0);
    analogWrite(ledBlue,0);
    Serial.print("Pressed");
    delay(200);
  }

  if (buttonState == HIGH && previousButtonState == LOW) {
      // and it's currently released:
    Keyboard.release(97);
    analogWrite(ledRed,0);
    analogWrite(ledGreen,255);
    analogWrite(ledBlue,0);
    delay(350);
  }
 
  previousButtonState = buttonState;

}

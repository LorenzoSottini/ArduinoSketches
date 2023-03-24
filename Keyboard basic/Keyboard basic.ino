#include "Keyboard.h"

//declaring button pins
const int buttonPin = 2;          

int previousButtonState = HIGH; 

void setup() {
  Serial.begin(9600);
  Serial.print("Setup");
  //declare the buttons as input_pullup
  pinMode(buttonPin, INPUT_PULLUP);  
  Keyboard.begin();
}

void loop() {
  //checking the state of the button
  int buttonState = digitalRead(buttonPin);
 //replaces button press with UP arrow
  if (buttonState == LOW && previousButtonState == HIGH) {
      // and it's currently pressed:
    Keyboard.press(97);
    Serial.print("Pressed");
    delay(350);
  }

  if (buttonState == HIGH && previousButtonState == LOW) {
      // and it's currently released:
    Keyboard.release(97);
    delay(350);
  }
 
  previousButtonState = buttonState;

}

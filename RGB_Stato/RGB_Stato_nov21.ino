const int ledRed = 5;
const int ledGreen = 4;
const int ledBlue = 3;
const int pinButtonMode = 8;
int stato = 1;

void setup() {
    Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(pinButtonMode, INPUT);
àààà}

void loop() {
  if(digitalRead(pinButtonMode) == LOW){
    stato++;
    if(stato == 3){
      stato = 0;
    }
    delay(300);
    Serial.println(stato);
  }

  switch (stato) {
  case 1:
    analogWrite(ledRed,255);
    analogWrite(ledGreen,0);
    analogWrite(ledBlue,0);
    break;
  case 2:
    analogWrite(ledRed,0);
    analogWrite(ledGreen,255);
    analogWrite(ledBlue,0);
    break;
  default:
    analogWrite(ledRed,0);
    analogWrite(ledGreen,0);
    analogWrite(ledBlue,255);
    break;
  }
}

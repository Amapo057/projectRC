// TMRh20 RF24
#include <RF24.h>
#include <Servo.h>

const int joiX = A0;
const int joiY = A1;
const int drsButton = 2;

void setup() {
  Serial.begin(9600);
  pinMode(drsButton, INPUT);
}

void loop() {
  int xRead = analogRead(joiX);
  int yRead = analogRead(joiY);
  int drsRead = digitalRead(drsButton);

}

// TMRh20 RF24
#include <RF24.h>
#include <Servo.h>

const int joiX = A0;
const int joiY = A1;
const int drsButton = 2;

struct DataPack {
  byte joiX;
  byte joiY;
  byte drsButton;
};
DataPack data;

void setup() {
  Serial.begin(9600);
  pinMode(drsButton, INPUT);
}

void loop() {
  int xRead = analogRead(joiX);
  int yRead = analogRead(joiY);
  int drsRead = digitalRead(drsButton);
  data.joiX = map(xRead, 0, 1023, 0, 255);
  data.joiY = map(yRead, 0, 1023, 0, 255);
  data.drsButton = drsRead;

  Serial.print(data.joiX);
  Serial.print(data.joiY);
  Serial.print(data.drsButton);

  delay(100);
}

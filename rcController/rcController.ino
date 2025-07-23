// TMRh20 RF24
#include <RF24.h>

const int joiX = A0;
const int joiY = A1;
const int drsButton = 2;

struct DataPack {
  byte joiX;
  byte joiY;
  byte drsButton;
};
DataPack data;

RF24 radio(7, 8);
const byte adress[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(drsButton, INPUT);

  radio.begin();
  // 보낼 주소
  radio.openWritingPipe(adress);
  // 파워 설정
  radio.setPALevel(RF24_PA_MIN);
  //송신모드
  radio.stopListening();
}

void loop() {
  int xRead = analogRead(joiX);
  int yRead = analogRead(joiY);
  int drsRead = digitalRead(drsButton);
  data.joiX = map(xRead, 0, 1023, 0, 255);
  data.joiY = map(yRead, 0, 1023, 0, 255);
  data.drsButton = drsRead;

  // 데이터 전송
  radio.write(&data, sizeof(DataPack));
  
  Serial.print("joix : ");
  Serial.print(data.joiX);
  Serial.print("  |  joiy : ");
  Serial.print(data.joiY);
  Serial.print("  |  drs : ");
  Serial.print(data.drsButton);
  Serial.println("next");

  delay(1000);
}

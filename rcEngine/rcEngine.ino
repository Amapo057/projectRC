#include <RF24.h>

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

  radio.begin();
  // 보낼 주소
  radio.openWritingPipe(adress);
  // 파워 설정
  radio.setPALevel(RF24_PA_MIN);
  //수신모드
  radio.startListening();
}

void loop() {
  if (radio.available()){
    radio.read(&data, sizeof(DataPack));
    
      Serial.print("joix : ");
    Serial.print(data.joiX);
    Serial.print("  |  joiy : ");
    Serial.print(data.joiY);
    Serial.print("  |  drs : ");
    Serial.println(data.drsButton);
  }

}

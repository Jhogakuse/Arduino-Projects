#include "SD.h"
#include "TMRpcm.h"
#include "SPI.h"

#define SD_PIN 10
#define AUDIO_PIN 9
#define SERIAL_PORT 9600

TMRpcm tm;
// bom1.wav  hh1.wav  pla1.wav  pla2.wav  tam1.wav  tam2.wav

void setup() {
  // put your setup code here, to run once:
  tm.speakerPin = AUDIO_PIN;
  Serial.begin(SERIAL_PORT);

  if(!SD.begin(SD_PIN)) {
    Serial.println("SD failed");
    return;
  }

  //tm.setVolume(6);
  tm.play("bom1.wav");
}

void loop() {
  // put your main code here, to run repeatedly:
}

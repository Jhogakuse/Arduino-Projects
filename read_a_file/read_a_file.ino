#include <CapacitiveSensor.h>

#include <TMRpcm.h>

#include <SD.h>
#include <SPI.h>

#define pinSD 10
#define pinSpeaker 9
#define serialPort 9600

TMRpcm tmrpcm;
File myFile;

CapacitiveSensor cs_14_8 = CapacitiveSensor(14,8);
CapacitiveSensor cs_14_7 = CapacitiveSensor(14,7);

int sense = 400;  // define sencibilidad a menor numero mas sencible
int tiempo = 100; // define tiempo maximo de reproduccion
bool sdAccess = false;
byte start = 0;
byte count = 9; 
char* sounds[] = {
  "bom1.wav",
  "bom2.wav",
  "bom3.wav",
  "pla1.wav",
  "pla2.wav",
  "tam1.wav",
  "tam2.wav",
  "hat2.wav",
  "hat6.wav"
};

void setup() {
  tmrpcm.speakerPin = pinSpeaker; // The speaker
  //tmrpcm.setVolume(7);
  Serial.begin(serialPort);
  Serial.println(F(" Accessing to SD ..."));
  if (SD.begin(pinSD)) {
    Serial.println(F("Accessed correctly"));
    sdAccess = true;
    return;
  } else {
    Serial.println(F("Error in the access"));
  }
}

void loop() {
  while(!sdAccess);
  // for(int sound = start; sound < count; sound++) {
  //   tmrpcm.play(sounds[sound]);
  //   Serial.println(sounds[sound]);
  //   delay(tiempo);
  // }
  // Serial.println("<<<< Repeat >>>>");
  long valor1 =  cs_14_8.capacitiveSensor(20);
  long valor2 =  cs_14_7.capacitiveSensor(20);
    
  if (valor1 > sense) {
    tmrpcm.play(sounds[3]);  // nombre de archivo a reproducir guardado en la sd.
    delay(tiempo);
  }

  if (valor2 > sense){
    tmrpcm.play(sounds[0]);    
    delay(tiempo);
  } 
}

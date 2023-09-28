
#include <SD.h>
#include <TMRpcm.h>

#define serialPort 9600

const byte pinSD = 10;
const byte pinSpeaker = 9;
const byte pinA0 = A0;
const byte pinA1 = A1;
const byte sense = 200; 
const byte time = 100; 

bool sdAccess = false;
int sensorA0;
int sensorA1;
TMRpcm tmrpcm;
TMRpcm tm;

const char* sounds[] = {
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

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(serialPort);

  if (SD.begin(pinSD)) {
    Serial.println(F("Access"));
    sdAccess = true;
    tmrpcm.speakerPin = pinSpeaker;
    tm.speakerPin = pinSpeaker;
    pinMode(pinA0, INPUT);
    pinMode(pinA1, INPUT);
  } else {
    Serial.println(F("No access"));
  }
}

void loop() {
  while(!sdAccess);

  sensorA0 = analogRead(pinA0);
  sensorA1 = analogRead(pinA1);

  if(sensorA0 > sense) {
    tmrpcm.play(sounds[4]);
  }

  if(sensorA1 > sense) {
    tm.play(sounds[6]);
  }

  delay(time);
}

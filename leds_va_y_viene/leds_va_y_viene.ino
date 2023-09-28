long _d = 100; 
void setup() {
  for(byte i=2; i<=8; i+=2) {
    pinMode(i, OUTPUT);
    digitalWrite(i, 0);
  }
}

void loop() {
  for(byte i=2; i<=8; i+=2) {
    digitalWrite(i, 1);
    delay(_d);
    digitalWrite(i, 0);
  }

  for(byte i=8; i>=2; i-=2) {
    digitalWrite(i, 1);
    delay(_d);
    digitalWrite(i, 0);
  }
}

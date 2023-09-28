long _d = 200; 
byte PULSADOR_1 = 2;
byte PULSADOR_2 = 8;
byte LED_1 = 4;
byte LED_2 = 6;

void setup() {
  pinMode(PULSADOR_1, INPUT);
  pinMode(PULSADOR_2, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_1, 0);
  digitalWrite(LED_2, 0);
}

void loop() {
  while(digitalRead(PULSADOR_1) == 0 && digitalRead(PULSADOR_2) == 0);

  if(digitalRead(PULSADOR_1) == 1) {
    digitalWrite(LED_1, !digitalRead(LED_1));
  }

  if(digitalRead(PULSADOR_2) == 1) {
    digitalWrite(LED_2, !digitalRead(LED_2));
  }
  delay(_d);
  while(digitalRead(PULSADOR_1) == 1 || digitalRead(PULSADOR_2) == 1);
}

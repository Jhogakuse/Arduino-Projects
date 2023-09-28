long _d = 100; 
int PULSADOR = 2;
int LED_W = 4;
int LED_G = 6;
bool e_a = true;

void setup() {
  pinMode(PULSADOR, INPUT);
  pinMode(LED_W, OUTPUT);
  pinMode(LED_G, OUTPUT);
  digitalWrite(LED_W, 1);
  digitalWrite(LED_G, 0);
  e_a = true;
}

void loop() {
  while(digitalRead(PULSADOR) == 1);
    digitalWrite(LED_W, e_a);
    digitalWrite(LED_G, !e_a);
    e_a = !e_a;
    delay(_d);
  while(digitalRead(PULSADOR) == 0);
}

byte led = 2, ledPrev = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  if (led == 10) {
    led = 2;
  }
  digitalWrite(led, 1);
  digitalWrite(ledPrev, 0);
  ledPrev = led;
  led += 2;
  delay(100);
}

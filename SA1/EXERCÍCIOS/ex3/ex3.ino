void setup() {
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int num = 0; num < 256; num++) {
    for (int bit = 0; bit < 8; bit++) {
      int estado = (num >> bit) & 1;
      digitalWrite(2 + bit, estado);
    }
    delay(500);
  }
}
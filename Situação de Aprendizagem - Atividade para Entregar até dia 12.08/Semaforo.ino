void setup() {
  for(int i = 0; i <= 9; i++){
    pinMode(i+3, OUTPUT);
  }
}

void loop() {
  for(int i = 0; i <= 9; i++){
    digitalWrite(i+3, HIGH);
    delay(1000);
    digitalWrite(i+3, LOW);
  }
}

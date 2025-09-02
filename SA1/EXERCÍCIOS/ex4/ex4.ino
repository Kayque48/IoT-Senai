void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 2; i <= 6; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }

  for (int i = 5; i >= 3; i--){
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}
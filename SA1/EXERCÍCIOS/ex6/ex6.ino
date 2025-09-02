void setup() {
  // put your setup code here, to run once:
 pinMode(9, OUTPUT);
 pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2) == HIGH){
    digitalWrite(9, HIGH);
    delay(3000);
  } else {
    digitalWrite(9, LOW);
  }
}
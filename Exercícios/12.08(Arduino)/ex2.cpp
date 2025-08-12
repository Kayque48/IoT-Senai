#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
 pinMode(9, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(6, HIGH);
 delay(5000);
 digitalWrite(6, LOW);
 digitalWrite(9, HIGH);
 delay(3000);
 digitalWrite(9, LOW);
 digitalWrite(12, HIGH);
 delay(5000);
 digitalWrite(12, LOW);
}

// LEDs
int led1 = 11;  
int led2 = 12;  
int led3 = 13;
int led4 = 6;
int botao = 2;  

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  if (digitalRead(botao) == LOW) {
    digitalWrite(led1, HIGH);
    delay(3000);
    digitalWrite(led1, LOW);

    digitalWrite(led2, HIGH);
    delay(3000);
    digitalWrite(led2, LOW);

    digitalWrite(led3, HIGH);
    delay(3000);
    digitalWrite(led3, LOW);
  } else { 
    digitalWrite(led4, HIGH);
    delay(2000);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    delay(1000);
    digitalWrite(led3, HIGH);
    delay(6000);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

  }
}

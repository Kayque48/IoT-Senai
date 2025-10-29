int ledverm = 13;
int buzz = 12;
int button = 11;
int sensor = 10;

bool pisc = false;
bool estadop = HIGH;

void setup() {
  pinMode(ledverm, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(button, INPUT); // usa resistor interno
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = digitalRead(button);
  int lsensor = digitalRead(sensor);



  // detecta mudança: botão pressionado
  if (leitura == LOW && estadop == HIGH) {
    pisc = !pisc;        // inverte o estado
    delay(200);          // debounce simples
  }

  if (lsensor == HIGH) {
    pisc = true;
    while(pisc == true) {
      digitalWrite(ledverm, HIGH);
      digitalWrite(buzz, HIGH);
      delay(300);
      digitalWrite(ledverm, LOW);
      digitalWrite(buzz, LOW);
      delay(300);
    }
  } else {
    pisc = false;
    digitalWrite(ledverm, LOW);
    digitalWrite(buzz, LOW);

  }

  estadop = leitura;

  // se pisc for true, pisca e buzina
  if (pisc) {
    digitalWrite(ledverm, HIGH);
    digitalWrite(buzz, HIGH);
    delay(300);
    digitalWrite(ledverm, LOW);
    digitalWrite(buzz, LOW);
    delay(300);
  } else {
    // se pisc for false, garante que tá tudo desligado
    digitalWrite(ledverm, LOW);
    digitalWrite(buzz, LOW);
  }
  Serial.println(lsensor);
}

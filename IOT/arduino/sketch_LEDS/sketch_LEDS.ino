const int led1Pin = 8;
const int led2Pin = 9;

void setup() {
  Serial.begin(9600);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch(command) {
      case 'A':
        digitalWrite(led1Pin,HIGH);
        break;
      
      case 'a':
        digitalWrite(led1Pin, LOW);
        break;
      case 'B':
        digitalWrite(led2Pin, HIGH);

      case 'b':
        digitalWrite(led2Pin, LOW);
        break;
    }

  }
}
int ledverm = 13;
int buzz = 12;
int button = 11;
int sensor = 10;

bool alarmEnabled = false;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledverm, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(button, INPUT_PULLUP); // usa resistor interno pull-up
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  delay(2000); // aguarda serial estabilizar
  Serial.println("READY");
}

void loop() {
  // Leitura do botão (com debounce) para alternar modo localmente
  int reading = digitalRead(button);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // detecta borda de pressão (botão para GND -> LOW)
    if (reading == LOW && lastButtonState == HIGH) {
      alarmEnabled = !alarmEnabled;
      Serial.println(alarmEnabled ? "ALARM_ON" : "ALARM_OFF");
      delay(200); // pequeno debounce
    }
  }
  lastButtonState = reading;

  // Recebe comandos via Serial: "ON" ou "OFF"
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.equalsIgnoreCase("ON")) {
      alarmEnabled = true;
      Serial.println("ALARM_ON");
    } else if (cmd.equalsIgnoreCase("OFF")) {
      alarmEnabled = false;
      Serial.println("ALARM_OFF");
    } else {
      // opcional: eco do comando recebido
      Serial.print("CMD:");
      Serial.println(cmd);
    }
  }

  int lsensor = digitalRead(sensor);

  // Se alarme habilitado e sensor detectou, pisca e buzina
  if (alarmEnabled && lsensor == HIGH) {
    digitalWrite(ledverm, HIGH);
    digitalWrite(buzz, HIGH);
    delay(300);
    digitalWrite(ledverm, LOW);
    digitalWrite(buzz, LOW);
    delay(300);
  } else {
    // Garante desligado quando não ativado
    digitalWrite(ledverm, LOW);
    digitalWrite(buzz, LOW);
  }

  // Opcional: envia estado do sensor periodicamente (útil para debug)
  static unsigned long lastReport = 0;
  if (millis() - lastReport > 1000) {
    lastReport = millis();
    Serial.print("SENSOR:");
    Serial.println(lsensor);
  }
}

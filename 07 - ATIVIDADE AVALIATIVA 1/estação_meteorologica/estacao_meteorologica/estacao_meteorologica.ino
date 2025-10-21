// Inclui a biblioteca do sensor DHT
#include "DHT.h"

// Configurações do Sensor DHT
#define DHTPIN 2       // Pino onde o sensor está conectado
#define DHTTYPE DHT11  // Define o tipo de sensor (DHT11)
DHT dht(DHTPIN, DHTTYPE);

// Pinos dos LEDs (como no projeto do PDF)
const int ledPinVerde = 7;
const int ledPinAmar = 8;
const int ledPinVrm = 9;

void setup() {
  // Inicia a comunicação serial para o Python
  Serial.begin(9600);

  // Inicia o sensor DHT
  dht.begin();

  // Configura os pinos dos LEDs como saída
  pinMode(ledPinVerde, OUTPUT);
  pinMode(ledPinAmar, OUTPUT);
   pinMode(ledPinVrm, OUTPUT);
  
}

void loop() {
  // Verifica se há algum comando vindo do Python
  if (Serial.available() > 0) {
    // Lê o caractere recebido
    char command = Serial.read();

    // Estrutura switch para tratar os comandos
    switch (command) {
      // Casos para controlar os LEDs (do projeto original)
      case 'A':
        digitalWrite(ledPinVerde, HIGH); // Liga LED 1 (Verde)
        break;
      case 'a':
        digitalWrite(ledPinVerde, LOW); // Desliga LED 1 (Verde)
        break;
      case 'B':
      digitalWrite(ledPinAmar, HIGH); // Liga Amarelo 2 (Verde)
        break;
      case 'b':
        digitalWrite(ledPinAmar, LOW); // Desliga Amarelo 2 (Verde)
        break;
      case 'C':
        digitalWrite(ledPinVrm, HIGH); // Liga LED 3 (Vermelho)
        break;
      case 'c':
        digitalWrite(ledPinVrm, LOW); // Desliga LED 3 (Vermelho)
        break;
      
      // --- NOSSO NOVO COMANDO ---
      case 'T':
        // Lê a temperatura e umidade
        float t = dht.readTemperature();
        float h = dht.readHumidity();

        // Verifica se a leitura falhou
        if (isnan(t) || isnan(h)) {
          Serial.println("ERRO");
        } else {
          // Envia os dados de volta para o Python no formato "temp;umid"
          Serial.print(t);
          Serial.print(";");
          Serial.println(h);
        }
        break;
    }
  }
}
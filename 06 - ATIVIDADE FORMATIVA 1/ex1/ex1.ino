#include <DHT.h>
#include <DHT_U.h>

// Porta do sensor e tipo
#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// LEDs
int led1 = 11;  
int led2 = 12;  
int led3 = 13;  

// Temperatura
float temperatura;

void setup() {
  Serial.begin(9600); // inicializando o monitor serial
  dht.begin();        // inicializando o sensor

  // Configura LEDs como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  delay(2000); // Aguarda 2 segundos entre as leituras
  temperatura = dht.readTemperature(); // lê temperatura em °C

  // Mostra temperatura
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  // Lógica dos LEDs
  if (temperatura < 5) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } 
  else if (temperatura <= 20) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } 
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH); 
  }
}

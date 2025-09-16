// Porta do sensor e tipo
#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Temperatura
float temperatura;

void setup() {
  Serial.begin(9600); // inicializando o monitor serial
  dht.begin();        // inicializando o sensor

 for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  delay(2000); // Aguarda 2 segundos entre as leituras
  temperatura = dht.readTemperature(); // lê temperatura em °C

  // Mostra temperatura
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  for (int bit = 0; bit < 8; bit++) {
    int estado = (tempInt >> bit) & 1;
    digitalWrite(2 + bit, estado);
    Serial.print(estado);
  }
  Serial.println();
}


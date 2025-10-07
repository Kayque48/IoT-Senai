#include <DHT.h>
#include <LiquidCrystal.h>

// ----- Configuração do sensor DHT11 -----
#define DHTPIN 7         // Pino de dados do DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ----- Configuração do LCD (modo paralelo) -----
// Pinos: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  dht.begin();
  lcd.begin(16, 2); // LCD com 16 colunas e 2 linhas
  lcd.print("Iniciando...");
  delay(2000);
}

void loop() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  lcd.clear();

  if (isnan(temperatura) || isnan(umidade)) {
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatura);
    lcd.print((char)223); // símbolo de grau
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidade);
    lcd.print(" %");
  }

  delay(2000);
}
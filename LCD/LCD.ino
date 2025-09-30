#include <LiquidCrystal.h>
// Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  lcd.clear();

  // Exibi uma mensagem na primera linha
  lcd.setCursor(0, 0); //coluna 0, linha 0
  lcd.print("Ola, Mundo!");

  // Exibi uma mensagem na segunda linha
  lcd.setCursor(0, 1); //coluna 2, linha 1
  lcd.print("Oi Kayque, eu vim fazer um anúnico...");
}

void loop() {
  //Limpa a tela

}
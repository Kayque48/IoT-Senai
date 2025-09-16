#include <Servo.h>

Servo blessed;
#define pot A0
int valor;
void setup() {
  blessed.attach(3);
  Serial.begin(9600);
}
void loop(){
  valor = map(analogRead(pot),0,1023,0,180);
  Serial.print("Posicao: ");
  Serial.print(valor);
  Serial.println("graus");
  blessed.write(valor);
  delay(500);
}
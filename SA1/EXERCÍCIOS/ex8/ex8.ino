int leds[4] = {13,12,11,10};
int pot = A0;
int valpot = 0;
int a =0;
void setup() {
  for (int i =0; i< 4; i++){
    pinMode(leds[i], OUTPUT); 
  }
  pinMode(pot, INPUT);
}

void loop() {
  valpot = analogRead(pot);
  a = map(valpot, 0 , 1023, 0, 4);
  switch (a){
    case 1:
      digitalWrite(leds[0],HIGH);
      digitalWrite(leds[1],LOW);
      digitalWrite(leds[2],LOW);
      digitalWrite(leds[3],LOW);
      break;
    case 2:
      digitalWrite(leds[0],HIGH);
      digitalWrite(leds[1],HIGH);
      digitalWrite(leds[2],LOW);
      digitalWrite(leds[3],LOW);
      break;
    case 3:
      digitalWrite(leds[0],HIGH);
      digitalWrite(leds[1],HIGH);
      digitalWrite(leds[2],HIGH);
      digitalWrite(leds[2],LOW);
      break;
    case 4:
      digitalWrite(leds[0],HIGH);
      digitalWrite(leds[1],HIGH);
      digitalWrite(leds[2],HIGH);
      digitalWrite(leds[3],HIGH);
      break;
    default:
      digitalWrite(leds[0],LOW);
      digitalWrite(leds[1],LOW);
      digitalWrite(leds[2],LOW);
      digitalWrite(leds[3],LOW);
      break;
  }
}
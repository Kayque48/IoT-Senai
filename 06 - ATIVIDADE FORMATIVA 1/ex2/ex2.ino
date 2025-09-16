#define buzzer 10
Ultrasonic ultrasonic(3,2); 
void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (ultrasonic.read(CM) < 10 ) {
      digitalWrite(buzzer,HIGH);
  }
  Serial.println(ultrasonic.read(CM));
}
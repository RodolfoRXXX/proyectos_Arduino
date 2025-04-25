
/*
  Circuito con un módulo Relé
*/

#define pinRele 8
#define pinRed 7
#define pinGreen 6

void setup() {
  Serial.begin(9600);
  pinMode(pinRele, OUTPUT);
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  digitalWrite(pinRele, HIGH);
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, LOW);
}

void loop() {
  //Cierra circuito
  digitalWrite(pinRele, LOW);
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  Serial.println("Cerrado");
  delay(3000);
  //Abre circuito
  digitalWrite(pinRele, HIGH);
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinGreen, LOW);
  Serial.println("Abierto");
  delay(3000);
}

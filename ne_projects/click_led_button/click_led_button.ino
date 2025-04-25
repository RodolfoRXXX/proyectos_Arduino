//Código para leer cuando se pulsa un botón y que eso active
//un LED

int PULSADOR = 2;
int LED = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(PULSADOR, INPUT);   //pin 2 como entrada
  pinMode(LED, OUTPUT);  //pin 3 como salida
}

void loop() {
  // toma el valor del pin digital 2 y compara para saber si es HIGH o LOW
  /*if (digitalRead(PULSADOR) == HIGH) {
    digitalWrite(LED, HIGH); //si el pin 2 es HIGH entonces valorizo el pin 3 como HIGH
  } else {
    digitalWrite(LED, LOW);  //si el pin 2 es LOW entonces valorizo el pin 3 como LOW
  }*/

  while (digitalRead(PULSADOR) == HIGH) {
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);
}

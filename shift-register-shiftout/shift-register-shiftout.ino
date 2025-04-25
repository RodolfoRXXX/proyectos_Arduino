/*
    Código que prueba el chip de desplazamiento de registros con la función shiftOut()
    <    >
*/

#define pinData 2
#define pinClock 3
#define pinLatch 4

void setup() {
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);
  pinMode(pinLatch, OUTPUT);
}

/*
//Con la función shiftOut() carga en el chip el valor ingresado = 1
void loop() {
  digitalWrite(pinLatch, LOW);  // Se inicia en bajo
  shiftOut(pinData, pinClock, MSBFIRST, 1);
  digitalWrite(pinLatch, HIGH);  // Se cambia a alto
}
*/


//para obtener diferentes valores decimales con esa función
void loop() {
  for(int i = 0; i <= 256; i++)
  {
    digitalWrite(pinLatch, LOW);  // Se inicia en bajo
    shiftOut(pinData, pinClock, MSBFIRST, i);
    digitalWrite(pinLatch, HIGH);  // Se cambia a alto
    delay(500);
  }
}

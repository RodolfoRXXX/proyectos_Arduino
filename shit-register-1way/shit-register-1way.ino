/*
    Código que prueba el chip de desplazamiento de registros
    <    >
*/

#define pinData 2
#define pinClock 3
#define pinLatch 4

void setup() {
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);
  pinMode(pinLatch, OUTPUT);
  digitalWrite(pinClock, LOW);  // Se inicia en bajo
  digitalWrite(pinLatch, LOW);  // Se inicia en bajo
}

void loop() {
  byte j = B00000001;  // Se empieza con el bit menos significativo encendido
  int i = 0;
  while (i < 14) {
    
    if(i < 7){
      escribir(j);
      j <<= 1;  // Se desplaza hacia la izquierda
    } else{
      escribir(j);
      j >>= 1;  // Se desplaza hacia la derecha
    }
    
    delay(500);
    i++;
  }
}

// Función para escribir datos en el registro de desplazamiento
void escribir(byte data) {
  digitalWrite(pinLatch, LOW);  // Se baja el latch para empezar a cargar datos
  int i = 0;

  while (i < 8) {
    digitalWrite(pinData, (data & 0b10000000) ? HIGH : LOW);  // Se envía el bit más significativo
    digitalWrite(pinClock, HIGH);  // Pulso de reloj para registrar el bit
    digitalWrite(pinClock, LOW);
    data <<= 1;  // Se desplaza a la izquierda para enviar el siguiente bit
    i++;
  }

  digitalWrite(pinLatch, HIGH);  // Se sube el latch para actualizar la salida
}




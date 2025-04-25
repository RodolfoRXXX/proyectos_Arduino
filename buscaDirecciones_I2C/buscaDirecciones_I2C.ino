
/*
  Programa para buscar la dirección del dispositivo que usa el protocolo I2C
*/

#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Buscando dispositivos I2C...");

  for (byte i = 1; i < 127; i++) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo encontrado en 0x");
      Serial.println(i, HEX);
      delay(10);
    }
  }

  Serial.println("Escaneo terminado");
}

void loop() {}

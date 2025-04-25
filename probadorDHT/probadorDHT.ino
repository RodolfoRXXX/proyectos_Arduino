
/*
  Probador de sensor DHT11
*/

#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Probando DHT11...");
  dht.begin();
  delay(2000); // Espera para estabilizar
}

void loop() {
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("❌ No se pudo leer del sensor DHT.");
  } else {
    Serial.print("🌡️ Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    Serial.print("💧 Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
  }

  delay(2000);
}


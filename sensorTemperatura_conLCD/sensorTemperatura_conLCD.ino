
/* Programa medir la temperatura
   con sensor de temperatura DHT11 y LCD 2x14 
   con el mòdulo I2C
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

//Dirección I2C común: 0x2 o 0x3F
LiquidCrystal_I2C lcd(0x27, 14, 2);  // (dirección de memoria, columnas, filas)

// configuración de DHT
#define DHTPIN 8         //pin conectado al sensor
#define DHTTYPE DHT11    //el modelo del sensor de temperatura

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  //inicializamos el LCD
  lcd.init();       
  lcd.backlight();

  //inicializamos el sensor de temperatura
  dht.begin();
  delay(1000);    

  //inicializamos el monitor serial
  Serial.begin(9600);
  Serial.println("Iniciando lectura de temperatura...");

  lcd.setCursor(0, 0);  //columna 0, fila 0
  lcd.print("Temp: ");

  lcd.setCursor(9, 0);  //columna 11, fila 0
  lcd.print("Hum: ");

}

void loop() {
  float temp = dht.readTemperature();
  float humedad = dht.readHumidity();

  if(isnan(temp)&&isnan(humedad)) {
    lcd.setCursor(0, 1);
    lcd.print("Error de lectura");

    Serial.println("Error: no se pudo leer el sensor DHT.");
  } else {
    lcd.setCursor(0, 1);
    lcd.print(temp);
    lcd.print(" C   ");

    lcd.setCursor(9, 1);
    lcd.print(humedad);
    lcd.print(" %");

    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");

    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
  }

  delay(2000);   //espera 2 segundos entre lecturas
}

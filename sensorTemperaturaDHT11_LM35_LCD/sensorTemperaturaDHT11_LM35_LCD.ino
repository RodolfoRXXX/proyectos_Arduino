
/* Programa para comparar funcionamiento de sensores de temperatura
   DHT11 vs LM35
   con LCD
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

//Dirección I2C común: 0x2 o 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);  // (dirección de memoria, columnas, filas)

// configuración de DHT
#define DHTPIN 8         //pin conectado al sensor
#define DHTTYPE DHT11    //el modelo del sensor de temperatura

// Pin donde está conectado el LM35
const int lm35Pin = A0;

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
  lcd.print("Temp_1: ");

  lcd.setCursor(9, 0);  //columna 11, fila 0
  lcd.print("Temp_2: ");

}

void loop() {
  //leo el valor entregado por la entrada digital Pin8
  float tempDHT11 = dht.readTemperature();
  
  //leo el valor analógico del pin A0, donde está el sensor, en una escala de 0 a 1023
  int valorADC = analogRead(lm35Pin);

  //calculo el voltaje de cada división y multiplico por el valor leído
  float voltaje = valorADC * (5.0/1024.0);

  //obtengo la temperatura obtenida en relación con el voltaje medido
  float tempLM35 = voltaje / 0.01;


  if(isnan(tempDHT11)||isnan(tempLM35)) {
    lcd.setCursor(0, 1);
    lcd.print("Error de lectura");
  } else {
    lcd.setCursor(0, 1);
    lcd.print(tempDHT11);
    lcd.print(" C   ");

    lcd.setCursor(9, 1);
    lcd.print(tempLM35);
    lcd.print(" C   ");

  }

  delay(2000);   //espera 2 segundos entre lecturas
}
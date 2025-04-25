
/* Programa para controlar el LCD de 2 filas y 14 caracteres
 con el mòdulo I2C
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

//Dirección I2C común: 0x2 o 0x3F
LiquidCrystal_I2C lcd(0x27, 14, 2);  // (dirección de memoria, columnas, filas)

char *hi = "Hola Mundo";
char *ho = "LED";

void setup() {
  lcd.init();  //inicializa el LCD
  lcd.backlight();  //enciende la luz de fondo

  lcd.setCursor(0, 0);  //columna 0, fila 0
  for (int i=0; i<strlen(hi);i++) {
    lcd.print(hi[i]);
    delay(500);
  }
  lcd.setCursor(strlen(hi)+1, 0);
  lcd.print(ho);
  delay(500);

  lcd.setCursor(0, 1);  //columna 0, fila 1
  lcd.print("I2C LCD ready");

}

void loop() {}

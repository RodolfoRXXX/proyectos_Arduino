
//Deslazando texto en la pantalla lcd

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Creo el objeto lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //Inicializamos el lcd
  lcd.init();

  //Encendemos el backlight
  lcd.backlight();

  //Escribimos el mensaje en una posición central
  lcd.setCursor(10, 0);
  lcd.print("Hola");
  lcd.setCursor(4, 1);
  lcd.print("Texto en desplazamiento");

}

void loop() {
  // Desplazamos una posición a la izquierda
  lcd.scrollDisplayRight();
  delay(500);

}

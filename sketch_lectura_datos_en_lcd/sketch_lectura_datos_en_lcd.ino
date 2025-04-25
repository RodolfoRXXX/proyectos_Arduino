
//Lectura de valor de variación de resistencia de un potenciómetro y mostrado en un lcd

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//Creamos el caracter
byte customChar[] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000
};

void setup() {
  lcd.init();
  lcd.backlight();
  //Crea el caracter
  lcd.createChar (0,customChar);
}

void loop() {
  //Defino la entrada analógica como una variable
  int val1 = analogRead(A0);
  lcd.setCursor(2, 0);
  lcd.print("Resistencia");
  lcd.setCursor(3, 1);
  lcd.print("Valor: ");
  //Muestreo el valor de la entrada analógica
  lcd.print(val1);
  //Escribe el caracter creado
  lcd.write(byte (0));
  delay(300);

}


//Pantalla LCD funcionamiento básico con módulo I2C

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crea el objeto que permite manipular el lcd
//dirección 0x27 y 16 columnas y 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  //inicializa el lcd
  lcd.init();

  //Encender la luz de fondo
  lcd.backlight();

  //Escribimos un mensaje
  lcd.print("Hola mundo");

}

void loop() {
  //Ubicamos el cursor en la primera posición(columna:0) de a segunda fila
  lcd.setCursor(0,1);

  //Escribimos el número de segundos transcurridos
  lcd.print(millis()/1000);
  lcd.print(" segundos");
  delay(1000);

}

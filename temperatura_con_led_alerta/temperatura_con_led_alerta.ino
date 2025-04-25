
/*
  Programa que mide la temperatura y prende un LED rojo si supera un valor máximo y un LED amarillo si cae debajo de un valor mínimo
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//crear el objeto LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//defino los pines a utilizar
#define greenPin 4
#define redPin 5
#define yellPin 6
#define tempPin A0
#define bajo 22.00
#define alto 26.00

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellPin, OUTPUT);
  pinMode(tempPin, INPUT);

  //inicio el LCD
  lcd.init();
  lcd.backlight();

  //inicializamos el monitor serial
  Serial.begin(9600);
  Serial.println("Iniciando...");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Clima: ");
}

void loop() {
  //tomamos el valor de temperatura y lo seteamos como valor de °C
  float temp = (analogRead(tempPin)*(5.0/1024.0))/0.01;

  Serial.println(temp);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellPin, LOW);

  lcd.setCursor(9, 0);
  lcd.print(temp);

  //temp < 24 = amarillo
  // 24 <= temp <= 26 = verde
  // 26 < temp = rojo
  if(temp < bajo) {
    digitalWrite(yellPin, HIGH);
    
    lcd.setCursor(9, 1);
    lcd.print("Frio");
  } else if(temp >= bajo && temp <= alto) {
    digitalWrite(greenPin, HIGH);

    lcd.setCursor(9, 1);
    lcd.print("Lindo");
  } else {
    digitalWrite(redPin, HIGH);
    
    lcd.setCursor(9, 1);
    lcd.print("Calor");
  }

  delay(1000);

}

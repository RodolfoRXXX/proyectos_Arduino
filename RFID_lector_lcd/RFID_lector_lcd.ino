
/*
  Lector RFID RC522 con LCD
*/

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10    // seteamos el pin de datos del RC522
#define RST_PIN 9    // seteamos el reset del RC522

#define redPin 7     // seteamos el pin led rojo
#define greenPin 6   // seteamos el pin led verde

byte tagOk[4] = {72, 11, 92, 51};  //UID válido

LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN); // Creamos el objeto

void setup() {
  Serial.begin(9600);    // Iniciamos el puerto serial
  lcd.init();            // Iniciamos el LCD
  lcd.backlight();       // Activamos luz de fondo
  SPI.begin();           // Iniciamos el bus SPI
  rfid.PCD_Init();       // Iniciamos el RC522

  Serial.println("Listo para leer RFID...");
  lcd.setCursor(0, 0);
  lcd.print("Listo TAG...");
}

void loop() {
  // Esperamos una tarjeta nueva
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  // Mostrar UID en Serial
  Serial.print("UID de tarjeta: ");

  // Construir string del UID
  String uidString = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) uidString += "0"; // Agrega cero para formato
    uidString += String(rfid.uid.uidByte[i], HEX);
    uidString += " ";
  }

  Serial.println(uidString);

  // Mostrar UID en LCD (segunda línea)
  lcd.setCursor(0, 1);
  lcd.print("ID: ");
  lcd.print(uidString);

  delay(2000); // Espera un poco antes de limpiar

  // Limpiar pantalla para esperar nueva tarjeta
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Listo TAG...");

  rfid.PICC_HaltA(); // Detener comunicación con tarjeta
}



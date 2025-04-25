
/*
  Lector RFID RC522
*/

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10    // SDA del RC522
#define RST_PIN 9    // RST del RC522

MFRC522 rfid(SS_PIN, RST_PIN); // Creamos el objeto

void setup() {
  Serial.begin(9600);
  SPI.begin();         // Iniciamos el bus SPI
  rfid.PCD_Init();     // Iniciamos el RC522
  Serial.println("Listo para leer RFID...");
}

void loop() {
  // Esperamos a que se acerque una tarjeta
  if ( !rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial() ) {
    return;
  }

  Serial.print("UID de tarjeta: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Esperamos a que se quite la tarjeta antes de leer otra
  rfid.PICC_HaltA();
}


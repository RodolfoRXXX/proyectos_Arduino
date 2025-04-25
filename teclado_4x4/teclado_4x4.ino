
/*
  Funcionamiento del keypad
*/

#include <Keypad.h>

// Definir numeros de filas y columnas
const byte FILAS = 4;
const byte COLUMNAS = 4;

// Definir las teclas del teclado
char teclas[FILAS][COLUMNAS] = {
  { '1', '2', '3', '4' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

//Pines del arduino conectado al teclado
byte pinesFILAS[FILAS] = {4, 5, 6, 7};
byte pinesCOLUMNAS[COLUMNAS] = {8, 9, 10, 11};

// Crear el objeto teclado
Keypad teclado = Keypad(makeKeymap(teclas), pinesFILAS, pinesCOLUMNAS, FILAS, COLUMNAS);

void setup() {
  Serial.begin(9600);
  Serial.println("Listo para leer el teclado 4x4");

}

void loop() {
  char tecla = teclado.getKey();

  if(tecla) {
    Serial.print("Tecla presionada: ");
    Serial.println(tecla);
  }
}


/*
  Funcionamiento KeyPad 4x4 sin librerías con display de 7 segmentos + punto

  1- identificar los pines que controlan las columnas de los pulsadores
  2- identificar los pines que controlan las filas de los pulsadores
  3- definir los pines para filas y columnas de arduino
  4- construimos una matriz donde asignamos cada fila y columna a cada fila y columna del teclado
  5- Definimos los pines de las filas como salidas y en HIGH
  6- Definimos los pines de las columnas como entradas con pull-up
  7- Paso fila a fila con LOW y espero si de esa fila alguna columna detecto un LOW
  8- Con ese valor de índice de fila y columna busco en la matriz para saber que tecla se presionó
  9- Con el caracter obtenido desde el teclado se busca en el array de display y se obtiene el codigo binario que muestra el dígito en el display
*/

// Definir los pines para filas y columnas
const byte filas[4] = {2, 3, 4, 5};     // Pines para filas
const byte columnas[4] = {6, 7, 8, 9};  // Pines para columnas

const byte segmentos[8] = {11, 10, A2, A1, A0, 12, 13, A3};  // 10-B/11-A/12-F/13-G/A0-E/A1-D/A2-C/A3-DP

char mapaTeclas[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Definir el array de salidas del display
byte display[16][2] = {
  { '1', 0b00000110},  //1
  { '2', 0b01011011},  //2
  { '3', 0b01001111},  //3
  { '4', 0b01100110},  //4
  { '5', 0b01101101},  //5
  { '6', 0b01111101},  //6
  { '7', 0b00000111},  //7
  { '8', 0b01111111},  //8
  { '9', 0b01101111},  //9
  { '0', 0b00111111},  //0
  { 'A', 0b01110111},  //A
  { 'B', 0b01111111},  //B
  { 'C', 0b00111001},  //C
  { 'D', 0b00111111},  //D
  { '*', 0b00000000},  //*
  { '#', 0b10000000}   //#
};

void setup() {
  Serial.begin(9600);

  // Configurar filas como salidas y ponerlas en HIGH
  for (int i = 0; i < 4; i++) {
    pinMode(filas[i], OUTPUT);
    digitalWrite(filas[i], HIGH);
  }

  // Configurar columnas como entradas con pull-up
  for (int i = 0; i < 4; i++) {
    pinMode(columnas[i], INPUT_PULLUP);
  }

  //Configurar pines de los segmentos del display
  for(int i = 0; i < 8; i++) {
    pinMode(segmentos[i], OUTPUT);
    digitalWrite(segmentos[i], LOW);
  }
}

void loop() {
  for (int f = 0; f < 4; f++) {
    // Activar una fila a LOW
    digitalWrite(filas[f], LOW);

    // Leer todas las columnas
    for (int c = 0; c < 4; c++) {
      if (digitalRead(columnas[c]) == LOW) {
        // Tecla detectada
        Serial.print("Tecla presionada: ");
        Serial.println(mapaTeclas[f][c]);

        muestraDigito(mapaTeclas[f][c]);

        // Esperar a que se suelte la tecla para evitar rebote múltiple
        while (digitalRead(columnas[c]) == LOW);
        delay(50); // Pequeño debounce
      }
    }

    // Desactivar fila
    digitalWrite(filas[f], HIGH);
  }
}

// Función que recibe un caracter y muestra en el display el valor leído
void muestraDigito(char tecla) {
  byte codigo = 0;
  for (int i = 0; i < 16; i++) {
    if(display[i][0] == tecla) {
      Serial.println(display[i][1]);
      codigo = display[i][1];
      for (int b = 0; b < 8; b++) {
       digitalWrite(segmentos[b], bitRead(codigo, b));
      }
      break;
    }
  }
  
}

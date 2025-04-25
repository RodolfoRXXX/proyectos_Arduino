/*
  Teclado de 4x4 botones con display de 8 segmentos por 4 unidades con shift register

  Se debe multiplexar la información para alimentar a todos los displays por separado
*/

//TECLADO

// Definir los pines para filas y columnas
const byte filas[4] = {2, 3, 4, 5};     // Pines para filas
const byte columnas[4] = {6, 7, 8, 9};  // Pines para columnas

char mapaTeclas[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'<', '0', '>', 'D'}
};

// DISPLAY

const byte pinData = 10;
const byte pinClock = 11;
const byte pinLatch = 12;
const byte digito[4] = {A0, A1, A2, A3};  //A0-DIG0/A1-DIG1/A2-DIG2/A3-DIG3

// Definir el array de salidas del display
byte display[14][2] = {
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
  { 'D', 0b00000000}   //D
};

//Valores ingresados
char memoria[4] = {'\0', '\0', '\0', '\0'};

void setup() {
  Serial.begin(9600);

// Configurar el teclado
  // Configurar filas como salidas y ponerlas en HIGH
  for (int i = 0; i < 4; i++) {
    pinMode(filas[i], OUTPUT);
    digitalWrite(filas[i], HIGH);
  }

  // Configurar columnas como entradas con pull-up
  for (int i = 0; i < 4; i++) {
    pinMode(columnas[i], INPUT_PULLUP);
  }

//Configurar el shift register
  pinMode(pinData, OUTPUT);
  pinMode(pinClock, OUTPUT);
  pinMode(pinLatch, OUTPUT);
  digitalWrite(pinData, LOW);
  digitalWrite(pinClock, LOW);
  digitalWrite(pinLatch, LOW);

  //Configurar los pines de alimentación del cátodo de cada display
  for(int i = 0; i < 4; i++) {
    pinMode(digito[i], OUTPUT);
    digitalWrite(digito[i], HIGH);
  }
}

void loop() {
  char teclaPresionada = presionado();
  if (teclaPresionada != '\0') {
    guardarDigito(teclaPresionada);
    Serial.println(memoria[0]);
    Serial.println(memoria[1]);
    Serial.println(memoria[2]);
    Serial.println(memoria[3]);
    if(teclaPresionada == 'D') {
      limpiarMemoria();
    }
  }

  //Recorrer la memoria para buscar valores
  if(!estaVacio()) {
    for(int i = 0; i < 4; i++) {
      if (memoria[i] != '\0') {
        mostrarDigito(memoria[i]);
      } else {
        mostrarCodigo(0x00);
      }
      activarDigito(i);
      delay(2);
      apagarTodo();
    }
  }
}

void mostrarCodigo(byte codigo) {
  digitalWrite(pinLatch, LOW);
  for (int b = 7; b >= 0; b--) {
    digitalWrite(pinClock, LOW);
    digitalWrite(pinData, bitRead(codigo, b));
    digitalWrite(pinClock, HIGH);
  }
  digitalWrite(pinLatch, HIGH);
}

//Comprueba si la memoria está vacía
boolean estaVacio() {
  for(int i = 0; i < 4; i++) {
    if(memoria[3 - i] != '\0') {
      return false;
    }
  }
  return true;
}

//Función que detecta lo presionado en el teclado
char presionado() {
  for (int f = 0; f < 4; f++) {
    digitalWrite(filas[f], LOW);

    for (int c = 0; c < 4; c++) {
      if (digitalRead(columnas[c]) == LOW) {
        char tecla = mapaTeclas[f][c];

        // Esperar a que se suelte (debounce)
        while (digitalRead(columnas[c]) == LOW);
        delay(50);

        return tecla;
      }
    }

    digitalWrite(filas[f], HIGH);
  }

  return '\0'; // Nada presionado
}

//Función que guarda el dígito en memoria
void guardarDigito(char tecla) {
  int i = 0;
  while((i < 4) && (memoria[i] != '\0')) i++;
  if(i < 4) memoria[i] = tecla;
}

// Función que recibe un caracter y muestra en el display el valor leído
void mostrarDigito(char tecla) {
  byte codigo = 0;
  for (int i = 0; i < 14; i++) {
    if (display[i][0] == tecla) {
      codigo = display[i][1];
      break;
    }
  }

  // Enviar el byte al 74HC595
  digitalWrite(pinLatch, LOW);
  for (int b = 7; b >= 0; b--) {
    digitalWrite(pinClock, LOW);
    digitalWrite(pinData, bitRead(codigo, b));
    digitalWrite(pinClock, HIGH);
  }
  digitalWrite(pinLatch, HIGH);
}

//Función para activar dígito
void activarDigito(int i) {
  digitalWrite(digito[i], LOW);
}

//Apaga todos los dígitos
void apagarTodo() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digito[3 - i], HIGH);
  }
}

//Limpiar memoria
void limpiarMemoria() {
  for(int i = 0; i < 4; i++) {
    memoria[3 - i] = '\0';
  }
}

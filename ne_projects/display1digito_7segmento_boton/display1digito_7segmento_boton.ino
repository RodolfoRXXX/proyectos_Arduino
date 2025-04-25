//Código para probar el display de 1 dígito y 7 segmentos con botón

//Defino los pones de arduino conectados a cada segmento
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int dp = 9;

int botonPinUp = 10;
int botonPinDown = 12;

int led = 11;

//variables para contar y almacenr el estado del botón

int contador = 0;
int estadoBotonUp = 0;
int ultimoEstadoBotonUp = 0;

int estadoBotonDown= 0;
int ultimoEstadoBotonDown = 0;

//Defino la tabla de números para el display de cátodo común
//Un 1 encenderá el segmento(envía HIGH), un 0 lo apagará (envía LOW)

int num[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}, //9
};

void setup() {
  // configurar los pines de segmentos como salidas
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(botonPinUp, INPUT);
  pinMode(botonPinDown, INPUT);
  pinMode(led, OUTPUT);

}

// creo la función que activa cada segmento
void mostrarNumero(int n) {
  digitalWrite(a, num[n][0]);
  digitalWrite(b, num[n][1]);
  digitalWrite(c, num[n][2]);
  digitalWrite(d, num[n][3]);
  digitalWrite(e, num[n][4]);
  digitalWrite(f, num[n][5]);
  digitalWrite(g, num[n][6]);
}

void loop() {
  //Lee el estado del botón
  estadoBotonUp = digitalRead(botonPinUp);
  estadoBotonDown = digitalRead(botonPinDown);

//Verifica si el botón se ha presionado
  if (estadoBotonUp == HIGH && ultimoEstadoBotonUp == LOW) {
    contador++;
    if (contador > 9) {
      contador = 0;
    }
    mostrarNumero(contador);
    delay(200);
  }

  if (estadoBotonDown == HIGH && ultimoEstadoBotonDown == LOW) {
    contador--;
    if (contador < 0) {
      contador = 9;
    }
    mostrarNumero(contador);
    delay(100);
  }

  if (contador == 0) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }


//Actualizar el estado anterior del botón
  ultimoEstadoBotonUp = estadoBotonUp;
  ultimoEstadoBotonDown = estadoBotonDown;
}
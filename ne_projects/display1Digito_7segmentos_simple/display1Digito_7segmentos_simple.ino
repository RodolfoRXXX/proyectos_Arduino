//Código para probar el display de 1 dígito y 7 segmentos

//Defino los pones de arduino conectados a cada segmento
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int dp = 9;

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
  // contar del 0 al 9 y mostrarlo en el display
  for (int i = 0; i < 10; i++) {
    mostrarNumero(i);
    delay(1000);
  }

}

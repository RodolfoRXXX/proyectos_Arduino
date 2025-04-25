//  Alimentación de un led con una señal analógica simulada a través de un pin de salida
// digital con Pwm

int LED = 3;
int BRILLO;
int POT = 0;
boolean state = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  // las entradas analógicas no requieren inicialización porq solo se pueden usar
  // como entrada
}

void loop() {
  // Código para que el led funcione sin el potenciómetro
  /*for(BRILLO = 0; BRILLO <= 255; BRILLO++) {
    if(state) {
      analogWrite(LED, BRILLO);
    } else {
      analogWrite(LED, 255 - BRILLO);
    }
    delay(15);
  }
  state = !state;
  */

  // Código para leer el valor del potenciómetro y controlar el led
    //El rango de lectura de la entrada analógica es de 0 a 1023 y de la entrada digital
    // es de 255, por ello es que para controlar el led debemos dividir por 4 el valor
    // de la entrada analógica
    Serial.println(analogRead(POT));
  BRILLO = analogRead(POT) / 4;
  analogWrite(LED, BRILLO);
  Serial.println(BRILLO);
  delay(500);
}

//Encender un LED con un potenciómetro

int LED = 3;         // Pin PWM donde está conectado el LED
int LDR_PIN = A0;    // Pin analógico donde está conectado el divisor de tensión del LDR
int brillo;          // Variable para almacenar el valor del brillo

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial para depuración
  pinMode(LED, OUTPUT); // Configura el pin del LED como salida
}

void loop() {
  int lecturaLDR = analogRead(LDR_PIN); // Lee el valor analógico del LDR (0-1023)
  Serial.println(lecturaLDR);           // Imprime el valor leído en el monitor serial
  
  // Convierte la lectura al rango 0-255 para el PWM
  brillo = map(lecturaLDR, 0, 1023, 0, 255);
  
  // Ajusta el brillo del LED según el valor del LDR
  analogWrite(LED, brillo);
  
  delay(100); // Espera un poco antes de la siguiente lectura
}

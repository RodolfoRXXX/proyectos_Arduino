
//Sketch de un código que permite muestrear la salida de un potenciómetro que va modificando su valor de resistencia
//Estos datos se obtienen leyendo un puerto analógico al que está conectado un extremo del potenciómetro

void setup() {
  //Velocidad de transferencia de dato, 9600 bits/seg o baudios
  Serial.begin(9600);
}

void loop() {
  //Con esto leemos el valor analógico del pin A0 y lo guardamos en la variable serialValue
  int sensorValue = analogRead(A5);

  Serial.println(sensorValue, HEX);

  delay(1000);
}

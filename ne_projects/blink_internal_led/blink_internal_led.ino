//Código básico para prender y apagar el led de la placa arduino

void setup() {
  pinMode(13, OUTPUT);        //pin 13 configurado como salida
}

void loop() {
  digitalWrite(13, HIGH);     // pin 13 seteado en un nivel alto
  delay(2000);
  digitalWrite(13, LOW);     // pin 13 seteado en un nivel bajo
  delay(100);
}
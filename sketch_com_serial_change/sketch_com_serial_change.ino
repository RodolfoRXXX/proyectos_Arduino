//Programa "Hola Mundo"

//Código que muestra cómo enviar datos a la computadora por el puerto serial


void setup() {
  //Invoco a la librería serial, configuro la comunicación serial entre la computadora y la placa arduino a una velocidad de 9600 bits/s o baudios
  Serial.begin(9600);

  //Imprimo en el monitor serial la frase: "Hola Mundo" y luego dejo el cursor en la siguiente linea
  Serial.println("Hola Mundo");
  Serial.println("Convertiremos a binario");
  Serial.println("Convirtiendo 12 de decimal a binario");
  delay(2000);
  Serial.println("Procesando.....");
  delay(3000);
  Serial.println(12, BIN);
  Serial.println("----------------------------------------");
  Serial.println("Hola Mundo");
  Serial.println("Convertiremos a hexadecimal");
  Serial.println("Convirtiendo 78 de decimal a hexadecimal");
  delay(2000);
  Serial.println("Procesando.....");
  delay(3000);
  Serial.println(78, HEX);
}

void loop() {
  // put your main code here, to run repeatedly:

}

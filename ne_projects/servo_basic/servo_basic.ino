//Ejemplo simple de funconamiento de un servomotor

#include  <Servo.h>

Servo myServo;  //Creo un objeto servo

void setup() {
  myServo.attach(9);  //conecta el pin de contról del servo al pin 9 de Arduino

}

void loop() {
  myServo.write(0);  //mueve el servo a la posición de 0 grados
  delay(500);

  myServo.write(90);  //mueve el servo a la posición de 90 grados
  delay(500);

  myServo.write(180);  //mueve el servo a la posición de 180 grados
  delay(500);

  myServo.write(90);  //mueve el servo a la posición de 90 grados
  delay(500);

}

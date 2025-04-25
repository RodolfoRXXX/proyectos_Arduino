//Ejemplo simple de funconamiento de un servomotor

#include  <Servo.h>

Servo myServo;  //Creo un objeto servo

void setup() {
  myServo.attach(9);  //conecta el pin de contról del servo al pin 9 de Arduino

}

void loop() {
  for (int angle = 5; angle <= 105; angle += 1) {
    myServo.write(angle);
    delay(10);
  }

  delay(2000);

  for (int angle = 105; angle >= 5; angle -= 1) {
    myServo.write(angle);
    delay(10);
  }

  delay(3000);

}

/*
    Códigos con LED x 8
    <  W  >
    
*/

#define delTime 300

void setup() {
  for(int i = 4; i <=11; i++)
  {
    pinMode(i, OUTPUT);
  }

}

void loop() {

/*
  //enciende los leds una sola vez
  for(int i = 4; i <=11; i++)
  {
    digitalWrite(i, HIGH);
  }
*/

  //enciende y apaga cada led con un retraso de 500ms de derecha a izquierda
  for(int i = 4; i <11; i++)
  {
    digitalWrite(i, HIGH);
    delay(delTime);
    digitalWrite(i, LOW);
    delay(delTime);
  }

  //enciende y apaga cada led con un retraso de 500ms de izquierda a derecha
  for(int i = 11; i >4; i--)
  {
    digitalWrite(i, HIGH);
    delay(delTime);
    digitalWrite(i, LOW);
    delay(delTime);
  }
}

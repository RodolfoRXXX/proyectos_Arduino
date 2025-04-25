/*
    Códigos con LED x 8 con interruptor
    <  W  >
    
*/

int estado_led;

void setup() {
  for(int i = 4; i <= 11; i++)
  {
    pinMode(i, OUTPUT);
  }
    pinMode(2, INPUT);
}


void loop() {

  //leds que encienden cuando mantengo apretado el botón
  /*
  if(digitalRead(2) == HIGH)
  {
    for(int i = 4; i <= 11; i++)
    {
      digitalWrite(i, HIGH);
    }
  } else
  {
    for(int i = 4; i <= 11; i++)
    {
      digitalWrite(i, LOW);
    }
  }
  */

  /*
  int verificador = digitalRead(2);
  if(verificador != estado_led && estado_led == HIGH)
  {
    estado_led = digitalRead(4);
    for(int i = 4; i <= 11; i++)
    {
      digitalWrite(i, !estado_led);
    }
  }
  estado_led = verificador;
  */

  int verificador;
  while(digitalRead(2) == LOW) {}

  verificador = digitalRead(4);
  for(int i = 0; i <= 11; i++)
  {
    digitalWrite(i, !verificador);
  }

  while(digitalRead(2) == HIGH) {}

}

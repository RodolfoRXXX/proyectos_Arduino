/*
    Alarma de inclinación
    
    <  W  >
    LOW
    digitalWrite();

*/

void setup() {
  Serial.begin(9600); // Inicializar comunicación serie

  for(int i = 4; i <= 11; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(2, INPUT);
}

void loop() {
  
  if(digitalRead(2) == LOW)
  {
    alarma();
  }else
  {
    reset();
  }
  
  Serial.println(digitalRead(2));

}

//funciones

void alarma()
{
  for(int i = 4; i <= 11; i++)
  {
    digitalWrite(i, HIGH);
  }

  delay(300);

  for(int i = 4; i <= 11; i++)
  {
    digitalWrite(i, LOW);
  }

  delay(300);
}

void reset()
{
  for(int i = 4; i <= 11; i++)
  {
    digitalWrite(i, LOW);
  }
}



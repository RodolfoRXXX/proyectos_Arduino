/*
    Alarma de inclinación sonora
    
    <  W  >
    LOW
    digitalWrite();

*/

void setup() {
  Serial.begin(9600); // Inicializar comunicación serie

  pinMode(4, OUTPUT);

  pinMode(3, INPUT);
}

void loop() {
  
  if(digitalRead(3) == LOW)
  {
    alarma();
    Serial.println(digitalRead(3));
  }else
  {
    reset();
  }
  
  

}

//funciones

void alarma()
{
  digitalWrite(4, HIGH);

  delay(300);

  digitalWrite(4, LOW);

  delay(300);
}

void reset()
{
  digitalWrite(4, LOW);
}

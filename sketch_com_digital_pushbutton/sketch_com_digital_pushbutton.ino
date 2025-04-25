
//Lectura de valores digitales desde el puerto digital(0, 1)

int pushButton = 2; //El pin digital 2 tiene un pushbutton conectado a él, guardamos esa salida en una variable

void setup() {
  Serial.begin(9600); //Se inicia la comunicación serial, de entrada análoga o digital, funciona para ambas

  pinMode(pushButton, INPUT); //definimos el pin 2 como entrada con pinMode
}

void loop() {
  int buttonState = digitalRead(pushButton); //la entrada digital que leemos en el pin 2 la almacenamos en una variable
  Serial.println(buttonState);  //mostramos el estado de la entrada digital
  delay(50); //generamos un retraso entre lecturas para darle estabilidad
}

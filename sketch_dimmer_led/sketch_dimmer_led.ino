
//Sketch para controlar el dimmer de un LED con un potenciómetro(resistencia variable)
//variando la corriente que circula por la resistencia de 220k que está conectada al LED

  int cursorPin = A0; //setea el pin A0 conectado al potenciómetro
  int cursorValue = 0;  //variable para el value digital del potenciómetro
  int LEDPin = 6; //pin de salida para el LED

void setup() {

  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  cursorValue = analogRead(cursorPin); // lee el valor del potenciómetro y lo guarda

  // señal de salida digital PWM para el LED
    //el potenciómetro genera una entrada desde 0 hasta 1023 pero el LED soporta desde 0 hasta 255
    //por eso dividimos por 4
  analogWrite(LEDPin, cursorValue/4);
}


//Funcionamiento de un joystick con servomotor

#include <Servo.h>

int pin_servo = 3;
int pin_joy_x = A0;
int x;
int x_ang;

Servo motor;

void setup() {
  Serial.begin(9600);
  motor.attach(pin_servo);
  motor.write(0);
}

void loop() {
  x = analogRead(pin_joy_x);
  x_ang = map( x, 0, 1023, 0, 180 );
  Serial.print( "X_ang:" );
  Serial.println(x_ang);
  motor.write( x_ang );
  delay(100);
}

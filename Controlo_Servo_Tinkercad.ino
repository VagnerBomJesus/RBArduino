#include <Servo.h>

#define SERVO_PIN 3

Servo myServo;

int pos = 0;

void setup()
{
  pinMode(SERVO_PIN, OUTPUT);
  myServo.attach(SERVO_PIN);
}

void loop()
{
  //servoPositionControlWidthSignal(2000);
  //servoPositionControlWidthLib1();
  //servoPositionControlWidthLib2();
  servoSpeedControlWidthLib();
}

void servoPositionControlWidthSignal(int t) {
   digitalWrite(SERVO_PIN, HIGH);
   delayMicroseconds(t); 
   digitalWrite(SERVO_PIN, LOW);
  
   delayMicroseconds(20000);
}

void servoPositionControlWidthLib1() {
  myServo.write(0);
  delay(2000);
  
  myServo.write(45);
  delay(2000);
  
  myServo.write(90);
  delay(2000);

  myServo.write(180);
  delay(2000);
}

void servoPositionControlWidthLib2() {
  for(pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);
  }
  for(pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
}

void servoSpeedControlWidthLib() {
  // No caso dos servomotores de rotação continua, o valor 90 corresponde a uma velocidade nula. 
  // Valores abaixo de 90 fazem o motor rodar num dado sentido e valores acima de 90 fazem o 
  // motor rodar no sentido oposto. Em ambos os sentidos de rotação, os valores extremos de 0 e 180
  // correspondem ás velocidades máximas.
  
  // Pára o motor.
  myServo.write(90);
  delay(2000);
    
  // Incrementa a velocidade de rotação do motor num dado sentido, desde o valor mínimo 89, até ao valor  
  // máxima 0.
  for(pos = 89; pos >=0; pos -= 1) {
    myServo.write(pos);
    delay(250);
  }
  
  myServo.write(90);
  delay(2000);

  // Incrementa a velocidade de rotação do motor no sentido oposto, desde o valor mínimo 91, até ao valor  
  // máxima 180.
  for(pos = 91; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(250);
  } 
}


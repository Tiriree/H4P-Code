#include <ESP32Servo.h>
int pin_pot=A0;

Servo myservo; 
int pos = 0;    
int servoPin = D6;

void setup() {
	myservo.setPeriodHertz(50);
  myservo.attach(servoPin);
}

void loop() {
int pot_value=analogRead(pin_pot);
int servo_value=map(pot_value,0,3220,0,180);
myservo.write(servo_value);	
}


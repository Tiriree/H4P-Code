#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <ESP32Servo.h>

Adafruit_MPU6050 mpu;
Servo myservo;
int servoPin = D6;

void setup() {
  Serial.begin(115200);
  // MPU6050
  Wire.begin();
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 connected!");
  // servo
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin);
}

void loop() {
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  mpu.getEvent(&accel, &gyro, &temp);
  // read tilt from X axis
  float x = accel.acceleration.x;
  // constrain it to approximately -1g to +1g
  x = constrain(x, -9.8, 9.8);
  // convert -9.8 to +9.8 into 0 to 180 degrees
  int servoPos = map(x * 100, -980, 980, 0, 180);
  myservo.write(servoPos);
  Serial.print("Accel X: ");
  Serial.print(x);
  Serial.print("  Servo: ");
  Serial.println(servoPos);
  delay(20);
}
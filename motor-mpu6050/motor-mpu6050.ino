#include <Stepper.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

const int stepsPerRevolution = 2048;

#define IN1 D0
#define IN2 D1
#define IN3 D2
#define IN4 D3

Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 connected!");

  // Stepper speed
  myStepper.setSpeed(15);
}

void loop() {
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;

  mpu.getEvent(&accel, &gyro, &temp);

  float x = accel.acceleration.x;

  Serial.print("Accel X: ");
  Serial.println(x);

  if (x > 3.0) {
    Serial.println("Clockwise");
    myStepper.step(20);
  }
  else if (x < -3.0) {
    Serial.println("Counterclockwise");
    myStepper.step(-20);
  }
  else {
    Serial.println("Stop");
  }
  delay(20);
}
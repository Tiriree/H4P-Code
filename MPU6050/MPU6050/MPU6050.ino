#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

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
}

void loop() {
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  mpu.getEvent(&accel, &gyro, &temp);
  Serial.print("Accel X: ");
  Serial.print(accel.acceleration.x);
  Serial.print("  Y: ");
  Serial.print(accel.acceleration.y);
  Serial.print("  Z: ");
  Serial.println(accel.acceleration.z);

  Serial.print("Gyro X: ");
  Serial.print(gyro.gyro.x);
  Serial.print("  Y: ");
  Serial.print(gyro.gyro.y);
  Serial.print("  Z: ");
  Serial.println(gyro.gyro.z);
  Serial.println();
  delay(100);
}
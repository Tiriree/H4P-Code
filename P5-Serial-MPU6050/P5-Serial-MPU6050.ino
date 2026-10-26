const int LED = D7;
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Wire.begin();                       // D4 = SDA, D5 = SCL

  if (!mpu.begin()) {                 // defaults to address 0x68
    while (true) {                    // blink fast if the sensor isn't found
      digitalWrite(LED, !digitalRead(LED));
      delay(100);
    }
  }
  // mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  // mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  // mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  //read incoming serial 
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '1') digitalWrite(LED, HIGH);
    if (c == '0') digitalWrite(LED, LOW);
  }

  // check sensor
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); 
  Serial.printf("%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n",
                a.acceleration.x, a.acceleration.y, a.acceleration.z,
                g.gyro.x, g.gyro.y, g.gyro.z);
  delay(20);
}

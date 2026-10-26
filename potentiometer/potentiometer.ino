void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(A0); 
  // int outputValue = map(sensorValue, 0, 4095, 0, 255);
  // int voltage = analogReadMilliVolts(A0);
  Serial.println(sensorValue);
  delay(100);
}
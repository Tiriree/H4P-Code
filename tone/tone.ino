void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(A0);
  int thisPitch = map(sensorValue, 0, 3320, 120, 800);
  tone(D8, thisPitch);
  // Serial.print("ADC: ");
  // Serial.print(sensorValue);
  // Serial.print("  Pitch: ");
  // Serial.println(thisPitch);
  delay(20);
}
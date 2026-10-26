void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(A0);
  int LED_Value = map(sensorValue, 0, 3320, 0, 255);
  analogWrite(D8, LED_Value);
  // Serial.print("sensorValue: "); 
  // Serial.print(sensorValue);
  // Serial.print("  LED Value: ");
  // Serial.println(LED_Value);
  delay(100);
}

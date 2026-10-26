const int ledPin = D7;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int LED_Value = map(sensorValue, 200, 2800, 0,255);
  analogWrite(ledPin,LED_Value);
  Serial.print(sensorValue);
  Serial.print("  ");
  Serial.println(LED_Value);
  delay(100);
}
const int ledPin = D7;

void setup() {
  pinMode(ledPin, OUTPUT);
  analogReadResolution(12);
}

void loop() {
  int sensorValue = analogRead(A0);
  int blinkSpeed = map(sensorValue, 0, 4095, 50, 1000);
  digitalWrite(ledPin, HIGH);
  delay(blinkSpeed);
  digitalWrite(ledPin, LOW);
  delay(blinkSpeed);
}
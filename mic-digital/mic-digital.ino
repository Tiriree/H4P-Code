const int micPin = D2;

void setup() {
  Serial.begin(115200);
  pinMode(micPin, INPUT);
}

void loop() {
  int sound = digitalRead(micPin);
  Serial.println(sound);
  delay(10);
}
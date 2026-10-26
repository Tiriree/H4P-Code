int touchButton = D0;

void setup() {
  Serial.begin(115200);
  pinMode(touchButton, INPUT);
}

void loop() {
  int touchState = digitalRead(touchButton);
  Serial.println(touchState);
  delay(1);  // delay in between reads for stability
}


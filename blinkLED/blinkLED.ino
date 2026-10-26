const int LEDPIN = D7;
void setup() {
  pinMode(LEDPIN,OUTPUT);
  // digitalWrite(LEDPIN, HIGH);
}

void loop() {
  digitalWrite(LEDPIN, HIGH);  // LED ON
  delay(1000);                 // wait 1 second
  digitalWrite(LEDPIN, LOW);   // LED OFF
  delay(1000);                 // wait 1 second
}

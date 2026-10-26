const int READPIN = A0;

void setup() {
  pinMode(READPIN, INPUT);
  // pinMode(READPIN, INPUT_PULLDOWN);
  Serial.begin(115200);//communication rate

}

void loop() {
  Serial.println(analogRead(READPIN));
  delay(100);
}

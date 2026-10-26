const int LEDPIN = D7;
const int SWITCHPIN = D6;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(SWITCHPIN, INPUT_PULLDOWN); //pull down resistor 
}

void loop() {
  if (digitalRead(SWITCHPIN) == LOW) { // read the switch, if it's low>>
    digitalWrite(LEDPIN, HIGH);  // LED ON
  }
  else {
    digitalWrite(LEDPIN, LOW);   // LED OFF
  }
}
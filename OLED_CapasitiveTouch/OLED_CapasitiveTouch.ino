#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

#define TOUCH_PIN D0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

bool lastState = false;
int touchCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(TOUCH_PIN, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display();
}

void loop() {
  bool touched = digitalRead(TOUCH_PIN) == HIGH;

  // Count only on a new touch, not while held
  if (touched && !lastState) {
    touchCount++;
    Serial.println("Touched!");
  }
  lastState = touched;

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Touch Sensor");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.println(touched ? "TOUCHED" : "Nothing");

  display.setTextSize(1);
  display.setCursor(0, 50);
  display.print("Count: ");
  display.println(touchCount);

  display.display();
  delay(20);
}

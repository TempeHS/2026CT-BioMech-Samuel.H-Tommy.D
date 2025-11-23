#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED setup
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const int HR_PIN = A0;   // Analog pin connected to heart rate sensor
unsigned long lastBeat = 0;
int bpm = 6000 / int;

void setup() {
  Serial.begin(9600);

  // Start OLED
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Heart Rate Monitor");
  display.display();
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(HR_PIN);

  // Simple threshold detection (adjust threshold as needed)
  if (sensorValue > 550) {  
    unsigned long now = millis();
    unsigned long interval = now - lastBeat;

    if (interval > 300 && interval < 2000) { // filter out noise
      bpm = 60000 / interval;
      Serial.print("BPM: ");
      Serial.println(bpm);

      // Show BPM on OLED
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0, 20);
      display.print("BPM: ");
      display.print(bpm);
      display.display();
    }
    lastBeat = now;
  }

  delay(20); // small delay for stability
}

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED setup
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const int HR_PIN = A0;        // Analog pin connected to heart rate sensor
unsigned long lastBeat = 0;   // time of last detected beat
int bpm = 0;                  // beats per minute

void setup() {
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED init failed"));
    while (true); // stop if OLED not found
  }
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

  // Simple threshold detection (tune this value for your sensor)
  if (sensorValue > 550) {
    unsigned long now = millis();
    unsigned long interval = now - lastBeat;

    // Only count plausible heartbeats (30–200 BPM range)
    if (lastBeat > 0 && interval > 300 && interval < 2000) {
      bpm = 60000 / interval;  // convert ms interval to BPM
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

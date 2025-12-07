#include <Wire.h>
#define HR_SENSOR_ADDR 0x50  // Confirm in README

const int BUZZER_PIN = 5;    // Grove D5

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.println("Heart Rate Sensor Test");
}

void loop() {
  Wire.requestFrom(HR_SENSOR_ADDR, 1);
  if (Wire.available()) {
    uint8_t hr = Wire.read();
    Serial.print("Heart Rate: ");
    Serial.println(hr);

    if (hr > 150) {
      tone(BUZZER_PIN, 1000, 200); // 1000 Hz for 200 ms
    }
  } else {
    Serial.println("No data from sensor");
  }
  delay(500);
}
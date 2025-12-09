#include <Wire.h>
#define HR_SENSOR_ADDR 0x50  // Confirm in README

void heartrate_sensor_setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("Heart Rate Sensor Test");
}

void heartrate_sensor_loop() {
  Wire.requestFrom(HR_SENSOR_ADDR, 1);
  if (Wire.available()) {
    uint8_t hr = Wire.read();
    Serial.print("Heart Rate: ");
    Serial.println(hr);
  } else {
    Serial.println("No data from sensor");
  }
  delay(500);
}
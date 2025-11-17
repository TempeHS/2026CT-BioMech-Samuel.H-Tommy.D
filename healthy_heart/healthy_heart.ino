#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>


unsigned static int buzzer = 5;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

void setup() {
  heartrate_sensorSetup();
  OLED_screenSetup();
  buzzerSetup();
}
void loop() {
  heartrate_sensor();
  OLED_screen();
  buzzer();
}
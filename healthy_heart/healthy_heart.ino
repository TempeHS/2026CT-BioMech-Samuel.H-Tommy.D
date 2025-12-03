#include <math.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "heartrate.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
int rate;
int speaker_access;
int buttonPIN = 4;

void setup() {
  Serial.begin(9600);
  heartrate_setup();
  OLED_screen_setup();
  buzzer_setup();
}

void loop() {
  heartrate_setup();
  OLED_screen_setup();
  buzzer_setup();
  delay(100);
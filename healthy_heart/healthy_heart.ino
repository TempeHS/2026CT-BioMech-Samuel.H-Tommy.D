#include <math.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
int rate;
int speaker_access;
int buttonPIN = 4;
const int BUZZER_PIN = 5;  // Grove D5 (change if using another port)

void setup() {
  Serial.begin(9600);
  heartrate_setup();
  OLED_screen_setup();
  buzzer_setup();
}

void buzzer_setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  // Optionally, play a startup tone
  tone(BUZZER_PIN, 1000, 200);  // 1000 Hz for 200 ms
}

void OLED_screen_setup() {
  OLED.begin();
  OLED.clearBuffer();
  OLED.setFont(u8g2_font_ncenB08_tr);
  OLED.drawStr(0, 10, "OLED Ready");
  OLED.sendBuffer();
}

void heartrate_setup() {
  // Example: pinMode for heart rate sensor
  pinMode(A0, INPUT);  // Replace A0 with your sensor pin
  // Add any other initialization needed for your sensor
}

void loop() {
  heartrate_setup();
  OLED_screen_setup();
  buzzer_setup();
  delay(100);
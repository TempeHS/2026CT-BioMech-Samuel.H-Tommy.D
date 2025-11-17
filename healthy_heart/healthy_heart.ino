void setup() {
  heartrate_sensor_setup();
  buzzer_setup();
  OLED_setup();
}

void loop() {
  heartrate_sensor();
  buzzer();
  OLED();
  delay(100);
}
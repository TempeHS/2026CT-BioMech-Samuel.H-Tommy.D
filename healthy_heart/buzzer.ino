#define VIBRATION_PIN 9     // Pin connected to vibration motor
#define SENSOR_PIN 2        // Example: button or digital sensor

void buzzer_setup() {
  pinMode(VIBRATION_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
}

void buzzer_loop() {
  int sensorState = digitalRead(SENSOR_PIN);

  if (sensorState == HIGH) {
    digitalWrite(VIBRATION_PIN, HIGH); // Turn on vibration
    delay(500);                         // Vibrate for 0.5 seconds
    digitalWrite(VIBRATION_PIN, LOW);  // Turn off
  }

  delay(100); // Small delay to avoid bouncing


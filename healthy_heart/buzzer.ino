const int BUZZER_PIN = 5;
const int THRESHOLD_BPM = 150;

void buzzer_setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void buzzer_loop() {
  int currentHR = heartrate;  // lowercase - MATCHES Tab 1

  if (currentHR > THRESHOLD_BPM) {
    tone(BUZZER_PIN, 1000);
    delay(200);
    noTone(BUZZER_PIN);
    delay(100);
  } else {
    noTone(BUZZER_PIN);
  }

  delay(100);
}
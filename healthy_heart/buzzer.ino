/*
  Purpose: Play a tone on Grove Buzzer
  Hardware: Grove Buzzer on D3 (PWM pin)
  Notes:
    - Use tone() for melodies
    - Connect to D3, D5, D6, D9, D10, or D11 for PWM/tone
*/

const int BUZZER_PIN = 3;  // Grove D3 (PWM)

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.println("Buzzer test ready");
}

void loop() {
  // Play 1kHz tone for 500ms
  tone(BUZZER_PIN, 1000);  // 1000 Hz
  delay(500);

  // Stop tone for 500ms
  noTone(BUZZER_PIN);
  delay(500);
}



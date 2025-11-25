const int BUZZER_PIN = 5;              // Change to your buzzer port (D2-D8)
const int THRESHOLD_BPM = 150;
volatile bool alarmActive = false;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);     // Ensure buzzer starts off
}

void loop() {
    int currentHR = heartRate;         // Read global variable from Tab 1

    if (currentHR > THRESHOLD_BPM && !alarmActive) {
        // Heart rate exceeded threshold - sound buzzer
        activateBuzzer();
        alarmActive = true;
    } 
    else if (currentHR <= THRESHOLD_BPM) {
        // Heart rate back to normal - stop buzzer
        digitalWrite(BUZZER_PIN, LOW);
        alarmActive = false;
    }

    delay(100);
}

void activateBuzzer() {
    // Simple buzzer pattern: 3 short beeps
    for (int i = 0; i < 3; i++) {
        digitalWrite(BUZZER_PIN, HIGH);  // Buzzer on
        delay(200);
        digitalWrite(BUZZER_PIN, LOW);   // Buzzer off
        delay(100);
    }
}
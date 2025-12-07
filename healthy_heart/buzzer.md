<<<<<<< HEAD
=======
-when we try to make cod efor the buzer, it will give us errors and we are trying to get the buzzer and the heartrate sensor to correlate. but this error 'Compilation error: 'heartrate' was not declared in this scope' amd we have tried debugging it and nothing works we are wokring throught this at the moment and is what we are currently aiming for as a goal.
>>>>>>> 95a6d7af3330fd2ff9adf84497fc923e48cabb37
We are getting progress with processes in the buzzer.


const int BUZZER_PIN = 5;
const int THRESHOLD_BPM = 150;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
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
int PULSE_PIN = 2;
volatile unsigned long lastBeatMs = 0;
volatile unsigned int bpm = 0;
volatile bool newBeat = false;

void pulseISR() {
  unsigned long now = millis();
  unsigned long dt = now - lastBeatMs;
  if (lastBeatMs != 0 && dt > 250 && dt < 2000) {
    bpm = 60000 / dt;
    newBeat = true;
  }
  lastBeatMs = now;
}

void setup() {
  Serial.begin(9600);
  pinMode(PULSE_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(PULSE_PIN), pulseISR, RISING);
  Serial.println("Pulse sensor test ready");
}

void loop() {
  if (newBeat) {
    noInterrupts();
    unsigned int currentBpm = bpm;
    newBeat = false;
    interrupts();

    Serial.print("BPM: ");
    Serial.println(currentBpm);
  }
  delay(50);
}
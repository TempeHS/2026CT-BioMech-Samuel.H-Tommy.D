#include <Wire.h>

// CRITICAL: Declare OUTSIDE all functions so Tab 2 can access it
volatile int heartRate = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("heart rate sensor:");
    Wire.begin();
}

void loop() {
    Wire.requestFrom(0xA0 >> 1, 1);
    while (Wire.available()) {
        unsigned char c = Wire.read();
        heartRate = (int)c;  // Update the global variable
        Serial.print("HR: ");
        Serial.println(heartRate, DEC);
    }
    delay(500);
}
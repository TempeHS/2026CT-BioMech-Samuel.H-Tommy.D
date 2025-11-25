#include <Wire.h>

volatile int heartRate = 0;  // Global variable - Tab 2 will read this

void setup() {
    Serial.begin(9600);
    Serial.println("heart rate sensor:");
    Wire.begin();
}

void loop() {
    Wire.requestFrom(0xA0 >> 1, 1);    // request 1 byte from I2C address 0x50
    while (Wire.available()) {         
        unsigned char c = Wire.read();
        heartRate = (int)c;             // Update global heartRate variable
        Serial.print("HR: ");
        Serial.println(heartRate, DEC);
    }
    delay(500);
}
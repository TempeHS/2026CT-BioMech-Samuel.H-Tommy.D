#include <Wire.h>

volatile int heartrate  = 0;  // lowercase

void setup() {
    Serial.begin(9600);
    Serial.println("heartrate");
    Wire.begin();
}

void loop() {
    Wire.requestFrom(0xA0 >> 1, 1);
    while (Wire.available()) {
        unsigned char c = Wire.read();
        heartrate = (int)c;  // lowercase
        Serial.print("HR: ");
        Serial.println(heartrate, DEC);
    }
    delay(500);

}
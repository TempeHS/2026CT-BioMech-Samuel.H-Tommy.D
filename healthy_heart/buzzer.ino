#define BUZZER_PIN 8   // Connect the buzzer module’s signal pin here

void setup() 
  pinMode(BUZZER_PIN, OUTPUT);  // Set buzzer pin as output


void loop() 
  // Example: make buzzer sound when "something happens"
  // Replace this condition with your sensor or trigger logic
  bool trigger = true;  

  if (trigger) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
    delay(500);                      // Keep buzzing for 0.5 seconds
    digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
    delay(500);                      // Pause before next buzz
  }
}




#define BUZZER_PIN 10

void buzzerInit(void) {
  pinMode(BUZZER_PIN, OUTPUT);
}

void buzzerBeep(void) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }
}

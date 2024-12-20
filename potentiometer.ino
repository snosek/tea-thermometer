#define POTENTIOMETER_PIN 0

void potentiometerInit(void) {
  pinMode(POTENTIOMETER_PIN, INPUT);
}

int readPotentiometer(void) {
  return map(analogRead(POTENTIOMETER_PIN), 0, 1023, 0, 99);
}
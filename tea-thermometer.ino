struct Display;

void initAll() {
  sensorInit();
  displayInit();
  potentiometerInit();
  buzzerInit();
}

void setup() {
  Serial.begin(9600);
  initAll();
}

void loop() {
    int temperature = readTemperature();
    int thresholdTemperature = readPotentiometer();
    displayNumber(thresholdTemperature);
    if (temperature > thresholdTemperature) {
        buzzerBeep();
    }
}
#include <DallasTemperature.h>
#include <OneWire.h>

#define TEMP_PIN 12

OneWire oneWire(TEMP_PIN);
DallasTemperature sensor(&oneWire);

void sensorInit() {
  sensor.begin();
}

int readTemperature() {
  sensor.requestTemperatures();
  return (int)sensor.getTempCByIndex(0);
}
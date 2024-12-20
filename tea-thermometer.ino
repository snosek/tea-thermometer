#include <DallasTemperature.h>

#define TEMP_PIN 12

OneWire oneWire(TEMP_PIN);
DallasTemperature sensor(&oneWire);

struct Display {
    int a, b, c, d, e, f, g;
};

struct Display display1 = {8, 6, 16, 18, 17, 7, 9};
struct Display display2 = {3, 5, 21, 19, 20, 4, 2};

void initDisplay(const Display* disp) {
    const int* pins = (const int*)disp;
    for (int i = 0; i < 7; ++i) {
        pinMode(pins[i], OUTPUT);
    }
}

void clearDisplay(const Display* disp) {
    const int* pins = (const int*)disp;
    for (int i = 0; i < 7; ++i) {
        digitalWrite(pins[i], LOW);
    }
}

void writeDigit(const Display* disp, int digit) {
    static const int segments[10][7] = {
        {1, 1, 1, 1, 1, 1, 0}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1, 1}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}  // 9
    };

    const int* pins = (const int*)disp;
    for (int i = 0; i < 7; ++i) {
        digitalWrite(pins[i], segments[digit][i]);
    }
}

void displayNumber(int number) {
    clearDisplay(&display1);
    clearDisplay(&display2);
    writeDigit(&display1, number / 10);
    writeDigit(&display2, number % 10);
}

void setup() {
    Serial.begin(9600);
    sensor.begin();
    initDisplay(&display1);
    initDisplay(&display2);
}

void loop() {
    sensor.requestTemperatures();
    int temperature = (int)sensor.getTempCByIndex(0);
    displayNumber(temperature);
    delay(500);
}

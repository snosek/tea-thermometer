struct Display {
    int a, b, c, d, e, f, g;
};

Display display1 = {8, 6, 16, 18, 17, 7, 9};
Display display2 = {3, 5, 21, 19, 20, 4, 2};

void initDisplayPins(const Display* disp) {
    const int* pins = (const int*)disp;
    for (int i = 0; i < 7; ++i) {
        pinMode(pins[i], OUTPUT);
    }
}

void displayInit() {
    initDisplayPins(&display1);
    initDisplayPins(&display2);
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

#include "buttons.h"

Button buttons[] = {
    {1, BTN_1_PIN, 0, 0, false},  // Pins defined in config.h
    {2, BTN_2_PIN, 0, 0, false},
    {3, BTN_3_PIN, 0, 0, false}};

void initButtons() {
    for (Button &btn : buttons) {
        pinMode(btn.pin, INPUT_PULLUP);
    }
}

// Check individual button
ClickType checkButton(Button &btn) {
    unsigned long now = millis();

    if (now - btn.lastDebounceTime > BTN_DEBOUNCE_DELAY) {
        int btnState = digitalRead(btn.pin);

        if (btnState == LOW) {
            if (btn.startTime == 0) {
                btn.startTime = now;
            } else {
                if (now - btn.startTime > BTN_LONG_PRESS_DURATION && !btn.held) {
                    // Serial.printf("Long press on pin %d\n", btn.pin);
                    btn.held = true;
                    return LONG_CLICK;
                }
            }
        } else if (btn.startTime != 0) {
            btn.startTime = 0;
            btn.lastDebounceTime = now;
            if (!btn.held) {
                // Serial.printf("Short press on pin %d\n", btn.pin);
                return SHORT_CLICK;
            } else {
                btn.held = false;
            }
        }
    }
    return NONE;
}

// void handleButtons() {
//     for (Button &btn : buttons) {
//         checkButton(btn);
//     }
// }
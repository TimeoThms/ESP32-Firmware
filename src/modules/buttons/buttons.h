#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

#include "../../configs/config.h"

enum ClickType {
    NONE,
    SHORT_CLICK,
    LONG_CLICK
};

struct Button {
    int id;
    int pin;
    unsigned long startTime;
    unsigned long lastDebounceTime;
    bool held;
};

extern Button buttons[3];

void initButtons();
ClickType checkButton(Button &btn);
// void handleButtons();

#endif  // BUTTONS_H
#include <Arduino.h>

#include "configs/config.h"
#include "modules/buttons/buttons.h"
#include "utils/wifi/wifi.h"

void setup() {
    Serial.begin(115200);

    pinMode(21, OUTPUT);
    initButtons();
    initWiFi();
}

void loop() {
    for (Button &btn : buttons) {
        ClickType clickType = checkButton(btn);
        if (clickType == SHORT_CLICK) {
            Serial.printf("Short click on %d\n", btn.id);
        } else if (clickType == LONG_CLICK) {
            Serial.printf("Long click on %d\n", btn.id);

            if (btn.id == 3) {
                Serial.println(getLocalIpAdress());
            }
        }
    }
}
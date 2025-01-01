#include <Arduino.h>

#include "configs/config.h"
#include "modules/buttons/buttons.h"
#include "modules/dht22/dht22.h"
#include "utils/wifi/wifi.h"

void setup() {
    Serial.begin(115200);

    pinMode(21, OUTPUT);
    initButtons();
    initWiFi();
    initDHT22();
}

void loop() {
    // Buttons
    for (Button &btn : buttons) {
        ClickType clickType = checkButton(btn);
        if (clickType == SHORT_CLICK) {
            Serial.printf("Short click on %d\n", btn.id);

            if (btn.id == 1) {
                Serial.printf("Humidity: %.2f%%\n", readHumidity());
                Serial.printf("Temperature: %.2f°C\n", readTemperature());
            }

        } else if (clickType == LONG_CLICK) {
            Serial.printf("Long click on %d\n", btn.id);
        }
    }
}
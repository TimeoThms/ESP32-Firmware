#include <Arduino.h>
#include <BH1750.h>
#include <Wire.h>

#include "configs/config.h"
#include "modules/bh1750/bh1750.h"
#include "modules/buttons/buttons.h"
#include "modules/dht22/dht22.h"
#include "modules/ds3231/ds3231.h"
#include "utils/wifi/wifi.h"

void setup() {
    Serial.begin(115200);

    pinMode(21, OUTPUT);
    initButtons();
    initWiFi();

    Wire.begin(I2C_SDA, I2C_SCL);

    initDS3231();
    initDHT22();
    initBH1750();
}

void loop() {
    // Buttons
    for (Button &btn : buttons) {
        ClickType clickType = checkButton(btn);
        if (clickType == SHORT_CLICK) {
            Serial.printf("Short click on %d\n", btn.id);

            if (btn.id == 1) {
                Serial.printf("Humidity: %.1f%%\n", readHumidity());
                Serial.printf("Temperature: %.1f°C\n", readTemperature());
                Serial.printf("Light Level: %.2f LUX\n", readLightLevel());

                Serial.printf("Current Time: %02d/%02d/%04d %02d:%02d:%02d\n",
                              getTimeFromDS3231().day(), getTimeFromDS3231().month(), getTimeFromDS3231().year(),
                              getTimeFromDS3231().hour(), getTimeFromDS3231().minute(), getTimeFromDS3231().second());
            }

        } else if (clickType == LONG_CLICK) {
            Serial.printf("Long click on %d\n", btn.id);
        }
    }
}
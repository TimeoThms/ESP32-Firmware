#include <Arduino.h>
#include <FastLed.h>
#include <Wire.h>

#include <vector>

#include "apps/app.h"
#include "apps/humidity/humidity.h"
#include "apps/time/time.h"
#include "apps/temperature/temperature.h"
#include "configs/config.h"
#include "graphics/screen/screen.h"
#include "graphics/utils/graphics_utils.h"
#include "modules/bh1750/bh1750.h"
#include "modules/buttons/buttons.h"
#include "modules/dht22/dht22.h"
#include "modules/ds3231/ds3231.h"
#include "modules/ws2812b/ws2812b.h"
#include "utils/i2s/i2s.h"
#include "utils/wifi/wifi.h"

std::vector<std::vector<CRGB>> exampleBitmap = {
    {CRGB::Red, CRGB::Green, CRGB::Blue},
    {CRGB::Yellow, CRGB::Magenta, CRGB::Cyan},
    {CRGB::White, CRGB::Black, CRGB::Gray},
    {CRGB::Pink, CRGB::Aqua, CRGB::Orange}};

std::vector<std::vector<CRGB>> exampleBitmap2 = {
    {CRGB::Green, CRGB::GreenYellow, CRGB::Purple},
    {CRGB::Olive, CRGB::Magenta, CRGB::Aqua}};

std::vector<App*> apps;
size_t activeIndex;

unsigned long previousMillis = 0;
int framerate = 10;

void setup() {
    Serial.begin(115200);

    pinMode(21, OUTPUT);
    initButtons();
    initWiFi();

    Wire.begin(I2C_SDA, I2C_SCL);
    initI2S();

    initDS3231();
    initDHT22();
    initBH1750();
    initWS2812B();

    setBrightness(5);

    // Apps
    apps.push_back(new TimeApp());
    apps.push_back(new TemperatureApp());
    apps.push_back(new HumidityApp());

    activeIndex = 0;
    apps[activeIndex]->setup();
}

void loop() {
    unsigned long currentMillis = millis();

    // Buttons
    for (Button& btn : buttons) {
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
                // } else if (btn.id == 2) {
                //     std::vector<std::vector<CRGB>> finalBitmap = joinColoredBitmaps(exampleBitmap, exampleBitmap2, exampleBitmap[0].size() + 1, 2);
                //     screen.place(1, 0, finalBitmap);
                //     screen.place(10, 1, textToBitmap("HELLO", CRGB::Green));
                //     screen.updateScreen();
                // }

            } else if (clickType == LONG_CLICK) {
                Serial.printf("Long click on %d\n", btn.id);
            } else if (btn.id == 3) {
                activeIndex = (activeIndex + 1) % apps.size();
                apps[activeIndex]->setup();
            }
        }

        if (checkSound()) {
            digitalWrite(21, !digitalRead(21));
            Serial.println("Sound detected");
        }
        if (currentMillis - previousMillis >= framerate * 10) {
            previousMillis = currentMillis;

            // Serial.println("Tick");
            if (apps[activeIndex]) {
                apps[activeIndex]->tick();
                apps[activeIndex]->getScreen().updateScreen();
            }
        }
    }
}
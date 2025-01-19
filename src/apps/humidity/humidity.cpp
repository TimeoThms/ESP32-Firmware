#include "../../modules/dht22/dht22.h"
#include "humidity.h"

float lastAppHumidity;

void HumidityApp::tick() {
    float humidity = readHumidity();

    if (humidity != lastAppHumidity) {
        lastAppHumidity = humidity;

        char humidityString[10];
        snprintf(humidityString, sizeof(humidityString), "%.1f%%", humidity);

        screen.place(0, 0, icon);
        screen.place(9, 1, textToBitmap(humidityString, CRGB::White));
    }
}

void HumidityApp::handleButtonPressed(int button, ClickType clickType) {
    if (button == 2) {
        if (clickType == LONG_CLICK) {
            // activeApp = new HomeApp();
            // activeApp->setup();
            Serial.println("Switch to home app");
        }
    }
}

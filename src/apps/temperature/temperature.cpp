#include "temperature.h"

#include "../../modules/dht22/dht22.h"

void TemperatureApp::tick() {
    float temperature = readTemperature();
    float humidity = readHumidity();

    char tempString[10];
    snprintf(tempString, sizeof(tempString), "%.1f°C", temperature);

    screen.place(0, 0, icon);
    screen.place(9, 1, textToBitmap(tempString, CRGB::White));
}

// Implémentation de la méthode handleButtonPressed()
void TemperatureApp::handleButtonPressed(int button, ClickType clickType) {
    if (button == 2) {
        if (clickType == LONG_CLICK) {
            // activeApp = new HomeApp();
            // activeApp->setup();
            Serial.println("Switch to home app");
        }
    }
}

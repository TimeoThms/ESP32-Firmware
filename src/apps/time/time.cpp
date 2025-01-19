#include "time.h"

#include "../../modules/ds3231/ds3231.h"

DateTime cachedTime;
unsigned long lastUpdateMillis = 0;
unsigned long lastSyncMillis = 0;
const unsigned long syncInterval = 300000; // 5 minutes

void TimeApp::setup() {
    cachedTime = getTimeFromDS3231();
    lastSyncMillis = millis();
}

void TimeApp::tick() {
    unsigned long currentMillis = millis();

    if (currentMillis - lastUpdateMillis >= 100) {
        lastUpdateMillis = currentMillis;

        DateTime currentTime = cachedTime + TimeSpan((currentMillis-lastSyncMillis)/1000);

        screen.place(2, 1, joinColoredBitmaps(textToBitmap((currentTime.hour() < 10 ? " " : "") + std::to_string(currentTime.hour()), CRGB::White), joinColoredBitmaps(textToBitmap(":", CRGB(100, 100, 100)), joinColoredBitmaps(textToBitmap((currentTime.minute() < 10 ? "0" : "") + std::to_string(currentTime.minute()), CRGB::White), joinColoredBitmaps(textToBitmap(":", CRGB(100, 100, 100)), textToBitmap((currentTime.second() < 10 ? "0" : "") + std::to_string(currentTime.second()), CRGB::White), 2, 0), 8, 0), 2, 0), 8, 0));
    }

    if (currentMillis - lastSyncMillis >= syncInterval) {
        cachedTime = getTimeFromDS3231();
        lastSyncMillis = currentMillis;
    }
}

void TimeApp::handleButtonPressed(int button, ClickType clickType) {
    if (button == 2) {
        if (clickType == LONG_CLICK) {
            Serial.println("Switch to home app");
        }
    }
}

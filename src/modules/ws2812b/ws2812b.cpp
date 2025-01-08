#include "ws2812b.h"

CRGB leds[NUM_LEDS];

void initWS2812B() {
    FastLED.addLeds<LED_TYPE, LEDS_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 4000);
    FastLED.clear();
    FastLED.show();
}

int getCoordsIndex(int x, int y) {
    return x*8 + ((x%2) ? 7-y : y);
}

void setPixel(int x, int y, CRGB color) {
    int index = getCoordsIndex(x, y);
    leds[index] = color;
}

void setBrightness(int brightness) {
    FastLED.setBrightness(brightness);
}
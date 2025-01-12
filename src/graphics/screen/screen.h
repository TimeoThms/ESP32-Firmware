#ifndef SCREEN_H
#define SCREEN_H

#include <FastLED.h>

#include <vector>

#include "../../modules/ws2812b/ws2812b.h"

class Screen {
   public:
    CRGB pixels[32][8];

    Screen();

    void placePixel(int x, int y, CRGB color);

    void place(int x, int y, const std::vector<std::vector<CRGB>>& bitmap);

    void updateScreen();
};

extern Screen screen;

#endif  // SCREEN_H
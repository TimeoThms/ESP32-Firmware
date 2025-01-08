#include "screen.h"

Screen screen;

Screen::Screen() {
    // Initialisation des pixels à une couleur noire (éteints)
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 8; j++) {
            pixels[i][j] = CRGB::Black;  // Initialisation avec un pixel éteint
        }
    }
}

void Screen::placePixel(int x, int y, CRGB color) {
    pixels[x][y] = color;
}

void Screen::place(int x, int y, std::vector<std::vector<CRGB>>& bitmap) {
    for (int i = 0; i < bitmap.size(); i++) {
        for (int j = 0; j < bitmap[0].size(); j++) {
            if (x + j < 32 && y + i < 8) {
                pixels[x + j][y + i] = bitmap[i][j]; 
            }
        }
    }
}

void Screen::updateScreen() {
    for (int x = 0; x < 32; x++) {
        for (int y = 0; y < 8; y++) {
            if (pixels[x][y] != leds[getCoordsIndex(x, y)]) {
                setPixel(x, y, pixels[x][y]);
            }
        }
    }
    FastLED.show();
}
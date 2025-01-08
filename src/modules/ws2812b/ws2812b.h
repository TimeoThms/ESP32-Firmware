#ifndef WS2812B_H
#define WS2812B_H

#include <Arduino.h>
#include <FastLED.h>

#include "../../configs/config.h"

#define NUM_LEDS 256      // Nombre total de LEDs
#define LED_TYPE WS2812B  // Type de LED
#define COLOR_ORDER GRB

extern CRGB leds[NUM_LEDS];
void initWS2812B();
void setPixel(int x, int y, CRGB color);
void setBrightness(int brightness);
int getCoordsIndex(int x, int y);

#endif  // WS2812B_H
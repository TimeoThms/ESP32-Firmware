#ifndef GRAPHICS_UTILS_H
#define GRAPHICS_UTILS_H

#include <Arduino.h>
#include <FastLED.h>

#include <vector>

std::vector<std::vector<CRGB>> joinColoredBitmaps(std::vector<std::vector<CRGB>> colorBitmap1, std::vector<std::vector<CRGB>> colorBitmap2,
                                                  int xOffset, int yOffset);
std::vector<std::vector<CRGB>> colorBitmap(std::vector<std::vector<bool>> bitmap, CRGB color);
std::vector<std::vector<CRGB>> textToBitmap(const std::string text, CRGB color);

#endif  // GRAPHICS_UTILS_H
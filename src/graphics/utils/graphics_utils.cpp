#include "graphics_utils.h"

#include <Arduino.h>

#include "../../configs/chars.h"

std::vector<std::vector<CRGB>> joinColoredBitmaps(std::vector<std::vector<CRGB>> colorBitmap1, std::vector<std::vector<CRGB>> colorBitmap2, int xOffset, int yOffset) {
    int height1 = colorBitmap1.size();
    int width1 = colorBitmap1[0].size();

    int height2 = colorBitmap2.size();
    int width2 = colorBitmap2[0].size();

    int resultHeight = std::max(height1, yOffset + height2);
    int resultWidth = std::max(width1, xOffset + width2);

    // Init empty colored bitmap
    std::vector<std::vector<CRGB>> result(resultHeight, std::vector<CRGB>(resultWidth, CRGB::Black));

    // Copy colorBitmap1
    for (int i = 0; i < height1; ++i) {
        for (int j = 0; j < width1; ++j) {
            result[i][j] = colorBitmap1[i][j];
        }
    }

    // Copy colorBitmap2
    for (int i = 0; i < height2; ++i) {
        for (int j = 0; j < width2; ++j) {
            int resultY = yOffset + i;
            int resultX = xOffset + j;

            if (resultY < resultHeight && resultX < resultWidth) {
                result[resultY][resultX] = colorBitmap2[i][j];
            }
        }
    }

    return result;
}

std::vector<std::vector<CRGB>> colorBitmap(std::vector<std::vector<bool>> bitmap, CRGB color) {
    int height = bitmap.size();
    int width = bitmap[0].size();
    std::vector<std::vector<CRGB>> result(height, std::vector<CRGB>(width, CRGB::Black));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (bitmap[i][j] == 1) {
                result[i][j] = color;
            }
        }
    }
    return result;
}

std::vector<std::vector<CRGB>> textToBitmap(const std::string text, CRGB color) {
    std::vector<std::vector<CRGB>> textColorBitmap;
    for (size_t i = 0; i < text.size(); ++i) {
        char currentChar = text[i];
        std::vector<std::vector<CRGB>> charColorBitmap;

        // Get char bitmap
        if (font.find(currentChar) != font.end()) {
            const std::vector<int>& charPixels = font.at(currentChar);

            std::vector<std::vector<bool>> charBitmap;
            int width = charPixels.size() / 5;

            for (int row = 0; row < 5; row++) {
                std::vector<bool> pixelRow;
                for (int col = 0; col < width; ++col) {
                    pixelRow.push_back(charPixels[row * width + col] == 1);
                }
                charBitmap.push_back(pixelRow);
            }
            charColorBitmap = colorBitmap(charBitmap, color);
        }
        if (textColorBitmap.empty()) {
            textColorBitmap = charColorBitmap;
        } else {
            textColorBitmap = joinColoredBitmaps(textColorBitmap, charColorBitmap, textColorBitmap[0].size() + 1, 0);
        }
    }
    return textColorBitmap;
}

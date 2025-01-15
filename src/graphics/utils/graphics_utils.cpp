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

bool isMultibyteChar(unsigned char byte) {
    return byte >= 0x80;
}

std::vector<std::vector<CRGB>> textToBitmap(const std::string text, CRGB color) {
    std::vector<std::vector<CRGB>> textColorBitmap;
    size_t i = 0;
    while (i < text.size()) {
        std::string currentCharStr;

        // Vérifier si le caractère est un caractère multioctet
        if (isMultibyteChar(text[i])) {
            // Si c'est un caractère UTF-8 multioctet, prendre les 2 octets
            currentCharStr.push_back(text[i]);
            currentCharStr.push_back(text[i + 1]);
            i += 2;  // Passer les 2 octets
        } else {
            // Si c'est un caractère simple, prendre un seul octet
            currentCharStr.push_back(text[i]);
            i += 1;
        }

        // Afficher le caractère actuel et son code hexadécimal
        Serial.print("Caractère actuel: ");
        Serial.print(currentCharStr.c_str());
        Serial.print(" (Code Unicode: ");
        for (char ch : currentCharStr) {
            Serial.print((int)(unsigned char)ch, HEX);
            Serial.print(" ");
        }
        Serial.println(")");

        std::vector<std::vector<CRGB>> charColorBitmap;

        // Get char bitmap
        if (font.find(currentCharStr) != font.end()) {
            const std::vector<int>& charPixels = font.at(currentCharStr);

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

            if (textColorBitmap.empty()) {
                textColorBitmap = charColorBitmap;
            } else {
                textColorBitmap = joinColoredBitmaps(textColorBitmap, charColorBitmap, textColorBitmap[0].size() + 1, 0);
            }
        } else {
            Serial.printf("Char not found in font:%s\n", currentCharStr.c_str());
        }
    }
    return textColorBitmap;
}

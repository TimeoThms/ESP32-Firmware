#include "bh1750.h"

BH1750 lightMeter;

void initBH1750() {
    if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
        Serial.println("Unable to initialize BH1750!");
    }
}

float readLightLevel() {
    float lux = lightMeter.readLightLevel();
    if (lux < 0) {
        Serial.println("Unable to read light level!");
        return -1.0;
    }
    return lux;
}
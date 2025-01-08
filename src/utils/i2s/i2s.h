#ifndef I2S_H
#define I2S_H

#include <Arduino.h>

#include "driver/i2s.h"

extern int16_t mic_buffer[];
extern int16_t audio_buffer[];

void initI2S();
bool checkSound();

#endif  // I2S_H
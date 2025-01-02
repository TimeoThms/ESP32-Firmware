#ifndef BH1750_H
#define BH1750_H

#include <Arduino.h>
#include <BH1750.h>

#include "../../configs/config.h"

extern BH1750 lightMeter;

void initBH1750();
float readLightLevel();

#endif  // BH1750_H
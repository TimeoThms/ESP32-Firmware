#ifndef DHT22_H
#define DHT22_H

#include <Arduino.h>
#include <DHT.h>

#include "../../configs/config.h"

extern DHT dht;

void initDHT22();
float readHumidity();
float readTemperature();

#endif  // DHT22_H
#include "dht22.h"

DHT dht(DHT_PIN, DHT22);
unsigned long lastMeasureTime;
float lastHumidity;
float lastTemperature;

void initDHT22() {
    dht.begin();
}

static void updateMeasurements() {
    unsigned long now = millis();
    if (now - lastMeasureTime >= 2000) {
        lastHumidity = dht.readHumidity();
        lastTemperature = dht.readTemperature();
        lastMeasureTime = now;
    }
}

float readHumidity() {
    updateMeasurements();
    return lastHumidity;
}

float readTemperature() {
    updateMeasurements();
    return lastTemperature;
}
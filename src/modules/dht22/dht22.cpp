#include "dht22.h"

DHT dht(DHT_PIN, DHT22);
unsigned long lastMeasureTime;
float lastHumidity;
float lastTemperature;

static void updateMeasurements() {
    unsigned long now = millis();
    if (now - lastMeasureTime >= 10000) {  // One measurement every 10 seconds
        lastHumidity = dht.readHumidity();
        lastTemperature = dht.readTemperature();
        lastMeasureTime = now;
    }
}

void initDHT22() {
    dht.begin();
    updateMeasurements();
}

float readHumidity() {
    updateMeasurements();
    return lastHumidity;
}

float readTemperature() {
    updateMeasurements();
    return lastTemperature;
}
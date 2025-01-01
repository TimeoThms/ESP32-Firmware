// Global configuration

#ifndef CONFIG_H
#define CONFIG_H

#include "credentials.h"

// WiFi Credentials
#ifndef CREDENTIALS_H
#error "Please define WIFI credentials in credentials.h file. Check README.md for more informations."
#endif

// Buttons settings
#define BTN_1_PIN 5
#define BTN_2_PIN 4
#define BTN_3_PIN 6
#define BTN_DEBOUNCE_DELAY 200
#define BTN_LONG_PRESS_DURATION 1000

// MODULES
// DHT22
#define DHT_PIN 38

#endif  // CONFIG_H
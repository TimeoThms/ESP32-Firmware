// Global configuration

#ifndef CONFIG_H
#define CONFIG_H

#include "credentials.h"

// WiFi Credentials
#ifndef CREDENTIALS_H
#error "Please define WIFI credentials in credentials.h file. Check README.md for more informations."
#endif

// Bluetooth
#define DEVICE_NAME "ESP32"

// Buttons settings
#define BTN_1_PIN 5
#define BTN_2_PIN 4
#define BTN_3_PIN 6
#define BTN_DEBOUNCE_DELAY 200
#define BTN_LONG_PRESS_DURATION 1000

// I2C Pins
#define I2C_SCL 2
#define I2C_SDA 1

// I2S Config
#define I2S_SCK_PIN 15
#define I2S_WS_PIN 16
#define I2S_MIC_SD_PIN 47
#define I2S_SPK_DIN_PIN 48

// DHT22
#define DHT_PIN 38

// WS2812B
#define LEDS_PIN 18

// --- Timezone Configuration ---
// TIMEZONE: character string abbreviation for the time zone; it must be no longer than five character
// WEEK: the week of the month that the time change rule starts (First, Second, Third, Fourth, Last)
// DOW: the day of the week that the rules starts (Sun, Mon, Tue, Wed, Thu, Fri, Sat)
// MONTH: the month of the year that the rules starts (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec)
// HOUR: the hour in local time that the rule starts (0-23)
// OFFSET: the UTC offset in minutes for the time zone being defined

// Values for Central European (Summer) Time (CET/CEST)
// Standard Timezone (Winter Time)
#define STANDARD_TIMEZONE "CET"
#define STANDARD_TIME_RULE_WEEK Last
#define STANDARD_TIME_RULE_DOW Sun
#define STANDARD_TIME_RULE_MONTH Oct
#define STANDARD_TIME_RULE_HOUR 2
#define STANDARD_TIME_OFFSET 60

// Daylight Saving Timezone (Summer Time)
#define SUMMER_TIMEZONE "CEST"
#define SUMMER_TIME_RULE_WEEK Last
#define SUMMER_TIME_RULE_DOW Sun
#define SUMMER_TIME_RULE_MONTH Mar
#define SUMMER_TIME_RULE_HOUR 2
#define SUMMER_TIME_OFFSET 120

#endif  // CONFIG_H
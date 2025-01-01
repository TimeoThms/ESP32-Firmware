# ESP32 Firmware Project

## Overview
This is a firmware project for the ESP32 microcontroller. This firmware is designed to manage various modules such as sensors, LEDs, etc. The projects includes mutliple apps, enabling different functionnalities such as clock, alarm, temperature measurement, speaker, etc.

## Parts list
*All parts were bought from Aliexpress*
- **Microcontroller:** ESP32-S3-DevKitC-1
- **LED Matrix:** 32x8 WS2812B LED Matrix
- **Temperature and Humidity Sensor:** DHT22
- **Light Sensor:** BH1750
- **RTC Module:** DS3132
- **Audio Amplifier:** : MAX98357A
- **Speaker:** 4Ω 3W Speaker from Aliexpress 
- **Microphone:** INMP441

## Installation

### X. Configure WiFi Credentials
Create a `credentials.h` in `src/configs` and fill it like this:
```h
// WiFi Credentials
#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#define WIFI_SSID "Your_SSID"
#define WIFI_PASSWORD "Your_Password"

#endif  // CREDENTIALS_H``
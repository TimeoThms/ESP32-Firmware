#ifndef DS3231_H
#define DS3231_H

#include <Arduino.h>
#include <RTClib.h>

#include "../../configs/config.h"

extern RTC_DS3231 rtc;

void initDS3231();
DateTime getTimeFromDS3231();

#endif  // DS3231_H
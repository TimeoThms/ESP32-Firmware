#include "ds3231.h"

#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <Timezone.h>

RTC_DS3231 rtc;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

TimeChangeRule standard_TCR = {STANDARD_TIMEZONE, STANDARD_TIME_RULE_WEEK, STANDARD_TIME_RULE_DOW, STANDARD_TIME_RULE_MONTH, STANDARD_TIME_RULE_HOUR, STANDARD_TIME_OFFSET};
TimeChangeRule summer_TCR = {SUMMER_TIMEZONE, SUMMER_TIME_RULE_WEEK, SUMMER_TIME_RULE_DOW, SUMMER_TIME_RULE_MONTH, SUMMER_TIME_RULE_HOUR, SUMMER_TIME_OFFSET};
Timezone tz(standard_TCR, summer_TCR);

void initDS3231() {
    if (!rtc.begin()) {
        Serial.println("Unable to initialize DS3231");
    } else {
        timeClient.begin();

        if (timeClient.update()) {
            unsigned long epochTime = timeClient.getEpochTime();
            struct tm *ptm = gmtime((time_t *)&epochTime);

            rtc.adjust(DateTime(ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
                                ptm->tm_hour, ptm->tm_min, ptm->tm_sec));
        } else {
            Serial.println("Failed to get NTP time");
        }
    }
}

DateTime getTimeFromDS3231() {
    DateTime now = rtc.now();
    time_t utcTime = now.unixtime();
    time_t localTime = tz.toLocal(utcTime);
    struct tm *ptm = localtime(&localTime);
    return DateTime(ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
                    ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
}
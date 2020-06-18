#include <Arduino.h>
#include <stdint.h>
#include "battery.h"
#include "bluetooth.h"
#include "config.h"

uint8_t counter = 0;
uint8_t raw = 0;
uint8_t percent = 0;

uint8_t mvToPercent(float mvolts) {
    uint8_t battery_level;

    // Adding a constant since the full charge on lipo is 4.2V
    mvolts = mvolts - 900;

    if (mvolts >= 3000)
    {
        battery_level = 100;
    }
    else if (mvolts > 2900)
    {
        battery_level = 100 - ((3000 - mvolts) * 58) / 100;
    }
    else if (mvolts > 2740)
    {
        battery_level = 42 - ((2900 - mvolts) * 24) / 160;
    }
    else if (mvolts > 2440)
    {
        battery_level = 18 - ((2740 - mvolts) * 12) / 300;
    }
    else if (mvolts > 2100)
    {
        battery_level = 6 - ((2440 - mvolts) * 6) / 340;
    }
    else
    {
        battery_level = 0;
    }

    return battery_level;
}

void battery_tick() {
    if (counter >= BATTERY_UPDATE_TICKS) {
        counter = 0;
    } else {
        counter++;
    }
}

void battery_task() {
    if(counter == 0) {
        raw = analogRead(VBAT_PIN);
        percent = mvToPercent(raw);

        update_battery(percent);

        counter++;
    }
}

uint8_t battery_get_percentage() {
    return percent;
}

void battery_init() {
    // Set the analog reference to 3.0V (default = 3.6V)
    analogReference(AR_INTERNAL_3_0);

    // Set the resolution to 12-bit (0..4095)
    analogReadResolution(12); // Can be 8, 10, 12 or 14

    // pinMode is already set by the framework
}

#ifndef CONFIG_H
    #define CONFIG_H
    #include <Arduino.h>
    #include <stdint.h>
    #include <stdbool.h>

    #define ADVERTISE_NAME    "Wireless Button Box"
    #define MANUFACTURER_NAME "Century Synthetics"
    #define MODEL_NAME        "Wireless Button Box"

    #define BUTTON_1 27
    #define BUTTON_2 28
    #define BUTTON_3 29
    #define BUTTON_4 30
    #define BUTTON_5 2
    #define BUTTON_6 3
    #define BUTTON_7 4
    #define BUTTON_8 5
    #define BUTTON_9 7
    #define BUTTON_10 11
    #define BUTTON_11 12
    #define BUTTON_12 13
    #define BUTTON_13 14
    #define BUTTON_14 15
    #define BUTTON_15 16
    #define BUTTON_16 18
    #define TOTAL_BUTTONS 16

    #define CONNECTED_INDICATOR_LED_PIN 17

    #define DEBOUNCE 16 // 16ms around 60Hz  

    #define BATTERY_UPDATE_TICKS 1800 // Debounces/second * 30 - around every 30 seconds 

    #define _delay_us(us) delayMicroseconds(us)
    #define _delay_ms(ms) delay(ms)
    #define _delay(ms) delay(ms)
#endif

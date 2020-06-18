#include <Arduino.h>
#include <bluefruit.h>
#include <stdbool.h>
#include "config.h"
#include "bluetooth.h"
#include "battery.h"
#include "indicators.h"

uint8_t buttons[TOTAL_BUTTONS] = {BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4, BUTTON_5, BUTTON_6, BUTTON_7, BUTTON_8, BUTTON_9, BUTTON_10, BUTTON_11, BUTTON_12, BUTTON_13, BUTTON_14, BUTTON_15, BUTTON_16};
uint8_t button_index =0;
uint16_t current_button_state = 0;
uint16_t previous_button_state = 0;

void setup(void) {
  Bluefruit.autoConnLed(false);
   
  bluetooth_init();
  battery_init();
  indicators_init();
  start_advertising();

  for (button_index=0; button_index < TOTAL_BUTTONS; button_index++) {
   pinMode(buttons[button_index], INPUT_PULLUP); 
  }

  Serial.end();
  disableI2CPins();
  sd_power_mode_set(NRF_POWER_MODE_LOWPWR);
  sd_power_dcdc_mode_set(NRF_POWER_DCDC_ENABLE);
}

void loop() {
  connected_led_task();
  battery_task();

  for (button_index=0; button_index < TOTAL_BUTTONS; button_index++) {
   current_button_state = current_button_state | (digitalRead(buttons[button_index]) == LOW) << button_index; 
  }

  if (current_button_state != previous_button_state) {
    sendButtonState(current_button_state);
  }

  previous_button_state = current_button_state;

  current_button_state = 0;

  battery_tick();
  _delay(DEBOUNCE);

  sd_power_mode_set(NRF_POWER_MODE_LOWPWR);
  waitForEvent();
}

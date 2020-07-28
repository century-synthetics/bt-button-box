#include <Arduino.h>
#include <bluefruit.h>

#include "config.h"
#include "bluetooth.h"

// Note this application uses a custom version of BLEHidAdafruit to support gamepad HID.
// Please see install instructions in the Readme 
BLEHidAdafruit blehid;
BLEDis bledis;

bool is_bluetooth_connected() {
  return Bluefruit.connected();
}

void sendButtonState(uint16_t button_state){
  blehid.gamepadButtonPress(button_state);
}

void bluetooth_init() {
  Bluefruit.begin();
  Bluefruit.setName(ADVERTISE_NAME);
  Bluefruit.setTxPower(4);
  Bluefruit.autoConnLed(false);

  bledis.setManufacturer(MANUFACTURER_NAME);
  bledis.setModel(MODEL_NAME);
  bledis.begin();
  blehid.begin();

  BLECharacteristic pnp_id = BLECharacteristic(UUID16_CHR_PNP_ID);
  pnp_id.setProperties(CHR_PROPS_READ);
  pnp_id.setFixedLen(7);
  pnp_id.begin();
  uint8_t pnp_id_data[7] = {0x02, 0x11, 0x23, 0xfe, 0xca, 0x01, 0x00};
  pnp_id.write(pnp_id_data, 7);
}

void start_advertising() {
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_GAMEPAD);
  Bluefruit.Advertising.addService(blehid);

  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode

  Bluefruit.Advertising.addName();

  Bluefruit.ScanResponse.addName();

  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising
}

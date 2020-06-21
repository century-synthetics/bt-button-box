/**
 * Bluetooth driver from
 * https://github.com/afriggeri/kb
 */
#ifndef BLUETOOTH_H
    #define BLUETOOTH_H

    void bluetooth_init();
    bool is_bluetooth_connected();
    void sendButtonState(uint16_t button_state);
    void start_advertising();
#endif

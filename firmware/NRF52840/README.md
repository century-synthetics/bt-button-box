# Firmware for the Adafruit Feather nRF52840 Express

You will need:

* Arduino IDE v1.8+
* The contents of the firmware directory
* An Adafruit Feather nRF52840 Express dev board

Go into the Arduino IDE Preferences and add `https://www.adafruit.com/package_adafruit_index.json` as an 'Additional Board Manager URL'

Restart the Arduino IDE

Open the Boards Manager option from the Tools -> Board menu and install 'Adafruit nRF52 by Adafruit' using **version 0.20.5**

This will install the Board Support Package (BSP) to your computer and may take a few minutes.

Once completed, find the installed package (C:\Users\Your User\AppData\Local\Arduino15\packages\adafruit\hardware\nrf52\0.20.5\libraries) and *replace* the Bluefruit52Lib library file with the zipped version from the firmware directory in this project. This will add a gamepad API to the BSP.

Load the sketch from the 52840/button-box firmware directory.

Change your board settings to use Adafruit Feather nRF52840 Express, plug in the device and choose the correct  port.

Upload the sketch to your board using the upload button.

## Electrical Layout

By default the configuration will set the board up to use active low button presses (you ground an input to activate the button). There is no need for pullup resistors as that is done internally.

The default pinout looks like this:

|Input button | Board Terminal |
|-------------|----------------|
|BUTTON_1     | 9              |
|BUTTON_2     | 6              |
|BUTTON_3     | 10             |
|BUTTON_4     | SCK            |
|BUTTON_5     | MO             |
|BUTTON_6     | A3             |
|BUTTON_7     | A5             |
|BUTTON_8     | 5              |
|BUTTON_9     | SCL            |
|BUTTON_10    | 11             |
|BUTTON_11    | 12             |
|BUTTON_12    | 13             |
|BUTTON_13    | A0             |
|BUTTON_14    | A1             |
|BUTTON_15    | A2             |
|BUTTON_16    | A4             |

## Example Circuit

```text
GND o-----o ┴ o------o Pin 9
       Switch (N/O)
```

## Advanced/Power Savings

It's best to use about a 500mAh LiPo cell with this device and code. The battery will last about 5 days on a charge for the latest revisions.

## Latency

The measured latency between button press and game reaction is approximately 30ms average.

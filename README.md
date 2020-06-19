# Bluetooth Button Box

A Bluetooth low energy wireless button box circuit for use with sim racing. It is based on the the Adafruit Feather nRF52 Bluefruit development board. It can be embedded into existing wheels and appears as a standalone gamepad on most desktop computers.

## Usage

The easiest way to use this software is with an Adafruit Feather nRF52 Bluefruit.

You will need:

* Arduino IDE v1.8+
* The contents of the firmware directory
* A feather development board or compatible

Go into the Arduino IDE Preferences and add `https://www.adafruit.com/package_adafruit_index.json` as an 'Additional Board Manager URL'

Restart the Arduino IDE

Open the Boards Manager option from the Tools -> Board menu and install 'Adafruit nRF52 by Adafruit' using **version 0.7.5**

This will install the Board Support Package (BSP) to your computer and may take a few minutes.

Once completed, find the installed package (usually in AppData\Local\Arduino15\packages) and replace the Bluefruit52Lib library file with the zipped version from the firmware directory in this project. This will add a gamepad API to the BSP.

Load the sketch from the firmware directory.

Change your board settings to use Adafruit Bluefruit nRF52832 Feather, plug in the device and choose the correct serial port.

Upload the sketch to your board using the upload button.

## Electrical Layout

By default the configuration will set the board up to use active low button presses (you ground an input to activate the button). There is no need for pullup resistors as that is done internally.

The default pinout looks like this:

|Input button | Board Terminal |
|-------------|----------------|
|BUTTON_1     |27              |
|BUTTON_2     |A4              |
|BUTTON_3     |A5              |
|BUTTON_4     |A6              |
|BUTTON_5     |A0              |
|BUTTON_6     |A1              |
|BUTTON_7     |A2              |
|BUTTON_8     |A3              |
|BUTTON_9     |7               |
|BUTTON_10    |11              |
|BUTTON_11    |SCK             |
|BUTTON_12    |MOSI            |
|BUTTON_13    |MISO            |
|BUTTON_14    |15              |
|BUTTON_15    |16              |

## Example Circuit

```text
GND o-----o ┴ o------o Pin 27
       Switch (N/O)
```

## Advanced/Power Savings

This circuit uses around 2mA on the latest feather boards.

Note: If you bought your board before March 2018, there is a known hardware issue that will cause the sketch to use about 9mA. for the older style boards, there's a couple of options: buy a new one or you can use a rework station to remove the CP2104 serial chip from the board if the battery isn't lasting through your game sessions. Programming the chip thereafter would need an external 3.3V UART bridge.

It's best to use about a 500mAh LiPo cell with this device and code. The battery will last about 5 days on a charge for the latest revisions.

You can also further hack the BSP by changing hardware/FreeRTOSConfig.h and changing the tick rate value:

`#define configTICK_RATE_HZ 65535`

## Latency

The measured latency between button press and game reaction is approximately 30ms average.

## Schematic and PCB layouts

This project was kicked off to replace the Accuforce direct drive wheel's  button box PCB with a Bluetooth Low Energy HID button box controller. This project is DIY and derives much from the original Adafruit design with specific board shapes and pinouts for the steering wheel controls.

If you'd like to build one, the gerbers and schematics are freely available in this repository. They circuit can be easily forked and modified on the Circuitmaker repository here: <https://workspace.circuitmaker.com/Projects/Details/century-synthetics/AFV2-Wireless-Button-Box-Mod>

The circuit is designed to be built by hand using 0805 surface mount parts or larger. It is a moderately challenging build due to the bluetooth QFN module. You can see the BOM folder for a parts list.

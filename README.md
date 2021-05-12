# PICO 1.14" LCD HAT

1.14" LCD HAT for Raspberry Pi Pico is a 1.14-inch display expansion board module of 240×135 resolution, 65K RGB colors, clear and colorful displaying effect, with a joystick, designed dedicatedly for Raspberry Pi Pico to expand its engagement via SPI communication by providing standard 40 pins GPIO interface. 


## How to use ?

### Board Details :

|  Pico 1.14" LCD board |   Raspberry Pi PICO  |
|-----------------|----------------------|
| LCD DIN         |   GP11             |
| LCD CLK         |   GP10             |
| LCD DC          |   GP8              |
| LCD CS          |   GP9              |
| LCD RST         |   GP12             |
| LCD BL          |   GP13             |
| JOYSTICK UP     |   GP18             |
| JOYSTICK DOWN   |   GP20             |
| JOYSTICK LEFT   |   GP21             |
| JOYSTICK RIGHT  |   GP17             |
| JOYSTICK SELECT |   GP19             |



### Requirements

* Pico 1.14" LCD HAT: (Buy it from : https://shop.sb-components.co.uk/products/1-14-lcd-hat-for-pico )
* Raspberry Pi Pico (Buy it from : https://shop.sb-components.co.uk/collections/latest-collections/products/raspberry-pi-pico-board-with-header )
* USB Cable

### Steps :

* Stack Raspberry Pi Pico on female header of Pico 1.14" LCD HAT.
* Connect USB cable on Raspberry Pi Pico USB port.
* Now Create a file "Lcd1_14driver.py" as same content from Pico 1.14" LCD HAT's github repository in any micropython supported ide (preferred thonny ide) and save it in root location of Raspberry Pi Pico with same name "Lcd1_14driver.py" (without quotes).

* Copy and Paste or Open "Lcd1_14Demo.py" code in thonny ide.

* Choose interpreter as MicroPython (Raspberry Pi pico).

<img src="https://github.com/sbcshop/Raspberry-Pi-Pico-RFID-Expansion/blob/main/images/thonny-interpreter.PNG" />

* Click on green play button to run example of Pico 3V Relay HAT, You can either save this file on root location of PICO or on your Computer drive.
* You can use Joystick to change background color of LCD.



#include <cstring>
#include <stdlib.h>

#include "pico/binary_info.h"
#include "pico/stdlib.h"

#include "../Lcd1-14driver.h"

//TODO: Remake what the python demo is doing
int main() {
    bi_decl(bi_program_description("This is an example program which shows content on the Pico 1.14 LCD HAT"));
    bi_decl(bi_program_name("Pico 1.14 LCD HAT Demo program (C++)"));

    Lcd1_14 lcd;
    while (true){
        memset(lcd.buffer, rand() % 255, BUFFERLENGTH);
        lcd.LcdShow();

        sleep_ms(100);
    }
}
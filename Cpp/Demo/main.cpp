#include <cstring>

#include "pico/binary_info.h"
#include "pico/stdlib.h"

#include "../Lcd1-14driver.h"

//TODO: Remake what the python demo is doing
int main() {
    bi_decl(bi_program_description("This is an example program which shows content on the Pico 1.14 LCD HAT"));
    bi_decl(bi_program_name("Pico 1.14 LCD HAT Demo program (C++)"));

    Lcd1_14 lcd;
    //lcd.DrawRect({0, 0}, {100, 100}, BLUE);

    bool left = true;
    for (uint i = 0; i < lcd.Width; ++i) {
        left = !left;
        lcd.DrawHorizontalLine({ i + (left ? 1 : -1), i }, 100 + i, BLUE + i);
        sleep_ms(1);
        lcd.LcdShow();
    }

    /*while (true){
        lcd.Fill(rand() % 255);
        lcd.LcdShow();

        sleep_ms(100);
    }*/
}
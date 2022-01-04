#pragma once
#include "Frame.h"

#define PIN_DC 8
#define PIN_RST 12
#define PIN_MOSI 11
#define PIN_SCK 10
#define PIN_CS 9
#define SPI_PORT spi1

#define WIDTH 240
#define HEIGHT 135
#define BUFFERLENGTH HEIGHT * WIDTH * 2

#define RED 0x07E0
#define GREEN 0x001F
#define BLUE 0xF800
#define WHITE 0xFFFF

//TODO: Maybe change the naming of theses?
class Lcd1_14 : public Frame {
public:
    Lcd1_14();
    void LcdShow();
private:
    uint8_t buffer[BUFFERLENGTH]; //TODO: Maybe make this configurable?
    void LcdWriteCmd(uint8_t data);
    void LcdWriteData(uint8_t buf);
    void LcdInitDisplay();
};
#include <cstdio>
#include "hardware/gpio.h"
#include "hardware/spi.h"
#include "Lcd1-14driver.h"
#define BAUDRATE 10000000

//TODO: Readd asserts
static void InitAndSetDirection(uint gpio_pin, bool out){
    gpio_init(gpio_pin);
    gpio_put(gpio_pin, false);
    gpio_set_dir(gpio_pin, out);
}

Lcd1_14::Lcd1_14() { //: Frame(buffer, WIDTH, HEIGHT) {
    InitAndSetDirection(PIN_CS, GPIO_OUT);
    InitAndSetDirection(PIN_RST, GPIO_OUT);

    gpio_put(PIN_CS, true);

    //Setup SPI
    spi_init(SPI_PORT, BAUDRATE);
    uint actualBaudrate = spi_set_baudrate(SPI_PORT, BAUDRATE);
    spi_set_format(SPI_PORT, 8,  SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
    if(actualBaudrate != BAUDRATE){
        printf("Wasn't able to get Baudrate requested (Got %u when we wanted %u)", BAUDRATE, actualBaudrate);
    }

    InitAndSetDirection(PIN_SCK, GPIO_IN);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);

    InitAndSetDirection(PIN_MOSI, GPIO_IN);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);

    InitAndSetDirection(PIN_DC, GPIO_OUT);
    gpio_put(PIN_DC, true);
    LcdInitDisplay();
}

void Lcd1_14::LcdWriteCmd(uint8_t data) {
    uint8_t content[1] { data };

    gpio_put(PIN_CS, true);
    gpio_put(PIN_DC, false);
    gpio_put(PIN_CS, false);
    spi_write_blocking(SPI_PORT, content, sizeof(content));
    //assert(amountWritten == sizeof(content));
    gpio_put(PIN_CS, true);
}

void Lcd1_14::LcdWriteData(uint8_t buf) {
    uint8_t content[1] { buf };

    gpio_put(PIN_CS, true);
    gpio_put(PIN_DC, true);
    gpio_put(PIN_CS, false);
    spi_write_blocking(SPI_PORT, content, sizeof(content));
    //assert(amountWritten == sizeof(content));
    gpio_put(PIN_CS, true);
}

void Lcd1_14::LcdInitDisplay() {
    //Initialize display
    gpio_put(PIN_RST, true);
    gpio_put(PIN_RST, false);
    gpio_put(PIN_RST, true);

    LcdWriteCmd(0x36);
    LcdWriteData(0x70);

    LcdWriteCmd(0x3A);
    LcdWriteData(0x05);

    LcdWriteCmd(0xB2);
    LcdWriteData(0x0C);
    LcdWriteData(0x0C);
    LcdWriteData(0x00);
    LcdWriteData(0x33);
    LcdWriteData(0x33);

    LcdWriteCmd(0xB7);
    LcdWriteData(0x35);

    LcdWriteCmd(0xBB);
    LcdWriteData(0x19);

    LcdWriteCmd(0xC0);
    LcdWriteData(0x2C);

    LcdWriteCmd(0xC2);
    LcdWriteData(0x01);

    LcdWriteCmd(0xC3);
    LcdWriteData(0x12);

    LcdWriteCmd(0xC4);
    LcdWriteData(0x20);

    LcdWriteCmd(0xC6);
    LcdWriteData(0x0F);

    LcdWriteCmd(0xD0);
    LcdWriteData(0xA4);
    LcdWriteData(0xA1);

    LcdWriteCmd(0xE0);
    LcdWriteData(0xD0);
    LcdWriteData(0x04);
    LcdWriteData(0x0D);
    LcdWriteData(0x11);
    LcdWriteData(0x13);
    LcdWriteData(0x2B);
    LcdWriteData(0x3F);
    LcdWriteData(0x54);
    LcdWriteData(0x4C);
    LcdWriteData(0x18);
    LcdWriteData(0x0D);
    LcdWriteData(0x0B);
    LcdWriteData(0x1F);
    LcdWriteData(0x23);

    LcdWriteCmd(0xE1);
    LcdWriteData(0xD0);
    LcdWriteData(0x04);
    LcdWriteData(0x0C);
    LcdWriteData(0x11);
    LcdWriteData(0x13);
    LcdWriteData(0x2C);
    LcdWriteData(0x3F);
    LcdWriteData(0x44);
    LcdWriteData(0x51);
    LcdWriteData(0x2F);
    LcdWriteData(0x1F);
    LcdWriteData(0x1F);
    LcdWriteData(0x20);
    LcdWriteData(0x23);

    LcdWriteCmd(0x21);

    LcdWriteCmd(0x11);

    LcdWriteCmd(0x29);
}

void Lcd1_14::LcdShow() {
    LcdWriteCmd(0x2A);
    LcdWriteData(0x00);
    LcdWriteData(0x28);
    LcdWriteData(0x01);
    LcdWriteData(0x17);

    LcdWriteCmd(0x2B);
    LcdWriteData(0x00);
    LcdWriteData(0x35);
    LcdWriteData(0x00);
    LcdWriteData(0xBB);

    LcdWriteCmd(0x2C);

    gpio_put(PIN_CS, true);
    gpio_put(PIN_DC, true);
    gpio_put(PIN_CS, false);
    spi_write_blocking(SPI_PORT, buffer, BUFFERLENGTH);
    //assert(amountWritten == sizeof(BUFFERLENGTH));
    gpio_put(PIN_CS, true);
}
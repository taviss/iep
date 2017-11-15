#ifndef SPI_H
#define SPI_H

#include "bcm2835.h"
#include "serial.h"


class SPI : public Serial
{
    public:
        SPI(uint8_t bitOrder, uint8_t dataMode, uint16_t clockDivider, uint8_t csPolarity);
        ~SPI();
        int start();
        uint8_t transfer(uint8_t data);

    private:
        uint8_t bitOrder;
        uint8_t dataMode;
        uint16_t clockDivider;
        uint8_t csPolarity;
};

#endif // SPI_H

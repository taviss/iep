#include "spi.h"

SPI::SPI(uint8_t bitOrder, uint8_t dataMode, uint16_t clockDivider, uint8_t csPolarity) : Serial()
{
    this->bitOrder=bitOrder;
    this->dataMode=dataMode;
    this->clockDivider=clockDivider;
    this->csPolarity=csPolarity;
}

SPI::~SPI()
{
    bcm2835_spi_end();
    bcm2835_close();
}

int SPI::start()
{
    if (!bcm2835_init())
    {
        //printf("bcm2835_init failed. Are you running as root??\n");
        return -1;
    }
    if (!bcm2835_spi_begin())
    {
        //printf("bcm2835_spi_begin failed. Are you running as root??\n");
        return -1;
    }
    bcm2835_spi_setBitOrder(this->bitOrder);
    bcm2835_spi_setDataMode(this->dataMode);
    bcm2835_spi_setClockDivider(this->clockDivider);
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, this->csPolarity);
    return 1;
}

uint8_t SPI::transfer(uint8_t data)
{
    uint8_t read_data = bcm2835_spi_transfer(data);
    return read_data;
}

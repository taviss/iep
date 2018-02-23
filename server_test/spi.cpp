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
    bcm2835_spi_setBitOrder(this->bitOrder);      // The default
    bcm2835_spi_setDataMode(this->dataMode);                   // The default
    bcm2835_spi_setClockDivider(this->clockDivider); // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, this->csPolarity);      // the default
    return 1;
}

uint8_t SPI::transfer(uint8_t data)
{
    uint8_t read_data = bcm2835_spi_transfer(data);
    //printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", send_data, read_data);
    //if (send_data != read_data)
        //printf("Do you have the loopback from MOSI to MISO connected?\n");
    return read_data;
}

#include "outputpin.h"

OutputPin::OutputPin(uint8_t pinNumber) : Pin(pinNumber, PIN_DIRECTION_OUTPUT)
{
    if (!bcm2835_init())
          //cout << "EXCEPTION INIT TODO";

    bcm2835_gpio_fsel(pinNumber, PIN_DIRECTION_OUTPUT);
}

void OutputPin::set(uint8_t data)
{
    if (!bcm2835_init())
        return;

    // Turn it on
    bcm2835_gpio_write(pinNumber, data);

    this->lastData = data;
}

uint8_t OutputPin::get()
{
    return this->lastData;
}

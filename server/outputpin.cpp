#include "outputpin.h"

OutputPin::OutputPin(int pinNumber) : Pin(pinNumber, PIN_DIRECTION_OUTPUT)
{
    if (!bcm2835_init())
          //cout << "EXCEPTION INIT TODO";

    bcm2835_gpio_fsel(pinNumber, BCM2835_GPIO_FSEL_OUTP);
}

void OutputPin::set(int data)
{
    if (!bcm2835_init())
        return;

    // Turn it on
    bcm2835_gpio_write(pinNumber, data);
}

OutputPin::get()
{
    return this->lastData;
}

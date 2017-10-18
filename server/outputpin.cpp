#include "outputpin.h"

OutputPin::OutputPin(int pinNumber) : Pin(pinNumber, PIN_DIRECTION_OUTPUT)
{

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

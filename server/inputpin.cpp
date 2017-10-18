#include "inputpin.h"

InputPin::InputPin(int pinNumber, int pullUp) : Pin(pinNumber, PIN_DIRECTION_INPUT)
{
    this->pullUp = pullUp;
}

void InputPin::set(int data)
{
    (void)data;
}

InputPin::get()
{
    if (!bcm2835_init())
            return 1;

    return bcm2835_gpio_lev(pinNumber);
}

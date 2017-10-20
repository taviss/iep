#include "inputpin.h"

InputPin::InputPin(uint8_t pinNumber, uint8_t pullUp) : Pin(pinNumber, PIN_DIRECTION_INPUT)
{
    if (!bcm2835_init())
            //cout << "ERROR INIT TODO";

    bcm2835_gpio_fsel(pinNumber, PIN_DIRECTION_INPUT);
    bcm2835_gpio_set_pud(pinNumber, pullUp);

    this->pullUp = pullUp;
}

void InputPin::set(uint8_t data)
{
    (void)data;
}

uint8_t InputPin::get()
{
    if (!bcm2835_init())
            return 1;

    return bcm2835_gpio_lev(pinNumber);
}

#include "inputpin.h"

InputPin::InputPin(int pinNumber, int pullUp) : Pin(pinNumber, PIN_DIRECTION_INPUT)
{
    if (!bcm2835_init())
            //cout << "ERROR INIT TODO";

    bcm2835_gpio_fsel(pinNumber, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(pinNumber, pullUp);

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

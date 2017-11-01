#include "button.h"
#include "pin.h"

Button::Button(uint8_t pinNumber) : InputPin(pinNumber, DEFAULT_PULL_UP)
{

}

uint8_t Button::get() {
    while (1)
    {
        if (bcm2835_gpio_eds(this->pinNumber))
        {
            // Now clear the eds flag by setting it to 1
            bcm2835_gpio_set_eds(this->pinNumber);
            return 1;
        }
        // wait a bit
        delay(500);
    }
    return 0;
}

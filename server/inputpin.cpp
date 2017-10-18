#include "inputpin.h"

InputPin::InputPin(int pinNumber, int pullUp) : Pin(pinNumber, PIN_DIRECTION_INPUT)
{
    this->pullUp = pullUp;
}

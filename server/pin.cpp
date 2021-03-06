#include "pin.h"
#include "outputpin.h"
#include "inputpin.h"
/*
Implementați clasa Pin care să conțină numărul pinului, direcția, starea de pull-up (în caz ca e pin de input)
, și metode pentru get, set și change direction unde, în caz că pinul e output, set va scrie pe pin și get va citi valoarea scrisă, iar în caz de input, set nu face nimic, iar get va citi de pe pin. Metoda change direction schimb direcția pinului.
Reimplementați exemplul de blink folosind clasa Pin
Încercați un Pin de input pentru buton și unul de output pentru LED.
 * */
Pin::Pin(uint8_t pinNumber, uint8_t direction)
{
    this->pinNumber = pinNumber;
    this->direction = direction;
}

uint8_t Pin::getDirection() {
    return this->direction;
}

Pin* Pin::setDirection(uint8_t direction) {
    if(this->direction == direction) {
        return this;
    }

    switch(direction)
    {
        case PIN_DIRECTION_INPUT:
        {
            InputPin* inputPin;
            inputPin = new InputPin(this->pinNumber, DEFAULT_PULL_UP);
            return inputPin;
        }
        case PIN_DIRECTION_OUTPUT:
        {
            OutputPin* outputPin;
            outputPin = new OutputPin(this->pinNumber);
            return outputPin;
        }
        default:
            return nullptr;
    }
}

Pin* Pin::changeDirection() {
    switch(direction)
    {
        case PIN_DIRECTION_INPUT:
        {
            OutputPin* outputPin;
            outputPin = new OutputPin(this->pinNumber);
            return outputPin;
        }
        case PIN_DIRECTION_OUTPUT:
        {
            InputPin* inputPin;
            inputPin = new InputPin(this->pinNumber, DEFAULT_PULL_UP);
            return inputPin;
        }
        default:
            return nullptr;
    }
}

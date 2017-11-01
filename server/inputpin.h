#ifndef INPUTPIN_H
#define INPUTPIN_H

#include "pin.h"

class InputPin : public Pin
{
    public:
        InputPin(uint8_t pinNumber, uint8_t pullUp);
        void set(uint8_t data);
        uint8_t get();

    private:
        uint8_t pullUp;
};

#endif // INPUTPIN_H

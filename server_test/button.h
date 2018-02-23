#ifndef BUTTON_H
#define BUTTON_H

#include "inputpin.h"

//Test
class Button : public InputPin
{
    public:
        Button(uint8_t pinNumber);
        uint8_t get();
};

#endif // BUTTON_H

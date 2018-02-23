#ifndef OUTPUTPIN_H
#define OUTPUTPIN_H

#include "pin.h"


class OutputPin : public Pin
{
    public:
        OutputPin(uint8_t pinNumber);
        void set(uint8_t data);
        uint8_t get();

    private:
        uint8_t lastData;
};

#endif // OUTPUTPIN_H

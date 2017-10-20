#ifndef PIN_H
#define PIN_H

#include "bcm2835.h"

#define PIN_DIRECTION_INPUT BCM2835_GPIO_FSEL_INPT
#define PIN_DIRECTION_OUTPUT BCM2835_GPIO_FSEL_OUTP

class Pin
{
    public:
        Pin(uint8_t pinNumber, uint8_t direction);
        uint8_t getDirection();
        Pin* setDirection(uint8_t direction);
        Pin* changeDirection();
        virtual void set(uint8_t data)=0;
        virtual uint8_t get()=0;

    private:

    protected:
        uint8_t pinNumber;
        uint8_t direction;


};

#endif // PIN_H

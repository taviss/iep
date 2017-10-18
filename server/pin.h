#ifndef PIN_H
#define PIN_H

#include "bcm2835.h"

#define PIN_DIRECTION_INPUT 0
#define PIN_DIRECTION_OUTPUT 1

class Pin
{
    public:
        Pin(int pinNumber, int direction);
        int getDirection();
        Pin* setDirection(int direction);
        Pin* changeDirection();
        virtual void set(int data)=0;
        virtual int get()=0;

    private:

    protected:
        int pinNumber;
        int direction;


};

#endif // PIN_H

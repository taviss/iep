#ifndef PIN_H
#define PIN_H

#define PIN_DIRECTION_INPUT 0
#define PIN_DIRECTION_OUTPUT 1

#include "inputpin.h"
#include "outputpin.h"

class Pin
{
    public:
        Pin(int pinNumber, int direction);
        int getDirection();
        Pin* setDirection(int direction);
        Pin* changeDirection();

    private:
        int pinNumber;
        int direction;


};

#endif // PIN_H

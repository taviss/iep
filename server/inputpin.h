#ifndef INPUTPIN_H
#define INPUTPIN_H

#include "pin.h"

#define DEFAULT_PULL_UP 0

class InputPin : public Pin
{
    public:
        InputPin(int pinNumber, int pullUp);
        void set(int data);
        int get();

    private:
        int pullUp;
};

#endif // INPUTPIN_H

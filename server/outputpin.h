#ifndef OUTPUTPIN_H
#define OUTPUTPIN_H

#include "pin.h"


class OutputPin : public Pin
{
    public:
        OutputPin(int pinNumber);
        void set(int data);
        int get();

    private:
        int lastData;
};

#endif // OUTPUTPIN_H

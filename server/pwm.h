#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#define PIN RPI_GPIO_P1_12
#define PWM_CHANNEL 0

class PWM
{
    public:
        PWM(uint8_t dutyCycle, uint8_t frequency);
        uint8_t getDutyCycle();
        uint8_t getFrequency();
        void setDutyCycle(uint8_t dutyCycle);
        void setFrequency(uint8_t frequency);
        void reconfigure();

    private:
        uint8_t dutyCycle;
        uint8_t frequency;
        uint8_t data;
        uint8_t range;
};

#endif // PWM_H

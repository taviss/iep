#include "pwm.h"
#include "bcm2835.h"

PWM::PWM(uint8_t dutyCycle, uint8_t frequency)
{
    this->dutyCycle = dutyCycle;
    this->frequency = frequency;
    /*
     * PWM Range = PWM frequency / Desired Output Frequency
     */
    this->range=1.2e6/frequency;
    /*
     * The 'duty cycle' is the ratio of PWM data to PWM range expressed as a percentage
     */
    this->data=range*(dutyCycle/100);
}

uint8_t PWM::getDutyCycle() {
    return this->dutyCycle;
}

uint8_t PWM::getFrequency() {
    return this->frequency;
}

void PWM::setDutyCycle(uint8_t dutyCycle) {
    this->dutyCycle = dutyCycle;
}

void PWM::setFrequency(uint8_t frequency) {
    this->frequency = frequency;
}

void PWM::reconfigure() {
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_ALT5);
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);


    bcm2835_pwm_set_range(PWM_CHANNEL, this->range);
    bcm2835_pwm_set_data(PWM_CHANNEL, this->data);
}

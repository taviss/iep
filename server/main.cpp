#include <QApplication>
#include <bcm2835.h>
#include <pin.h>
#include <inputpin.h>
#include <outputpin.h>
#include <button.h>
#include <pwm.h>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    //Blink.c reimpl TODO - deleted this
    if (!bcm2835_init())
        return 1;

    Pin* pin = new Button(RPI_GPIO_P1_11);
    int dCycle = 0;
    int freq = 500;
    PWM* pwm = new PWM(dCycle, freq);

    while(1) {
        pin->get();
        dCycle+=10;
        pwm->setDutyCycle(dCycle);
        pwm->reconfigure();
        if(dCycle==100)
            dCycle=0;
    }
    bcm2835_close();
    return app.exec();
}

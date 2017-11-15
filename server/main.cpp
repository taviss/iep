#include <QApplication>
#include <bcm2835.h>
#include <pin.h>
#include <inputpin.h>
#include <outputpin.h>
#include <button.h>
#include <pwm.h>
#include <spi.h>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    bcm2835_set_debug(1);
    //Blink.c reimpl TODO - deleted this
    if (!bcm2835_init())
        return 1;

    Pin* pin = new Button(RPI_GPIO_P1_11);
    int dCycle = 0;
    int freq = 500;
    PWM* pwm = new PWM(dCycle, freq);

    //bcm2835_set_debug(1);
    SPI* spi = new SPI(BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE0,
                       BCM2835_SPI_CLOCK_DIVIDER_65536, LOW);

    spi->start();
    int read = spi->transfer(0x32);
    if(read != 0x32)
        return -1;
    else
        return 1;

    while(1) {
        //Blocking wait for button press
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

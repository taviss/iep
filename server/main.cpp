#include <QApplication>
#include <bcm2835.h>
#include <outputpin.h>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    //Blink.c reimpl TODO - deleted this
    if (!bcm2835_init())
        return 1;

    OutputPin pin(RPI_GPIO_P1_11);
    while (1)
    {
        pin.set(HIGH);

        // wait a bit
        bcm2835_delay(500);

        pin.set(LOW);

        // wait a bit
        bcm2835_delay(500);
    }
    bcm2835_close();
    return app.exec();
}

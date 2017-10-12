#include <QCoreApplication>
#include "server.h"

int main(int argc, char **argv)
{
    QCoreApplication app (argc, argv);
    Server server(8888);
    server.start();
    return app.exec();
}

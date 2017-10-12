#include "server.h"
#include "thread.h"

Server::Server(int port, QObject* parent) : QTcpServer(parent)
{
    qInfo() << "Initialized server with port" << port;
    portNo=port;
}

void Server::start()
{
    if(!this->listen(QHostAddress::Any, portNo))
    {
        qDebug() <<"could not start server";
    }
    qInfo() << "Started server on port" << this->serverPort();
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    Thread *thread = new Thread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

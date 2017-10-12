#include "thread.h"
#include <QtNetwork>

Thread::Thread(int socketDescriptor, QObject *parent) : QThread(parent), socketDescriptor(socketDescriptor)
{

}

void Thread::run() {
    tcpSocket = new QTcpSocket();
    //qInfo() << "New QTcpServer with socketDescriptor: " << socketDescriptor;
    if (!tcpSocket->setSocketDescriptor(socketDescriptor)) {
        qInfo() << "error" << tcpSocket->error();
        emit error(tcpSocket->error());
        return;
    }

    qInfo() << "New connection from" << tcpSocket->peerAddress();

    connect(tcpSocket, SIGNAL(readyRead()), SLOT(readyRead()));

    /*
    qInfo() << "isOpen:" << tcpSocket->isOpen();
    qInfo() << "isReadable:" << tcpSocket->isReadable();
    qInfo() << "isWritable:" << tcpSocket->isWritable();
    qInfo() << "localAddress:" << tcpSocket->localAddress();
    */

    tcpSocket->waitForReadyRead();

}

void Thread::readyRead()
{
    qInfo() << "----------------------------------";
    QByteArray data = tcpSocket->readAll();
    qInfo() << data;

    const char* success = "Command executed successfuly";

    tcpSocket->write(success);
    tcpSocket->waitForBytesWritten();
}

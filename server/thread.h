#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class Thread : public QThread
{
    Q_OBJECT

    public:
        Thread(int socketDescriptor, QObject *parent=0);

        void run() override;

    signals:
        void error(QTcpSocket::SocketError socketerror);

   private slots:
        void readyRead();

    private:
        int socketDescriptor;
        QString text;
        QTcpSocket* tcpSocket;
};

#endif // THREAD_H

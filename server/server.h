#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>


class Server : public QTcpServer
{
    Q_OBJECT

    public:
        Server(int port, QObject* parent=0);

        void start();

    protected:
        void incomingConnection(qintptr socketDescriptor) override;

    private:
        int portNo;
};

#endif // SERVER_H

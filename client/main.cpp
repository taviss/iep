#include <QCoreApplication>
#include <QTcpSocket>
#include <QtNetwork>


static inline QByteArray IntToArray(qint32 source);

int main(int argc, char **argv)
{
    QCoreApplication app (argc, argv);
    QTcpSocket socket;
    QString hostname = "127.0.0.1";
    qInfo() << "Trying to connect to" << hostname;
    socket.connectToHost(hostname, 8888);
    socket.waitForConnected();
    if(socket.state() == QAbstractSocket::ConnectedState)
    {
        qInfo() << "Connected to" << hostname;
    }

    if(socket.state() == QAbstractSocket::ConnectedState)
    {
        qInfo("Trying to write data...");
        socket.write("Some test"); //write the data itself
        socket.waitForBytesWritten();
        qInfo() << "Write successful!";
        socket.waitForReadyRead();
        qInfo() << socket.readAll();
        qInfo() << "State is:" << socket.state();
        socket.disconnectFromHost();
        qInfo() << "State is:" << socket.state();
    } else {
        qInfo() << "Error, state is:" << socket.state();
    }


    return app.exec();
}

QByteArray IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

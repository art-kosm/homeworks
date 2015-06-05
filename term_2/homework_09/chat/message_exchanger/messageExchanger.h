#pragma once

#include <QTcpSocket>
#include <QString>

class MessageExchanger
{
public:
    void sendMessage(QTcpSocket *tcpSocket, const QString &message)
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << (quint16) 0;
        out << message;
        out.device()->seek(0);
        out << (quint16) (block.size() - sizeof(quint16));

        tcpSocket->write(block);
    }

    QString getMessage(QTcpSocket *tcpSocket)
    {
        QDataStream in(tcpSocket);
        in.setVersion(QDataStream::Qt_4_0);

        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return "";

        quint16 blockSize = 0;
        in >> blockSize;

        if (tcpSocket->bytesAvailable() < blockSize)
            return "";

        QString message = "";
        in >> message;

        return message;
    }
};

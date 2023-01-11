#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class TcpConnection : public QObject
{
    Q_OBJECT

public:

    TcpConnection();

    void send_xml(QByteArray xml_data);

signals:

    void update_statusBar_signal(QString text, int time);

private:

    QTcpSocket *m_socket;

    QHostAddress m_host_address = QHostAddress::LocalHost;;

    quint16 m_port_number = 6164;;
};

#endif // TCPCONNECTION_H

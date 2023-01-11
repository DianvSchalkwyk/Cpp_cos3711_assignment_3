#include "tcpconnection.h"
#include <QIcon>

#include <QMessageBox>

TcpConnection::TcpConnection()
              :m_socket(new QTcpSocket)
{}

void TcpConnection::send_xml(QByteArray xml_data)
{
    m_socket->connectToHost(m_host_address, m_port_number);

    if(m_socket->waitForConnected())
    {
        m_socket->write(xml_data);

        QMessageBox connection_information;

        connection_information.setWindowIcon(QIcon(":/COS3711_A3/Resources/Images/info.png"));
        connection_information.setWindowTitle("Success");
        connection_information.setText("Connection to localhost was successful. Data was sent to the server.");

        connection_information.exec();

        m_socket->close();
    }
    else
    {
        QMessageBox connection_information;

        connection_information.setWindowIcon(QIcon(":/COS3711_A3/Resources/Images/info.png"));
        connection_information.setWindowTitle("Error");
        connection_information.setText("No connection to localhost. Please check if server is listening for a connection.");

        connection_information.exec();

        m_socket->close();
    }
}

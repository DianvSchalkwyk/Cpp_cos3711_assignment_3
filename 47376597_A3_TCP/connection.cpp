#include "connection.h"
#include "data.h"

#include <QXmlStreamReader>

Connection::Connection(QObject *parent)
           :QTcpServer{parent}
{
    connect(&new_server, &QTcpServer::newConnection, this, &Connection::new_connection);
}

quint16 Connection::get_port_number()
{
    return port_number;
}

void Connection::convert_received_data()
{
    QXmlStreamReader data_receieved_QByteArray(data_recieved);

    Data *converted_xml = new Data;

    int pallet_number = 0;

    while(!data_receieved_QByteArray.atEnd())
    {
        data_receieved_QByteArray.readNext();

        if(data_receieved_QByteArray.isStartElement())
        {
            for(int i = 0; i < container_names.size(); i++)
            {
                if(data_receieved_QByteArray.name().toString() == container_names.at(i))
                {
                    converted_xml->set_container_type(container_names.at(i));
                }
            }
            if(data_receieved_QByteArray.name().toString() == "pallet")
            {
                pallet_number = data_receieved_QByteArray.attributes().value("number").toInt();
            }
            else if(data_receieved_QByteArray.name() == "code")
            {
                converted_xml->set_container_code(data_receieved_QByteArray.readElementText());
            }
            else if(data_receieved_QByteArray.name().toString() == "weight")
            {
                converted_xml->set_container_weight(data_receieved_QByteArray.readElementText().toInt());
            }
            else if(data_receieved_QByteArray.name().toString() == "height")
            {
                converted_xml->set_container_height(data_receieved_QByteArray.readElementText().toInt());
            }
            else if(data_receieved_QByteArray.name().toString() == "breadth")
            {
                converted_xml->set_container_brea_diam(data_receieved_QByteArray.readElementText().toInt());
            }
            else if(data_receieved_QByteArray.name().toString() == "diameter")
            {
                converted_xml->set_container_brea_diam(data_receieved_QByteArray.readElementText().toInt());
            }
            if(data_receieved_QByteArray.name().toString() == "length")
            {
                converted_xml->set_container_length(data_receieved_QByteArray.readElementText().toInt());
            }
        }
        if(data_receieved_QByteArray.isEndElement())
        {
            converted_xml->set_pallet_number(pallet_number);

            for(int i = 0; i < container_names.size(); i++)
            {
                if(data_receieved_QByteArray.name().toString() == container_names.at(i))
                {
                    xml_data_list.append(converted_xml);

                    converted_xml = new Data;
                }
            }
        }
    }

    delete converted_xml;

    emit data_added_signal();
}

void Connection::start_listen()
{
    if(new_server.listen(host_address, port_number))
    {
        qInfo()<<"listening for connection";
    }
}

void Connection::stop_listen()
{
    new_server.close();
}

void Connection::new_connection()
{
    QTcpSocket *server_socket = new_server.nextPendingConnection();

    connect(server_socket,&QTcpSocket::disconnected,this,&Connection::remove_connection);
    connect(server_socket,&QTcpSocket::readyRead,   this,&Connection::read_data);

    emit clear_model_signal();
}

void Connection::remove_connection()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());

    delete socket;
}

void Connection::read_data()
{
    QTcpSocket *server_socket = qobject_cast<QTcpSocket*>(sender());

    data_recieved = server_socket->readAll();

    Connection::convert_received_data();
}

const QList<Data *> &Connection::get_data_list() const
{
    return xml_data_list;
}

void Connection::set_data_list(const QList<Data *> &data_list)
{
    xml_data_list = data_list;
}

void Connection::clear_list()
{
    xml_data_list.clear();
}

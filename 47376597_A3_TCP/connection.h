#ifndef CONNECTION_H
#define CONNECTION_H

#include "data.h"

#include <QObject>
#include <QAbstractSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QByteArray>
#include <QRegularExpression>

class QByteArray;

class Connection : public QTcpServer
{
    Q_OBJECT

public:

    explicit Connection(QObject *parent = nullptr);

    quint16 get_port_number();

    void convert_received_data();

    const QList<Data *> &get_data_list() const;
    void set_data_list(const QList<Data *> &data_list);

    void clear_list();

signals:

    void clear_model_signal();

public slots:

    void start_listen();
    void stop_listen();
    void new_connection();
    void remove_connection();
    void read_data();

signals:

    void data_added_signal();

private:

    QTcpServer new_server;

    QHostAddress host_address = QHostAddress::Any;
    quint16      port_number  = 6164;

    QByteArray data_recieved;

    QList<Data*> xml_data_list;

    QRegularExpression required_layout;

    QList <QString> container_names = {"Box" , "Cylinder"};
};

#endif // CONNECTION_H

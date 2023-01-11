#include "view.h"
#include "connection.h"
#include <QAbstractTableModel>
#include <QTableView>
#include <QLabel>
#include <QGridLayout>
#include <QHeaderView>
#include <QPushButton>

View::View(QWidget *parent)
     :QWidget(parent),
      new_server        (new Connection),
      new_model         (new Model),
      table_view        (new QTableView(this)),
      listen_QPushButton(new QPushButton("Start Listening")),
      listen_info_Qlabel(new QLabel("Click start to create new server"))
{
    this->setWindowTitle("Container Server");
    setup_view();

    connect(listen_QPushButton, &QPushButton::clicked, this, &View::create_connection_slot);

    connect(new_server, &Connection::data_added_signal, this, &View::data_sent_slot);
    connect(new_server, &Connection::clear_model_signal,this, &View::clear_model_slot);
}

void View::setup_view()
{
    table_view->setModel(new_model);

    QGridLayout *grid_layout(new QGridLayout(this));

    this->setMinimumWidth(600);

    table_view->resizeColumnsToContents();
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    grid_layout->addWidget(listen_QPushButton, 0, 0      );
    grid_layout->addWidget(listen_info_Qlabel, 0, 1      );
    grid_layout->addWidget(table_view,         1, 0, 1, 2);
}

View::~View(){}

void View::clear_model_slot()
{
    new_server->clear_list();

    new_model ->clear_model();
}

void View::create_connection_slot()
{
    new_server->start_listen();

    listen_QPushButton->setText("Waiting for data");
    listen_info_Qlabel->setText("Listening on port: " + QVariant(new_server->get_port_number()).toString());
}

void View::data_sent_slot()
{
    new_model->set_data_list(new_server->get_data_list());

    new_model->insert_row();
}

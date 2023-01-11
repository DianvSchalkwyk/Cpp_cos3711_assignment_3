#ifndef VIEW_H
#define VIEW_H

#include "connection.h"
#include "model.h"
#include <QDialog>

class QTableView;
class QLabel;

class View : public QWidget
{
    Q_OBJECT

public:

    View(QWidget *parent = nullptr);

    void setup_view();

    ~View();

public slots:

    void clear_model_slot();

public slots:

    void create_connection_slot();
    void data_sent_slot();

private:

    Connection *new_server;

    Model *new_model;

    QTableView *table_view;

    QPushButton *listen_QPushButton;
    QLabel      *listen_info_Qlabel;

};
#endif // VIEW_H

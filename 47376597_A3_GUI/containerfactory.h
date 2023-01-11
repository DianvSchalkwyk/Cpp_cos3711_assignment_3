#ifndef CONTAINERFACTORY_H
#define CONTAINERFACTORY_H

#include "container.h"
#include <QObject>

class ContainerFactory : public QObject
{
    Q_OBJECT

public:

    explicit ContainerFactory();

    Container *create_container(QString button_name,
                                    int box_breadth,
                                    int box_length,
                                    int box_height,
                                    int box_weight,
                                    int cyl_diameter,
                                    int cyl_height,
                                    int cyl_weight);

    void get_container_backup_counters();
    void set_container_backup_counters();

private:

    int box_container_counter = 0;
    int cyl_container_counter = 0;
};

#endif // CONTAINERFACTORY_H

#ifndef PALLET_H
#define PALLET_H

#include "containerlist.h"
#include <QObject>

class Pallet : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int m_pallet_number READ get_pallet_number WRITE set_pallet_number)
    Q_PROPERTY(int m_pallet_weight READ get_pallet_weight WRITE set_pallet_weight)
    Q_PROPERTY(int m_pallet_volume READ get_pallet_volume WRITE set_pallet_volume)

public:

    Pallet(int pallet_number);
    ~Pallet();

    void add_container(Container *container);

    Container *get_container(int index);

    int get_size();

    int get_pallet_number();
    void set_pallet_number(int pallet_number);

    int get_pallet_weight();
    void set_pallet_weight(int pallet_weight);

    int get_pallet_volume();
    void set_pallet_volume(int pallet_volume);

private:

    ContainerList *m_container_list;

    int m_pallet_number;
    int m_pallet_weight=0;
    int m_pallet_volume=0;
};

#endif // PALLET_H

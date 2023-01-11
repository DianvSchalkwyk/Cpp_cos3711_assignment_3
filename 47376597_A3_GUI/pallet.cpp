#include "pallet.h"

Pallet::Pallet(int pallet_number)
       :m_container_list(new ContainerList),
        m_pallet_number(pallet_number)
{}

Pallet::~Pallet()
{
    delete m_container_list;
}

void Pallet::add_container(Container *container)
{
    m_container_list->add_container(container);

    m_pallet_volume+=container->get_volume();
    m_pallet_weight+=container->get_weight();
}

int Pallet::get_size()
{
    return m_container_list->get_size();
}

Container *Pallet::get_container(int index)
{
    return m_container_list->get_container(index);
}

int Pallet::get_pallet_number()
{
    return m_pallet_number;
}

void Pallet::set_pallet_number(int pallet_number)
{
    m_pallet_number = pallet_number;
}

int Pallet::get_pallet_weight()
{
    return m_pallet_weight;
}

void Pallet::set_pallet_weight(int pallet_weight)
{
    m_pallet_weight += pallet_weight;
}

int Pallet::get_pallet_volume()
{
    return m_pallet_volume;
}

void Pallet::set_pallet_volume(int pallet_volume)
{
    m_pallet_volume += pallet_volume;
}

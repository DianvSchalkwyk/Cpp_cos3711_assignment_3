#include "containerlist.h"

ContainerList::ContainerList(){}

ContainerList::~ContainerList(){}

void ContainerList::add_container(Container *container)
{
    m_container_list.append(container);
}

void ContainerList::remove_container(int location)
{
    m_container_list.removeAt(location);
}

int ContainerList::get_size() const
{
    return m_container_list.size();
}

void ContainerList::set_container_list(ContainerList *container_list)
{
    m_container_list = container_list->m_container_list;
}

void ContainerList::clear_container_list()
{

    m_container_list.clear();
}

Container *ContainerList::get_container(int location)
{
    return m_container_list.at(location);
}

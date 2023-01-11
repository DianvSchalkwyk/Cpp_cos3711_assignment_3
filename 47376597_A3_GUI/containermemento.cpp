#include "containermemento.h"

ContainerMemento::~ContainerMemento(){}

ContainerMemento::ContainerMemento()
                 :memento_state(new ContainerList)
{}

ContainerList *ContainerMemento::get_state()
{
    return memento_state;
}

void ContainerMemento::set_state(ContainerList *current_list)
{
    memento_state->clear_container_list();

    Container *copy_container;

    for(int i = 0; i < current_list->get_size(); i++)
    {
        copy_container = current_list->get_container(i);
        memento_state->add_container(copy_container);
    }
}

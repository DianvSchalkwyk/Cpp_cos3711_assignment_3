#ifndef CONTAINERMEMENTO_H
#define CONTAINERMEMENTO_H

#include "containerlist.h"

class ContainerMemento
{
public:

    ~ContainerMemento();

private:

    friend class MainWidget;

    ContainerMemento();

    ContainerList* get_state();
    void set_state(ContainerList *current_list);

    ContainerList *memento_state;

};

#endif // CONTAINERMEMENTO_H

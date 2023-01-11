#ifndef CONTAINERCARETAKER_H
#define CONTAINERCARETAKER_H

#include "containermemento.h"

class ContainerCaretaker
{
public:

    ContainerCaretaker();

    void request_memento(ContainerMemento *new_memento);

    ContainerMemento* restore_memento();

private:

    ContainerMemento *memento;
};

#endif // CONTAINERCARETAKER_H

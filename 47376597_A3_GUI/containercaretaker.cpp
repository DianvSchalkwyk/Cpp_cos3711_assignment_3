#include "containercaretaker.h"

ContainerCaretaker::ContainerCaretaker(){}

void ContainerCaretaker::request_memento(ContainerMemento *new_memento)
{
    memento = new_memento;
}

ContainerMemento *ContainerCaretaker::restore_memento()
{
    return memento;
}

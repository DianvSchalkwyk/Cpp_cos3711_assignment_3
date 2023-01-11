#ifndef CONTAINERLIST_H
#define CONTAINERLIST_H

#include "container.h"
#include <QObject>
class ContainerList : public QObject
{
    Q_OBJECT

public:

    ContainerList();
    ~ContainerList();

    void add_container(Container *container);
    void remove_container(int location);

    void set_container_list(ContainerList *container_list);
    void clear_container_list();

    int  get_size() const;

    Container *get_container(int location);

private:

    QList<Container*> m_container_list;
};
#endif // CONTAINERLIST_H

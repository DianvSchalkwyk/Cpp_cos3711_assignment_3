#ifndef BOX_H
#define BOX_H

#include "container.h"

#include <QObject>

class Box : public Container
{
    Q_OBJECT

    Q_PROPERTY(int length  READ get_length  WRITE set_length)
    Q_PROPERTY(int breadth READ get_breadth WRITE set_breadth)

public:

    explicit Box(int height, int weight, int volume, QString code, int breadth, int length);

    int  get_breadth() const;
    void set_breadth(int breadth);

    int  get_length()  const;
    void set_length (int length);

private:

    int m_breadth;
    int m_length;
};

#endif // BOX_H

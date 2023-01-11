#ifndef CYLINDER_H
#define CYLINDER_H

#include "container.h"

#include <QObject>

class Cylinder : public Container
{
    Q_OBJECT

    Q_PROPERTY(int diameter READ get_diameter WRITE set_diameter)

public:

    explicit Cylinder(int height, int weight, int volume, QString code, int diameter);

    int get_diameter() const;
    void set_diameter(int diameter);

private:

    int m_diameter;
};

#endif // CYLINDER_H

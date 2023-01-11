#include "cylinder.h"

#include <QMessageBox>

Cylinder::Cylinder(int height, int weight, int volume, QString code, int diameter)
         :Container(height, weight, volume, code),
          m_diameter(diameter)
{}

int Cylinder::get_diameter() const
{
    return m_diameter;
}

void Cylinder::set_diameter(int diameter)
{
    m_diameter = diameter;
}

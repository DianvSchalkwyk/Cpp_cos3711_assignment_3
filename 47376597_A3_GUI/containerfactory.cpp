#include "containerfactory.h"
#include "box.h"
#include "cylinder.h"

#include <QDate>
#include <cmath>

ContainerFactory::ContainerFactory(){}

Container *ContainerFactory::create_container(QString button_name,
                                              int     box_breadth,
                                              int     box_length,
                                              int     box_height,
                                              int     box_weight,
                                              int     cyl_diameter,
                                              int     cyl_height,
                                              int     cyl_weight)
{
    if(button_name == "BoxButton")
    {
        if(box_container_counter == 9999)
        {
            box_container_counter = 0;
        }

        int box_volume = box_length*box_breadth*box_height;

        QString box_code = QString("%1/%2/B").arg(QString::number(QDate::currentDate().year()),
                                                  QDate::currentDate().toString("MM"))
                                                + QString::number(++box_container_counter);

        return new Box(box_height, box_weight, box_volume, box_code, box_breadth, box_length);
    }
    else if (button_name == "CylinderButton")
    {
        if(cyl_container_counter == 9999)
        {
            cyl_container_counter = 0;
        }

        int cyl_volume = static_cast<int>(M_PI*std::pow(cyl_diameter/2.0,2)*cyl_height);

        QString cyl_code = QString("%1/%2/C").arg(QString::number(QDate::currentDate().year()),
                                                  QDate::currentDate().toString("MM"))
                                                + QString::number(++cyl_container_counter);

        return new Cylinder(cyl_height, cyl_weight, cyl_volume, cyl_code, cyl_diameter);
    }
    else
    {
        return nullptr;
    }
}

#include "box.h"

#include <QDate>

Box::Box(int height, int weight, int volume, QString code, int breadth, int length)
    :Container(height, weight, volume, code),
     m_breadth(breadth),
     m_length(length)
{}

int Box::get_breadth() const
{
    return m_breadth;
}

void Box::set_breadth(int breadth)
{
    m_breadth = breadth;
}

int Box::get_length() const
{
    return m_length;
}

void Box::set_length(int length)
{
    m_length = length;
}


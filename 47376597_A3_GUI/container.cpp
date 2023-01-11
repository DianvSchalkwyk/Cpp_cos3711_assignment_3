#include "container.h"

#include <QDate>

Container::Container(QObject *parent)
          :QObject{parent}
{}

Container::Container(int height, int weight, int volume, QString code)
          :m_height(height),
           m_weight(weight),
           m_volume(volume),
           m_code  (code)
{}

int Container::get_height() const
{
    return m_height;
}

void Container::set_height(int height)
{
    m_height = height;
}

int Container::get_weight() const
{
    return m_weight;
}

void Container::set_weight(int weight)
{
    m_weight = weight;
}

int Container::get_volume() const
{
    return m_volume;
}

void Container::set_volume(int volume)
{
    m_volume = volume;
}


QString Container::get_code() const
{
    return m_code;
}

void Container::set_code(QString code)
{
    m_code = code;
}

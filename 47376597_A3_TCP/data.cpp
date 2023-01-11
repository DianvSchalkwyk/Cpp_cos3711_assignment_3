#include "data.h"

Data::Data(){}

int Data::get_pallet_number() const
{
    return m_pallet_number;
}

void Data::set_pallet_number(int number)
{
    m_pallet_number = number;
}

QString Data::get_container_type() const
{
    return m_container_type;
}

void Data::set_container_type(QString type)
{
    m_container_type = type;
}

QString Data::get_container_code() const
{
    return m_container_code;
}

void Data::set_container_code(QString code)
{
    m_container_code = code;
}

int Data::get_container_height() const
{
    return m_container_height;
}

void Data::set_container_height(int height)
{
    m_container_height = height;
}

int Data::get_container_brea_diam() const
{
    return m_container_brea_diam;
}

void Data::set_container_brea_diam(int newContainer_brea_diam)
{
    m_container_brea_diam = newContainer_brea_diam;
}

int Data::get_container_length() const
{
    return m_container_length;
}

void Data::set_container_length(int newContainer_length)
{
    m_container_length = newContainer_length;
}

int Data::get_container_weight() const
{
    return m_container_weight;
}

void Data::set_container_weight(int weight)
{
    m_container_weight = weight;
}

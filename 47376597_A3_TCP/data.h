#ifndef DATA_H
#define DATA_H

#include <QString>

class Data
{
public:

    Data();

    int     get_pallet_number() const;
    void    set_pallet_number(int number);

    QString get_container_type() const;
    void    set_container_type(QString type);

    QString get_container_code() const;
    void    set_container_code(QString code);

    int     get_container_height() const;
    void    set_container_height(int height);

    int     get_container_brea_diam() const;
    void    set_container_brea_diam(int brea_diam);

    int     get_container_length() const;
    void    set_container_length(int length);

    int     get_container_weight() const;
    void    set_container_weight(int weight);

private:

    int     m_pallet_number       = 0;
    QString m_container_type      = "";
    QString m_container_code      = "";
    int     m_container_height    = 0;
    int     m_container_brea_diam = 0;
    int     m_container_length    = 0;
    int     m_container_weight    = 0;

};

#endif // DATA_H

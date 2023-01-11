#ifndef CONTAINER_H
#define CONTAINER_H

#include <QObject>

class Container : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString code   READ get_code   WRITE set_code  )
    Q_PROPERTY(int     weight READ get_weight WRITE set_weight)
    Q_PROPERTY(int     volume READ get_volume WRITE set_volume)
    Q_PROPERTY(int     height READ get_height WRITE set_height)

public:

    Container(QObject *parent = nullptr);

    Container(int height, int weight, int volume, QString code);

    int  get_height() const;
    void set_height(int height);

    int  get_weight() const;
    void set_weight(int weight);

    int  get_volume() const;
    void set_volume(int volume);

    QString get_code()   const;
    void    set_code(QString code);

private:

    int     m_height;
    int     m_weight;
    int     m_volume;
    QString m_code;
};

#endif // CONTAINER_H

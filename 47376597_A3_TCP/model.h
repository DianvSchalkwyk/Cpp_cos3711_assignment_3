#ifndef MODEL_H
#define MODEL_H

#include "data.h"
#include "qregularexpression.h"
#include <QAbstractTableModel>

class Model:public QAbstractTableModel
{

public:

    Model();
    ~Model();

    int rowCount   (const QModelIndex &parent)const;
    int columnCount(const QModelIndex &parent)const;

    QVariant data(const QModelIndex &index,int role = Qt::DisplayRole) const;

    QVariant headerData(int section,Qt::Orientation orientation,int role=Qt::DisplayRole) const;

    void insert_row();

    void clear_model();

    const QList<Data *> &get_data_list() const;
    void set_data_list(const QList<Data *> &data_list);

private:

    QList<Data*> xml_data_list;

    QRegularExpression required_layout;
};

#endif // MODEL_H

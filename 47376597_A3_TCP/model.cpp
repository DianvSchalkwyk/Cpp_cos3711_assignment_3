#include "model.h"

Model::Model()
      :required_layout("20\\d\\d/(0?[1-9]|[1][0-2])/([B]|[C])[\\d]{1,4}")
{}

Model::~Model()
{
    qDeleteAll(xml_data_list);
}

int Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return xml_data_list.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 7;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    int column_number  = index.column();
    int row_number     = index.row();

    if(!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::DisplayRole)
    {
        QRegularExpressionMatch correct_code = required_layout.match(xml_data_list.at(row_number)->get_container_code());

        switch(column_number)
        {
            case 0:
                return xml_data_list.at(row_number)->get_pallet_number();
                break;
            case 1:
                return xml_data_list.at(row_number)->get_container_type();
                break;
            case 2:
                if(correct_code.hasMatch())
                {
                    return xml_data_list.at(row_number)->get_container_code();
                    break;
                }
                else
                {
                    return "****";
                }

            case 3:
                return xml_data_list.at(row_number)->get_container_height();
                break;
            case 4:
                return xml_data_list.at(row_number)->get_container_brea_diam();
                break;
            case 5:
                if(xml_data_list.at(row_number)->get_container_type() == "Cylinder")
                {
                    return "-";
                    break;
                }
                else
                {
                    return xml_data_list.at(row_number)->get_container_length();
                    break;
                }
            case 6:
                return xml_data_list.at(row_number)->get_container_weight();
                break;
            default:
                return QVariant();
        }
    }

    return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return QString("PALLET");
            break;
        case 1:
            return QString("CONTAINER");
            break;
        case 2:
            return QString("CODE");
            break;
        case 3:
            return QString("HEIGHT");
            break;
        case 4:
            return QString("BR/DIA");
            break;
        case 5:
            return QString("LENGTH");
            break;
        case 6:
            return QString("WEIGHT");
            break;
        default:
            return QVariant();
        }
    }

    return ++section;
}

void Model::insert_row()
{
    int row_count = xml_data_list.count();

    for(int i = 0; i < row_count; i++)
    {
        beginInsertRows(QModelIndex(), row_count, row_count);

        xml_data_list.append(xml_data_list.at(i));

        endInsertRows();
    }
}

void Model::clear_model()
{
    int model_rows = xml_data_list.size();

    beginResetModel();

    xml_data_list.clear();

    if(model_rows > 0)
    {
        beginRemoveRows(QModelIndex(), 0, model_rows-1);
        endRemoveRows();
    }

    endResetModel();
}

const QList<Data *> &Model::get_data_list() const
{
    return xml_data_list;
}

void Model::set_data_list(const QList<Data *> &data_list)
{
    xml_data_list = data_list;
}



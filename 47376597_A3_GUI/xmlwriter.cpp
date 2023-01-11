#include "xmlwriter.h"
#include "container.h"

#include <QDomDocument>
#include <QDomElement>
#include <QMetaObject>
#include <QMetaProperty>

XmlWriter::XmlWriter(){}

void XmlWriter::get_xml_list(PalletList *pallet_list)
{
    QDomDocument document;

    QDomElement root_element = document.createElement("pallets");

    document.appendChild(root_element);

    for(int i = 0; i < pallet_list->get_size(); i++)
    {
        Pallet *new_pallet = pallet_list->get_pallet(i);

        QDomElement pallet_element = document.createElement("pallet");

        pallet_element.setAttribute("weight", new_pallet->get_pallet_weight());
        pallet_element.setAttribute("volume", new_pallet->get_pallet_volume());
        pallet_element.setAttribute("number", new_pallet->get_pallet_number());

        root_element.appendChild(pallet_element);

        for(int j = 0; j < new_pallet->get_size(); j++)
        {
            Container *new_container = new_pallet->get_container(j);

            QString new_container_name = QString(new_container->metaObject()->className());

            QDomElement container_element = document.createElement(new_container_name);

            pallet_element.appendChild(container_element);

            for(int k = 1; k < new_container->metaObject()->propertyCount(); k++)
            {
                QMetaProperty property = new_container->metaObject()->property(k);

                QString property_name = QString(property.name());

                QString property_value = QString(property.read(new_container).toString());

                QDomElement container_property_element = document.createElement(property_name);

                QDomText container_property_value = document.createTextNode(property_value);

                container_property_element.appendChild(container_property_value);

                container_element.appendChild(container_property_element);
            }
        }
    }
    emit xml_list_completed(document.toString());
}

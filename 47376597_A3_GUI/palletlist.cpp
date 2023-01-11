#include "palletlist.h"

PalletList::PalletList(){}

PalletList::~PalletList(){}

void PalletList::add_pallet(Pallet *pallet)
{
    for(int i = 0; i < m_pallet_list.size(); i++)
    {
        if(m_pallet_list[i]->get_pallet_number() == pallet->get_pallet_number())
        {
            m_pallet_list.at(i)->add_container(pallet->get_container(0));
        }
    }

    if(pallet!=nullptr)
    {
        m_pallet_list.append(pallet);
    }
}

int PalletList::get_size()
{
    return m_pallet_list.size();
}

Pallet *PalletList::get_pallet(int index)
{
    return m_pallet_list.at(index);
}

void PalletList::clear()
{
    m_pallet_list.clear();
}

void PalletList::set_pallet_list(PalletList *pallet_list)
{
    m_pallet_list = pallet_list->m_pallet_list;
}

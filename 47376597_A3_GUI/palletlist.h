#ifndef PALLETLIST_H
#define PALLETLIST_H

#include "pallet.h"
#include <QObject>

class PalletList : public QObject
{
    Q_OBJECT

public:

    PalletList();
    ~PalletList();

    void add_pallet(Pallet *pallet);

    int get_size();

    Pallet *get_pallet(int index);

    void clear();

    void set_pallet_list(PalletList *pallet_list);

private:

    QList<Pallet*> m_pallet_list;

};

#endif // PALLETLIST_H

#ifndef XMLWRITER_H
#define XMLWRITER_H

#include "palletlist.h"
//#include "qthread.h"

class XmlWriter : public QObject
{

    Q_OBJECT

public:

    XmlWriter();

public slots:

        void get_xml_list(PalletList *pallet_list);

signals:

    void xml_list_completed(QString xml_list_QString);
};

#endif // XMLWRITER_H

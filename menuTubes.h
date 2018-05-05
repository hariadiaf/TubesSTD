#ifndef MENUTUBES_H_INCLUDED
#define MENUTUBES_H_INCLUDED
#include "libEvent.h"
#include "libSponsor.h"
#include "listRelasi.h"
void menuUtama(ListEvent Levent, ListChild Lsponsor, List_relasi Lrelasi);
void MenuSponsor(ListChild &Lsponsor, List_relasi &Lrelasi);
void menuEvent(ListEvent &L, List_relasi &Lrelasi);
void menuRelasi(ListEvent &Levent, ListChild &Lsponsor, List_relasi &Lrelasi);
void olahData(ListEvent &Levent,ListChild &Lsponsor, List_relasi &Lrelasi,
              address_parent P, address_child C,string grade,int persen);


#endif // MENUTUBES_H_INCLUDED

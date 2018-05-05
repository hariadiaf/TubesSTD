#include "libSponsor.h"
#include "libEvent.h"
#include "listRelasi.h"
#include "menuTubes.h"

int main()
{
    ListEvent Levent;
    ListChild Lsponsor;
    List_relasi Lrelasi;
    createChild(Lsponsor);
    createListEvent(Levent);
    createListRelasi(Lrelasi);

    menuUtama(Levent,Lsponsor,Lrelasi);

   /*   ListEvent Levent;
    createChild(Lsponsor);
    createListEvent(Levent);
    menuEvent(Levent);
    MenuSponsor(Lsponsor);
*/
    return 0;
}

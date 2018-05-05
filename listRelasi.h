#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED
#include "libSponsor.h"
#include "libEvent.h"
#include <iostream>
#define first(L) L.first
#define prev(P) P->prev
#define info(P) P->info
#define next(P) P->next
#define child(P) P->child
#define parent(P) P->parent

using namespace std;

typedef struct elmRelasi *address_relasi;
struct relasi{
    string grade;
    long gradeBudget;
};
typedef relasi infotypeR;
struct elmRelasi{
    infotypeR info;
    address_relasi next;
    address_relasi prev;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
};

void createListRelasi(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(List_relasi &L,address_relasi Prec, address_relasi &P);
address_relasi alokasi(address_parent P, address_child C,infotypeR x);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_parent P, address_child C);
void printInfo(List_relasi L);
void deleteData(List_relasi &Lrelasi,address_relasi &P);


#endif // LISTRELASI_H_INCLUDED

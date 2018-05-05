#ifndef LIBEVENT_H_INCLUDED
#define LIBEVENT_H_INCLUDED
#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct event{
    string nameEvent;
    long needBudget;
    long minusBudget;
    long plusBudget;
    int counter;
};
typedef event infotypes;
typedef struct elmListEvent *address_parent;

struct elmListEvent{
    infotypes info;
    address_parent next;
};

struct ListEvent{
    address_parent first;
    address_parent last;
};

void createListEvent(ListEvent &L);
address_parent alokasiEvent(infotypes x);
void dealokasiEvent(address_parent &P);
bool isEmptyList(ListEvent L);
void insertFirstEvent(ListEvent &L, address_parent P);
void insertAfterEvent(ListEvent &L, address_parent P, address_parent Prec);
void insertLastEvent(ListEvent &L, address_parent P);
void deleteFirstEvent(ListEvent &L, address_parent &P);
void deleteAfterEvent(ListEvent &L, address_parent &P, address_parent Prec);
void deleteLastEvent(ListEvent &L, address_parent &P);
address_parent cariEvent(ListEvent L, string namaEv);
void showEvent(ListEvent &L);
void tengah1(int lebar, char* q);
void tambahEvent(ListEvent &L);
void hapusEvent(ListEvent &L, string namaEv, address_parent &P);
#endif // LIBEVENT_H_INCLUDED

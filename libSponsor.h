#ifndef LIBSPONSOR_H_INCLUDED
#define LIBSPONSOR_H_INCLUDED
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#define info(P) P->info
#define next(P) P->next
#define first(L) L.first

using namespace std;

struct sponsor{
    string namaSponsor;
    long budget,sisaBudget;
    int counter;
};

typedef sponsor infotype;
typedef struct elmChild *address_child;

struct elmChild{
    infotype info;
    address_child next;
};

struct ListChild{
    address_child first;
};

void createChild(ListChild &L);
address_child alokasi(infotype x);
void dealokasi(address_child &P);
void insertFirst(ListChild &L, address_child P);
void insertAfter(ListChild &L, address_child P, address_child Prec);
void insertLast(ListChild &L, address_child P);
void deleteFirst(ListChild &L, address_child P);
void deleteAfter(ListChild &L, address_child P, address_child Prec);
void deleteLast(ListChild &L, address_child P);
address_child cariSponsor(ListChild L, string namaSpo);
void show(ListChild &L);
void tengah2(int width, char* s);
void deleteData(ListChild &L, string namaSpo,address_child &P);
void insertData(ListChild &L);



#endif // LIBSPONSOR_H_INCLUDED

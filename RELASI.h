#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "Mobil.h"
#include <iostream>
using namespace std;

#define info_relasi(P) P->info_relasi
#define next_relasi(P) P->next_relasi
#define prev_relasi(P) P->prev_relasi
#define first_relasi(L) L.first_relasi
#define last_relasi(L) L.last_relasi

typedef struct elmlist_relasi *addressRelasi;
struct elmlist_relasi{
    addressRelasi next_relasi;
    addressRelasi prev_relasi;


};
struct List_relasi{
    addressRelasi first_relasi;
    addressRelasi last_relasi;
};

void createListRelasi(List_relasi &L);
addressRelasi alokasi_relasi(addressMobil P, );
void dealokasi_relasi(addressRelasi &P);
void insertLastRelasi(List_relasi &L, addressRelasi P);
void printRelasi(List_relasi L);
void deleteRelasi(List_relasi &L, addressRelasi &P);


#endif // RELASI_H_INCLUDED

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


typedef struct elmlistRelasi *addressRelasi;

struct elmlistRelasi{
    addressMobil parent;
    addrChild child;
    addressRelasi next;
};

struct listRelasi{
    addressRelasi first;
    addressRelasi last;
};

addressRelasi alokasi_Relasti(addressMobil P,addrChild Q);
void createListRelasi(addressRelasi &L);
void insertFirstRelasi(addressRelasi &L, addressRelasi P);
void insertLastRelasi(addressRelasi &L, addressRelasi P);
void insertAfterRelasi(addressRelasi Prec, addressRelasi P);
void deleteFirstRelasi(addressRelasi &L, addressRelasi &P);
void deleteLastRelasi(addressRelasi &L, addressRelasi &P);
void deleteAfterRelasi(addressRelasi Prec, addressRelasi &P);
void checkConnection(List_relasi L,ListChild L2,List_mobil L3,string X, int Y);


#endif // RELASI_H_INCLUDED

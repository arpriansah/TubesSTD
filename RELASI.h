#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "Mobil.h"
#include "List_Child.h"
#include <iostream>
using namespace std;



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

addressRelasi alokasi_Relasi(addressMobil P,addrChild Q);
void createListRelasi(listRelasi &L);
void dealokasiRelasi(addressRelasi &P);
void insertFirstRelasi(listRelasi &L, addressRelasi P);
void insertLastRelasi(listRelasi &L, addressRelasi P);
void insertAfterRelasi(addressRelasi Prec, addressRelasi P);
void deleteFirstRelasi(listRelasi &L, addressRelasi &P);
void deleteLastRelasi(listRelasi &L, addressRelasi &P);
void deleteAfterRelasi(addressRelasi Prec, addressRelasi &P);
addressRelasi checkConnection(listRelasi L,ListChild L2,List_mobil L3,int X, int Y);
void Connection(listRelasi &L,ListChild L2,List_mobil L3,int X, int Y);
void disconnect(listRelasi &L,ListChild L2,List_mobil L3,int X, int Y);
void Delete_Child(listRelasi &L,ListChild &L2,int X);
void Delete_Parent(listRelasi &L,List_mobil &L2,int X);
void printRelasi(listRelasi L);
void Total_Keuntungan_case1(listRelasi L,List_mobil L2,int &x);


#endif // RELASI_H_INCLUDED

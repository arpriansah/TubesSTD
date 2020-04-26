// Nama :   Arpriansah Yonathan
// NIM  :   1301194112
#ifndef MLL_TUBES_STD_H_INCLUDED
#define MLL_TUBES_STD_H_INCLUDED
#include <iostream>
#define first_mobil(L) L.first_mobil
#define next_mobil(P) P->next_mobil
#define info_mobil(P) P->info_mobil

using namespace std;

typedef struct elmlist_mobil *addressMobil;
struct infotype{
    int IDmobil;
    string jenis_mobil;
    string nama_mobil;
    string kondisi_mobil;
    int hargaRental;
};
struct elmlist_mobil{
    infotype info_mobil;
    addressMobil next_mobil;
};
struct List_mobil{
    addressMobil first_mobil;
};

addressMobil alokasi_mobil(infotype x);
void dealokasi_mobil(addressMobil &P);
void createListMobil(List_mobil &L);
void insertFirstMobil(List_mobil &L, addressMobil P);
void insertAfterMobil(List_mobil &L, addressMobil Prec, addressMobil P);
void insertLastMobil(List_mobil &L, addressMobil P);
void deleteFirstMobil(List_mobil &L, addressMobil &P);
void deleteAfterMobil(List_mobil &L, addressMobil Prec, addressMobil &P);
void deleteLastMobil(List_mobil &L, addressMobil &P);
addressMobil searchByID(List_mobil L, int x);
void printInfo_mobil(List_mobil L);

#endif // MLL_TUBES_STD_H_INCLUDED

// Nama : Arpriansah Yonathan
// NIM  : 1301194112
#include <iostream>
#include "Mobil.h"

using namespace std;

addressMobil alokasi_mobil(infotype x){
    addressMobil P = new elmlist_mobil;
    info_mobil(P) = x;
    next_mobil(P) = NULL;
    return P;
}

void dealokasi_mobil(addressMobil &P){
    delete P;
}

void createListMobil(List_mobil &L){
    first_mobil(L) = NULL;
}

void insertFirstMobil(List_mobil &L, addressMobil P){
    if(first_mobil(L) == NULL){
        first_mobil(L) = P;
    }else{
        next_mobil(P) = first_mobil(L);
        first_mobil(L) = P;
    }
}

void insertAfterMobil(List_mobil &L, addressMobil Prec, addressMobil &P){
    if(Prec != NULL){
        if(next_mobil(Prec) == NULL){
            insertLastMobil(L, P);
        }else{
            next_mobil(P) = next_mobil(Prec);
            next_mobil(Prec) = P;
        }
    }
}

void insertLastMobil(List_mobil &L, addressMobil P){
    if(first_mobil(L) == NULL){
        insertFirstMobil(L, P);
    }else{
        addressMobil Q = first_mobil(L);
        while(next_mobil(Q) != NULL){
            Q = next_mobil(Q);
        }
        next_mobil(Q) = P;
    }
}

void deleteFirstMobil(List_mobil &L, addressMobil &P){
    if(first_mobil(L) == NULL){
        cout << "Data Tidak Ada" << endl;
    }else{
        if(next_mobil(first_mobil(L)) == NULL){
            P = first_mobil(L);
            first_mobil(L) = NULL;
        }else{
            P = first_mobil(L);
            first_mobil(L) = next_mobil(P);
            next_mobil(P) = NULL;
        }
    }
}

void deleteAfterMobil(List_mobil &L, addressMobil Prec, addressMobil &P){
    if(Prec != NULL){
        if(next_mobil(next_mobil(Prec)) == NULL){
            deleteLastMobil(L, P);
        }else{
            addressMobil Q = next_mobil(P);
            next_mobil(Prec) = Q;
            next_mobil(P) = NULL;
        }
    }
}

void deleteLastMobil(List_mobil &L, addressMobil &P){
    if(first_mobil(L) != NULL){
        if(next_mobil(first_mobil(L)) == NULL){
            P = first_mobil(L);
            first_mobil(L) = NULL;
        }else{
            addressMobil Q = first_mobil(L);
            while(next_mobil(next_mobil(Q)) != NULL){
                Q = next_mobil(Q);
            }
            P = next_mobil(Q);
            next_mobil(Q) = NULL;
        }
    }
}

addressMobil searchByID(List_mobil L, int x){
    addressMobil P = first_mobil(L);
    while(P != NULL){
        if(x == info_mobil(P).IDmobil){
            return P;
        }
        P = next_mobil(P);
    }
    return NULL;
}

void printInfo_mobil(List_mobil L){
    addressMobil P;
    if(first_mobil(L) == NULL){
        cout << "Tidak Ada Mobil" << endl;
    }else{
        P = first_mobil(L);
        do{
            cout << P->info_mobil.IDmobil << "\n" << P->info_mobil.jenis_mobil << "\n" << P->info_mobil.nama_mobil << "\n" << P->info_mobil.kondisi_mobil << "\n"<<"Rp." << P->info_mobil.hargaRental << "\n" << endl;
            P =P->next_mobil;
        }while(P != NULL);
    }
}

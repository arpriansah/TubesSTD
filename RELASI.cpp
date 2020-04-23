#include <iostream>
#include "RELASI.h"

using namespace std;

void createListRelasi(List_relasi &L){
    first_relasi(L) = NULL;
    last_relasi(L) = NULL;
}

addressRelasi alokasi_relasi(addressMobil P, ){
    addressRelasi P = new elmlist_relasi;


    next_relasi(P) = NULL;
}

void dealokasi_relasi(addressRelasi &P){
    delete P;
}

void insertLastRelasi(List_relasi &L, addressRelasi P){
    if(first_relasi(L) == NULL){
        first_relasi(L) = P;
        next_relasi(first_relasi(L)) = first_relasi(L);
        prev_relasi(first_relasi(L)) = first_relasi(L);
    }else{
        addressRelasi Q = prev_relasi(first_relasi(L));
        prev_relasi(P) = Q;
        prev_relasi(first_relasi(L)) = P;
        next_relasi(P) = first_relasi(L);
        next_relasi(Q) = P;
        last_relasi(L) = P;
    }
}

void printRelasi(List_relasi L){
    addressRelasi P;
    if(first_relasi(L) == NULL){
        cout << "Tidak Ada Data" << endl;
    }else{
        P = first_relasi(L);
        do{
            cout << << endl;
            P = next_relasi(P);
        }while(P != first_relasi(L));
        cout << endl;
    }
}

void deleteRelasi(List_relasi &L, addressRelasi &P){
    if(first_relasi(L) != NULL){
        addressRelasi Q = first_relasi(L);
        if(next_relasi(first_relasi(L)) == first_relasi(L)){
            first_relasi(L) = NULL;
            last_relasi(L) = NULL;
            next_relasi(L) = NULL;
            prev_relasi(L) = NULL;
        }else if(P == first_relasi(L) && next_relasi(P) != first_relasi(L)){
            Q = next_relasi(P);
            first_relasi(L) = Q;
            next_relasi(last_relasi(L)) = Q;
            prev_relasi(Q) = last_relasi(L);
            next_relasi(P) = NULL;
            prev_relasi(P) = NULL;
        }else if(P == last_relasi(L)){
            Q = prev_relasi(P);
            next_relasi(Q) = first_relasi(L);
            prev_relasi(first_relasi(L)) = Q;
            next_relasi(P) = NULL;
            prev_relasi(P) = NULL;
            last_relasi(L) = Q;
        }else{
            Q = next_relasi(P);
            addressRelasi R = prev_relasi(P);
            next_relasi(R) = Q;
            prev_relasi(Q) = R;
            next_relasi(P) = NULL;
            prev_relasi(P) = NULL;
        }
    }
}


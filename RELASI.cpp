#include "RELASI.h"

void createListRelasi(addressRelasi &L){
    L.first =NULL;
    L.last = NULL;
}

addressRelasi alokasi_Relasti(addressMobil P,addrChild Q){
    addressRelasi R = new elmlistRelasi;
    R -> parent = P;
    R -> child = Q;
    R -> next =NULL;
}
void insertFirstRelasi(addressRelasi &L, addressRelasi P){
    if (L.first == NULL){
        L.first = P;
        L.last = P:
    }else {
        P->next= L.first;
        L.first = P;
}
void insertLastRelasi(addressRelasi &L, addressRelasi P){
    if (L.first == NULL){
        L.first = P;
        L.last = P:
    }else {
        L.last->next =P;
        L.last =P;
    }
}
void insertAfterRelasi(addressRelasi Prec, addressRelasi P){
    P = Prec->next;
    Prec->next = P;
}
void deleteFirstRelasi(addressRelasi &L, addressRelasi &P){
    P =L.first;
    if(L.first->next !=NULL){

    L.first = P->next;
    P->next= NULL
    else{
        L.first = NULL
    }
}
void deleteLastRelasi(addressRelasi &L, addressRelasi &P){
    addressRelasi temp =L.first;
    P =L.last;
    while (temp->next != L.last){
        temp = temp->next;
    }
    L.last = temp;
    L.last->next =NULL;

}
void deleteAfterRelasi(addressrelasi Prec, addressrelasi &P){
    P= Prec->next;
    Prec->next = P->next;
    P->next =NULL;
}

void checkConnection(List_relasi L,ListChild L2,List_mobil L3,string X, int Y){
    addrChild Q, addressMobil R;
    Q=searchByID(L2,X);
    R=searchByID(L3,Y);
    addressRelasi P = L.first_relasi;
    while ( P!=NULL ){
        if(P.Parent== Q  && P.Child == R){
            return P;
        }
        P = P->next;
    }
}

void Connection(){
}

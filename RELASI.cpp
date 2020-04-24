#include "RELASI.h"

void createListRelasi(listRelasi &L){
    L.first =NULL;
    L.last = NULL;
}

addressRelasi alokasi_Relasi(addressMobil P,addrChild Q){
    addressRelasi R = new elmlistRelasi;
    R -> parent = P;
    R -> child = Q;
    R -> next =NULL;
    return R;
}
void insertFirstRelasi(listRelasi &L, addressRelasi P){
    if (L.first == NULL){
        L.first = P;
        L.last = P;
    }else {
        P->next= L.first;
        L.first = P;
    }
}
void insertLastRelasi(listRelasi &L, addressRelasi P){
    if (L.first == NULL){
        L.first = P;
        L.last = P;
    }else {
        L.last->next =P;
        L.last =P;
    }
}
void insertAfterRelasi(addressRelasi Prec, addressRelasi P){
    P = Prec->next ;
    Prec->next = P;
}
void deleteFirstRelasi(listRelasi&L, addressRelasi &P){
    P =L.first;
    P->child =NULL;
    P->parent =NULL;
    if(L.first->next !=NULL){

    L.first = P->next;
    P->next= NULL;
    }else{
        L.first = NULL;
    }
}
void deleteLastRelasi(listRelasi &L, addressRelasi &P){
    addressRelasi temp =L.first;
    P =L.last;
    P->child =NULL;
    P->parent =NULL;
    while (temp->next != L.last){
        temp = temp->next;
    }
    L.last = temp;
    L.last->next =NULL;
}
void deleteAfterRelasi(addressRelasi Prec, addressRelasi &P){
    P= Prec->next;
    P->child =NULL;
    P->parent =NULL;
    Prec->next = P->next;
    P->next =NULL;
}

addressRelasi checkConnection(listRelasi L,ListChild L2,List_mobil L3,int X, int Y){
    addressMobil Q=searchByID(L3,X);
    addrChild R=searchByID_Child(L2,Y);
    addressRelasi P = L.first;
    while ( P!=NULL ){
        if(P->parent== Q  && P->child == R){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void Connection(listRelasi &L,ListChild L2,List_mobil L3,int X, int Y){
    addressMobil P =searchByID(L3,Y);
    addrChild Q = searchByID_Child(L2,X);
    insertLastRelasi(L,alokasi_Relasi(P,Q));
}

void disconnect(listRelasi &L,ListChild L2,List_mobil L3,int X, int Y){
    addressMobil P =searchByID(L3,Y);
    addrChild Q = searchByID_Child(L2,X);
    addressRelasi R = L.first;
    if ( R->parent == P && R->child == Q){
        deleteFirstRelasi(L,R);
    }else {
    while (R != NULL && R->next->parent != P && R->next->child != Q){
        R =R->next;
    }
    if (R->next == L.last){
        deleteLastRelasi(L,R);
    }else{
        deleteAfterRelasi(R,R->next);
    }
    }
}

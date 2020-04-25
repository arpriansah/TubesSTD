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

void dealokasiRelasi(addressRelasi &P){
    delete P;
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
    while (temp->next != L.last){
        temp = temp->next;
    }
    L.last = temp;
    L.last->next =NULL;
}
void deleteAfterRelasi(addressRelasi Prec, addressRelasi &P){
    P= Prec->next;
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
    addressRelasi R = L.first,S;
    if (P != NULL && Q != NULL){
    if ( R->parent == P && R->child == Q){
        R->child =NULL;
        R->parent =NULL;
        deleteFirstRelasi(L,R);
    }else {
    while (R != NULL && R->next->parent != P && R->next->child != Q){
        R =R->next;
    }
    if (R->next == L.last){
        R->next->child =NULL;
        R->next->parent =NULL;
        deleteLastRelasi(L,R);
    }else{
        R->child =NULL;
        R->parent =NULL;
        S = R;
        R = R->next;
        deleteAfterRelasi(S,R);

    }
    dealokasiRelasi(R);
    }
    }
}


void Delete_Child(listRelasi &L,ListChild &L2,int X){
    addrChild Q = searchByID_Child(L2,X);
    addressRelasi R = L.first,S;
    if(Q != NULL){

    if(R->child == Q){
        deleteFirstRelasi(L,R);
    }
    while (R != NULL && R->next->child != Q){
        R =R->next;
    }
    if (R->next == L.last){
        R->next->child =NULL;
        R->next->parent =NULL;
        deleteLastRelasi(L,R);
    }else {
        S = R;
        R = R->next;
        R->child =NULL;
        R->parent =NULL;

        deleteAfterRelasi(S,R);
    }
    dealokasiRelasi(R);

    if (Q != NULL){
        if(Q == L2.first){
            deleteFirst(L2,Q);
        }else if (Q == L2.first){
            deleteLast(L2,Q);
        }else{
            deleteAfter(L2,Q->prev,Q);
        }
    }
    }
}

void Delete_Parent(listRelasi &L,List_mobil &L2,int X){
    addressMobil Q = searchByID(L2,X),P;
    addressRelasi R = L.first,S;
    if(Q != NULL){

    if(R->parent == Q){
        deleteFirstRelasi(L,R);
    }
    while (R != NULL && R->next->parent != Q){
        R =R->next;
    }
    if (R->next == L.last){
        R->next->child =NULL;
        R->next->parent =NULL;
        deleteLastRelasi(L,R);
    }else {
        S = R;
        R = R->next;
        R->child =NULL;
        R->parent =NULL;
        deleteAfterRelasi(S,R);
    }
    dealokasiRelasi(R);

    if (Q != NULL){
        if(Q == L2.first_mobil){
            deleteFirstMobil(L2,P);
        }else if (Q == L2.first_mobil){
            deleteLastMobil(L2,Q);
        }else{
            P = L2.first_mobil;
            while (P->next_mobil !=Q ){
                P->next_mobil;
            }
            deleteAfterMobil(L2,P,Q);
        }
        dealokasi_mobil(Q);
    }
    }
}

void printRelasi(listRelasi L){
    addressRelasi P;
    if(first_relasi(L) == NULL){
        cout << "*================================*" << endl;
        cout << "* Daftar Mobil yang Telah Disewa *" << endl;
        cout << "*================================*" << endl;
        cout << "         Tidak ada mobil" << endl;
    }else{
        cout << "*================================*" << endl;
        cout << "* Daftar Mobil yang Telah Disewa *" << endl;
        cout << "*================================*" << endl;
        P = first_relasi(L);
        do{
            cout << " ID Mobil       : " << P->parent->info_mobil.IDmobil << endl;
            cout << " Jenis Mobil    : " << P->parent->info_mobil.jenis_mobil << endl;
            cout << " Nama Mobil     : " << P->parent->info_mobil.nama_mobil << endl;
            cout << " Kondisi Mobil  : " << P->parent->info_mobil.kondisi_mobil << endl;
            cout << " ID Penyewa     : " << P->child->info.ID << endl;
            cout << " Nama Penyewa   : " << P->child->info.Nama << endl;
            cout << " NIK            : " << P->child->info.NIK << endl;
            cout << " Tanggal Lahir  : " << P->child->info.TglLahir << endl;
            cout << " Alamat Penyewa : " << P->child->info.Alamat << endl;
            cout << " No. Telpon     : " << P->child->info.NoTlp << endl;
            cout << endl;
            P = next_relasi(P);
        }while(next_relasi(P) != NULL);
        cout << "*================================*" << endl;
        cout << endl;
    }
}

#include "List_Child.h"

void cleared() {
    system("cls");
}

void createList(ListChild &L)
{
    L.first = NULL;
}


addrChild createNewElmt(infoType_Child X)
{
    addrChild P = new elmList;
    P->info.ID=X.ID;
    P->info.Nama=X.Nama;
    P->info.Alamat=X.Alamat;
    P->info.NoTlp=X.NoTlp;
    P->info.TglLahir=X.TglLahir;
    P->info.NIK=X.NIK;
    P->next=NULL;
    P->prev=NULL;
    return P;
}

void dealokasi_Child(addrChild &P){
    delete P;
}

void insertFirst(ListChild &L,addrChild P){
    if(L.first != NULL){
        P->next=L.first;
        P->prev=L.first->prev;
        L.first->prev->next=P;
        L.first->prev=P;
        L.first=P;
    }else{
        L.first=P;
        P->next=P;
        P->prev=P;
    }
}

void insertLast(ListChild &L,addrChild P){
    if (L.first !=NULL){
        P->next=L.first;
        P->prev=L.first->prev;
        L.first->prev->next=P;
        L.first->prev=P;
    }else {
        L.first=P;
        P->next=P;
        P->prev=P;
    }
}

void insertAfter(ListChild &L,addrChild Prec,addrChild P){
    P->next=Prec->next;
    P->prev=Prec;
    Prec->next->prev=P;
    Prec->next=P;
}

void deleteFirst(ListChild &L,addrChild &P){
    P = L.first;
    if (P->next != P){
        L.first = P->next;
        L.first->prev=P->prev;
        P->prev->next=L.first;
        P->next=NULL;
        P->prev=NULL;
    }else {
        L.first=NULL;
    }
}

void deleteLast(ListChild &L,addrChild &P){
    P = L.first->prev;
    if (P->next != P){
        L.first->prev=P->prev;
        P->prev->next=L.first;
        P->next=NULL;
        P->prev=NULL;
    }else {
        L.first=NULL;
    }
}

void deleteAfter(ListChild &L,addrChild &Prec,addrChild &P){
    P=Prec->next;
    if (Prec->next != L.first){
        Prec->next=P->next;
        P->next->prev=Prec;
        P->next=NULL;
        P->prev=NULL;
    }else if (Prec->next == L.first) {
        L.first= L.first->next;
        deleteAfter(L,Prec,P);
    }else if (Prec ->next == Prec){
        L.first=NULL;
    }
}

addrChild searchByID_Child(ListChild L,int x){
    addrChild P = L.first;
    while (P != NULL){
        if(P->info.NIK == x){
            return P;
        }
        P=P->next;
    }
    return NULL;
}

void printList(ListChild L){
    addrChild P=L.first;
    if (P!=NULL){
    do{
        cout<<"ID            :"<<P->info.ID<<endl;
        cout<<"Nama          :"<<P->info.Nama<<endl;
        cout<<"NIK           :"<<P->info.NIK<<endl;
        cout<<"Alamat        :"<<P->info.Alamat<<endl;
        cout<<"Tanggal Lahir :"<<P->info.TglLahir<<endl;
        cout<<"No.Telpon     :"<<P->info.NoTlp<<endl;
        P = P->next;
        cout<<endl;
    }while (P != L.first);
    }else {
        cout<<"List Kosong. . .";
    }
    cout<<endl;
}

void insertSorted(ListChild &L, infoType_Child X){
    addrChild P = createNewElmt(X);
    if (L.first == NULL || L.first->info.NIK > X.NIK){
        insertFirst(L,createNewElmt(X));
    }else{
        addrChild Q = L.first;
        while (Q != NULL && X.NIK < Q->info.NIK){
            Q = Q->next;
        }
        if (Q->next == L.first ){
            insertLast(L,createNewElmt(X));
        }else {
            insertAfter(L,Q,createNewElmt(X));
        }
    }
}

void deleteSorted(ListChild &L,int X){
    addrChild P = searchByID_Child(L,X);
    if (P != NULL){
        if(P == L.first){
            deleteFirst(L,P);
        }else if (P == L.first){
            deleteLast(L,P);
        }else{
            deleteAfter(L,P->prev,P);
        }
    }

}

void inputUserChild(ListChild &L, infoType_Child X){
    cout<<"Masukkan Nama Penyewa :\t ";
    cin.get();
    getline(cin,X.Nama);
    cout<<"Masukkan alamat Penyewa :\t ";
    cin.get();
    getline(cin,X.Alamat);
    cout<<"Masukkan NIK Penyewa :\t ";
    cin>>X.NIK;
    cout<<"Masukkan No. telfon Penyewa :\t ";
    cin>>X.NoTlp;
    cout<<"Masukkan tanggal lahir Penyewa :\t ";
    cin>>X.TglLahir;
    insertSorted(L,X);
}

#include "List_Child.h"


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
   if (L.first != NULL){
    do{
        if(P->info.ID == x){
            return P;
        }
        P=P->next;
    }while(P != L.first);

    return NULL;
   }else {
    return NULL;
   }
}

void printList(ListChild L){
    addrChild P=L.first;
    if (P!=NULL){
    do{
        cout<<"ID            :"<<P->info.ID<<endl;
        cout<<"Nama          :"<<P->info.Nama<<endl;
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
    if (L.first == NULL || L.first->info.ID > X.ID){
        insertFirst(L,createNewElmt(X));
    }else{
        addrChild Q = L.first->next;
        while (Q->next != L.first && X.ID > Q->info.ID){
            Q = Q->next;
        }
        if (Q->next == L.first &&  X.ID > Q->info.ID){
            insertLast(L,createNewElmt(X));
        }else {
            insertAfter(L,Q->prev,createNewElmt(X));
        }
    }
}

void delete_(ListChild &L,addrChild &P){
    if (P != NULL){
        if(P == L.first){
            deleteFirst(L,P);
        }else if (P->next == L.first){
            deleteLast(L,P);
        }else{
            deleteAfter(L,P->prev,P);
        }
        dealokasi_Child(P);
        cout<<endl;
        cout<<"Delete telah berhasil...";
    }

}

void inputUserChild(ListChild &L){
    infoType_Child X;
    cout<<"Masukkan NIK Penyewa            : ";
    cin>>X.ID;
    if(searchByID_Child(L,X.ID)== NULL){
        cout<<"Masukkan Nama Penyewa           : ";
        cin.get();
        getline(cin,X.Nama);
        cout<<"Masukkan No. telfon Penyewa     : ";
        cin>>X.NoTlp;
        cout<<"Masukkan alamat Penyewa         : ";
        cin.get();
        getline(cin,X.Alamat);
        cout<<"Masukkan tanggal lahir Penyewa  : ";
        cin>>X.TglLahir;
        insertSorted(L,X);
        cout<<endl;
        cout << "Data Penyewa telah terdaftar..." << endl;
    }else {
        cout<<endl;
        cout << "NIK telah terdaftar... Coba lagi" << endl;
    }

}

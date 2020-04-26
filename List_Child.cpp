#include "List_Child.h"


void createList(ListChild &L){
    /* Membuat L.first dengan isi NULL*/
    L.first = NULL;
}


addrChild createNewElmt(infoType_Child X){
    /* Membuat addressChild dengan isi info dari data penyewa dan mengembalikan addressChild */

    addrChild P = new elmList;
    P->info.ID=X.ID;
    P->info.Nama=X.Nama;
    P->info.Alamat=X.Alamat;
    P->info.NoTlp=X.NoTlp;
    P->info.tanggal_peminjaman=X.tanggal_peminjaman;
    P->info.tanggal_pengembalian=X.tanggal_pengembalian;
    P->next=NULL;
    P->prev=NULL;
    return P;
}

void dealokasi_Child(addrChild &P){
    /* Menghapus addressChild*/
    delete P;
}

void insertFirst(ListChild &L,addrChild P){
    /*Memasukkan addressChild ke dalam List sebagai urutan pertama di List*/

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
    /*Memasukkan addressChild ke dalam List sebagai urutan terakhir di List*/

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
    /*Memasukkan addressChild P setelah Prec di List*/
    P->next=Prec->next;
    P->prev=Prec;
    Prec->next->prev=P;
    Prec->next=P;
}

void deleteFirst(ListChild &L,addrChild &P){
    /*Menghapus urutan pertama addressChild ke dalam List*/
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
    /*Menghapus urutan terakhir addressChild di dalam List*/
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
    /*Menghapus addressChild  setelah element Prec di dalam List*/
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
    /* Mencari address dengan ID dan setelah ditemukan akan mengembalikan address tersebut
        jika tidak ditemukan akan menegembalikan NULL*/
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
    /* Memperlihatkan semua info didalam List*/
    addrChild P=L.first;
    if (P!=NULL){
    do{
        cout<<"NIK                     :"<<P->info.ID<<endl;
        cout<<"Nama                    :"<<P->info.Nama<<endl;
        cout<<"Alamat                  :"<<P->info.Alamat<<endl;
        cout<<"Tanggal Peminjaman      :"<<P->info.tanggal_peminjaman<<endl;
        cout<<"Tanggal Pengembalian    :"<<P->info.tanggal_pengembalian<<endl;
        P = P->next;
        cout<<endl;
    }while (P != L.first);
    }else {
        cout<<"List Kosong. . .";
    }
    cout<<endl;
}

void insertSorted(ListChild &L, infoType_Child X){
    /* Memasukkan info=x setelah itu mengalokasikan address berdasarkan Pengembalian Mobil*/
    if (L.first == NULL || L.first->info.tanggal_pengembalian > X.tanggal_pengembalian){
        insertFirst(L,createNewElmt(X));
    }else{
        addrChild Q = L.first->next;
        while (Q->next != L.first && X.tanggal_pengembalian> Q->info.tanggal_pengembalian){
            Q = Q->next;
        }
        if (Q->next == L.first &&  X.tanggal_pengembalian > Q->info.tanggal_pengembalian){
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
        cout<<"Delete telah berhasil..."<<endl;
    }

}

void inputUserChild(ListChild &L){
    /* Menerima inputan user setelah itu dimasukkan ke dalam list*/
    infoType_Child X;
    cout<<"Masukkan NIK Penyewa                 : ";
    cin>>X.ID;
    if(searchByID_Child(L,X.ID)== NULL){
        cout<<"Masukkan Nama Penyewa                : ";
        cin.get();
        getline(cin,X.Nama);
        cout<<"Masukkan No. telfon Penyewa          : ";
        cin>>X.NoTlp;
        cout<<"Masukkan alamat Penyewa              : ";
        cin.get();
        getline(cin,X.Alamat);
        cout<<"Masukkan tanggal Peminjaman Penyewa  : ";
        cin>>X.tanggal_peminjaman;
        X.tanggal_pengembalian = (X.tanggal_peminjaman+7)%30;
        if ((X.tanggal_peminjaman+7)%30 == 0){
            X.tanggal_pengembalian=1;
        }
        insertSorted(L,X);
        cout<<endl;
        cout << "Data Penyewa telah terdaftar..." << endl;
    }else {
        cout<<endl;
        cout << "NIK telah terdaftar... Coba lagi" << endl;
    }

}

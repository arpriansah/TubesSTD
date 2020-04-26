#include "RELASI.h"

void createListRelasi(listRelasi &L)
{
    L.first =NULL;
    L.last = NULL;
}

addressRelasi alokasi_Relasi(addressMobil P,addrChild Q)
{
    addressRelasi R = new elmlistRelasi;
    R -> parent = P;
    R -> child = Q;
    R -> next =NULL;
    return R;
}

void dealokasiRelasi(addressRelasi &P)
{
    delete P;
}
void insertFirstRelasi(listRelasi &L, addressRelasi P)
{
    if (L.first == NULL)
    {
        L.first = P;
        L.last = P;
    }
    else
    {
        P->next= L.first;
        L.first = P;
    }
}
void insertLastRelasi(listRelasi &L, addressRelasi P)
{
    if (L.first == NULL)
    {
        L.first = P;
        L.last = P;
    }
    else
    {
        L.last->next =P;
        L.last =P;
    }
}
void insertAfterRelasi(addressRelasi Prec, addressRelasi P)
{
    P = Prec->next ;
    Prec->next = P;
}
void deleteFirstRelasi(listRelasi&L, addressRelasi &P)
{
    P =L.first;
    if(L.first->next !=NULL)
    {

        L.first = P->next;
        P->next= NULL;
    }
    else
    {
        L.first = NULL;
    }
}
void deleteLastRelasi(listRelasi &L, addressRelasi &P)
{
    addressRelasi temp =L.first;
    P =L.last;
    while (temp->next != L.last)
    {
        temp = temp->next;
    }
    L.last = temp;
    L.last->next =NULL;
}
void deleteAfterRelasi(addressRelasi Prec, addressRelasi &P)
{
    P= Prec->next;
    P->child =NULL;
    P->parent =NULL;
    Prec->next = P->next;
    P->next =NULL;
}

addressRelasi checkConnection(listRelasi L,ListChild L2,List_mobil L3,int X, int Y){
    /*Mencari addressParent dan addressChild kemudian mencari addressRelasi yang terhubung ke addressParent dan adressChild di List relasi*/
    addressMobil Q=searchByID(L3,X);
    addrChild R=searchByID_Child(L2,Y);
    addressRelasi P = L.first;
    while ( P!=NULL )
    {
        if(P->parent== Q  && P->child == R)
        {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void Connection(listRelasi &L,ListChild L2,List_mobil L3,int X, int Y){
    /*Membuat addressRelasi yang terhubung ke addressParent dan addressChild kemudian dialokasikan kedalam List Relasi */
    addressMobil P =searchByID(L3,Y);
    addrChild Q = searchByID_Child(L2,X);
    if (P != NULL && Q != NULL){
        insertLastRelasi(L,alokasi_Relasi(P,Q));
        cout<<"Connection berhasil...";
    }
    else
    {
        if(P == NULL)
        {
            cout<<"ID Mobil tidak ditemukan... "<<endl;
        }
        else
        {
            cout<<"NIK penyewa tidak ditemukan... "<<endl;
        }
    }
}

void disconnect(listRelasi &L,ListChild L2,List_mobil L3,int X, int Y){
    /*Menghapus addressRelasi di List Relasi yang terhubung ke addressParent dan addressChild*/
    addressMobil P =searchByID(L3,Y);
    addrChild Q = searchByID_Child(L2,X);
    addressRelasi R = L.first,S;
    if (P != NULL && Q != NULL){
        if ( R->parent == P && R->child == Q){
            R->child =NULL;
            R->parent =NULL;
            deleteFirstRelasi(L,R);
        }else{
            while (R != NULL && R->next->parent != P && R->next->child != Q){
                R =R->next;
            }
            S = R;
            if (R->next == L.last){
                R->next->child =NULL;
                R->next->parent =NULL;
                deleteLastRelasi(L,R);
            }else{

                R = R->next;
                deleteAfterRelasi(S,R);

            }
            dealokasiRelasi(R);
        }
    }
}


void Delete_Child(listRelasi &L,ListChild &L2,int X){
    /* Menghapus address_relasi yang terhubung ke addressChild kemudian menghapus addressChild melalui List relasi*/
    addrChild Q = searchByID_Child(L2,X);
    addressRelasi R = L.first,S;
    if (Q != NULL){
        while (R != NULL){
            if(R->child == Q){
                if(R == L.first){
                    R->child =NULL;
                    R->parent =NULL;
                    R= R->next;
                    deleteFirstRelasi(L,S);
                    dealokasiRelasi(S);
                }else{
                    S =L.first;
                    while(S->next->child != Q){
                        S =S->next;
                    }
                    R = S;
                    if (R->next ==L.last){
                        R->next->child =NULL;
                        R->next->parent =NULL;
                        deleteLastRelasi(L,S);
                        dealokasiRelasi(S);
                    }else {
                        deleteAfterRelasi(R,S);
                        R= R->next;
                        dealokasiRelasi(S);
                    }
                }
            }else {
                R=R->next;
            }
        }
    delete_(L2,Q);
    }else{
        cout<<"NIK penyewa tidak ditemukan..."<<endl;
    }
}

void Delete_Parent(listRelasi &L,List_mobil &L2,int X){
    /* Menghapus address_relasi yang terhubung ke addressParent kemudian menghapus addressParent melalui List relasi*/
    addressMobil Q = searchByID(L2,X);
    addressRelasi R = L.first,S;
    if (Q != NULL){
        while (R != NULL){
            if(R->parent == Q){
                if(R == L.first){
                    R->child =NULL;
                    R->parent =NULL;
                    R= R->next;
                    deleteFirstRelasi(L,S);
                    dealokasiRelasi(S);
                }else{
                    S =L.first;
                    while(S->next->parent != Q){
                        S =S->next;
                    }
                    R = S;
                    if (R->next ==L.last){
                        R->next->child =NULL;
                        R->next->parent =NULL;
                        deleteLastRelasi(L,S);
                        dealokasiRelasi(S);
                    }else {
                        deleteAfterRelasi(R,S);
                        R= R->next;
                        dealokasiRelasi(S);
                    }
                }
            }else {
                R=R->next;
            }
        }
        if (Q == L2.first_mobil){
            deleteFirstMobil(L2,Q);
        }else if (Q->next_mobil == NULL){
            deleteLastMobil(L2,Q);
        }else{
            addressMobil temp= L2.first_mobil;
            while (temp->next_mobil != Q){
                temp = temp->next_mobil;
            }
            deleteAfterMobil(L2,temp,Q);
        }
    dealokasi_mobil(Q);
    }else{
        cout<<"ID mobil tidak ditemukan..."<<endl;
    }
}

void printRelasi(listRelasi L){
    addressRelasi P;
    if(L.first == NULL)
    {
        cout << "*================================*" << endl;
        cout << "* Daftar Mobil yang Telah Disewa *" << endl;
        cout << "*================================*" << endl;
        cout << "         Tidak ada mobil" << endl;
    }
    else
    {
        cout << "*================================*" << endl;
        cout << "* Daftar Mobil yang Telah Disewa *" << endl;
        cout << "*================================*" << endl;
        P = L.first;
        do
        {
            cout << " ID Mobil                : " << P->parent->info_mobil.IDmobil << endl;
            cout << " Jenis Mobil             : " << P->parent->info_mobil.jenis_mobil << endl;
            cout << " Nama Mobil              : " << P->parent->info_mobil.nama_mobil << endl;
            cout << " Kondisi Mobil           : " << P->parent->info_mobil.kondisi_mobil << endl;
            cout << " Harga rental            : " << P->parent->info_mobil.hargaRental << endl;
            cout << " Data Penyewa"<<endl;
            cout << " NIK Penyewa             : " << P->child->info.ID << endl;
            cout << " Nama Penyewa            : " << P->child->info.Nama << endl;
            cout << " Alamat Penyewa          : " << P->child->info.Alamat << endl;
            cout << " Tanggal Peminjaman      : " <<P->child->info.tanggal_peminjaman<<endl;
            cout << " Tanggal Pengembalian    : " <<P->child->info.tanggal_pengembalian<<endl;
            cout << endl;
            P = P->next;
        }
        while(P != NULL);
        cout << "*================================*" << endl;
        cout << endl;
    }
}

void Total_Keuntungan_case1(listRelasi L,List_mobil L2,int &x){
    /*Menghitung seluruh harga rental di List relasi*/
    addressRelasi R = L.first;
    while (R != NULL){
        x = x + R->parent->info_mobil.hargaRental;
        R = R->next;
    }
}

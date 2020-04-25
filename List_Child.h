#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
//NAMA : Muh. Fachrul Hidayat
//NIM  : 1301194066

#include <bits/stdc++.h>
using namespace std;
struct dataPenyewa{
    int ID;
    string Nama;
    string Alamat;
    double NoTlp;
    int TglLahir;
    ;
};
typedef dataPenyewa infoType_Child;
typedef struct elmList *addrChild;
struct elmList{
    infoType_Child info;
    addrChild next;
    addrChild prev;
};

struct ListChild{
    addrChild first;
};

void createList(ListChild &L);
addrChild createNewElmt(infoType_Child X);
void dealokasi_Child(addrChild &P);
void insertFirst(ListChild &L, addrChild P);
void insertAfter(ListChild &L, addrChild Prec, addrChild P);
void insertLast(ListChild &L, addrChild P);
void deleteFirst(ListChild &L, addrChild &P);
void deleteLast(ListChild &L, addrChild &P);
void deleteAfter(ListChild &L, addrChild &Prec, addrChild &P);
addrChild searchByID_Child(ListChild L, int x);

void printList(ListChild L);
void insertSorted(ListChild &L, infoType_Child X);
void delete_(ListChild &L,addrChild &P);
void inputUserChild(ListChild &L);

#endif // LIST_CHILD_H_INCLUDED

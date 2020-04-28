#include "Case_Functional.h"
#include "Mobil.h"
#include "List_Child.h"
#include "RELASI.h"

using namespace std;

void PengeluaranPelanggan(List_mobil LM, listRelasi LR){
    /* Membuat total pengeluaran dari pelanggan */
    string id;
    int x,i;
    addressMobil P, Q;
    addressRelasi r;
    cout << "Masukkan ID Mobil : ";
    cin >> id;

    P = first_mobil(LM);
    while(P != NULL){
        if(P->info_mobil.IDmobil == id){
            Q = P;
        }
        P = next_mobil(P);
    }
    if(Q != NULL){
        addressRelasi R = first_relasi(LR);
        if(R != NULL){
            do{
                if(R->child == Q){
                    r = R;
                }
                R = next_relasi(R);
            }
        }
    }
    long pengeluaran = 0;
    cout << "Jumlah hari mobil dipakai : ";
    cin >> x;
    pengeluaran = x * Q->info_mobil.hargaRental;
    cout << "Jumlah harga yang harus dibayar pelanggan " << r->child->info.Nama << " adalah: " pengeluaran << endl;

}


#include <iostream>
#include <conio.h>
#include "Mobil.h"
#include "List_Child.h"
#include "RELASI.h"
#include "Case_Functional.h"


using namespace std;

int main(){
    infotype P;
    dataPenyewa Z;
    bool cek;
    List_mobil LM;
    ListChild LC;
    listRelasi LR;
    createListMobil(LM);
    createList(LC);
    createListRelasi(LR);
    int menu, r, s, x,total=0;
  do {
        system("CLS");
    	cout << "*===================================================================*" << endl;
    	cout << "*||                       JASA SEWA MOBIL SEMINGGU                  ||*" << endl;
    	cout << "*===================================================================*" << endl;
    	cout << "* 1.  Membuat data mobil                                            *" << endl;
    	cout << "* 2.  Menampilkan semua data mobil                                  *" << endl;
    	cout << "* 3.  Membuat data pelanggan                                        *" << endl;
    	cout << "* 4.  Menampilkan semua data pelanggan                              *" << endl;
    	cout << "* 5.  Membuat data pelanggan yang menyewa mobil                     *" << endl;
    	cout << "* 6.  Cek status pelanggan yang belum mengembalikan mobil           *" << endl;
    	cout << "* 7.  Menghapus pelanggan yang sudah mengembalikan mobil            *" << endl;
    	cout << "* 8.  Menampilkan semua data pelanggan beserta mobil yang disewa    *" << endl;
        cout << "* 9.  Mencari data pelanggan melalui ID mobil yang disewa           *" << endl;
        cout << "* 10. Menghapus data mobil                                          *" << endl;
        cout << "* 11. Menghapus data pelanggan                                      *" << endl;
        cout << "* 12. Total Keuntungan dari rental mobil                            *" << endl;
    	cout << "*===================================================================*" << endl;
    	cout << "\n Pilih menu (Angka): ";
    	cin >> menu;
    	switch(menu){
             case 1:{
                system("CLS");
                cout << "*===INPUT MOBIL===*" << endl;
                cout << " ID            : ";
                cin >> P.IDmobil;
                cout << " Jenis mobil   : ";
                cin >> P.jenis_mobil;
                cout << " Nama mobil    : ";
                cin.get();
                getline(cin,P.nama_mobil);
                cout << " Kondisi mobil : ";
                cin >> P.kondisi_mobil;
                cout << " Harga Rental  : Rp.";
                cin >> P.hargaRental;
                if(first_mobil(LM) == NULL){
                    insertFirstMobil(LM, alokasi_mobil(P));
                }else{
                    addressMobil Q = first_mobil(LM);
                    while(Q != NULL){
                        if(Q->info_mobil.IDmobil == P.IDmobil){
                            cek = true;
                        }
                        Q = next_mobil(Q);
                    }
                    if(!cek){
                        insertLastMobil(LM, alokasi_mobil(P));
                    }else{
                        cout << "ID telah terdaftar" << endl;
                    }
                }
                cout<<"tekan enter untuk melanjutkan...";
                getch();
                break;
            }


            case 2:{
                system("CLS");
                cout << "*==INFO MOBIL==*" << endl;
                printInfo_mobil(LM);
                cout<<"tekan enter untuk melanjutkan...";
                getch();
            }
            break;

            case 3:{
                system("CLS");
                cout << "*===INPUT PENYEWA===*" << endl;
                inputUserChild(LC);
                getch();
            }
            break;

            case 4:{
                system("CLS");
                cout << "*==INFO PENYEWA===*" << endl;
                printList(LC);
                cout<<"tekan enter untuk melanjutkan...";
                getch();
            }
            break;

            case 5:{
                system("CLS");
                cout << "*==INSERT RELASI==*" << endl;
                cout << " ID Mobil   : ";
                cin >> r;
                cout << " ID Penyewa : ";
                cin >> s;
                Connection(LR, LC, LM, s, r);
                getch();
            }
            break;

            case 6:{
                system("CLS");
                cout << "*==CHECK CONNECTION==*" << endl;
                cout << " ID Mobil   : ";
                cin >> r;
                cout << " ID Penyewa : ";
                cin >> s;
                if  (checkConnection(LR, LC, LM, r, s) != NULL ){
                    addressMobil P =searchByID(LM,r);
                    addrChild Q = searchByID_Child(LC,s);
                    cout<<endl;
                    cout<<"Mobil "<< P->info_mobil.nama_mobil <<" sedang dipakai oleh "<< Q->info.Nama;
                }else{
                    cout<<endl;
                    cout<<" Mobil sedang tidak dipakai... ";
                }
                getch();
            }
            break;

            case 7:{
                system("CLS");
                cout << "*==DISCONNECT==*" << endl;
                cout << " ID Mobil   : ";
                cin >> r;
                cout << " ID Penyewa : ";
                cin >> s;
                disconnect(LR, LC, LM, s, r);
                cout<<"Disconnect berhasil...";
                cout<<endl;
                cout<<"tekan enter untuk melanjutkan...";
                getch();
            }
            break;

            case 8:{
                system("CLS");
                printRelasi(LR);
                getch();
            }
            break;

            case 9:{
                system("CLS");
                cout << " ID Mobil : ";
                cin >> x;
                addressMobil PR = searchByID(LM, x);
                addressRelasi t = LR.first;
                if(PR == NULL){
                    cout << "ID Mobil " << x << " Tidak Ditemukan" << endl;
                }else{
                    cout << "ID Mobil : " << PR->info_mobil.IDmobil << endl;
                    if(t != NULL){
                        cout << "ID Penyewa : ";
                        do{
                            if(t->parent == PR){
                                cout << " " << t->child->info.ID;
                            }
                            t = t->next;
                        }while(t != NULL);
                    }
                }
                cout<<"tekan enter untuk melanjutkan...";
                getch();
            }
            break;

            case 10:{
                system("CLS");
                cout << "*===DELETE MOBIL===*" << endl;
                cout << " ID Mobil : ";
                cin >> x;
                Delete_Parent(LR, LM, x);
                cout<<endl;
                cout<<"tekan enter untuk melanjutkan...";
                getch();
            }
            break;

            case 11:{
                system("CLS");
                cout << "*===DELETE PENYEWA===*" << endl;
                cout << " ID Penyewa : ";
                cin >> x;
                Delete_Child(LR, LC, x);
                cout<<"tekan enter untuk melanjutkan...";
                getch();
            }
            break;

            case 12:{
                system("CLS");
                Total_Keuntungan_case1(LR,LM,total);
                cout<<"Total pendapatan saat ini : Rp."<<total<<" "<<endl;
                cout<<endl;
                cout<<"tekan enter untuk melanjutkan...";
                getch();
            }
            break;
    	}
	}while(menu != 0);
    return 0;
}

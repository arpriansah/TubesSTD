#include <iostream>
#include "Mobil.h"
#include "List_Child.h"
#include "RELASI.h"
#include "Case_Functional.h"


using namespace std;

int main(){
    infotype P;
    dataPenyewa Z;
    bool cek;
    createListMobil(LM);
    createList(LC);
    createListRelasi(LR);
    int menu, r, s, x;
    do {
    	cout << "*==========================================*" << endl;
    	cout << "*||              MAIN MENU               ||*" << endl;
    	cout << "*==========================================*" << endl;
    	cout << "* 1.  Input Parent                         *" << endl;
    	cout << "* 2.  Print all parent                     *" << endl;
    	cout << "* 3.  Input child                          *" << endl;
    	cout << "* 4.  Print child                          *" << endl;
    	cout << "* 5.  Connect                              *" << endl;
    	cout << "* 6.  Check connect                        *" << endl;
    	cout << "* 7.  Disconnect                           *" << endl;
    	cout << "* 8.  Print Relasi                         *" << endl;
        cout << "* 9.  Print *" << endl;
        cout << "* 10. Delete Parent                        *" << endl;
        cout << "* 11. Delete Child                         *" << endl;
    	cout << "*==========================================*" << endl;
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
                cin >> P.nama_mobil;
                cout << " Kondisi mobil : ";
                cin >> P.kondisi_mobil;
                addressMobil P1 = alokasi_mobil(P);
                if(first_mobil(LM) == NULL){
                    insertFirstMobil(LM, P1);
                }else{
                    addressMobil Q = first_mobil(LM);
                    while(Q != NULL){
                        if(Q->info_mobil.IDmobil == P.IDmobil){
                            cek = true;
                        }
                        Q = next_mobil(Q);
                    }
                    if(!cek){
                        insertLastMobil(LM, P1);
                    }else{
                        cout << "ID telah terdaftar" << endl;
                    }
                }
                getch();
            }
            break;

            case 2:{
                system("CLS");
                cout << "*==INFO MOBIL==*" << endl;
                printInfo_mobil(LM);
                getch();
            }
            break;

            case 3:{
                system("CLS");
                cout << "*===INPUT PENYEWA===*" << endl;
                cout << " ID Penyewa    : ";
                cin >> Z.ID;
                cout << " Nama          : ";
                cin >> Z.Nama;
                cout << " NIK           : ";
                cin >> Z.NIK;
                cout << " Alamat        : ";
                cin >> Z.Alamat;
                cout << " Tanggal Lahir : ";
                cin >> Z.TglLahir;
                cout << " No. Telpon    : ";
                cin >> Z.NoTlp;
                addrChild Z1 = createNewElmt(Z);
                if(LC.first == NULL){
                    insertFirst(LC, Z1);
                }else{
                    addrChild A = LC.first;
                    while(A != NULL){
                        if(A->info.ID == Z1->info.ID){
                            cek = true;
                        }
                        A = A->next;
                    }
                    if(!cek){
                        insertLast(LC, Z1);
                    }else{
                        cout << "ID telah terdaftar" << endl;
                    }
                }
                getch();
            }
            break;

            case 4:{
                system("CLS");
                cout << "*==INFO PENYEWA" << endl;
                printList(LC);
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
                checkConnection(LR, LC, LM, r, s);
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
                addressRelasi t = first_relasi(LR);
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
                            t = next_relasi(t);
                        }while{t != NULL};
                    }
                }

                getch();
            }
            break;

            case 10:{
                system("CLS");
                cout << "*===DELETE MOBIL===*" << endl;
                cout << " ID Mobil : " << endl;
                cin >> x;
                Delete_Parent(LR, LM, x);
                getch();
            }
            break;

            case 11:{
                system("CLS");
                cout << "*===DELETE PENYEWA===*" << endl;
                cout << " ID Penyewa : " << endl;
                cin >> x;
                Delete_Child(LR, LC, x);
                getch();
            }
            break;
    	}
	}while(menu != 0);
    return 0;
}

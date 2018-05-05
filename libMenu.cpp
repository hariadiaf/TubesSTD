#include "menuTubes.h"
void menuUtama(ListEvent Levent, ListChild Lsponsor, List_relasi Lrelasi){
    int pil;
    do{
        system("cls");
        cout<<"||========================================================||"<<endl;
        cout<<"||                     TUBES STD                          ||"<<endl;
        cout<<"||========================================================||"<<endl;
        cout<<"||     oleh : 1. Hariadi Adha Firmansyah (1301174252)     ||"<<endl;
        cout<<"||            2. Ivan Naufal (1301174318)                 ||"<<endl;
        cout<<"||========================================================||"<<endl;
        cout<<"  TUBES>>MENU UTAMA"<<endl<<endl;
        cout<<"  1. Event"<<endl;
        cout<<"  2. Sponsor"<<endl;
        cout<<"  3. Daftar kerjasama"<<endl;
        cout<<"  4. keluar"<<endl<<endl;
        cout<<"  Masukan pilihan [1/2/3/4] : "; cin>>pil;

        switch(pil){
            case 1 : menuEvent(Levent,Lrelasi); break;
            case 2 : MenuSponsor(Lsponsor,Lrelasi); break;
            case 3 : menuRelasi(Levent,Lsponsor,Lrelasi);break;
            case 4 : exit(0);break;

     //       case 3 :
        }
    }while(pil!=1||pil!=2);
}
void menuEvent(ListEvent &L, List_relasi &Lrelasi){
    char menu;
    while(menu != '3'){
    do{
        system("cls");
        tengah1(120,"=====================================\n");
        tengah1(122,"DAFTAR EVENT\n");
        tengah1(120,"=====================================\n");
        cout<<endl;
        tengah1(25,"No. ");
        tengah1(30,"Nama Event ");
        tengah1(35,"Dana dibutuhkan ");
        tengah1(40,"Dana Kurang ");
        tengah1(45,"Dana Lebih ");

        cout<<endl;
        showEvent(L);
        cout<<endl;
        cout<<endl;
        tengah1(40,"1. Tambah Event \n");
        tengah1(38,"2. Hapus Event \n");
        tengah1(34,"3. Kembali \n");
        cout<<endl;
        tengah1(34,"Pilih Menu : ");
            cin>>menu;
            if(menu == '1'){
                system("CLS");
                tambahEvent(L);
            }else if(menu == '2'){
                system("CLS");
                string nmEvent;
                char pil;
                cout<<"Cari Nama Event : "; cin>>nmEvent;
                address_parent P = cariEvent(L,nmEvent);
                if(P == NULL){
                    cout<<"Tidak ada event bernama "<<nmEvent<<" "<<endl;
                    system("pause");
                    system("CLS");
                    menuEvent(L,Lrelasi);
                }else{
                    cout<<"Nama Event : "<<info(P).nameEvent<<endl;
                    cout<<"Budget Yang dibutuhkan : "<<info(P).needBudget<<endl;
                    cout<<"Budget Kurang : "<<info(P).minusBudget<<endl;
                    cout<<"\nApakah anda yakin menghapus data ini ? [y/t] "; cin>>pil;
                    if(pil == 'y'){
                        address_relasi R = first(Lrelasi);
                        while(R != NULL){
                            if(info(P).nameEvent == info(parent(R)).nameEvent){
                                deleteData(Lrelasi,R);
                            }
                            R = next(R);
                        }


                        hapusEvent(L,nmEvent,P);
                        system("CLS");
                        menuEvent(L,Lrelasi);
                    }else if(pil == 't'){
                        system("CLS");
                        menuEvent(L,Lrelasi);
                    }
                }
            }/*else{
                tengah1(34,"input tidak valid, re input!\n");
            }*/
        }while((menu=='1')||(menu=='2')&&(menu=='3'));
    }
}

void MenuSponsor(ListChild &Lsponsor, List_relasi &Lrelasi){
    int menu = 0;
    system("cls");
    tengah2(120,"=====================================\n");
    tengah2(122,"MENU SPONSOR\n");
    tengah2(120,"=====================================\n");
    cout<<endl;
    tengah2(25,"No. ");
    tengah2(35,"Nama Sponsor ");
    tengah2(45,"Budget ");
    tengah2(55,"Sisa Budget ");
    cout<<endl;
    show(Lsponsor);
    cout<<endl;
    cout<<endl;
    tengah2(40,"1. Tambah Sponsor \n");
    tengah2(38,"2. Hapus Sponsor \n");
    tengah2(33,"3. Kembali \n");
    cout<<endl;
    tengah2(34,"Pilih Menu : "); cin>>menu;

    if(menu == 1){
        system("CLS");
        insertData(Lsponsor);
    }else if(menu == 2){
        system("CLS");
        string nmSponsor;
        char pil;
        cout<<"Cari Nama Sponsor : "; cin>>nmSponsor;
        address_child P = cariSponsor(Lsponsor,nmSponsor);
        if(P == NULL){
            cout<<"Tidak Ditemukan\n";
            system("pause");
            system("CLS");
            MenuSponsor(Lsponsor,Lrelasi);
        }else{
            cout<<"Nama Sponsor : "<<info(P).namaSponsor<<endl;
            cout<<"Budget Awal : "<<info(P).budget<<endl;
            cout<<"Sisa Budget : "<<info(P).sisaBudget<<endl;
            cout<<"\nApakah anda yakin menghapus data ini ? [y/t] "; cin>>pil;
            if(pil == 'y'){

                address_relasi R = first(Lrelasi);
                while(R != NULL){
                    if(info(P).namaSponsor == info(child(R)).namaSponsor){
                        deleteData(Lrelasi,R);
                    }
                    R = next(R);
                }

                deleteData(Lsponsor,nmSponsor,P);
                system("CLS");
                MenuSponsor(Lsponsor,Lrelasi);
            }else if(pil == 't'){
                system("CLS");
                MenuSponsor(Lsponsor,Lrelasi);
            }
        }

    }else if(menu==3){

    }

}

void menuRelasi(ListEvent &Levent, ListChild &Lsponsor, List_relasi &Lrelasi){
    int pilih;
    char pilGrade; string nmevent,nmSponsor;
        system("cls");
        cout<<"1. Dukung Event\n";
        cout<<"2. Lihat Event Yang Didukung\n";
        cout<<"pilih : "; cin>>pilih;
    if(pilih == 1){
        int pilGrade;
        system("cls");
        address_relasi R;
        address_child C;
        relasi infoR;
        sponsor so;
        event ev;
        address_parent Pr = first(Levent);
        cin.ignore();
        if(Pr != NULL){
            cout<<"Nama Event\n";
            do{
                cout<<info(Pr).nameEvent<<endl;
                Pr = next(Pr);
            }while(Pr != first(Levent));
                        cout<<"Masukan Nama Event Yang Akan Didukung : "; getline(cin,nmevent);
            address_parent P = cariEvent(Levent,nmevent);
            if(P == NULL){
                system("pause");
            }

            if(P != NULL){

                system("cls");
                cout<<"Nama Event : "<<info(P).nameEvent<<endl;
                cout<<"Dana Yang Dibutuhkan : "<<info(P).needBudget<<endl;
                cout<<"Dana Lebih : "<<info(P).plusBudget<<endl;
                cout<<"Grade Dukungan : \n";
                cout<<"1.Super-Uranium = 100%\n";
                cout<<"2.Uranium = 65%\n";
                cout<<"3.Platinum = 50%\n";
                cout<<"4.Gold = 25%\n";
                cout<<"5.Silver = 15%\n";
                cout<<"6.Bronze = 10%\n";
                cout<<"7.Reguler = 5%\n";
                cout<<"Pilih Grade Dukungan : "; cin>>pilGrade;
                cout<<"Masukan nama sponsor anda : "; cin>>nmSponsor;
                C = cariSponsor(Lsponsor,nmSponsor);
            if(C == NULL){
                cout<<"Sponsor tidak ditemukan !!\n";
                system("pause");
            }else{
                if(pilGrade == 1&&C!=NULL){
                    //
                    olahData(Levent,Lsponsor,Lrelasi,P,C,"Super-Uranium",100);
                }else if(pilGrade == 2&&C!=NULL){
                    olahData(Levent,Lsponsor,Lrelasi,P,C,"Uranium",65);
                }else if(pilGrade == 3&&C!=NULL){
                    olahData(Levent,Lsponsor,Lrelasi,P,C,"Platinum",50);
                }else if(pilGrade == 4&&C!=NULL){
                    olahData(Levent,Lsponsor,Lrelasi,P,C,"Gold",25);
                }else if(pilGrade == 5&&C!=NULL){
                    olahData(Levent,Lsponsor,Lrelasi,P,C,"Silver",15);
                }else if(pilGrade == 6&&C!=NULL){
                    olahData(Levent,Lsponsor,Lrelasi,P,C,"Bronze",10);
                }else if(pilGrade == 7&&C!=NULL){
                    olahData(Levent,Lsponsor,Lrelasi,P,C,"Reguler",5);
                }
            }

            }
        }else{
            cout<<"Silahkan tambah event & sponsor terlebih dahulu\n";
            system("pause");
        }


 }else if(pilih == 2){
        system("cls");
        int i = 1;
        cout<<"Masukan Nama Sponsor : "; cin>>nmSponsor;
        address_child C = cariSponsor(Lsponsor,nmSponsor);

        address_relasi R = first(Lrelasi);

        if(R != NULL && C != NULL){
        cout<<"Nama Sponsor : "<<nmSponsor<<endl;
        tengah2(5,"No. ");
        tengah2(15,"Nama Event ");
        tengah2(25,"Grade");
        tengah2(35,"Besar Donasi ");
        cout<<endl;
        while(R != NULL){
            if(info(child(R)).namaSponsor == nmSponsor){
                    cout<<" "<<setiosflags(ios::left)<<setw(0)<<i++;
                    cout<<" "<<setiosflags(ios::left)<<setw(8)<<info(parent(R)).nameEvent;
                    cout<<" "<<setiosflags(ios::left)<<setw(23)<<info(R).grade;
                    cout<<" "<<setiosflags(ios::left)<<setw(15)<<info(R).gradeBudget<<endl;
            }
            R = next(R);
        }
        cout<<"\n1. Batal Donasi\n";
        cout<<"2. Kembali\n";
        cout<<"Pilih Menu : "; cin>>pilih;
        if(pilih == 1){
            //cout<<"Masukan Nama Event : "; cin>>nmevent;
            cin.ignore();
            cout<<"Masukan Nama Event : "; getline(cin,nmevent);;
            address_parent P = cariEvent(Levent,nmevent);
            address_relasi Q = findElm(Lrelasi,P,C);

            if(Q != NULL){
                info(C).sisaBudget = info(C).sisaBudget+info(Q).gradeBudget;
                info(P).minusBudget = info(P).minusBudget+info(Q).gradeBudget;
                if(info(P).plusBudget > 0){
                    info(P).plusBudget = info(P).plusBudget-info(Q).gradeBudget;
                }

                if(next(Q) == NULL){
                    cout<<"\n";
                }else{
                    //cout<<info(parent(next(Q))).nameEvent;
                }


                deleteData(Lrelasi,Q);
                cout<<"Berhasil\n";
            }else{
                cout<<"Tidak Ditemukan\n";
            }
        }

        }else{
            cout<<"Tidak ada relasi\n";
        }

        system("pause");
    }
}

void olahData(ListEvent &Levent,ListChild &Lsponsor, List_relasi &Lrelasi,
              address_parent P, address_child C,string grade,int persen){
relasi infoR;
address_relasi R;
infoR.grade = grade;
infoR.gradeBudget = ((info(P).needBudget*persen)/100);

if(info(C).sisaBudget>=infoR.gradeBudget){
    long budgetSponsor = info(C).budget;
    if(info(C).counter == 0){
        info(C).sisaBudget = budgetSponsor - infoR.gradeBudget;
        info(C).counter = info(C).counter+1;
    }else if(info(C).counter >= 1){
        info(C).sisaBudget = info(C).sisaBudget - infoR.gradeBudget;
        info(C).counter = info(C).counter+1;
    }


    if(info(P).counter == 0){
        if(info(P).minusBudget<=0){
            info(P).plusBudget = -(info(P).minusBudget-infoR.gradeBudget);
            info(P).minusBudget = 0;
        }else{
            info(P).minusBudget = info(P).minusBudget-infoR.gradeBudget;
        }
        info(P).counter = info(P).counter+1;
    }else if(info(P).counter == 1){
        if(info(P).minusBudget<=0){
            info(P).plusBudget = -(info(P).minusBudget-infoR.gradeBudget);
            info(P).minusBudget = 0;
        }else{
            info(P).minusBudget = info(P).minusBudget-infoR.gradeBudget;
        }
        info(P).counter = info(P).counter+1;
    }else{
        info(P).plusBudget = info(P).plusBudget+infoR.gradeBudget;
        info(P).counter = info(P).counter+1;
    }


    R = alokasi(P,C,infoR);
    insertFirst(Lrelasi,R);

    cout<<"Selamat anda berhasil donasi sebesar "<<info(R).gradeBudget<<"\n";
    cout<<info(C).counter;
    system("pause");
}else{
     cout<<"Maaf Budget Anda tidak cukup!!\n";
     system("pause");
}








}



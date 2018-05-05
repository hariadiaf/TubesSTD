#include "libSponsor.h"
#include "menuTubes.h"

void createChild(ListChild &L){
    first(L) = NULL;
}
address_child alokasi(infotype x){
    address_child P;
    P = new elmChild;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void dealokasi(address_child &P){
    delete P;
}
void insertFirst(ListChild &L, address_child P){
    if(first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(ListChild &L, address_child P, address_child Prec){
    if(first(L) == NULL){
        insertFirst(L,P);
    }else{
        if(first(L) == Prec){
            insertFirst(L,P);
        }else if(next(Prec) == NULL){
            insertLast(L,P);
        }else{
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}

void insertLast(ListChild &L, address_child P){
    if(first(L) == NULL){
        insertFirst(L,P);
    }else{
        address_child Q = first(L);
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void deleteFirst(ListChild &L, address_child P){
    if(first(L) == NULL){
        cout<<"Kosong";
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteAfter(ListChild &L, address_child P, address_child Prec){
    if(first(L) == NULL){
        cout<<"Kosong";
    }else{
        if(first(L) == P){
            deleteFirst(L,P);
        }else if(next(P) == NULL){
            deleteLast(L,P);
        }else{
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = NULL;
        }
    }
}
void deleteLast(ListChild &L, address_child P){
    if(first(L) == NULL){
        cout<<"KOSONG";
    }else if(first(L) == NULL){
        deleteFirst(L,P);
    }else{
        address_child Q = first(L);
        while(next(next(Q)) != NULL){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}

address_child cariSponsor(ListChild L,string namaSpo){
    address_child P;
    if(first(L) == NULL){
        return NULL;
    }else{
        address_child Q = first(L);
        bool found = false;
        while((Q != NULL) && (found == false)){
            if(info(Q).namaSponsor == namaSpo){
                found = true;
                P = Q;
            }
            Q = next(Q);
        }

        if(found == true){
            return P;
        }else{
            return NULL;
        }
    }
}
void show(ListChild &L){
    address_child P;
    int i = 1;
    P = first(L);
    if(P == NULL){
        cout<<" "<<setiosflags(ios::right)<<setw(7);
        cout<<" "<<setiosflags(ios::left)<<setw(8)<<"Kosong";
    }
    while(P != NULL){
        cout<<" "<<setiosflags(ios::right)<<setw(7);
        cout<<" "<<setiosflags(ios::left)<<setw(3)<<i++;
        cout<<" "<<setiosflags(ios::left)<<setw(20)<<info(P).namaSponsor;
        cout<<" "<<setiosflags(ios::left)<<setw(27)<<info(P).budget;
        cout<<" "<<setiosflags(ios::left)<<setw(30)<<info(P).sisaBudget<<endl;
        P = next(P);
    }
}

void deleteData(ListChild &L, string namaSpo, address_child &P){
    //P = cariSponsor(L,namaSpo);
    if(P == NULL){
        cout<<"Data tidak ditemukan";
    }else{
        if(first(L) == P){
            deleteFirst(L,P);
        }else if(next(P)==NULL){
            deleteLast(L,P);
        }else{
            address_child Prec = first(L);
            while(next(Prec)!=P){
                Prec = next(Prec);
            }
            deleteAfter(L,P,Prec);
        }
    }
}
void tengah2(int width, char* s) {
 int l = strlen(s);
 int pos = (int)((width - l) / 2);
 for (int i = 0; i < pos; i++) { cout << " "; }
 cout << s;
}
void insertData(ListChild &L){
    int menu = 0;
    sponsor so;
    do{
    system("CLS");
    cin.ignore();
    cout<<"Nama Sponsor : "; getline(cin,so.namaSponsor);
    cout<<"Budget : "; cin>>so.budget;
    so.sisaBudget = so.budget;
    so.counter = 0;
    insertFirst(L,alokasi(so));
    cout<<"1.Tambah Data Sponsor Lagi\n";
    cout<<"2.Kembali\n";
    cout<<"Pilih Menu : "; cin>>menu;
    }while(menu == 1);
}






#include "libEvent.h"
#include "menuTubes.h"
void createListEvent(ListEvent &L){
    first(L)=NULL;
    last(L)=NULL;
}

address_parent alokasiEvent(infotypes x){
    address_parent P;
    P= new elmListEvent;
    info(P)=x;
    next(P)=NULL;
    return P;
}

void dealokasiEvent(address_parent &P){
    delete P;
}

bool isEmptyList(ListEvent L){
    if((first(L)==NULL)&&(last(L)==NULL)){
        return true;
    }else{
        return false;
    }
}

void insertFirstEvent(ListEvent &L, address_parent P){
    if(isEmptyList(L)==true){
        first(L)=P;
        last(L)=P;
        next(last(L))=P;
    }else{
        next(P)=first(L);
        next(last(L))=P;
        first(L)=P;
    }
}

void insertLastEvent(ListEvent &L, address_parent P){
    if(isEmptyList(L)==true){
        insertFirstEvent(L,P);
    }else{
        next(last(L))=P;
        next(P)=first(L);
        last(L)=P;
    }
}

void insertAfterEvent(ListEvent &L, address_parent P, address_parent Prec){
    if(isEmptyList(L)){
        insertFirstEvent(L,P);
    }else{
        if(Prec==last(L)){
            insertFirstEvent(L,P);
        }else if(next(Prec)==last(L)){
            insertLastEvent(L,P);
        }else{
            address_parent Q;
            Q=next(Prec);
            next(Prec)=P;
            next(P)=Q;
        }
    }
}

void deleteFirstEvent(ListEvent &L, address_parent &P){
    if(isEmptyList(L)==true){
        cout<<"Tidak Ada Event"<<endl;
    }else if(first(L)==last(L)){
        first(L)=NULL;
        last(L)=NULL;
    }else{
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
        next(last(L))=first(L);
    }
}
void deleteLastEvent(ListEvent &L, address_parent &P){
    if(isEmptyList(L)==true){
        cout<<"Tidak Ada Event"<<endl;
    }else if(first(L)==last(L)){
        deleteFirstEvent(L,P);
    }else if(next(first(L))==first(L)){
        deleteFirstEvent(L,P);
    }else{
        address_parent Q;
        Q=first(L);
        while(next(Q)!=last(L)){
            Q=next(Q);
        }
        P=last(L);
        next(P)=NULL;
        next(Q)=first(L);
        last(L)=Q;
    }
}

void deleteAfterEvent(ListEvent &L, address_parent &P, address_parent Prec){
    if(isEmptyList(L)==true){
        cout<<"Tidak Ada Event"<<endl;
    }else if(next(first(L))==first(L)){
        deleteFirstEvent(L,P);
    }else{
        if(Prec==last(L)){
            P=next(Prec);
            deleteFirstEvent(L,P);
        }else if(next(Prec)==last(L)){
            P=next(Prec);
            deleteLastEvent(L,P);
        }else{
            P=next(Prec);
            next(Prec)=next(P);
            next(P)=NULL;
        }
    }
}

address_parent cariEvent(ListEvent L, string namaEv){
    address_parent P,Q;
    bool found=false;
    if(isEmptyList(L)==true){
        cout<<"Tidak Ada Event"<<endl;
    }else{
        P=first(L);
        do{
            if(info(P).nameEvent==namaEv){
                found=true;
                Q=P;
            }
            P=next(P);
        }while(P!=first(L));
    }
    if(found==true){
        return Q;
    }else if(found==false){
        return NULL;
    }
}
void showEvent(ListEvent &L){
    address_parent P = first(L);
    int i=1;
    if(isEmptyList(L)==true){
        cout<<" "<<setiosflags(ios::right)<<setw(7);
        cout<<" "<<setiosflags(ios::right)<<setw(30)<<"Tidak ada event";
    }else{
        do{
            cout<<" "<<setiosflags(ios::right)<<setw(7);
            cout<<" "<<setiosflags(ios::left)<<setw(3)<<i++;
            cout<<" "<<setiosflags(ios::left)<<setw(15)<<info(P).nameEvent;
            cout<<" "<<setiosflags(ios::left)<<setw(30)<<info(P).needBudget;
            cout<<" "<<setiosflags(ios::left)<<setw(32)<<info(P).minusBudget;
            cout<<" "<<setiosflags(ios::left)<<setw(25)<<info(P).plusBudget<<endl;
            P = next(P);
        }while(P!=first(L));
    }
}

void tambahEvent(ListEvent &L){
    int menu = 0;
    event ev;
    while(menu != 2){
        do{
            system("CLS");
            cin.ignore();
            cout<<"Nama Event               : "; getline(cin,ev.nameEvent);
            cout<<"Dana yang dibutuhkan     : "; cin>>ev.needBudget;
            ev.minusBudget=ev.needBudget;
            ev.plusBudget=0;
            ev.counter = 0;
            address_parent P = alokasiEvent(ev);
            insertFirstEvent(L,P);
            cout<<"1.Tambah Data Event Lagi\n";
            cout<<"2.Kembali\n";
            cout<<"Pilih Menu : "; cin>>menu;
        }while(menu == 1);
    }

}

void hapusEvent(ListEvent &L, string namaEv, address_parent &P){
    address_parent Q;
    bool found=false;
    // P = cariEvent(L,namaEv);
    if(P==NULL){
        cout<<"Data tidak ditemukan\n";
    }else{
        if(P==first(L)){
            deleteFirstEvent(L,P);
            dealokasiEvent(P);
        }else if(P==last(L)){
            deleteLastEvent(L,P);
            dealokasiEvent(P);
        }else if(first(L)==last(L)){
            deleteFirstEvent(L,P);
            dealokasiEvent(P);
        }else{
            address_parent Prec;
            Q=first(L);
            do{
                if(next(Q)==P){
                    found==true;
                    Prec=Q;
                }
                Q = next(Q);
            }while(next(Q)!=first(L));
            deleteAfterEvent(L,P,Prec);
            dealokasiEvent(P);
        }
    }
}
void tengah1(int lebar, char* q){
     int l = strlen(q);
     int pos = (int)((lebar - l) / 2);
     for (int i = 0; i < pos; i++) { cout << " "; }
     cout << q;
}


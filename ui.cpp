#include "ui.h"
#include <iostream>
#include "validation_exception.h"

using namespace std;

Ui::Ui(){

}

Ui::~Ui(){
;
}

Ui::Ui(Service& sv){

    this->service =sv;
}

void citire_nuvela(char*& autor, char*& titlu, char*&editura){
    autor = new char[20];
    titlu = new char[50];
    editura = new char[50];

    cout<<"Dati autorul"<<endl;
    cin.ignore();
    cin.getline(autor,20);
    cout<<"Dati titlul"<<endl;
    cin.getline(titlu,50);
    cout<<"Dati editura"<<endl;
    cin.getline(editura,50);
}

void citire_poezie(char*& autor, char*&titlu, int& numar){
    autor = new char[20];
    titlu = new char[50];
    numar = 0;

    cout<<"Dati autorul"<<endl;
    cin.ignore();
    cin.getline(autor,20);
    cout<<"Dati titlul"<<endl;
    cin.getline(titlu,50);
    cout<<"Dati numarul de poezii"<<endl;
    cin>>numar;

}

void Ui::adaugare_volum(){
    cout<<"Alegeti tipul volumui: "<<endl;
    cout<<"1.Nuvela"<<endl;
    cout<<"2.Poezie"<<endl;

    int opt;
    char* autor;
    char* titlu;
    char* editura;
    int numar;
    cin>>opt;
    if(opt==1){
        citire_nuvela(autor,titlu,editura);
        try{
        this->service.adauga_nuvela(autor,titlu,editura);
        }
        catch(ValidationException& e){
            cout<<e.what()<<endl;
        }
    }
    if (opt==2){
        citire_poezie(autor,titlu,numar);
        try{
        this->service.adauga_poezii(autor,titlu,numar);
        }
        catch(ValidationException & e){
            cout<<e.what()<<endl;
        }

    }
    delete []autor;
    delete []editura;
    delete []titlu;

}

void Ui::imprumutare_volum(){
    cout<<"Alegeti tipul volumui: "<<endl;
    cout<<"1.Nuvela"<<endl;
    cout<<"2.Poezie"<<endl;

    int opt;
    cin>>opt;
    char* autor;
    char* titlu;
    char* editura;
    int numar;
    if(opt==1){
        citire_nuvela(autor,titlu,editura);
        int rez = this->service.imprumut_nuvela(autor,titlu,editura);
        if(rez == -1){
            cout<<"Volumul nu e disponibil";
        }
        else cout<<"Imprumutul s-a realizat cu succes"<<endl;
    }
    if(opt==2){
        citire_poezie(autor,titlu,numar);
        int rez = this->service.imprumut_poezie(autor,titlu,numar);
        if(rez == -1){
            cout<<"Volumul nu e disponibil";
        }
        else cout<<"Imprumutul s-a realizat cu succes"<<endl;
    }

}

void Ui::returnare_volum(){
    cout<<"Alegeti tipul volumului: "<<endl;
    cout<<"1.Nuvela"<<endl;
    cout<<"2.Poezie"<<endl;

    int opt;
    cin>>opt;
    char* autor;
    char* titlu;
    char* editura;
    int numar;
    if(opt==1){
        citire_nuvela(autor,titlu,editura);
        int rez = this->service.retur_nuvela(autor,titlu,editura);
        if(rez == -1){
            cout<<"Volumul nu a fost returnat";
        }
        else cout<<"Returnarea s-a realizat cu succes"<<endl;
    }
    if(opt==2){
        citire_poezie(autor,titlu,numar);
        int rez = this->service.retur_poezie(autor,titlu,numar);
        if(rez == -1){
            cout<<"Volumul nu a fost returnat";
        }
        else cout<<"Returnarea s-a realizat cu succes"<<endl;
    }

}

void Ui::cautare_volume(){
    cout<<"Alegeti tipul volumui: "<<endl;
    cout<<"1.Nuvela"<<endl;
    cout<<"2.Poezie"<<endl;

    int opt;
    cin>>opt;

    char* autor;
    char* titlu;
    char* editura;
    int numar;

    if(opt==1){
        citire_nuvela(autor,titlu,editura);
        int rez = this->service.cautare_nuvela(autor,titlu,editura);
        if(rez == 1){
            cout<<"Volumul a fost gasit cu succes"<<endl;
        }
        else cout<<"Volumul nu se afla in biblioteca"<<endl;
    }
    if(opt == 2){
        citire_poezie(autor,titlu,numar);
        int rez = this->service.cautare_poezie(autor,titlu,numar);
        if(rez == -1){
            cout<<"Volumul a fost gasit cu succes";
        }
        else cout<<"Volumul nu se afla in biblioteca"<<endl;
    }


}

void Ui::show_volume(){
    vector<Volum*> nuvele = this->service.get_nuvele();
    vector<Volum*> poezii = this->service.get_poezii();

    cout<<"Toate volumele din biblioteca: "<<endl;
    for(int i=0;i<nuvele.size();i++) cout<<nuvele[i]->toString()<<endl;
    for(int i=0;i<poezii.size();i++) cout<<poezii[i]->toString()<<endl;


}


void Ui::sort_volume(){
    vector<Volum*> all = this->service.sortare_autor();

    cout<<"Toate volumele sortate dupa autor din biblioteca: "<<endl;
    for(int i=0;i<all.size();i++) cout<<all[i]->toString()<<endl;

}

void Ui::show_menu(){
    cout<<"1.Adaugare volum"<<endl;
    cout<<"2.Imprumutare volum"<<endl;
    cout<<"3.Returnare volum"<<endl;
    cout<<"4.Cautare volum"<<endl;
    cout<<"5.Toate volumele"<<endl;
    cout<<"6.Volumele sortate dupa autor"<<endl;
    cout<<"0.Iesire"<<endl;

    int opt;
    cin>>opt;
    while(opt!=0){
        if(opt == 1) adaugare_volum();
        else if(opt==2) imprumutare_volum();
        else if(opt==3) returnare_volum();
        else if(opt==4) cautare_volume();
        else if(opt==5) show_volume();
        else if(opt==6) sort_volume();

        cout<<"1.Adaugare volum"<<endl;
        cout<<"2.Imprumutare volum"<<endl;
        cout<<"3.Returnare volum"<<endl;
        cout<<"4.Cautare volum"<<endl;
        cout<<"5.Toate volumele"<<endl;
        cout<<"6.Volumele sortate dupa autor"<<endl;
        cout<<"0.Iesire"<<endl;
        cin>>opt;
    }

}





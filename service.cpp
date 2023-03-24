#include "service.h"
#include <algorithm>
#include <cstring>
#include "validation_exception.h"

using namespace std;

Service::Service(Repository& nuvele,Repository &poezii){
    this->nuvele = nuvele;
    this->poezii = poezii;
}

Service::Service(){

}

void Service::adauga_nuvela(char* a,char *t, char* e){
    Nuvela *n = new Nuvela(a,t,e);
    try{
    this->nuvele.add(n);
    }
    catch(ValidationException& e){
        throw;
    }
}

void Service::adauga_poezii(char* a, char*t, int c){
    Poezii *p =  new Poezii(a,t,c);
    try{
    this->poezii.add(p);
    }
    catch(ValidationException& e){
        throw;
    }
}

int Service::imprumut_nuvela(char* a,char *t, char* e){
    Nuvela *n = new Nuvela(a,t,e);
    vector<Volum*> all_nuvele = this->nuvele.get_all();
    for(int i=0;i<all_nuvele.size();i++){
        if(all_nuvele[i]->equals(n)){
            if(all_nuvele[i]->esteDisponibil()){
                all_nuvele[i]->setDisponibil(false);
                return 1;
            }
        }
    }
    return 0;
}

int Service::imprumut_poezie(char*a ,char*t ,int c){
    Poezii * p = new Poezii(a,t,c);
    vector<Volum*> all_poezii = this->poezii.get_all();
    for(int i=0;i<all_poezii.size();i++){
        if(all_poezii[i]->equals(p)){
            if(all_poezii[i]->esteDisponibil()){
                all_poezii[i]->setDisponibil(false);
                return 1;
            }
        }
    }
    return 0;
}

int Service::retur_nuvela(char* a,char *t, char* e){
    Nuvela *n = new Nuvela(a,t,e);
    vector<Volum*> all_nuvele = this->nuvele.get_all();
    for(int i=0;i<all_nuvele.size();i++){
        if(all_nuvele[i]->equals(n)){
            if(all_nuvele[i]->esteDisponibil()){
                all_nuvele[i]->setDisponibil(true);
                return 1;
            }
        }
    }
    return 0;
}

int Service::retur_poezie(char* a, char*t ,int c){

    Poezii * p = new Poezii(a,t,c);
    vector<Volum*> all_poezii = this->poezii.get_all();
    for(int i=0;i<all_poezii.size();i++){
        if(all_poezii[i]->equals(p)){
            if(all_poezii[i]->esteDisponibil()){
                all_poezii[i]->setDisponibil(true);
                return 1;
            }
        }
    }
    return 0;
}

int Service::cautare_nuvela(char*a,char*t,char*e){
    Nuvela *n = new Nuvela(a,t,e);
    return this->nuvele.search(n);

}

int Service::cautare_poezie(char*a,char*t,int c){
    Poezii* p =new Poezii(a,t,c);
    return this->poezii.search(p);

}

vector<Volum*> Service::get_nuvele(){

    return this->nuvele.get_all();

}

vector<Volum*> Service::get_poezii(){

    return this->poezii.get_all();
}

Service::~Service(){
    ;
}

bool compare(Volum* a, Volum* b){

    return strcmp(a->getAutor(),b->getAutor()) <0 ;

}

vector<Volum*> Service::sortare_autor(){
    vector<Volum*> nuvele = this->nuvele.get_all();
    vector<Volum*> poezii = this->poezii.get_all();

    vector<Volum*> all;

    for(int i=0;i<nuvele.size();i++)
        all.push_back(nuvele[i]);

    for(int i=0;i<poezii.size();i++)
        all.push_back(poezii[i]);


    sort(all.begin(),all.end(),compare);

}

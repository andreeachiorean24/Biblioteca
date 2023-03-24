#include "v_nuvela.h"
#include <cstring>
using namespace std;
Nuvela::Nuvela():Volum(){

    this->editura=0;

}

Nuvela::Nuvela(char* a,char* t,char *e):Volum(a,t){
    this->editura= new char[strlen(e)+1];
    strcpy(this->editura, e);

}

Nuvela::~Nuvela(){
    if(this->editura) delete[] this->editura;

}

void Nuvela::setEditura(char*e){
    if(this->editura)
        delete[] this->editura;

    this->editura= new char[strlen(e)+1];
    strcpy(this->editura, e);

}

char* Nuvela::getEditura(){

    return this->editura;
}

int Nuvela::equals(Volum*v){
    Nuvela* n = (Nuvela* )v;
    return Volum::equals(v)&& strcmp(this->editura,n->editura)==0;

}

string Nuvela::toString(){
    string p;
    p+= Volum::toString();
    p+=" ";
    p+=(string) this->editura;
    return p;
}




